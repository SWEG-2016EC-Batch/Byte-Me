#include <bits/stdc++.h>
using namespace std;

// Admin password for login
const string ADMIN_PASS = "admin123";

// Max students in system
const int MAX_STUDENTS = 400;

// Grades (9-12) and sections (A, B)
const int MAX_GRADES = 4;
const int MAX_SECTIONS = 2;

// Fees for each grade
const double FEE_GRADE_9 = 5000.0;
const double FEE_GRADE_10 = 5500.0;
const double FEE_GRADE_11 = 6000.0;
const double FEE_GRADE_12 = 6500.0;

// Number of subjects
const int NUM_SUBJECTS = 8;

// Subject names
const string SUBJECT_NAMES[NUM_SUBJECTS] = {
    "Mathematics", "Geography", "English", "History", 
    "Chemistry", "Physics", "Civics", "Biology"
};

// Grade scale for GPA
const double GRADE_SCALE[5][2] = {
    {90, 4.0}, {80, 3.0}, {70, 2.0}, {60, 1.0}, {0, 0.0}
};

// Count students in each grade and section
int sectionCounts[MAX_GRADES][MAX_SECTIONS] = {0};



// Student info
struct Student {
    string id;
    string Fname, Lname;
    int age, grade;
    char section;
    int marks[8];
    bool isActive;
    double totalFees;
    double amountPaid;
    string paymentMethod;

    Student() {
        for (int i = 0; i < 8; i++) marks[i] = 0;
        isActive = false;
        totalFees = 0.0;
        amountPaid = 0.0;
        paymentMethod = "None";
    }

    double getBalance() const {
        return totalFees - amountPaid;
    }
};

// Array for students
Student CurrStudents[MAX_STUDENTS];

// List for removed students
vector<Student> recentlyLeftStudents;

// Count of active students
int currStudentCount = 0;


// Subject for scheduling
struct Subject {
    string name;
    string classID;
    string sectionID;
};

// Schedule entry for a class
struct ScheduleEntry {
    string classID;
    string sectionID;
    string subject;
    string teacher;
    string room;
    string timeSlot;
    string day;
};

// Scheduler class to create class schedules
class Scheduler {
private:
    vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    vector<string> timeSlots = {"08:00-09:00", "09:00-10:00", "10:00-11:00", "11:00-12:00", "2:00-3:00", "4:00-5:00"};
    vector<string> rooms = {"Room A", "Room B", "Room C"};
    vector<string> teachers = {"Teacher 1", "Teacher 2", "Teacher 3", "Teacher 4", "Teacher 5", "Teacher 6", "Teacher 7", "Teacher 8"};
    vector<Subject> subjects;
    vector<ScheduleEntry> schedule;
    set<string> usedSlots;

public:
    // Add subject to schedule
    void addSubject(const Subject& sub) {
        subjects.push_back(sub);
    }

    // Create subjects for all grades and sections
    void generateSubjectsAutomatically() {
        for (int cls = 9; cls <= 12; ++cls) {
            for (char sec = 'A'; sec <= 'B'; ++sec) {
                for (int s = 0; s < NUM_SUBJECTS; ++s) {
                    Subject subject = {SUBJECT_NAMES[s], to_string(cls), string(1, sec)};
                    addSubject(subject);
                }
            }
        }
    }

    // Generate schedule
    void generateSchedule() {
        int subjectIndex = 0;
        for (const auto& day : days) {
            for (const auto& time : timeSlots) {
                for (const auto& room : rooms) {
                    if (subjectIndex >= subjects.size()) return;
                    string slotKey = day + time + room;
                    if (usedSlots.find(slotKey) == usedSlots.end()) {
                        ScheduleEntry entry;
                        entry.classID = subjects[subjectIndex].classID;
                        entry.sectionID = subjects[subjectIndex].sectionID;
                        entry.subject = subjects[subjectIndex].name;
                        entry.day = day;
                        entry.timeSlot = time;
                        entry.room = room;
                        entry.teacher = teachers[subjectIndex % teachers.size()];
                        schedule.push_back(entry);
                        usedSlots.insert(slotKey);
                        subjectIndex++;
                    }
                }
            }
        }
    }

