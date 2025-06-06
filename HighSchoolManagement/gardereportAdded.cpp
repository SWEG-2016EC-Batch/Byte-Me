#include <bits/stdc++.h>
using namespace std;

const string ADMIN_PASS = "admin123";
const int MAX_STUDENTS = 400;
const int MAX_GRADES = 4; // Grades 9-12
const int MAX_SECTIONS = 2; // A and B

// Grade-specific fee constants
const double FEE_GRADE_9 = 5000.0;
const double FEE_GRADE_10 = 5500.0;
const double FEE_GRADE_11 = 6000.0;
const double FEE_GRADE_12 = 6500.0;

const int NUM_SUBJECTS = 8;
const string SUBJECT_NAMES[NUM_SUBJECTS] = {
    "Mathematics", "Geography", "English", "History", 
    "Chemistry", "Physics", "Civics", "Biology"
};

const double GRADE_SCALE[5][2] = {
    {90, 4.0},  // A
    {80, 3.0},  // B
    {70, 2.0},  // C
    {60, 1.0},  // D
    {0,  0.0}   // F
};

// Track section counts [0 for A, 1 for B]
int sectionCounts[MAX_GRADES][MAX_SECTIONS] = {0};

struct Student {
    string id;
    string Fname, Lname;
    int age, grade;
    char section;
    int marks[7];
    bool isActive;
    double totalFees;
    double amountPaid;
    string paymentMethod; // Store latest payment method

    Student() {
        for (int i = 0; i < 7; i++) marks[i] = 0;
        isActive = false;
        totalFees = 0.0;
        amountPaid = 0.0;
        paymentMethod = "None"; // Initialize new field
    }

    double getBalance() const 
    {
        return totalFees - amountPaid;
    }
};

Student CurrStudents[MAX_STUDENTS];
vector<Student> recentlyLeftStudents;
int currStudentCount = 0;

void loginScreen();
void adminMenu();
void ManageStudent();
void ManageFeesAndPayments(); // New menu function
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
double getGradeFee(int grade);
void payFees();
void generateFeeReport();
void viewOverduePayments(); // New: List students with outstanding balances
void generateFeeSummary(); // New: Summary of total fees and payments

void manageGrades();
void enterMarks();
void generateReportCard();
char calculateLetterGrade(double marks);
double calculateGPA(const Student& student);
void displayReportCard(const Student& student);
void saveReportCardToFile(const Student& student);

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
        cout << "2. Manage Fees and Payments\n";
        cout << "3. Manage Grades and Report Cards\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;  // <-- THIS WAS MISSING
        
        switch (choice) {
            case 1:
                ManageStudent();
                break;
            case 2:
                ManageFeesAndPayments();
                break;
            case 3:
                manageGrades();
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

void addStudent(){
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

    if (isClassFull(gradeToAdd, sectionToAdd)) {
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
            CurrStudents[i].totalFees = getGradeFee(gradeToAdd);
            updateSectionCount(gradeToAdd, sectionToAdd, true);
            currStudentCount++;
            numberToAdd--;
        }
    }

    cout << "Students added successfully.\n";
}

bool validateGradeAndSection(int grade, char section) {
    bool isGradeValid = true;
    if (grade < 9) {
        isGradeValid = false;
        cout << "Validation error: Grade " << grade << " is too low. Must be between 9 and 12.\n";
    } else if (grade > 12) {
        isGradeValid = false;
        cout << "Validation error: Grade " << grade << " is too high. Must be between 9 and 12.\n";
    }

    char Section = toupper(section);
    bool isSectionValid = true;
    if (Section != 'A' && Section != 'B') {
        isSectionValid = false;
        cout << "Validation error: Section '" << section << "' is invalid. Must be 'A' or 'B'.\n";
    }

    return isGradeValid && isSectionValid;
}

bool isClassFull(int grade, char section) {
    int studentCount = getSectionCount(grade, section);
    return studentCount >= 50;
}

int getSectionCount(int grade, char section) {
    if (!validateGradeAndSection(grade, section)) {
        return 0;
    }

    int gradeIndex = grade - 9;
    int sectionIndex = toupper(section) == 'A' ? 0 : 1;
    return sectionCounts[gradeIndex][sectionIndex];
}

