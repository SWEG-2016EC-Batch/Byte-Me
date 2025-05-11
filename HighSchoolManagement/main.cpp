#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>


using namespace std;

const string ADMIN_PASS = "admin123";
const int MAX_STUDENTS = 400;
const int MAX_LEFT_STUDENTS = 400;
const int MAX_GRADES = 4; // Grades 9-12
const int MAX_SECTIONS = 2; // A and B

// Track section counts [0 for A, 1 for B]
int sectionCounts[MAX_GRADES][MAX_SECTIONS] = {0};

struct Student {
    string id;
    string Fname, Lname;
    int age, grade;
    char section;
    int marks[7];
    bool isActive;

    Student() {
        for (int i = 0; i < 7; i++) marks[i] = 0;
        isActive = false;
    }
};

Student CurrStudents[MAX_STUDENTS];
Student recentlyLeftStudents[MAX_LEFT_STUDENTS];
int currStudentCount = 0;
int leftStudentCount = 0;

void loginScreen();
void adminMenu();
void ManageStudent();
void addStudent();
void addStudentFromConsole();
bool validateGradeAndSection(int grade, char section);
bool isClassFull(int grade, char section);
int getSectionCount(int grade, char section);
int getStartIndex(int grade, char section);
Student askStudentInfo(int grade, char section, int index);
string generateStudentID(int grade, char section, int index);
string getGradeLabel(int grade);
void addStudentFromFile();
void tryAddStudentFromLine(string line, ofstream& addedFile, ofstream& failedFile, int& successCount, int& failedCount);
void updateSectionCount(int grade, char section, bool increment);
void displayFileContent(string filename, string title);
void removeStudent();
void removeStudentFromConsole();
void removeStudentFromFile();
void viewStudents();
void viewCurrentStudents();
void viewRecentlyLeftStudents();
void searchStudent();
void searchCurrentStudents(string id);
void searchRecentlyLeftStudents(string id);


int main() {
    loginScreen();
    return 0;
}

void loginScreen() {
    cout << "Welcome to the Student Management System\n";
    string password;
    cout << "Enter admin password: ";
    cin >> password;
    if (password != ADMIN_PASS) {
        cout << "Access denied. Program terminating...\n";
        exit(0);
    }
    adminMenu();
}

void adminMenu() {
    int choice;
    do {
        cout << "\n--- Admin Dashboard ---\n";
        cout << "1. Manage Students\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            continue;
        }
        switch (choice) {
            case 1:
                ManageStudent();
                break;
            case 0:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}

void ManageStudent() {
    int choice;
    cout << "\n-- Manage Students --\n";
    cout << "1. Add student/s\n";
    cout << "2. Remove student\n";
    cout << "3. View students\n";
    cout << "4. Search students\n";
    cout << "5. Return to main menu\n";
    if (!(cin >> choice)) {
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        return;
    }
    switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            removeStudent();
            break;
        case 3:
            viewStudents();
            break;
        case 4:
            searchStudent();
            break;
        case 5:
            break;
        default:
            cout << "Invalid option.\n";
    }
}

void addStudent() {
    char choiceForAdd;
    cout << "Choose adding method:\n";
    cout << "A. Add from console input\n";
    cout << "B. Add from text file\n";
    cin >> choiceForAdd;
    choiceForAdd = toupper(choiceForAdd);
    if (choiceForAdd == 'A') {
        addStudentFromConsole();
    } else if (choiceForAdd == 'B') {
        addStudentFromFile();
    } else {
        cout << "Invalid choice!\n";
    }
}

void addStudentFromConsole() {
    int gradeToAdd;
    char sectionToAdd;

    cout << "Enter grade and section (e.g., 9 A): ";
    if (!(cin >> gradeToAdd >> sectionToAdd)) {
        cout << "Invalid input. Please enter a number for grade and a letter for section.\n";
        cin.clear();
        return;
    }
    sectionToAdd = toupper(sectionToAdd);

    if (!validateGradeAndSection(gradeToAdd, sectionToAdd)) {
        cout << "Invalid grade (9-12) or section (A or B).\n";
        return;
    }

    if (isClassFull(gradeToAdd, sectionToAdd)){
        cout << "This class section is already full.\n";
        return;
    }

    int sectionCount = getSectionCount(gradeToAdd, sectionToAdd);
    int availableSpots = 50 - sectionCount;

    int numberToAdd;
    cout << "How many students do you want to add in this section? ";
    if (!(cin >> numberToAdd) || numberToAdd <= 0) {
        cout << "Invalid number of students.\n";
        cin.clear();
        return;
    }

    if (numberToAdd > availableSpots) {
        cout << "Only " << availableSpots << " spot(s) available in this class.\n";
        return;
    }

    int startIdx = getStartIndex(gradeToAdd, sectionToAdd);
    int endIdx = startIdx + 50;

    for (int i = startIdx; i < endIdx && numberToAdd > 0; i++) {
        if (!CurrStudents[i].isActive) {
            CurrStudents[i] = askStudentInfo(gradeToAdd, sectionToAdd, i);
            updateSectionCount(gradeToAdd, sectionToAdd, true);
            currStudentCount++;
            numberToAdd--;
        }
    }

    cout << "Students added successfully.\n";
}