    // Show schedule
    void displaySchedule() {
        cout << "\n--- Class Schedule ---\n";
        for (const auto& entry : schedule) {
            cout << "Grade " << entry.classID << " Section " << entry.sectionID
                 << " | " << entry.day << " | " << entry.timeSlot << " | "
                 << entry.subject << " | " << entry.teacher << " | " << entry.room << endl;
        }
    }

    // Save schedule to file
    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error opening file!\n";
            return;
        }
        for (const auto& entry : schedule) {
            outFile << "Grade " << entry.classID << " Section " << entry.sectionID
                    << " | " << entry.day << " | " << entry.timeSlot << " | "
                    << entry.subject << " | " << entry.teacher << " | " << entry.room << "\n";
        }
        outFile.close();
        cout << "\nSchedule saved to " << filename << endl;
    }
};

// Class for timetable
struct Class {
    string className;
    string teacher;
    string timeSlot;
    string room;
};

// Timetable class to manage weekly classes
class Timetable {
private:
    map<string, vector<Class>> schedule;

public:
    // Add class to timetable
    void addClass(const string& day, const Class& c) {
        schedule[day].push_back(c);
        cout << "Class added to " << day << ".\n";
    }

    // Show timetable for one day
    void displayDaySchedule(const string& day) {
        if (schedule.find(day) == schedule.end()) {
            cout << "No classes for " << day << ".\n";
            return;
        }
        cout << "\nSchedule for " << day << ":\n";
        for (const auto& c : schedule[day]) {
            cout << " - " << c.timeSlot << ": " << c.className
                 << " with " << c.teacher << " in Room " << c.room << endl;
        }
    }

    // Show full timetable
    void displayFullSchedule() {
        cout << "\n--- Weekly Timetable ---\n";
        for (const auto& entry : schedule) {
            cout << "\n" << entry.first << ":\n";
            for (const auto& c : entry.second) {
                cout << " - " << c.timeSlot << ": " << c.className
                     << " with " << c.teacher << " in Room " << c.room << endl;
            }
        }
    }

    // Save timetable to file
    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error opening file!\n";
            return;
        }
        outFile << "Weekly Timetable\n";
        for (const auto& entry : schedule) {
            outFile << "\n" << entry.first << ":\n";
            for (const auto& c : entry.second) {
                outFile << " - " << c.timeSlot << ": " << c.className
                        << " with " << c.teacher << " in Room " << c.room << "\n";
            }
        }
        outFile.close();
        cout << "\nTimetable saved to " << filename << endl;
    }
};

// Scheduler and timetable objects
Scheduler scheduler;
Timetable timetable;

// Function declarations
void loginScreen();
void adminMenu();
void ManageStudent();
void ManageFeesAndPayments();
void manageScheduleAndTimetable();
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
void viewOverduePayments();
void generateFeeSummary();
void manageGrades();
void enterMarks();
void generateReportCard();
char calculateLetterGrade(double marks);
double calculateGPA(const Student& student);
void displayReportCard(const Student& student);
void saveReportCardToFile(const Student& student);

// Start program
int main() {
    loginScreen();
    return 0;
}

// Show login screen
void loginScreen() {
    cout << "Welcome to the Student Management System\n";
    string password;
    cout << "Enter admin password: ";
    cin >> password;
    if (password != ADMIN_PASS) {
        cout << "Access denied. Exiting...\n";
        exit(0);
    }
    adminMenu();
}