int getStartIndex(int grade, char section) {
    if (!validateGradeAndSection(grade, section)) {
        cout << "Invalid grade or section in getStartIndex. Returning 0.\n";
        return 0;
    }

    int gradeIndex = grade - 9;
    int baseIndex = gradeIndex * 100;
    int startIndex = baseIndex;
    if (toupper(section) == 'B') {
        startIndex += 50;
    }
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
    s.totalFees = getGradeFee(grade);
    return s;
}

string generateStudentID(int grade, char section, int index) {
    string gradeLabel = getGradeLabel(grade);
    char Section = toupper(section);
    int serialNumber = (index % 50) + 1;
    string serial = "00" + to_string(serialNumber);
    string studentID = gradeLabel + "-" + Section + serial;
    return studentID;
}

string getGradeLabel(int grade) {
    switch (grade) {
        case 9: return "FR";
        case 10: return "SO";
        case 11: return "JR";
        case 12: return "SR";
        default: return "XX";
    }
}

double getGradeFee(int grade) {
    switch (grade) {
        case 9: return FEE_GRADE_9;
        case 10: return FEE_GRADE_10;
        case 11: return FEE_GRADE_11;
        case 12: return FEE_GRADE_12;
        default: return 0.0;
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
        infile.close();
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

void tryAddStudentFromLine(string line, ofstream& addedFile, ofstream& failedFile, int& successCount, int& failedCount) {
    string fname, lname;
    int age, grade;
    char section;
    stringstream ss(line);
    if (!(ss >> fname >> lname >> age >> grade >> section)) {
        failedFile << line << "\n";
        failedCount++;
        return;
    }

    if (!validateGradeAndSection(grade, section) || isClassFull(grade, section)) {
        failedFile << fname << " " << lname << "\n";
        failedCount++;
        return;
    }

    int startIdx = getStartIndex(grade, section);
    int endIdx = startIdx + 50;

    for (int i = startIdx; i < endIdx; i++) {
        if (!CurrStudents[i].isActive) {
            CurrStudents[i].Fname = fname;
            CurrStudents[i].Lname = lname;
            CurrStudents[i].age = age;
            CurrStudents[i].grade = grade;
            CurrStudents[i].section = toupper(section);
            CurrStudents[i].id = generateStudentID(grade, section, i);
            CurrStudents[i].isActive = true;
            CurrStudents[i].totalFees = getGradeFee(grade);
            addedFile << CurrStudents[i].id << " " << fname << " " << lname << " " << age << " " << grade << " " << section
                      << " | Fees: $" << CurrStudents[i].totalFees << "\n";
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
    if (!validateGradeAndSection(grade, section)) {
        cout << "Invalid grade or section in updateSectionCount. No update performed.\n";
        return;
    }

    int gradeIndex = grade - 9;
    int sectionIndex = toupper(section) == 'A' ? 0 : 1;

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
            if (CurrStudents[j].isActive && CurrStudents[j].id == id) {
                cout << "Student Found:\n";
                cout << "ID: " << CurrStudents[j].id << "\n";
                cout << "Name: " << CurrStudents[j].Fname << " " << CurrStudents[j].Lname << "\n";
                cout << "Age: " << CurrStudents[j].age << ", Grade: " << CurrStudents[j].grade
                     << ", Section: " << CurrStudents[j].section << "\n";
                cout << "Total Fees: $" << CurrStudents[j].totalFees
                     << ", Paid: $" << CurrStudents[j].amountPaid
                     << ", Balance: $" << CurrStudents[j].getBalance()
                     << ", Payment Method: " << CurrStudents[j].paymentMethod << "\n";

                char confirm;
                cout << "Are you sure you want to remove this student? (Y/N): ";
                cin >> confirm;
                if (toupper(confirm) == 'Y') {
                    recentlyLeftStudents.push_back(CurrStudents[j]);
                    recentlyLeftStudents.back().isActive = false;
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
                cout << "Removing student: " << CurrStudents[i].Fname << " "
                     << CurrStudents[i].Lname << " (ID: " << id << ")\n";
                cout << "Total Fees: $" << CurrStudents[i].totalFees
                     << ", Paid: $" << CurrStudents[i].amountPaid
                     << ", Balance: $" << CurrStudents[i].getBalance()
                     << ", Payment Method: " << CurrStudents[i].paymentMethod << "\n";
                recentlyLeftStudents.push_back(CurrStudents[i]);
                recentlyLeftStudents.back().isActive = false;
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
    char viewChoice;
    cout << "Choose an option:\n";
    cout << "A. Current students\n";
    cout << "B. Recently left students\n";
    cout << "Choice: ";
    cin >> viewChoice;
    viewChoice = toupper(viewChoice);

    if (viewChoice != 'A' && viewChoice != 'B') {
        cout << "Invalid choice.\n";
        return;
    }

    if (viewChoice == 'A') {
        viewCurrentStudents();
    } else {
        viewRecentlyLeftStudents();
    }
}

void viewCurrentStudents() {
    int grade;
    char section;
    cout << "Enter grade and section to view (e.g., 9 A): ";
    if (!(cin >> grade >> section)) {
        cout << "Invalid input. Please enter a number for grade and a letter for section.\n";
        cin.clear();
       
        return;
    }
    section = toupper(section);

    if (!validateGradeAndSection(grade, section)) {
        cout << "Invalid grade (9-12) or section (A or B).\n";
        return;
    }

    int startIdx = getStartIndex(grade, section);
    int endIdx = startIdx + 50;

    bool found = false;
    cout << "\n--- Students in Grade " << grade << " Section " << section << " ---\n";
    for (int i = startIdx; i < endIdx; i++) {
        if (CurrStudents[i].isActive) {
            found = true;
            cout << "ID: " << CurrStudents[i].id
                 << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                 << " | Age: " << CurrStudents[i].age
                 << " | Fees: $" << CurrStudents[i].totalFees
                 << " | Paid: $" << CurrStudents[i].amountPaid
                 << " | Balance: $" << CurrStudents[i].getBalance()
                 << " | Payment Method: " << CurrStudents[i].paymentMethod << "\n";
        }
    }

    if (!found) {
        cout << "No students found in this section.\n";
        return;
    }

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

        for (int i = startIdx; i < endIdx; i++) {
            if (CurrStudents[i].isActive) {
                outFile << "ID: " << CurrStudents[i].id
                        << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                        << " | Age: " << CurrStudents[i].age
                        << " | Fees: $" << CurrStudents[i].totalFees
                        << " | Paid: $" << CurrStudents[i].amountPaid
                        << " | Balance: $" << CurrStudents[i].getBalance()
                        << " | Payment Method: " << CurrStudents[i].paymentMethod << "\n";
            }
        }
        outFile.close();
        cout << "Student list saved to file: " << filename << "\n";
    }
}

void viewRecentlyLeftStudents() {
    if (recentlyLeftStudents.empty()) {
        cout << "\nNo recently left students found.\n";
        return;
    }

    cout << "\n--- Recently Left Students ---\n";
    for (const auto& student : recentlyLeftStudents) {
        cout << "ID: " << student.id
             << " | Name: " << student.Fname << " " << student.Lname
             << " | Age: " << student.age
             << " | Grade: " << student.grade
             << " | Section: " << student.section
             << " | Fees: $" << student.totalFees
             << " | Paid: $" << student.amountPaid
             << " | Balance: $" << student.getBalance()
             << " | Payment Method: " << student.paymentMethod << "\n";
    }

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

        for (const auto& student : recentlyLeftStudents) {
            outFile << "ID: " << student.id
                    << " | Name: " << student.Fname << " " << student.Lname
                    << " | Age: " << student.age
                    << " | Grade: " << student.grade
                    << " | Section: " << student.section
                    << " | Fees: $" << student.totalFees
                    << " | Paid: $" << student.amountPaid
                    << " | Balance: $" << student.getBalance()
                    << " | Payment Method: " << student.paymentMethod << "\n";
        }
        outFile.close();
        cout << "Recently left students list saved to file: " << filename << "\n";
    }
}

void searchStudent() {
    char searchChoice;
    cout << "Choose an option:\n";
    cout << "A. Current students\n";
    cout << "B. Recently left students\n";
    cout << "Choice: ";
    cin >> searchChoice;
    searchChoice = toupper(searchChoice);

    if (searchChoice != 'A' && searchChoice != 'B') {
        cout << "Invalid choice. Please enter 'A' or 'B'.\n";
        return;
    }

    string id;
    cout << "Enter student ID (e.g., FR-A001): ";
    cin >> id;

    if (searchChoice == 'A') {
        searchCurrentStudents(id);
    } else {
        searchRecentlyLeftStudents(id);
    }
}

void searchCurrentStudents(string id) {
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
            cout << "Total Fees: $" << CurrStudents[i].totalFees << "\n";
            cout << "Amount Paid: $" << CurrStudents[i].amountPaid << "\n";
            cout << "Balance: $" << CurrStudents[i].getBalance() << "\n";
            cout << "Payment Method: " << CurrStudents[i].paymentMethod << "\n";
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << id << " not found among current students.\n";
    }
}

void searchRecentlyLeftStudents(string id) {
    bool found = false;
    for (const auto& student : recentlyLeftStudents) {
        if (student.id == id) {
            found = true;
            cout << "\nStudent Found (Recently Left):\n";
            cout << "ID: " << student.id << "\n";
            cout << "Name: " << student.Fname << " " << student.Lname << "\n";
            cout << "Age: " << student.age << "\n";
            cout << "Grade: " << student.grade << "\n";
            cout << "Section: " << student.section << "\n";
            cout << "Total Fees: $" << student.totalFees << "\n";
            cout << "Amount Paid: $" << student.amountPaid << "\n";
            cout << "Balance: $" << student.getBalance() << "\n";
            cout << "Payment Method: " << student.paymentMethod << "\n";
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << id << " not found among recently left students.\n";
    }
}



void ManageFeesAndPayments() {
    int choice;
    cout << "\n-- Manage Fees and Payments --\n";
    cout << "1. Pay fees\n";
    cout << "2. Generate fee report\n";
    cout << "3. View overdue payments\n"; // New option
    cout << "4. Generate fee summary\n"; // New option
    cout << "5. Return to main menu\n";

    if (!(cin >> choice)) {
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
       
        return;
    }
    switch (choice) {
        case 1:
            payFees();
            break;
        case 2:
            generateFeeReport();
            break;
        case 3:
            viewOverduePayments();
            break;
        case 4:
            generateFeeSummary();
            break;
        case 5:
            break;
        default:
            cout << "Invalid option.\n";
    }
}

void payFees() {
    string id;
    cout << "Enter Student ID (e.g., FR-A001): ";
    cin >> id;

    for (int i = 0; i < MAX_STUDENTS; i++){
        if (CurrStudents[i].isActive && CurrStudents[i].id == id){
            double amount;
            string method;
            cout << "Student: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname << "\n";
            cout << "Total Fees: $" << CurrStudents[i].totalFees
                 << ", Paid: $" << CurrStudents[i].amountPaid
                 << ", Balance: $" << CurrStudents[i].getBalance() << "\n";
            cout << "Enter amount to pay: $";
            if (!(cin >> amount) || amount <= 0 || CurrStudents[i].amountPaid + amount > CurrStudents[i].totalFees) {
                cout << "Invalid payment amount.\n";
                cin.clear();
               
                return;
            }
            cout << "Enter payment method (Cash/Check/Online): ";
            cin >> method;
            // Basic validation for payment method
            if (method != "Cash" && method != "Check" && method != "Online") {
                cout << "Invalid payment method. Must be Cash, Check, or Online.\n";
                return;
            }

            CurrStudents[i].amountPaid += amount;
            CurrStudents[i].paymentMethod = method; // Store payment method
            cout << "Payment successful. Remaining balance: $" << CurrStudents[i].getBalance()
                 << ", Paid via: " << CurrStudents[i].paymentMethod << "\n";
            return;
        }
    }
    cout << "Student ID not found among current students.\n";
}

void generateFeeReport() {
    cout << "\n--- Fee Report for Current Students ---\n";
    bool found = false;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (CurrStudents[i].isActive) {
            found = true;
            cout << "ID: " << CurrStudents[i].id
                 << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                 << " | Grade " << CurrStudents[i].grade << CurrStudents[i].section
                 << " | Paid: $" << CurrStudents[i].amountPaid
                 << " | Balance: $" << CurrStudents[i].getBalance()
                 << " | Payment Method: " << CurrStudents[i].paymentMethod << "\n";
        }
    }
    if (!found) {
        cout << "No active students found.\n";
    }

    char saveToFile;
    cout << "\nWould you like to save this report to a file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y'){
        string filename = "fee_report.txt";
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cout << "Failed to create output file.\n";
            return;
        }

        for (int i = 0; i < MAX_STUDENTS; i++){
            if (CurrStudents[i].isActive) {
                outFile << "ID: " << CurrStudents[i].id
                        << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                        << " | Grade " << CurrStudents[i].grade << CurrStudents[i].section
                        << " | Paid: $" << CurrStudents[i].amountPaid
                        << " | Balance: $" << CurrStudents[i].getBalance()
                        << " | Payment Method: " << CurrStudents[i].paymentMethod << "\n";
            }
        }
        outFile.close();
        cout << "Fee report saved to file: " << filename << "\n";
    }
}

void viewOverduePayments() {
    cout << "\n--- Overdue Payments (Current Students with Balance > $0) ---\n";
    bool found = false;
    for (int i = 0; i < MAX_STUDENTS; i++){
        if (CurrStudents[i].isActive && CurrStudents[i].getBalance() > 0) {
            found = true;
            cout << "ID: " << CurrStudents[i].id
                 << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                 << " | Grade " << CurrStudents[i].grade << CurrStudents[i].section
                 << " | Balance: $" << CurrStudents[i].getBalance()
                 << " | Payment Method: " << CurrStudents[i].paymentMethod << "\n";
        }
    }
    if (!found){
        cout << "No students with overdue payments found.\n";
    }

    char saveToFile;
    cout << "\nWould you like to save this report to a file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y') {
        string filename = "overdue_payments.txt";
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cout << "Failed to create output file.\n";
            return;
        }

        for (int i = 0; i < MAX_STUDENTS; i++) {
            if (CurrStudents[i].isActive && CurrStudents[i].getBalance() > 0) {
                outFile << "ID: " << CurrStudents[i].id
                        << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                        << " | Grade " << CurrStudents[i].grade << CurrStudents[i].section
                        << " | Balance: $" << CurrStudents[i].getBalance()
                        << " | Payment Method: " << CurrStudents[i].paymentMethod << "\n";
            }
        }
        outFile.close();
        cout << "Overdue payments report saved to file: " << filename << "\n";
    }
}