bool validateGradeAndSection(int grade, char section) {
    // Step 1: Check if the grade is within the valid range (9 to 12)
    bool isGradeValid = true;
    if (grade < 9) {
        isGradeValid = false;
        cout << "Validation error: Grade " << grade << " is too low. Must be between 9 and 12.\n";
    } else if (grade > 12) {
        isGradeValid = false;
        cout << "Validation error: Grade " << grade << " is too high. Must be between 9 and 12.\n";
    }

    // Step 2: Normalize section to uppercase for consistent checking
    char Section  = toupper(section);

    // Step 3: Check if the section is either 'A' or 'B'
    bool isSectionValid = true;
    if (Section  != 'A' && Section  != 'B') {
        isSectionValid = false;
        cout << "Validation error: Section '" << section << "' is invalid. Must be 'A' or 'B'.\n";
    }

    // Step 4: Return true only if both grade and section are valid
    if (isGradeValid && isSectionValid) {
        return true;
    } else {
        return false;
    }
}

bool isClassFull(int grade, char section) {
    // Check if the section has reached its maximum capacity of 50 students
    int studentCount = getSectionCount(grade, section);
    return studentCount >= 50;
}

int getSectionCount(int grade, char section) {
    // Validate the grade and section
    if (!validateGradeAndSection(grade, section)) {
        return 0; // Return 0 for invalid inputs to prevent further processing
    }

    //Calculate the grade index (grade 9 maps to index 0, grade 12 to index 3)
    int gradeIndex = grade - 9;

    // Step 3: Determine the section index (A maps to 0, B maps to 1)
    int sectionIndex;
    if (toupper(section) == 'A') {
        sectionIndex = 0;
    } else {
        sectionIndex = 1; // Only 'B' is valid due to validation
    }

    // Step 4: Return the student count for the specified grade and section
    return sectionCounts[gradeIndex][sectionIndex];
}

int getStartIndex(int grade, char section) {
    // Validate the grade and section
    if (!validateGradeAndSection(grade, section)) {
        cout << "Invalid grade or section in getStartIndex. Returning 0.\n";
        return 0; // Return 0 for invalid inputs to prevent incorrect indexing
    }

    // Calculate the base index for the grade
    // Each grade occupies 100 slots (50 for section A, 50 for section B)
    // Grade 9 maps to index 0, grade 10 to 100, grade 11 to 200, grade 12 to 300
    int gradeIndex = grade - 9;
    int baseIndex = gradeIndex * 100;

    // Adjust the index for the section
    // Section A starts at the base index, section B starts 50 slots later
    int startIndex = baseIndex;
    if (toupper(section) == 'B') {
        startIndex += 50;
    }

    // Return the starting index for the grade and section
    return startIndex;
}

Student askStudentInfo(int grade, char section, int index) {
    Student s;
    cout << "Enter student's First Name: ";
    cin >> s.Fname;
    cout << "Enter student's Last Name: ";
    cin >> s.Lname;
    cout << "Enter student's age: ";
    cin >> s.age;
    s.grade = grade;
    s.section = toupper(section);
    s.id = generateStudentID(grade, s.section, index);
    s.isActive = true;
    return s;
}

string generateStudentID(int grade, char section, int index) {
    // Step 1: Get the grade label
    string gradeLabel = getGradeLabel(grade);
    // Step 2: capitiize section
    char Section = toupper(section);

    // Step 3: Calculate the serial number (001 to 050)
    // The index is relative to the section (0 to 49 within the section)
    int serialNumber= (index % 50) + 1; // Maps index to 1-50

    // Step 4: Format the serial number

    string serial="00" + to_string(serialNumber);
    

    // Step 5: Combine the parts to form the ID (e.g., FR-A001)
    string studentID = gradeLabel + "-" + Section + serial;

    // Step 6: Return the generated student ID
    return studentID;
}