// Show main menu
void adminMenu() {
    int choice;
    do {
        cout << "\n--- Admin Dashboard ---\n";
        cout << "1. Manage Students\n";
        cout << "2. Manage Fees and Payments\n";
        cout << "3. Manage Grades and Report Cards\n";
        cout << "4. Manage Schedule and Timetable\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
            case 1: ManageStudent(); break;
            case 2: ManageFeesAndPayments(); break;
            case 3: manageGrades(); break;
            case 4: manageScheduleAndTimetable(); break;
            case 0: cout << "Exiting system...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}


// Manage students
void ManageStudent() {
    int choice;
    cout << "\n-- Manage Students --\n";
    cout << "1. Add student/s\n";
    cout << "2. Remove student\n";
    cout << "3. View students\n";
    cout << "4. Search students\n";
    cout << "5. Return to main menu\n";
    if (!(cin >> choice)) {
        cout << "Invalid input.\n";
        cin.clear();
        return;
    }
    switch (choice) {
        case 1: addStudent(); break;
        case 2: removeStudent(); break;
        case 3: viewStudents(); break;
        case 4: searchStudent(); break;
        case 5: break;
        default: cout << "Invalid option.\n";
    }
}

// Choose how to add students
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

// Add students from console
void addStudentFromConsole() {
    int gradeToAdd;
    char sectionToAdd;
    cout << "Enter grade and section (e.g., 9 A): ";
    if (!(cin >> gradeToAdd >> sectionToAdd)) {
        cout << "Invalid input.\n";
        cin.clear();
        return;
    }
    sectionToAdd = toupper(sectionToAdd);
    if (!validateGradeAndSection(gradeToAdd, sectionToAdd)) {
        cout << "Invalid grade or section.\n";
        return;
    }
    if (isClassFull(gradeToAdd, sectionToAdd)) {
        cout << "Class section is full.\n";
        return;
    }
    int sectionCount = getSectionCount(gradeToAdd, sectionToAdd);
    int availableSpots = 50 - sectionCount;
    int numberToAdd;
    cout << "How many students to add? ";
    if (!(cin >> numberToAdd) || numberToAdd <= 0) {
        cout << "Invalid number.\n";
        cin.clear();
        return;
    }
    if (numberToAdd > availableSpots) {
        cout << "Only " << availableSpots << " spot(s) available.\n";
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
    cout << "Students added.\n";
}

// Check if grade and section are valid
bool validateGradeAndSection(int grade, char section) {
    bool isGradeValid = true;
    if (grade < 9) {
        isGradeValid = false;
        cout << "Grade too low.\n";
    } else if (grade > 12) {
        isGradeValid = false;
        cout << "Grade too high.\n";
    }
    char Section = toupper(section);
    bool isSectionValid = true;
    if (Section != 'A' && Section != 'B') {
        isSectionValid = false;
        cout << "Section invalid.\n";
    }
    return isGradeValid && isSectionValid;
}

// Check if class is full
bool isClassFull(int grade, char section) {
    int studentCount = getSectionCount(grade, section);
    return studentCount >= 50;
}

// Get student count for a section
int getSectionCount(int grade, char section) {
    if (!validateGradeAndSection(grade, section)) {
        return 0;
    }
    int gradeIndex = grade - 9;
    int sectionIndex = toupper(section) == 'A' ? 0 : 1;
    return sectionCounts[gradeIndex][sectionIndex];
}

// Get start index for a section
int getStartIndex(int grade, char section) {
    if (!validateGradeAndSection(grade, section)) {
        cout << "Invalid grade or section.\n";
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

// Get student info from console
Student askStudentInfo(int grade, char section, int index) {
    Student s;
    cout << "Enter First Name: ";
    cin >> s.Fname;
    cout << "Enter Last Name: ";
    cin >> s.Lname;
    cout << "Enter age: ";
    cin >> s.age;
    s.grade = grade;
    s.section = toupper(section);
    s.id = generateStudentID(grade, s.section, index);
    s.isActive = true;
    s.totalFees = getGradeFee(grade);
    return s;
}

// Create student ID
string generateStudentID(int grade, char section, int index) {
    string gradeLabel = getGradeLabel(grade);
    char Section = toupper(section);
    int serialNumber = (index % 50) + 1;
    string serial = (serialNumber < 10 ? "00" : serialNumber < 100 ? "0" : "") + to_string(serialNumber);
    string studentID = gradeLabel + "-" + Section + serial;
    return studentID;
}

// Get grade label
string getGradeLabel(int grade) {
    switch (grade) {
        case 9: return "FR";
        case 10: return "SO";
        case 11: return "JR";
        case 12: return "SR";
        default: return "XX";
    }
}

// Add students from file
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
    cout << successCount << " students added.\n";
    cout << failedCount << " students failed to add.\n";
    displayFileContent("added_students.txt", "Added Students");
    displayFileContent("failed_students.txt", "Failed Students");
}

// Try adding student from file line
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

// Update student count
void updateSectionCount(int grade, char section, bool increment) {
    if (!validateGradeAndSection(grade, section)) {
        cout << "Invalid grade or section.\n";
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

// Show file content
void displayFileContent(string filename, string title) {
    cout << "\n-- " << title << " --\n";
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No data.\n";
        return;
    }
    string line;
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

// Choose how to remove students
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

// Remove students from console
void removeStudentFromConsole() {
    int numberToRemove;
    cout << "How many students to remove? ";
    if (!(cin >> numberToRemove) || numberToRemove <= 0) {
        cout << "Invalid number.\n";
        cin.clear();
        return;
    }
    for (int i = 0; i < numberToRemove; ++i) {
        string id;
        cout << "Enter student ID: ";
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
                cout << "Remove this student? (Y/N): ";
                cin >> confirm;
                if (toupper(confirm) == 'Y') {
                    recentlyLeftStudents.push_back(CurrStudents[j]);
                    recentlyLeftStudents.back().isActive = false;
                    CurrStudents[j].isActive = false;
                    updateSectionCount(CurrStudents[j].grade, CurrStudents[j].section, false);
                    currStudentCount--;
                    cout << "Student removed.\n";
                } else {
                    cout << "Removal cancelled.\n";
                }
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student not found.\n";
        }
    }
}

// Remove students from file
void removeStudentFromFile() {
    string filename;
    cout << "Enter filename: ";
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
            cout << "Student not found.\n";
        }
    }
    infile.close();
    cout << removedCount << " student(s) removed.\n";
}

// Choose to view students
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

// Show current students
void viewCurrentStudents() {
    int grade;
    char section;
    cout << "Enter grade and section: ";
    if (!(cin >> grade >> section)) {
        cout << "Invalid input.\n";
        cin.clear();
        return;
    }
    section = toupper(section);
    if (!validateGradeAndSection(grade, section)) {
        cout << "Invalid grade or section.\n";
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
        cout << "No students found.\n";
        return;
    }
    char saveToFile;
    cout << "\nSave to file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y') {
        string filename = "view_" + to_string(grade) + "_" + section + ".txt";
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cout << "Failed to create file.\n";
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
        cout << "List saved to " << filename << "\n";
    }
}

// Show recently left students
void viewRecentlyLeftStudents() {
    if (recentlyLeftStudents.empty()) {
        cout << "\nNo recently left students.\n";
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
    cout << "\nSave to file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y') {
        string filename = "recently_left_students.txt";
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cout << "Failed to create file.\n";
            return;
        }
        for (const auto& student : recentlyLeftStudents) {
            outFile << "ID: " << student.id
                    << " | Name: " << student.Fname << " " << student.Lname
                    << " | Age: " << student.age
                    << " | Grade: " << student.grade
                    << " | Section: " << student.section
                    << " | Fees: $" << student.totalFees
                    << " | Paid: " << student.amountPaid
                    << " | Balance: $" << student.getBalance()
                    << " | Payment Method: " << student.paymentMethod << "\n";
        }
        outFile.close();
        cout << "List saved to " << filename << "\n";
    }
}

// Search for a student
void searchStudent() {
    char searchChoice;
    cout << "Choose an option:\n";
    cout << "A. Current students\n";
    cout << "B. Recently left students\n";
    cout << "Choice: ";
    cin >> searchChoice;
    searchChoice = toupper(searchChoice);
    if (searchChoice != 'A' && searchChoice != 'B') {
        cout << "Invalid choice.\n";
        return;
    }
    string id;
    cout << "Enter student ID: ";
    cin >> id;
    if (searchChoice == 'A') {
        searchCurrentStudents(id);
    } else {
        searchRecentlyLeftStudents(id);
    }
}

// Search current students
void searchCurrentStudents(string id) {
    bool found = false;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (CurrStudents[i].isActive && CurrStudents[i].id == id) {
            found = true;
            cout << "\nStudent Found:\n";
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
        cout << "Student not found.\n";
    }
}

// Search recently left students
void searchRecentlyLeftStudents(string id) {
    bool found = false;
    for (const auto& student : recentlyLeftStudents) {
        if (student.id == id) {
            found = true;
            cout << "\nStudent Found:\n";
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
        cout << "Student not found.\n";
    }
}

// Get fee for a grade
double getGradeFee(int grade) {
    switch (grade) {
        case 9: return FEE_GRADE_9;
        case 10: return FEE_GRADE_10;
        case 11: return FEE_GRADE_11;
        case 12: return FEE_GRADE_12;
        default: return 0.0;
    }
}

// Manage fees and payments
void ManageFeesAndPayments() {
    int choice;
    cout << "\n-- Manage Fees and Payments ---\n";
    cout << "1. Pay fees\n";
    cout << "2. Generate fee report\n";
    cout << "3. View overdue payments\n";
    cout << "4. Generate fee summary\n";
    cout << "5. Return to main menu\n";
    cout << "Choice: ";
    if (!(cin >> choice)) {
        cout << "Invalid input.\n";
        cin.clear();
        return;
    }
    switch (choice) {
        case 1: payFees(); break;
        case 2: generateFeeReport(); break;
        case 3: viewOverduePayments();
        case 4: generateFeeSummary(); break;
        case 5: break;
        default: cout << "Invalid option.\n";
    }
}

// Pay fees for a student
void payFees() {
    string id;
    cout << "Enter Student ID: ";
    cin >> id;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (CurrStudents[i].isActive && CurrStudents[i].id == id) {
            double amount;
            string method;
            cout << "Student: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname << "\n";
            cout << "Total Fees: $" << CurrStudents[i].totalFees
                 << ", Paid: $" << CurrStudents[i].amountPaid
                 << ", Balance: $" << CurrStudents[i].getBalance() << "\n";
            cout << "Enter amount to pay: $";
            if (!(cin >> amount) || amount <= 0 || CurrStudents[i].amountPaid + amount > CurrStudents[i].totalFees) {
                cout << "Invalid amount.\n";
                cin.clear();
                return;
            }
            cout << "Enter payment method (Cash/Check/Online): ";
            cin >> method;
            if (method != "Cash" && method != "Check" && method != "Online") {
                cout << "Invalid method.\n";
                return;
            }
            CurrStudents[i].amountPaid += amount;
            CurrStudents[i].paymentMethod = method;
            cout << "Payment successful. Balance: $" << CurrStudents[i].getBalance()
                 << ", Paid via: " << CurrStudents[i].paymentMethod << "\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Show fee report
void generateFeeReport() {
    cout << "\n--- Fee Report ---\n";
    bool found = false;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (CurrStudents[i].isActive) {
            found = true;
            cout << "ID: " << CurrStudents[i].id
                 << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                 << " | Grade " << CurrStudents[i].grade << CurrStudents[i].section
                 << " | Paid: $" << CurrStudents[i].amountPaid
                 << " | Balance: " << CurrStudents[i].getBalance()
                 << " | Payment Method: " << CurrStudents[i].paymentMethod << "\n";
        }
    }
    if (!found) {
        cout << "No students found.\n";
    }
    char saveToFile;
    cout << "\nSave to file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y') {
        string filename = "fee_report.txt";
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cout << "Failed to create file.\n";
            return;
        }
        for (int i = 0; i < MAX_STUDENTS; i++) {
            if (CurrStudents[i].isActive) {
                outFile << "ID: " << CurrStudents[i].id
                        << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                        << " | Grade " << CurrStudents[i].grade << CurrStudents[i].section
                        << " | Paid: $" << CurrStudents[i].amountPaid
                        << " | Balance: " << CurrStudents[i].getBalance()
                        << " | Payment Method: " << CurrStudents[i].paymentMethod << "\n";
            }
        }
        outFile.close();
        cout << "Report saved to " << filename << "\n";
    }
}

// Show overdue payments
void viewOverduePayments() {
    cout << "\n--- Overdue Payments ---\n";
    bool found = false;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (CurrStudents[i].isActive && CurrStudents[i].getBalance() > 0) {
            found = true;
            cout << "ID: " << CurrStudents[i].id
                 << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                 << " | Grade " << CurrStudents[i].grade << CurrStudents[i].section
                 << " | Balance: $" << CurrStudents[i].getBalance()
                 << " | Payment Method: " << CurrStudents[i].paymentMethod << "\n";
        }
    }
    if (!found) {
        cout << "No overdue payments.\n";
    }
    char saveToFile;
    cout << "\nSave to file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y') {
        string filename = "overdue_payments.txt";
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cout << "Failed to create file.\n";
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
        cout << "Report saved to " << filename << "\n";
    }
}