void generateFeeSummary() {
    double totalAssigned = 0.0, totalPaid = 0.0, totalOutstanding = 0.0;
    int studentCount = 0;

    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (CurrStudents[i].isActive) {
            totalAssigned += CurrStudents[i].totalFees;
            totalPaid += CurrStudents[i].amountPaid;
            totalOutstanding += CurrStudents[i].getBalance();
            studentCount++;
        }
    }

    cout << "\n--- Fee Summary for Current Students ---\n";
    cout << "Total Students: " << studentCount << "\n";
    cout << "Total Fees Assigned: $" << totalAssigned << "\n";
    cout << "Total Fees Paid: $" << totalPaid << "\n";
    cout << "Total Outstanding Balance: $" << totalOutstanding << "\n";

    char saveToFile;
    cout << "\nWould you like to save this summary to a file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y') {
        string filename = "fee_summary.txt";
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cout << "Failed to create output file.\n";
            return;
        }

        outFile << "Fee Summary for Current Students\n";
        outFile << "Total Students: " << studentCount << "\n";
        outFile << "Total Fees Assigned: $" << totalAssigned << "\n";
        outFile << "Total Fees Paid: $" << totalPaid << "\n";
        outFile << "Total Outstanding Balance: $" << totalOutstanding << "\n";
        outFile.close();
        cout << "Fee summary saved to file: " << filename << "\n";
    }
}