string getGradeLabel(int grade){
    switch (grade) {
        case 9: return "FR";
        case 10: return "SO";
        case 11: return "JR";
        case 12: return "SR";
        default: return "XX";
    }
}

void addStudentFromFile() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Failed to open file.\n";
        return;
    }

    ofstream addedFile("added_students.txt");
    ofstream failedFile("failed_students.txt");
    if (!addedFile.is_open() || !failedFile.is_open()) {
        cout << "Failed to open output files.\n";
        return;
    }

    string line;
    int successCount = 0, failedCount = 0;
    while (getline(infile, line)) {
        tryAddStudentFromLine(line, addedFile, failedFile, successCount, failedCount);
    }

    infile.close();
    addedFile.close();
    failedFile.close();

    cout << successCount << " students added successfully.\n";
    cout << failedCount << " students failed to add due to full class or invalid data.\n";
    displayFileContent("added_students.txt", "Successfully Added Students");
    displayFileContent("failed_students.txt", "Failed to Add Students");
}

void tryAddStudentFromLine( string line, ofstream& addedFile, ofstream& failedFile, int& successCount, int& failedCount) {
    string fname, lname;
    int age, grade;
    char section;
    stringstream ss(line); // string to stringstream 
    if (!(ss >> fname >> lname >> age >> grade >> section)) {
        failedFile << line << "\n";
        failedCount++;
        return;
    }

    if (!validateGradeAndSection(grade, section) || isClassFull(grade, section)){
        failedFile << fname << " " << lname << "\n";
        failedCount++;
        return;
    }

    int startIdx = getStartIndex(grade, section);
    int endIdx = startIdx + 50;

    for (int i = startIdx; i < endIdx; i++){
        if (!CurrStudents[i].isActive) {
            CurrStudents[i].Fname = fname;
            CurrStudents[i].Lname = lname;
            CurrStudents[i].age = age;
            CurrStudents[i].grade = grade;
            CurrStudents[i].section = toupper(section);
            CurrStudents[i].id = generateStudentID(grade, section, i);
            CurrStudents[i].isActive = true;
            addedFile << CurrStudents[i].id << " " << fname << " " << lname << " " << age << " " << grade << " " << section << "\n";
            currStudentCount++;
            successCount++;
            updateSectionCount(grade, section, true);
            return;
        }
    }

    failedFile << fname << " " << lname << " " << age << " " << grade << " " << section << "\n";
    failedCount++;
}

void updateSectionCount(int grade, char section, bool increment) {
    // Validate the grade and section
    if (!validateGradeAndSection(grade, section)) {
        cout << "Invalid grade or section in updateSectionCount. No update performed.\n";
        return;
    }

    // Determine the grade index (grade 9 maps to index 0, grade 12 to index 3)
    int gradeIndex = grade - 9;

    // Determine the section index (A maps to 0, B maps to 1)
    int sectionIndex;
    if (toupper(section) == 'A') {
        sectionIndex = 0;
    } else {
        sectionIndex = 1; 
    }

    // Update the student count
    // Increment by 1 if adding a student, decrement by 1 if removing
    if (increment) {
        sectionCounts[gradeIndex][sectionIndex] += 1;
    } else {
        sectionCounts[gradeIndex][sectionIndex] -= 1;
    }
}

void displayFileContent(string filename, string title) {
    cout << "\n-- " << title << " --\n";
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No data available.\n";
        return;
    }
    string line;
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

void removeStudent() {
    char choiceForRemove;
    cout << "Choose removing method:\n";
    cout << "A. Remove from console input\n";
    cout << "B. Remove from text file\n";
    cin >> choiceForRemove;
    choiceForRemove = toupper(choiceForRemove);

    if (choiceForRemove == 'A') {
        removeStudentFromConsole();
    } else if (choiceForRemove == 'B') {
        removeStudentFromFile();
    } else {
        cout << "Invalid choice!\n";
    }
}