// Show fee summary
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
    cout << "\n--- Fee Summary ---\n";
    cout << "Total Students: " << studentCount << "\n";
    cout << "Total Fees Assigned: $" << totalAssigned << "\n";
    cout << "Total Fees Paid: $" << totalPaid << "\n";
    cout << "Total Outstanding Balance: $" << totalOutstanding << "\n";
    char saveToFile;
    cout << "\nSave to file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y') {
        string filename = "fee_summary.txt";
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cout << "Failed to create file.\n";
            return;
        }
        outFile << "Fee Summary for Current Students\n";
        outFile << "Total Students: " << studentCount << "\n";
        outFile << "Total Fees Assigned: $" << totalAssigned << "\n";
        outFile << "Total Fees Paid: $" << totalPaid << "\n";
        outFile << "Total Outstanding Balance: $" << totalOutstanding << "\n";
        outFile.close();
        cout << "Summary saved to " << filename << "\n";
    }
}

// Manage grades
void manageGrades() {
    int choice;
    cout << "\n-- Grade Management ---\n";
    cout << "1. Enter student marks\n";
    cout << "2. Generate report\n";
    cout << "3. Return to main menu\n";
    cout << "Choice: ";
    cin >> choice;
    switch (choice) {
        case 1: enterMarks(); break;
        case 2: generateReportCard(); break;
        case 3: break;
        default: cout << "Invalid choice!\n";
    }
}