void manageGrades() {
    int choice;
    cout << "\n-- Grade Management --\n";
    cout << "1. Enter student marks\n";
    cout << "2. Generate report card\n";
    cout << "3. Return to main menu\n";
    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            enterMarks();
            break;
        case 2:
            generateReportCard();
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice!\n";
    }
}

void enterMarks() {
    string id;
    cout << "Enter Student ID (e.g., FR-A001): ";
    cin >> id;

    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (CurrStudents[i].isActive && CurrStudents[i].id == id) {
            cout << "Entering marks for " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname << ":\n";
            
            for (int j = 0; j < NUM_SUBJECTS; j++) {
                do {
                    cout << SUBJECT_NAMES[j] << " marks (0-100): ";
                    cin >> CurrStudents[i].marks[j];
                    if (CurrStudents[i].marks[j] < 0 || CurrStudents[i].marks[j] > 100) {
                        cout << "Invalid marks! Please enter between 0-100.\n";
                    }
                } while (CurrStudents[i].marks[j] < 0 || CurrStudents[i].marks[j] > 100);
            }
            
            cout << "Marks entered successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void generateReportCard() {
    string id;
    cout << "Enter Student ID (e.g., FR-A001): ";
    cin >> id;

    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (CurrStudents[i].isActive && CurrStudents[i].id == id) {
            displayReportCard(CurrStudents[i]);
            
            char choice;
            cout << "\nSave to file? (Y/N): ";
            cin >> choice;
            if (toupper(choice) == 'Y') {
                saveReportCardToFile(CurrStudents[i]);
            }
            return;
        }
    }
    cout << "Student not found!\n";
}