void removeStudentFromConsole() {
    int numberToRemove;
    cout << "How many students do you want to remove? ";
    if (!(cin >> numberToRemove) || numberToRemove <= 0) {
        cout << "Invalid number of students.\n";
        cin.clear();
        return;
    }

    for (int i = 0; i < numberToRemove; ++i) {
        string id;
        cout << "Enter student ID to remove (e.g., FR-A001): ";
        cin >> id;

        bool found = false;
        for (int j = 0; j < MAX_STUDENTS; ++j) {
            if (CurrStudents[j].isActive && CurrStudents[j].id == id){

                cout << "Student Found:\n";
                cout << "ID: " << CurrStudents[j].id << "\n";
                cout << "Name: " << CurrStudents[j].Fname << " " << CurrStudents[j].Lname << "\n";
                cout << "Age: " << CurrStudents[j].age << ", Grade: " << CurrStudents[j].grade
                     << ", Section: " << CurrStudents[j].section << "\n";

                char confirm;
                cout << "Are you sure you want to remove this student? (Y/N): ";
                cin >> confirm;
                if (toupper(confirm) == 'Y'){
                    if(leftStudentCount >= MAX_LEFT_STUDENTS){
                        cout << "Cannot store more recently left students. Storage full.\n";
                        break;
                    }
                    recentlyLeftStudents[leftStudentCount] = CurrStudents[j];
                    recentlyLeftStudents[leftStudentCount].isActive = false;
                    leftStudentCount++;
                    CurrStudents[j].isActive = false;
                    updateSectionCount(CurrStudents[j].grade, CurrStudents[j].section, false);
                    currStudentCount--;
                    cout << "Student removed successfully.\n";
                } else {
                    cout << "Removal cancelled.\n";
                }
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student with ID " << id << " not found.\n";
        }
    }
}

void removeStudentFromFile() {
    string filename;
    cout << "Enter filename containing IDs of students to remove: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Failed to open file.\n";
        return;
    }

    string id;
    int removedCount = 0;
    while (infile >> id) {
        bool found = false;
        for (int i = 0; i < MAX_STUDENTS; i++) {
            if (CurrStudents[i].isActive && CurrStudents[i].id == id) {
                if (leftStudentCount >= MAX_LEFT_STUDENTS) {
                    cout << "Cannot store more recently left students. Storage full.\n";
                    infile.close();
                    return;
                }
                cout << "Removing student: " << CurrStudents[i].Fname << " "
                     << CurrStudents[i].Lname << " (ID: " << id << ")\n";
                recentlyLeftStudents[leftStudentCount] = CurrStudents[i];
                recentlyLeftStudents[leftStudentCount].isActive = false;
                leftStudentCount++;
                CurrStudents[i].isActive = false;
                currStudentCount--;
                updateSectionCount(CurrStudents[i].grade, CurrStudents[i].section, false);
                removedCount++;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student with ID " << id << " not found or already removed.\n";
        }
    }
    infile.close();
    cout << removedCount << " student(s) removed from the system.\n";
}

void viewStudents() {
    // Prompt user to choose between current or recently left students
    char viewChoice;
    cout << "Choose an option:\n";
    cout << "A. Current students\n";
    cout << "B. Recently left students\n";
    cout << "Choice: ";
    cin >> viewChoice;
    viewChoice = toupper(viewChoice);

    if (viewChoice != 'A' && viewChoice != 'B') {
        cout << "Invalid choice. \n";
        return;
    }

    if (viewChoice == 'A') {
        viewCurrentStudents();
    } else {
        viewRecentlyLeftStudents();
    }
}
void viewCurrentStudents() {
    // Get grade and section input
    int grade;
    char section;
    cout << "Enter grade and section to view (e.g., 9 A): ";
    if (!(cin >> grade >> section)) {
        cout << "Invalid input. Please enter a number for grade and a letter for section.\n";
        cin.clear();
        return;
    }
    section = toupper(section);

    // Validate grade and section
    if (!validateGradeAndSection(grade, section)) {
        cout << "Invalid grade (9-12) or section (A or B).\n";
        return;
    }

    //  Calculate index range for the grade and section
    int startIdx = getStartIndex(grade, section);
    int endIdx = startIdx + 50;

    // Display active students in the specified section
    bool found = false;
    cout << "\n--- Students in Grade " << grade << " Section " << section << " ---\n";
    for (int i = startIdx; i < endIdx; i++) {
        if (CurrStudents[i].isActive) {
            found = true;
            cout << "ID: " << CurrStudents[i].id
                 << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                 << " | Age: " << CurrStudents[i].age << "\n";
        }
    }

    // Handle case where no students are found
    if (!found) {
        cout << "No students found in this section.\n";
        return;
    }

    // Prompt to save the list to a file
    char saveToFile;
    cout << "\nWould you like to save this list to a file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y') {
        string filename = "view_" + to_string(grade) + "_" + section + ".txt";
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cout << "Failed to create output file.\n";
            return;
        }

    //  Write active students to the file
    for (int i = startIdx; i < endIdx; i++) {
        if (CurrStudents[i].isActive) {
                outFile << "ID: " << CurrStudents[i].id
                        << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                        << " | Age: " << CurrStudents[i].age << "\n";
        }
    }
        outFile.close();
        cout << "Student list saved to file: " << filename << "\n";
    }
}