// Enter student marks
void enterMarks() {
    string id;
    cout << "Enter Student ID: ";
    cin >> id;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (CurrStudents[i].isActive && CurrStudents[i].id == id) {
            cout << "Entering marks for " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname << "\n";
            for (int j = 0; j < NUM_SUBJECTS; j++) {
                do {
                    cout << SUBJECT_NAMES[j] << " marks (0-100): ";
                    cin >> CurrStudents[i].marks[j];
                    if (CurrStudents[i].marks[j] < 0 || CurrStudents[i].marks[j] > 100) {
                        cout << "Invalid marks!\n";
                    }
                } while (CurrStudents[i].marks[j] < 0 || CurrStudents[i].marks[j] > 100);
            }
            cout << "Marks entered.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Generate report card
void generateReportCard() {
    string id;
    cout << "Enter Student ID: ";
    cin >> id;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (CurrStudents[i].isActive && CurrStudents[i].id == id) {
            displayReportCard(CurrStudents[i]);
            char saveChoice;
            cout << "\nSave to file? (Y/N): ";
            cin >> saveChoice;
            if (toupper(saveChoice) == 'Y') {
                saveReportCardToFile(CurrStudents[i]);
            }
            return;
        }
    }
    cout << "Student not found.\n";
}

// Calculate letter grade
char calculateLetterGrade(int marks) {
    if (marks >= 90) return 'A';
    if (marks >= 80) return 'B';
    if (marks >= 70) return 'C';
    if (marks >= 60) return 'D';
    return 'F';
}

// Calculate GPA
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

// Show report card
void displayReportCard(const Student& student) {
    cout << "\n=== REPORT CARD ===\n";
    cout << "Name: " << student.Fname << " " << student.Lname << endl;
    cout << "ID: " << student.id << endl;
    cout << "Grade: " << student.grade << student.section << endl;
    cout << "----------------------------------------\n";
    cout << "SUBJECT\t\tMARKS\tGRADE\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cout << left << setw(16) << SUBJECT_NAMES[i]
             << " " << right << setw(4) << student.marks[i] << "\t"
             << calculateLetterGrade(student.marks[i]) << endl;
    }
    cout << "----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "GPA: " << calculateGPA(student) << "\n";
    cout << "=========================================\n";
}