char calculateLetterGrade(double marks) {
    if (marks >= 90) return 'A';
    if (marks >= 80) return 'B';
    if (marks >= 70) return 'C';
    if (marks >= 60) return 'D';
    return 'F';
}

double calculateGPA(const Student& student) {
    double totalPoints = 0.0;
    int validSubjects = 0;
    
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        if (student.marks[i] >= 0) {
            for (int j = 0; j < 5; j++) {
                if (student.marks[i] >= GRADE_SCALE[j][0]) {
                    totalPoints += GRADE_SCALE[j][1];
                    validSubjects++;
                    break;
                }
            }
        }
    }
    
    return (validSubjects > 0) ? (totalPoints / validSubjects) : 0.0;
}

void displayReportCard(const Student& student) {
    cout << "\n\n=== REPORT CARD ===\n";
    cout << "Name: " << student.Fname << " " << student.Lname << "\n";
    cout << "ID: " << student.id << "\n";
    cout << "Grade: " << student.grade << student.section << "\n";
    cout << "----------------------------------------\n";
    cout << "SUBJECT\t\tMARKS\tGRADE\n";
    cout << "----------------------------------------\n";
    
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cout << left << setw(16) << SUBJECT_NAMES[i] 
             << right << setw(4) << student.marks[i] << "\t"
             << calculateLetterGrade(student.marks[i]) << "\n";
    }
    
    cout << "----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "GPA: " << calculateGPA(student) << "\n";
    cout << "========================================\n";
}

void saveReportCardToFile(const Student& student) {
    string filename = "report_card_" + student.id + ".txt";
    ofstream outFile(filename);
    
    if (!outFile.is_open()) {
        cout << "Error creating report card file!\n";
        return;
    }
    
    outFile << "=== REPORT CARD ===\n";
    outFile << "Name: " << student.Fname << " " << student.Lname << "\n";
    outFile << "ID: " << student.id << "\n";
    outFile << "Grade: " << student.grade << student.section << "\n";
    outFile << "----------------------------------------\n";
    outFile << "SUBJECT\t\tMARKS\tGRADE\n";
    outFile << "----------------------------------------\n";
    
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        outFile << left << setw(16) << SUBJECT_NAMES[i] 
                << right << setw(4) << student.marks[i] << "\t"
                << calculateLetterGrade(student.marks[i]) << "\n";
    }
    
    outFile << "----------------------------------------\n";
    outFile << fixed << setprecision(2);
    outFile << "GPA: " << calculateGPA(student) << "\n";
    outFile << "========================================\n";
    
    outFile.close();
    cout << "Report card saved to " << filename << "\n";
}