void viewRecentlyLeftStudents() {
    // Check if there are any recently left students
    if (leftStudentCount == 0) {
        cout << "\nNo recently left students found.\n";
        return;
    }

    // Display all recently left students
    cout << "\n--- Recently Left Students ---\n";
    for (int i = 0; i < leftStudentCount; i++) {
        cout << "ID: " << recentlyLeftStudents[i].id
             << " | Name: " << recentlyLeftStudents[i].Fname << " " << recentlyLeftStudents[i].Lname
             << " | Age: " << recentlyLeftStudents[i].age
             << " | Grade: " << recentlyLeftStudents[i].grade
             << " | Section: " << recentlyLeftStudents[i].section << "\n";
    }

    // Prompt to save the list to a file
    char saveToFile;
    cout << "\nWould you like to save this list to a file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y') {
        string filename = "recently_left_students.txt";
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cout << "Failed to create output file.\n";
            return;
        }

        //  Write recently left students to the file
        for (int i = 0; i < leftStudentCount; i++) {
            outFile << "ID: " << recentlyLeftStudents[i].id
                    << " | Name: " << recentlyLeftStudents[i].Fname << " " << recentlyLeftStudents[i].Lname
                    << " | Age: " << recentlyLeftStudents[i].age
                    << " | Grade: " << recentlyLeftStudents[i].grade
                    << " | Section: " << recentlyLeftStudents[i].section << "\n";
        }
        outFile.close();
        cout << "Recently left students list saved to file: " << filename << "\n";
    }
}

void searchStudent() {
   
    // Prompt user to choose between current or recently left students
    char searchChoice;
    cout << "Choose an option:\n";
    cout << "A. Current students\n";
    cout << "B. Recently left students\n";
    cout << "Choice: ";
    cin >> searchChoice;
    searchChoice = toupper(searchChoice);

    // Validate the choice
    if (searchChoice != 'A' && searchChoice != 'B') {
        cout << "Invalid choice. Please enter 'A' or 'B'.\n";
        return;
    }

    //: Get the student ID to search for
    string id;
    cout << "Enter student ID (e.g., FR-A001): ";
    cin >> id;

    //  Call the appropriate search function based on choice
    if(searchChoice == 'A') {
        searchCurrentStudents(id);
    } else {
        searchRecentlyLeftStudents(id);
    }

}

void searchCurrentStudents(string id){
    // Search for the student in CurrStudents
    bool found = false;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (CurrStudents[i].isActive && CurrStudents[i].id == id) {
            found = true;
            cout << "\nStudent Found (Current):\n";
            cout << "ID: " << CurrStudents[i].id << "\n";
            cout << "Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname << "\n";
            cout << "Age: " << CurrStudents[i].age << "\n";
            cout << "Grade: " << CurrStudents[i].grade << "\n";
            cout << "Section: " << CurrStudents[i].section << "\n";
            break;
        }
    }

    // Handle case where student is not found
    if (!found) {
        cout << "Student with ID " << id << " not found among current students.\n";
    }
}


void searchRecentlyLeftStudents(string id) {
    // Search for the student in recentlyLeftStudents
    bool found = false;
    for (int i = 0; i < leftStudentCount; i++) {
        if (recentlyLeftStudents[i].id == id) {
            found = true;
            cout << "\nStudent Found (Recently Left):\n";
            cout << "ID: " << recentlyLeftStudents[i].id << "\n";
            cout << "Name: " << recentlyLeftStudents[i].Fname << " " << recentlyLeftStudents[i].Lname << "\n";
            cout << "Age: " << recentlyLeftStudents[i].age << "\n";
            cout << "Grade: " << recentlyLeftStudents[i].grade << "\n";
            cout << "Section: " << recentlyLeftStudents[i].section << "\n";
            break;
        }
    }

    // Handle case where student is not found
    if (!found) {
        cout << "Student with ID " << id << " not found among recently left students.\n";
    }
}