// Save report card to file
void saveReportCardToFile(const Student& student) {
    string filename = "report_card_" + student.id + ".txt";
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Error creating file!\n";
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
                << " " << right << setw(4) << student.marks[i] << "\t"
                << calculateLetterGrade(student.marks[i]) << "\n";
    }
    outFile << "----------------------------------------\n";
    outFile << fixed << setprecision(2);
    outFile << "GPA: " << calculateGPA(student) << "\n";
    outFile << "=========================================\n";
    outFile.close();
    cout << "Report card saved to " << filename << "\n";
}
// Handle schedule and timetable
void manageScheduleAndTimetable() {
    int choice;
    cout << "\n-- Manage Schedule and Timetable --\n";
    cout << "1. Generate and Display Class Schedule\n";
    cout << "2. Add Class to Timetable\n";
    cout << "3. Display Timetable for a Day\n";
    cout << "4. Display Full Timetable\n";
    cout << "5. Save Timetable to File\n";
    cout << "6. Return to main menu\n";
    cout << "Choice: ";
    if (!(cin >> choice)) {
        cout << "Invalid input.\n";
        cin.clear();
        return;
    }
    switch (choice) {
        case 1:
            scheduler.generateSubjectsAutomatically();
            scheduler.generateSchedule();
            scheduler.displaySchedule();
            scheduler.saveToFile("schedule.txt");
            break;
        case 2: {
            string day, className, teacher, timeSlot, room;
            cout << "Enter day: ";
            cin >> day;
            cout << "Enter class name: ";
            cin.ignore();
            getline(cin, className);
            cout << "Enter teacher: ";
            getline(cin, teacher);
            cout << "Enter time slot: ";
            getline(cin, timeSlot);
            cout << "Enter room: ";
            getline(cin, room);
            Class c = {className, teacher, timeSlot, room};
            timetable.addClass(day, c);
            break;
        }
        case 3: {
            string day;
            cout << "Enter day: ";
            cin >> day;
            timetable.displayDaySchedule(day);
            break;
        }
        case 4:
            timetable.displayFullSchedule();
            break;
        case 5:
            timetable.saveToFile("timetable.txt");
            break;
        case 6: break;
        default: cout << "Invalid option.\n";
    }
}
