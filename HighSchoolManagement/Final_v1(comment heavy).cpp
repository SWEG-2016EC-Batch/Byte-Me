#include <bits/stdc++.h>
using namespace std;

// This is a password for the admin to log into the system. It's set to "admin123".
const string ADMIN_PASS = "admin123";

// We can store up to 400 students in the system.
const int MAX_STUDENTS = 400;

// There are 4 grades in the school: 9, 10, 11, and 12.
const int MAX_GRADES = 4;

// Each grade has 2 sections: A and B.
const int MAX_SECTIONS = 2;

// Fees for each grade. For example, grade 9 costs $5000, grade 10 costs $5500, etc.
const double FEE_GRADE_9 = 5000.0;
const double FEE_GRADE_10 = 5500.0;
const double FEE_GRADE_11 = 6000.0;
const double FEE_GRADE_12 = 6500.0;

// There are 8 subjects that students study.
const int NUM_SUBJECTS = 8;

// Names of the 8 subjects students take, like Mathematics, English, etc.
const string SUBJECT_NAMES[NUM_SUBJECTS] = {
    "Mathematics", "Geography", "English", "History", 
    "Chemistry", "Physics", "Civics", "Biology"
};

// This table helps calculate grades. For example, 90+ marks = A (4.0 GPA points), 80-89 = B (3.0 points), etc.
const double GRADE_SCALE[5][2] = {
    {90, 4.0},  // A
    {80, 3.0},  // B
    {70, 2.0},  // C
    {60, 1.0},  // D
    {0,  0.0}   // F
};

// This array keeps track of how many students are in each grade and section. For example, sectionCounts[0][0] is for grade 9, section A.
int sectionCounts[MAX_GRADES][MAX_SECTIONS] = {0};

// This struct holds info about a subject for scheduling, like its name (e.g., "Mathematics"), grade (e.g., "9"), and section (e.g., "A").
struct Subject {
    string name;      // Name of the subject, like "Mathematics".
    string classID;   // Grade number, like "9" or "10".
    string sectionID; // Section letter, like "A" or "B".
};

// This struct represents one class in the schedule, like "Mathematics for grade 9A on Monday at 8:00-9:00".
struct ScheduleEntry {
    string classID;   // Grade number, like "9".
    string sectionID; // Section letter, like "A".
    string subject;   // Subject name, like "Mathematics".
    string teacher;   // Teacher’s name, like "Teacher 1".
    string room;      // Room name, like "Room A".
    string timeSlot;  // Time, like "08:00-09:00".
    string day;       // Day, like "Monday".
};

// This class creates a schedule for all classes, assigning subjects to days, times, rooms, and teachers.
class Scheduler {
private:
    // List of days school operates: Monday to Friday.
    vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    
    // Time slots for classes each day, like 8:00-9:00 AM, 9:00-10:00 AM, etc.
    vector<string> timeSlots = {"08:00-09:00", "09:00-10:00", "10:00-11:00", "11:00-12:00", "2:00-3:00", "4:00-5:00"};
    
    // Available rooms for classes, like Room A, Room B, Room C.
    vector<string> rooms = {"Room A", "Room B", "Room C"};
    
    // List of teachers who can teach classes. We have 8 teachers to match the 8 subjects.
    vector<string> teachers = {"Teacher 1", "Teacher 2", "Teacher 3", "Teacher 4", "Teacher 5", "Teacher 6", "Teacher 7", "Teacher 8"};
    
    // List of all subjects to schedule (e.g., Mathematics for grade 9A).
    vector<Subject> subjects;
    
    // List of scheduled classes, each with a day, time, room, teacher, etc.
    vector<ScheduleEntry> schedule;
    
    // Keeps track of used day-time-room combinations to avoid scheduling two classes in the same room at the same time.
    set<string> usedSlots;

public:
    // Adds a subject to the list of subjects to schedule.
    void addSubject(const Subject& sub) {
        subjects.push_back(sub); // Add the subject to our list.
    }

    // Creates subjects for all grades (9-12), sections (A and B), using the 8 subjects from SUBJECT_NAMES.
    void generateSubjectsAutomatically() {
        // Loop through grades 9 to 12.
        for (int cls = 9; cls <= 12; ++cls) {
            // Loop through sections A and B.
            for (char sec = 'A'; sec <= 'B'; ++sec) {
                // Add each of the 8 subjects for this grade and section.
                for (int s = 0; s < NUM_SUBJECTS; ++s) {
                    Subject subject = {SUBJECT_NAMES[s], to_string(cls), string(1, sec)};
                    addSubject(subject); // Add subject like "Mathematics for grade 9A".
                }
            }
        }
    }

    // Creates a schedule by assigning each subject a day, time, room, and teacher.
    void generateSchedule() {
        int subjectIndex = 0; // Keep track of which subject we’re scheduling.
        // Loop through each day (Monday to Friday).
        for (const auto& day : days) {
            // Loop through each time slot (e.g., 8:00-9:00).
            for (const auto& time : timeSlots) {
                // Loop through each room (e.g., Room A).
                for (const auto& room : rooms) {
                    // Stop if we’ve scheduled all subjects.
                    if (subjectIndex >= subjects.size()) return;

                    // Create a unique key for this day, time, and room (e.g., "Monday08:00-09:00Room A").
                    string slotKey = day + time + room;
                    // Check if this slot is free (not used yet).
                    if (usedSlots.find(slotKey) == usedSlots.end()) {
                        ScheduleEntry entry; // Create a new schedule entry.
                        entry.classID = subjects[subjectIndex].classID; // Set grade.
                        entry.sectionID = subjects[subjectIndex].sectionID; // Set section.
                        entry.subject = subjects[subjectIndex].name; // Set subject.
                        entry.day = day; // Set day.
                        entry.timeSlot = time; // Set time.
                        entry.room = room; // Set room.
                        // Assign a teacher (cycle through teachers list).
                        entry.teacher = teachers[subjectIndex % teachers.size()];

                        schedule.push_back(entry); // Add this class to the schedule.
                        usedSlots.insert(slotKey); // Mark this slot as used.
                        subjectIndex++; // Move to the next subject.
                    }
                }
            }
        }
    }

    // Shows the schedule on the screen.
    void displaySchedule() {
        cout << "\n--- Generated Class Schedule ---\n";
        // Loop through each scheduled class.
        for (const auto& entry : schedule) {
            // Print details like "Grade 9 Section A | Monday | 08:00-09:00 | Mathematics | Teacher 1 | Room A".
            cout << "Grade " << entry.classID << " Section " << entry.sectionID
                 << " | " << entry.day << " | " << entry.timeSlot << " | "
                 << entry.subject << " | " << entry.teacher << " | " << entry.room << endl;
        }
    }

    // Saves the schedule to a file, like "schedule.txt".
    void saveToFile(const string& filename) {
        ofstream outFile(filename); // Open the file for writing.
        if (!outFile) {
            cerr << "Error opening file for writing!\n"; // Show error if file can’t open.
            return;
        }

        // Write each scheduled class to the file.
        for (const auto& entry : schedule) {
            outFile << "Grade " << entry.classID << " Section " << entry.sectionID
                    << " | " << entry.day << " | " << entry.timeSlot << " | "
                    << entry.subject << " | " << entry.teacher << " | " << entry.room << "\n";
        }

        outFile.close(); // Close the file.
        cout << "\n Schedule saved to file: " << filename << endl;
    }
};

// This struct represents one class in the timetable, like "Mathematics with Teacher 1 at 8:00-9:00 in Room A".
struct Class {
    string className; // Subject name, like "Mathematics".
    string teacher;   // Teacher’s name, like "Teacher 1".
    string timeSlot;  // Time, like "08:00-09:00".
    string room;      // Room, like "Room A".
};

// This class manages a weekly timetable where you can add classes manually and view them by day or week.
class Timetable {
private:
    // This map stores the timetable. The key is the day (e.g., "Monday"), and the value is a list of classes for that day.
    map<string, vector<Class>> schedule;

public:
    // Adds a class to the timetable for a specific day.
    void addClass(const string& day, const Class& c) {
        schedule[day].push_back(c); // Add the class to the day’s list.
        cout << "Class added to " << day << " schedule.\n";
    }

    // Shows the timetable for one specific day.
    void displayDaySchedule(const string& day) {
        // Check if the day has any classes.
        if (schedule.find(day) == schedule.end()) {
            cout << "No classes scheduled for " << day << ".\n";
            return;
        }

        cout << "\nSchedule for " << day << ":\n";
        // Print each class for that day, like "08:00-09:00: Mathematics with Teacher 1 in Room A".
        for (const auto& c : schedule[day]) {
            cout << " - " << c.timeSlot << ": " << c.className
                 << " with " << c.teacher << " in Room " << c.room << endl;
        }
    }

    // Shows the full timetable for all days.
    void displayFullSchedule() {
        cout << "\n--- Weekly Timetable ---\n";
        // Loop through each day in the timetable.
        for (const auto& entry : schedule) {
            cout << "\n" << entry.first << ":\n"; // Print the day.
            // Print each class for that day.
            for (const auto& c : entry.second) {
                cout << " - " << c.timeSlot << ": " << c.className
                     << " with " << c.teacher << " in Room " << c.room << endl;
            }
        }
    }

    // Saves the timetable to a file, like "timetable.txt".
    void saveToFile(const string& filename) {
        ofstream outFile(filename); // Open the file for writing.
        if (!outFile) {
            cerr << "Error opening file for writing!\n"; // Show error if file can’t open.
            return;
        }

        outFile << "Weekly Timetable\n";
        // Write each day and its classes to the file.
        for (const auto& entry : schedule) {
            outFile << "\n" << entry.first << ":\n";
            for (const auto& c : entry.second) {
                outFile << " - " << c.timeSlot << ": " << c.className
                        << " with " << c.teacher << " in Room " << c.room << "\n";
            }
        }

        outFile.close(); // Close the file.
        cout << "\n Timetable saved to file: " << filename << endl;
    }
};

// This struct holds all the info about a student, like their name, ID, grades, and fees.
struct Student {
    string id;            // Unique ID, like "FR-A001".
    string Fname, Lname;  // First and last name.
    int age, grade;       // Age and grade (9, 10, 11, or 12).
    char section;         // Section (A or B).
    int marks[8];         // Marks for 8 subjects.
    bool isActive;        // True if the student is currently enrolled.
    double totalFees;     // Total fees for the student’s grade.
    double amountPaid;    // How much they’ve paid so far.
    string paymentMethod; // How they paid (e.g., Cash, Check, Online).

    // This is the constructor, which sets default values when a new student is created.
    Student() {
        for (int i = 0; i < 8; i++) marks[i] = 0; // Set all marks to 0.
        isActive = false; // Student is not active until added.
        totalFees = 0.0;  // No fees assigned yet.
        amountPaid = 0.0; // No payments made yet.
        paymentMethod = "None"; // No payment method yet.
    }

    // This calculates how much money the student still owes.
    double getBalance() const {
        return totalFees - amountPaid; // Total fees minus what’s paid.
    }
};

// This array stores all students (up to 400).
Student CurrStudents[MAX_STUDENTS];

// This list stores students who recently left the school.
vector<Student> recentlyLeftStudents;

// This counts how many active students are in the system.
int currStudentCount = 0;

// This is the scheduler object we’ll use to create class schedules.
Scheduler scheduler;

// This is the timetable object we’ll use to manage manual class schedules.
Timetable timetable;

// Function declarations so the compiler knows they exist.
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

// The main function is where the program starts.
int main() {
    loginScreen(); // Show the login screen first.
    return 0; // End the program.
}

// This function shows the login screen and checks the admin password.
void loginScreen() {
    cout << "Welcome to the Student Management System\n"; // Welcome message.
    string password; // Variable to store the password.
    cout << "Enter admin password: ";
    cin >> password; // Get the password from the user.
    if (password != ADMIN_PASS) { // Check if it’s correct.
        cout << "Access denied. Program terminating...\n"; // Wrong password, so exit.
        exit(0);
    }
    adminMenu(); // If correct, show the main menu.
}

// This is the main menu where the admin chooses what to do.
void adminMenu() {
    int choice; // Variable to store the user’s choice.
    do { // Keep showing the menu until the user chooses to exit.
        cout << "\n--- Admin Dashboard ---\n";
        cout << "1. Manage Students\n";
        cout << "2. Manage Fees and Payments\n";
        cout << "3. Manage Grades and Report Cards\n";
        cout << "4. Manage Schedule and Timetable\n"; // New option for scheduling.
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice; // Get the user’s choice.

        // Do different things based on the choice.
        switch (choice) {
            case 1:
                ManageStudent(); // Go to student management menu.
                break;
            case 2:
                ManageFeesAndPayments(); // Go to fees menu.
                break;
            case 3:
                manageGrades(); // Go to grades menu.
                break;
            case 4:
                manageScheduleAndTimetable(); // Go to schedule/timetable menu.
                break;
            case 0:
                cout << "Exiting system...\n"; // Exit the program.
                break;
            default:
                cout << "Invalid choice!\n"; // Wrong choice, show error.
        }
    } while (choice != 0); // Keep going until user chooses 0.
}

// This function handles scheduling and timetable options.
void manageScheduleAndTimetable() {
    int choice; // Variable for the user’s choice.
    cout << "\n-- Manage Schedule and Timetable --\n";
    cout << "1. Generate and Display Class Schedule\n"; // Auto-create a schedule.
    cout << "2. Add Class to Timetable\n"; // Manually add a class.
    cout << "3. Display Timetable for a Day\n"; // Show one day’s timetable.
    cout << "4. Display Full Timetable\n"; // Show the whole week’s timetable.
    cout << "5. Save Timetable to File\n"; // Save timetable to a file.
    cout << "6. Return to main menu\n";
    cout << "Choice: ";
    if (!(cin >> choice)) { // Check if the input is a number.
        cout << "Invalid input. Please enter a number.\n";
        cin.clear(); // Clear error flags.
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer.
        return;
    }

    // Do different things based on the choice.
    switch (choice) {
        case 1:
            // Create subjects, generate schedule, show it, and save to file.
            scheduler.generateSubjectsAutomatically();
            scheduler.generateSchedule();
            scheduler.displaySchedule();
            scheduler.saveToFile("schedule.txt");
            break;
        case 2: {
            // Add a class to the timetable manually.
            string day, className, teacher, timeSlot, room;
            cout << "Enter day (e.g., Monday): ";
            cin >> day; // Get the day.
            cout << "Enter class name (e.g., Mathematics): ";
            cin.ignore(); // Clear newline from previous input.
            getline(cin, className); // Get class name (supports spaces).
            cout << "Enter teacher (e.g., Teacher 1): ";
            getline(cin, teacher); // Get teacher name.
            cout << "Enter time slot (e.g., 08:00-09:00): ";
            getline(cin, timeSlot); // Get time slot.
            cout << "Enter room (e.g., Room A): ";
            getline(cin, room); // Get room.
            Class c = {className, teacher, timeSlot, room}; // Create a class.
            timetable.addClass(day, c); // Add it to the timetable.
            break;
        }
        case 3: {
            // Show the timetable for one day.
            string day;
            cout << "Enter day (e.g., Monday): ";
            cin >> day;
            timetable.displayDaySchedule(day);
            break;
        }
        case 4:
            // Show the full timetable.
            timetable.displayFullSchedule();
            break;
        case 5:
            // Save the timetable to a file.
            timetable.saveToFile("timetable.txt");
            break;
        case 6:
            break; // Go back to main menu.
        default:
            cout << "Invalid option.\n";
    }
}

// This function handles student management options.
void ManageStudent() {
    int choice; // Variable for the user’s choice.
    cout << "\n-- Manage Students --\n";
    cout << "1. Add student/s\n";
    cout << "2. Remove student\n";
    cout << "3. View students\n";
    cout << "4. Search students\n";
    cout << "5. Return to main menu\n";
    if (!(cin >> choice)) { // Check if input is a number.
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    // Do different things based on the choice.
    switch (choice) {
        case 1:
            addStudent(); // Add students.
            break;
        case 2:
            removeStudent(); // Remove students.
            break;
        case 3:
            viewStudents(); // View students.
            break;
        case 4:
            searchStudent(); // Search for a student.
            break;
        case 5:
            break; // Go back to main menu.
        default:
            cout << "Invalid option.\n";
    }
}

// This function lets the user choose how to add students.
void addStudent() {
    char choiceForAdd; // Variable for the user’s choice.
    cout << "Choose adding method:\n";
    cout << "A. Add from console input\n"; // Type student info manually.
    cout << "B. Add from text file\n"; // Read students from a file.
    cin >> choiceForAdd;
    choiceForAdd = toupper(choiceForAdd); // Convert to uppercase (e.g., ‘a’ becomes ‘A’).
    if (choiceForAdd == 'A') {
        addStudentFromConsole(); // Add manually.
    } else if (choiceForAdd == 'B') {
        addStudentFromFile(); // Add from file.
    } else {
        cout << "Invalid choice!\n"; // Wrong choice, show error.
    }
}

// This function adds students by asking the user to type their info.
void addStudentFromConsole() {
    int gradeToAdd; // Variable for the grade.
    char sectionToAdd; // Variable for the section.

    cout << "Enter grade and section (e.g., 9 A): ";
    if (!(cin >> gradeToAdd >> sectionToAdd)) { // Get grade and section.
        cout << "Invalid input. Please enter a number for grade and a letter for section.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    sectionToAdd = toupper(sectionToAdd); // Convert section to uppercase.

    // Check if the grade (9-12) and section (A or B) are valid.
    if (!validateGradeAndSection(gradeToAdd, sectionToAdd)) {
        cout << "Invalid grade (9-12) or section (A or B).\n";
        return;
    }

    // Check if the class is full (max 50 students per section).
    if (isClassFull(gradeToAdd, sectionToAdd)) {
        cout << "This class section is already full.\n";
        return;
    }

    // Calculate how many spots are available in this section.
    int sectionCount = getSectionCount(gradeToAdd, sectionToAdd);
    int availableSpots = 50 - sectionCount;

    int numberToAdd; // How many students to add.
    cout << "How many students do you want to add in this section? ";
    if (!(cin >> numberToAdd) || numberToAdd <= 0) { // Get number.
        cout << "Invalid number of students.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Check if there’s enough space for the new students.
    if (numberToAdd > availableSpots) {
        cout << "Only " << availableSpots << " spot(s) available in this class.\n";
        return;
    }

    // Find where to store the students in the CurrStudents array.
    int startIdx = getStartIndex(gradeToAdd, sectionToAdd);
    int endIdx = startIdx + 50;

    // Add each student one by one.
    for (int i = startIdx; i < endIdx && numberToAdd > 0; i++) {
        if (!CurrStudents[i].isActive) { // If this spot is free.
            CurrStudents[i] = askStudentInfo(gradeToAdd, sectionToAdd, i); // Get student info.
            CurrStudents[i].totalFees = getGradeFee(gradeToAdd); // Set fees.
            updateSectionCount(gradeToAdd, sectionToAdd, true); // Update student count.
            currStudentCount++; // Increase total student count.
            numberToAdd--; // One less student to add.
        }
    }

    cout << "Students added successfully.\n";
}

// This checks if the grade (9-12) and section (A or B) are valid.
bool validateGradeAndSection(int grade, char section) {
    bool isGradeValid = true;
    // Check if grade is too low or too high.
    if (grade < 9) {
        isGradeValid = false;
        cout << "Validation error: Grade " << grade << " is too low. Must be between 9 and 12.\n";
    } else if (grade > 12) {
        isGradeValid = false;
        cout << "Validation error: Grade " << grade << " is too high. Must be between 9 and 12.\n";
    }

    char Section = toupper(section); // Convert section to uppercase.
    bool isSectionValid = true;
    // Check if section is A or B.
    if (Section != 'A' && Section != 'B') {
        isSectionValid = false;
        cout << "Validation error: Section '" << section << "' is invalid. Must be 'A' or 'B'.\n";
    }

    return isGradeValid && isSectionValid; // Return true only if both are valid.
}

// This checks if a grade and section has reached its limit (50 students).
bool isClassFull(int grade, char section) {
    int studentCount = getSectionCount(grade, section); // Get current student count.
    return studentCount >= 50; // True if full.
}

// This gets the number of students in a specific grade and section.
int getSectionCount(int grade, char section) {
    if (!validateGradeAndSection(grade, section)) { // Check if inputs are valid.
        return 0;
    }

    int gradeIndex = grade - 9; // Grade 9 = index 0, grade 10 = index 1, etc.
    int sectionIndex = toupper(section) == 'A' ? 0 : 1; // A = 0, B = 1.
    return sectionCounts[gradeIndex][sectionIndex]; // Return student count.
}

// This finds where in the CurrStudents array to store students for a grade and section.
int getStartIndex(int grade, char section) {
    if (!validateGradeAndSection(grade, section)) { // Check if inputs are valid.
        cout << "Invalid grade or section in getStartIndex. Returning 0.\n";
        return 0;
    }

    int gradeIndex = grade - 9; // Grade 9 = index 0, etc.
    int baseIndex = gradeIndex * 100; // Each grade gets 100 slots (50 for A, 50 for B).
    int startIndex = baseIndex;
    if (toupper(section) == 'B') { // Section B starts 50 slots later.
        startIndex += 50;
    }
    return startIndex;
}

// This asks the user for a student’s info, like name and age.
Student askStudentInfo(int grade, char section, int index) {
    Student s; // Create a new student.
    cout << "Enter student's First Name: ";
    cin >> s.Fname; // Get first name.
    cout << "Enter student's Last Name: ";
    cin >> s.Lname; // Get last name.
    cout << "Enter student's age: ";
    cin >> s.age; // Get age.
    s.grade = grade; // Set grade.
    s.section = toupper(section); // Set section.
    s.id = generateStudentID(grade, s.section, index); // Create a unique ID.
    s.isActive = true; // Mark student as active.
    s.totalFees = getGradeFee(grade); // Set fees based on grade.
    return s; // Return the student.
}

// This creates a unique ID for a student, like "FR-A001".
string generateStudentID(int grade, char section, int index) {
    string gradeLabel = getGradeLabel(grade); // Get label like "FR" for grade 9.
    char Section = toupper(section); // Convert section to uppercase.
    int serialNumber = (index % 50) + 1; // Serial number from 1 to 50.
    string serial = (serialNumber < 10 ? "00" : serialNumber < 100 ? "0" : "") + to_string(serialNumber); // Pad with zeros.
    string studentID = gradeLabel + "-" + Section + serial; // Combine parts, e.g., "FR-A001".
    return studentID;
}

// This gets the label for a grade, like "FR" for Freshman (grade 9).
string getGradeLabel(int grade) {
    switch (grade) {
        case 9: return "FR"; // Freshman.
        case 10: return "SO"; // Sophomore.
        case 11: return "JR"; // Junior.
        case 12: return "SR"; // Senior.
        default: return "XX"; // Invalid grade.
    }
}

// This gets the fee amount for a grade.
double getGradeFee(int grade) {
    switch (grade) {
        case 9: return FEE_GRADE_9; // $5000 for grade 9.
        case 10: return FEE_GRADE_10; // $5500 for grade 10.
        case 11: return FEE_GRADE_11; // $6000 for grade 11.
        case 12: return FEE_GRADE_12; // $6500 for grade 12.
        default: return 0.0; // Invalid grade.
    }
}

// This function adds students from a text file.
void addStudentFromFile() {
    string filename; // Variable for the filename.
    cout << "Enter filename: ";
    cin >> filename; // Get filename from user.

    ifstream infile(filename); // Open the file for reading.
    if (!infile.is_open()) { // Check if it opened.
        cout << "Failed to open file.\n";
        return;
    }

    // Create files to log which students were added or failed.
    ofstream addedFile("added_students.txt");
    ofstream failedFile("failed_students.txt");
    if (!addedFile.is_open() || !failedFile.is_open()) {
        cout << "Failed to open output files.\n";
        infile.close();
        return;
    }

    string line; // Variable to store each line from the file.
    int successCount = 0, failedCount = 0; // Counters for successes and failures.
    while (getline(infile, line)) { // Read each line.
        tryAddStudentFromLine(line, addedFile, failedFile, successCount, failedCount); // Try to add the student.
    }

    infile.close(); // Close input file.
    addedFile.close(); // Close success file.
    failedFile.close(); // Close failure file.

    // Show how many students were added or failed.
    cout << successCount << " students added successfully.\n";
    cout << failedCount << " students failed to add due to full class or invalid data.\n";
    displayFileContent("added_students.txt", "Successfully Added Students");
    displayFileContent("failed_students.txt", "Failed to Add Students");
}

// This tries to add one student from a line in the file.
void tryAddStudentFromLine(string line, ofstream& addedFile, ofstream& failedFile, int& successCount, int& failedCount) {
    string fname, lname; // First and last name.
    int age, grade; // Age and grade.
    char section; // Section.
    stringstream ss(line); // Convert line to a stream for reading.
    if (!(ss >> fname >> lname >> age >> grade >> section)) { // Try to read data.
        failedFile << line << "\n"; // If reading fails, log the line.
        failedCount++;
        return;
    }

    // Check if grade and section are valid or if the class is full.
    if (!validateGradeAndSection(grade, section) || isClassFull(grade, section)) {
        failedFile << fname << " " << lname << "\n"; // Log failure.
        failedCount++;
        return;
    }

    // Find where to store the student in CurrStudents.
    int startIdx = getStartIndex(grade, section);
    int endIdx = startIdx + 50;

    // Look for an empty spot to add the student.
    for (int i = startIdx; i < endIdx; i++) {
        if (!CurrStudents[i].isActive) { // If spot is free.
            CurrStudents[i].Fname = fname; // Set first name.
            CurrStudents[i].Lname = lname; // Set last name.
            CurrStudents[i].age = age; // Set age.
            CurrStudents[i].grade = grade; // Set grade.
            CurrStudents[i].section = toupper(section); // Set section.
            CurrStudents[i].id = generateStudentID(grade, section, i); // Set ID.
            CurrStudents[i].isActive = true; // Mark as active.
            CurrStudents[i].totalFees = getGradeFee(grade); // Set fees.
            // Log the student’s details to the success file.
            addedFile << CurrStudents[i].id << " " << fname << " " << lname << " " << age << " " << grade << " " << section
                      << " | Fees: $" << CurrStudents[i].totalFees << "\n";
            currStudentCount++; // Increase total student count.
            successCount++; // Increase success count.
            updateSectionCount(grade, section, true); // Update section count.
            return;
        }
    }

    // If no spot was found, log failure.
    failedFile << fname << " " << lname << " " << age << " " << grade << " " << section << "\n";
    failedCount++;
}

// This updates the count of students in a grade and section.
void updateSectionCount(int grade, char section, bool increment) {
    if (!validateGradeAndSection(grade, section)) { // Check if inputs are valid.
        cout << "Invalid grade or section in updateSectionCount. No update performed.\n";
        return;
    }

    int gradeIndex = grade - 9; // Grade 9 = index 0, etc.
    int sectionIndex = toupper(section) == 'A' ? 0 : 1; // A = 0, B = 1.
    if (increment) {
        sectionCounts[gradeIndex][sectionIndex] += 1; // Add 1 student.
    } else {
        sectionCounts[gradeIndex][sectionIndex] -= 1; // Remove 1 student.
    }
}

// This shows the contents of a file on the screen.
void displayFileContent(string filename, string title) {
    cout << "\n-- " << title << " --\n";
    ifstream file(filename); // Open the file.
    if (!file.is_open()) { // Check if it opened.
        cout << "No data available.\n";
        return;
    }
    string line; // Variable for each line.
    while (getline(file, line)) { // Read and print each line.
        cout << line << "\n";
    }
    file.close(); // Close the file.
}

// This lets the user choose how to remove students.
void removeStudent() {
    char choiceForRemove; // Variable for the user’s choice.
    cout << "Choose removing method:\n";
    cout << "A. Remove from console input\n"; // Type student IDs manually.
    cout << "B. Remove from text file\n"; // Read IDs from a file.
    cin >> choiceForRemove;
    choiceForRemove = toupper(choiceForRemove); // Convert to uppercase.

    if (choiceForRemove == 'A') {
        removeStudentFromConsole(); // Remove manually.
    } else if (choiceForRemove == 'B') {
        removeStudentFromFile(); // Remove from file.
    } else {
        cout << "Invalid choice!\n";
    }
}

// This removes students by asking the user to type their IDs.
void removeStudentFromConsole() {
    int numberToRemove; // How many students to remove.
    cout << "How many students do you want to remove? ";
    if (!(cin >> numberToRemove) || numberToRemove <= 0) { // Get number.
        cout << "Invalid number of students.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Loop for each student to remove.
    for (int i = 0; i < numberToRemove; ++i) {
        string id; // Variable for the student’s ID.
        cout << "Enter student ID to remove (e.g., FR-A001): ";
        cin >> id; // Get ID.

        bool found = false; // Flag to track if student is found.
        for (int j = 0; j < MAX_STUDENTS; ++j) { // Search all students.
            if (CurrStudents[j].isActive && CurrStudents[j].id == id) { // If found.
                // Show student details.
                cout << "Student Found:\n";
                cout << "ID: " << CurrStudents[j].id << "\n";
                cout << "Name: " << CurrStudents[j].Fname << " " << CurrStudents[j].Lname << "\n";
                cout << "Age: " << CurrStudents[j].age << ", Grade: " << CurrStudents[j].grade
                     << ", Section: " << CurrStudents[j].section << "\n";
                cout << "Total Fees: $" << CurrStudents[j].totalFees
                     << ", Paid: $" << CurrStudents[j].amountPaid
                     << ", Balance: $" << CurrStudents[j].getBalance()
                     << ", Payment Method: " << CurrStudents[j].paymentMethod << "\n";

                char confirm; // Variable for confirmation.
                cout << "Are you sure you want to remove this student? (Y/N): ";
                cin >> confirm;
                if (toupper(confirm) == 'Y') { // If user confirms.
                    recentlyLeftStudents.push_back(CurrStudents[j]); // Save to recently left list.
                    recentlyLeftStudents.back().isActive = false; // Mark as inactive.
                    CurrStudents[j].isActive = false; // Mark as inactive in main list.
                    updateSectionCount(CurrStudents[j].grade, CurrStudents[j].section, false); // Decrease count.
                    currStudentCount--; // Decrease total count.
                    cout << "Student removed successfully.\n";
                } else {
                    cout << "Removal cancelled.\n";
                }
                found = true;
                break;
            }
        }
        if (!found) { // If student wasn’t found.
            cout << "Student with ID " << id << " not found.\n";
        }
    }
}

// This removes students by reading their IDs from a file.
void removeStudentFromFile() {
    string filename; // Variable for the filename.
    cout << "Enter filename containing IDs of students to remove: ";
    cin >> filename; // Get filename.

    ifstream infile(filename); // Open the file.
    if (!infile.is_open()) { // Check if it opened.
        cout << "Failed to open file.\n";
        return;
    }

    string id; // Variable for each ID.
    int removedCount = 0; // Counter for removed students.
    while (infile >> id) { // Read each ID.
        bool found = false; // Flag to track if student is found.
        for (int i = 0; i < MAX_STUDENTS; i++) { // Search all students.
            if (CurrStudents[i].isActive && CurrStudents[i].id == id) { // If found.
                // Show student details.
                cout << "Removing student: " << CurrStudents[i].Fname << " "
                     << CurrStudents[i].Lname << " (ID: " << id << ")\n";
                cout << "Total Fees: $" << CurrStudents[i].totalFees
                     << ", Paid: $" << CurrStudents[i].amountPaid
                     << ", Balance: $" << CurrStudents[i].getBalance()
                     << ", Payment Method: " << CurrStudents[i].paymentMethod << "\n";
                recentlyLeftStudents.push_back(CurrStudents[i]); // Save to recently left list.
                recentlyLeftStudents.back().isActive = false; // Mark as inactive.
                CurrStudents[i].isActive = false; // Mark as inactive.
                currStudentCount--; // Decrease total count.
                updateSectionCount(CurrStudents[i].grade, CurrStudents[i].section, false); // Decrease section count.
                removedCount++; // Increase removed count.
                found = true;
                break;
            }
        }
        if (!found) { // If student wasn’t found.
            cout << "Student with ID " << id << " not found or already removed.\n";
        }
    }
    infile.close(); // Close the file.
    cout << removedCount << " student(s) removed from the system.\n";
}

// This lets the user choose to view current or recently left students.
void viewStudents() {
    char viewChoice; // Variable for the user’s choice.
    cout << "Choose an option:\n";
    cout << "A. Current students\n";
    cout << "B. Recently left students\n";
    cout << "Choice: ";
    cin >> viewChoice;
    viewChoice = toupper(viewChoice); // Convert to uppercase.

    if (viewChoice != 'A' && viewChoice != 'B') { // Check if choice is valid.
        cout << "Invalid choice.\n";
        return;
    }

    if (viewChoice == 'A') {
        viewCurrentStudents(); // Show current students.
    } else {
        viewRecentlyLeftStudents(); // Show recently left students.
    }
}

// This shows all students in a specific grade and section.
void viewCurrentStudents() {
    int grade; // Variable for grade.
    char section; // Variable for section.
    cout << "Enter grade and section to view (e.g., 9 A): ";
    if (!(cin >> grade >> section)) { // Get inputs.
        cout << "Invalid input. Please enter a number for grade and a letter for section.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    section = toupper(section); // Convert section to uppercase.

    // Check if inputs are valid.
    if (!validateGradeAndSection(grade, section)) {
        cout << "Invalid grade (9-12) or section (A or B).\n";
        return;
    }

    // Find the range of students for this grade and section.
    int startIdx = getStartIndex(grade, section);
    int endIdx = startIdx + 50;

    bool found = false; // Flag to track if any students are found.
    cout << "\n--- Students in Grade " << grade << " Section " << section << " ---\n";
    for (int i = startIdx; i < endIdx; i++) { // Loop through students.
        if (CurrStudents[i].isActive) { // If student is active.
            found = true;
            // Show student details.
            cout << "ID: " << CurrStudents[i].id
                 << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                 << " | Age: " << CurrStudents[i].age
                 << " | Fees: $" << CurrStudents[i].totalFees
                 << " | Paid: $" << CurrStudents[i].amountPaid
                 << " | Balance: $" << CurrStudents[i].getBalance()
                 << " | Payment Method: " << CurrStudents[i].paymentMethod << "\n";
        }
    }

    if (!found) { // If no students were found.
        cout << "No students found in this section.\n";
        return;
    }

    // Ask if the user wants to save the list to a file.
    char saveToFile;
    cout << "\nWould you like to save this list to a file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y') {
        string filename = "view_" + to_string(grade) + "_" + section + ".txt"; // Create filename.
        ofstream outFile(filename); // Open file for writing.
        if (!outFile.is_open()) { // Check if it opened.
            cout << "Failed to create output file.\n";
            return;
        }

        // Write each student’s details to the file.
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
        outFile.close(); // Close the file.
        cout << "Student list saved to file: " << filename << "\n";
    }
}

// This shows all students who recently left the school.
void viewRecentlyLeftStudents() {
    if (recentlyLeftStudents.empty()) { // Check if the list is empty.
        cout << "\nNo recently left students found.\n";
        return;
    }

    cout << "\n--- Recently Left Students ---\n";
    // Loop through each recently left student.
    for (const auto& student : recentlyLeftStudents) {
        // Show their details.
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

    // Ask if the user wants to save the list to a file.
    char saveToFile;
    cout << "\nWould you like to save this list to a file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y') {
        string filename = "recently_left_students.txt"; // Create filename.
        ofstream outFile(filename); // Open file.
        if (!outFile.is_open()) { // Check if it opened.
            cout << "Failed to create output file.\n";
            return;
        }

        // Write each student’s details to the file.
        for (const auto& student : recentlyLeftStudents) {
            outFile << "ID: " << student.id
                    << " | Name: " << student.Fname << " " << student.Lname
                    << " | Age: " << student.age
                    << " | Grade: " << student.grade
                    << " | Section: " << student.section
                    << " | Fees: $" << student.totalFees
                    << " | Paid: " << student.amountPaid
                    << " | Balance: " << student.getBalance()
                    << " | Payment Method: " << student.paymentMethod << "\n";
        }
        outFile.close(); // Close the file.
        cout << "Recently left students list saved to file: " << filename << "\n";
    }
}

// This lets the user search for a student by ID.
void searchStudent() {
    char searchChoice; // Variable for the user’s choice.
    cout << "Choose an option:\n";
    cout << "A. Current students\n";
    cout << "B. Recently left students\n";
    cout << "Choice: ";
    cin >> searchChoice;
    searchChoice = toupper(searchChoice); // Convert to uppercase.

    if (searchChoice != 'A' && searchChoice != 'B') { // Check if choice is valid.
        cout << "Invalid choice. Please enter 'A' or 'B'.\n";
        return;
    }

    string id; // Variable for the student’s ID.
    cout << "Enter student ID (e.g., FR-A001): ";
    cin >> id; // Get ID.

    if (searchChoice == 'A') {
        searchCurrentStudents(id); // Search current students.
    } else {
        searchRecentlyLeftStudents(id); // Search recently left students.
    }
}

// This searches for a student among current students.
void searchCurrentStudents(string id) {
    bool found = false; // Flag to track if student is found.
    for (int i = 0; i < MAX_STUDENTS; i++) { // Loop through all students.
        if (CurrStudents[i].isActive && CurrStudents[i].id == id) { // If found.
            found = true;
            // Show student details.
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

    if (!found) { // If not found.
        cout << "Student with ID " << id << " not found among current students.\n";
    }
}

// This searches for a student among recently left students.
void searchRecentlyLeftStudents(string id) {
    bool found = false; // Flag to track if student is found.
    for (const auto& student : recentlyLeftStudents) { // Loop through list.
        if (student.id == id) { // If found.
            found = true;
            // Show student details.
            cout << "\nStudent Found (Recently Left):\n";
            cout << "ID: " << student.id << "\n";
            cout << "Name: " << student.Fname << " " << student.Lname << "\n";
            cout << "Age: " << student.age << "\n";
            cout << "Grade: " << student.grade << "\n";
            cout << "Section: " << student.section << "\n";
            cout << "Total Fees: $" << student.totalFees << "\n";
            cout << "Amount Paid: " << student.amountPaid << "\n";
            cout << "Balance: $" << student.getBalance() << "\n";
            cout << "Payment Method: " << student.paymentMethod << "\n";
            break;
        }
    }

    if (!found) { // If not found.
        cout << "Student with ID " << id << " not found among recently left students.\n";
    }
}

// This function handles fee and payment options.
void ManageFeesAndPayments() {
    int choice; // Variable for the user’s choice.
    cout << "\n-- Manage Fees and Payments --\n";
    cout << "1. Pay fees\n";
    cout << "2. Generate fee report\n";
    cout << "3. View overdue payments\n";
    cout << "4. Generate fee summary\n";
    cout << "5. Return to main menu\n";

    if (!(cin >> choice)) { // Check if input is a number.
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    // Do different things based on the choice.
    switch (choice) {
        case 1:
            payFees(); // Record a payment.
            break;
        case 2:
            generateFeeReport(); // Show fee details for all students.
            break;
        case 3:
            viewOverduePayments(); // Show students who owe money.
            break;
        case 4:
            generateFeeSummary(); // Show total fees and payments.
            break;
        case 5:
            break; // Go back to main menu.
        default:
            cout << "Invalid option.\n";
    }
}

// This function records a fee payment for a student.
void payFees() {
    string id; // Variable for the student’s ID.
    cout << "Enter Student ID (e.g., FR-A001): ";
    cin >> id; // Get ID.

    for (int i = 0; i < MAX_STUDENTS; i++) { // Search for the student.
        if (CurrStudents[i].isActive && CurrStudents[i].id == id) { // If found.
            double amount; // Variable for payment amount.
            string method; // Variable for payment method.
            // Show student’s fee details.
            cout << "Student: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname << "\n";
            cout << "Total Fees: $" << CurrStudents[i].totalFees
                 << ", Paid: $" << CurrStudents[i].amountPaid
                 << ", Balance: $" << CurrStudents[i].getBalance() << "\n";
            cout << "Enter amount to pay: $";
            if (!(cin >> amount) || amount <= 0 || CurrStudents[i].amountPaid + amount > CurrStudents[i].totalFees) { // Check payment.
                cout << "Invalid payment amount.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return;
            }
            cout << "Enter payment method (Cash/Check/Online): ";
            cin >> method; // Get payment method.
            // Check if method is valid.
            if (method != "Cash" && method != "Check" && method != "Online") {
                cout << "Invalid payment method. Must be Cash, Check, or Online.\n";
                return;
            }

            CurrStudents[i].amountPaid += amount; // Add payment.
            CurrStudents[i].paymentMethod = method; // Set payment method.
            // Show updated balance.
            cout << "Payment successful. Remaining balance: $" << CurrStudents[i].getBalance()
                 << ", Paid via: " << CurrStudents[i].paymentMethod << "\n";
            return;
        }
    }
    cout << "Student ID not found among current students.\n"; // If not found.
}

// This shows a report of fees for all students.
void generateFeeReport() {
    cout << "\n--- Fee Report for Current Students ---\n";
    bool found = false; // Flag to track if any students are found.
    for (int i = 0; i < MAX_STUDENTS; i++) { // Loop through all students.
        if (CurrStudents[i].isActive) { // If student is active.
            found = true;
            // Show their fee details.
            cout << "ID: " << CurrStudents[i].id
                 << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                 << " | Grade " << CurrStudents[i].grade << CurrStudents[i].section
                 << " | Paid: $" << CurrStudents[i].amountPaid
                 << " | Balance: $" << CurrStudents[i].getBalance()
                 << " | Payment Method: " << CurrStudents[i].paymentMethod << "\n";
        }
    }
    if (!found) { // If no students were found.
        cout << "No active students found.\n";
    }

    // Ask if the user wants to save the report to a file.
    char saveToFile;
    cout << "\nWould you like to save this report to a file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y') {
        string filename = "fee_report.txt"; // Create filename.
        ofstream outFile(filename); // Open file.
        if (!outFile.is_open()) { // Check if it opened.
            cout << "Failed to create output file.\n";
            return;
        }

        // Write each student’s fee details to the file.
        for (int i = 0; i < MAX_STUDENTS; i++) {
            if (CurrStudents[i].isActive) {
                outFile << "ID: " << CurrStudents[i].id
                        << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                        << " | Grade " << CurrStudents[i].grade << CurrStudents[i].section
                        << " | Paid: $" << CurrStudents[i].amountPaid
                        << " | Balance: $" << CurrStudents[i].getBalance()
                        << " | Payment Method: " << CurrStudents[i].paymentMethod << "\n";
            }
        }
        outFile.close(); // Close the file.
        cout << "Fee report saved to file: " << filename << "\n";
    }
}

// This shows students who owe money (balance > 0).
void viewOverduePayments() {
    cout << "\n--- Overdue Payments (Current Students with Balance > $0) ---\n";
    bool found = false; // Flag to track if any students are found.
    for (int i = 0; i < MAX_STUDENTS; i++) { // Loop through all students.
        if (CurrStudents[i].isActive && CurrStudents[i].getBalance() > 0) { // If they owe money.
            found = true;
            // Show their details.
            cout << "ID: " << CurrStudents[i].id
                 << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                 << " | Grade " << CurrStudents[i].grade << CurrStudents[i].section
                 << " | Balance: $" << CurrStudents[i].getBalance()
                 << " | Payment Method: " << CurrStudents[i].paymentMethod << "\n";
        }
    }
    if (!found) { // If no one owes money.
        cout << "No students with overdue payments found.\n";
    }

    // Ask if the user wants to save the report to a file.
    char saveToFile;
    cout << "\nWould you like to save this report to a file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y') {
        string filename = "overdue_payments.txt"; // Create filename.
        ofstream outFile(filename); // Open file.
        if (!outFile.is_open()) { // Check if it opened.
            cout << "Failed to create output file.\n";
            return;
        }

        // Write each student’s details to the file.
        for (int i = 0; i < MAX_STUDENTS; i++) {
            if (CurrStudents[i].isActive && CurrStudents[i].getBalance() > 0) {
                outFile << "ID: " << CurrStudents[i].id
                        << " | Name: " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname
                        << " | Grade " << CurrStudents[i].grade << CurrStudents[i].section
                        << " | Balance: $" << CurrStudents[i].getBalance()
                        << " | Payment Method: " << CurrStudents[i].paymentMethod << "\n";
            }
        }
        outFile.close(); // Close the file.
        cout << "Overdue payments report saved to file: " << filename << "\n";
    }
}

// This shows a summary of all fees and payments.
void generateFeeSummary() {
    double totalAssigned = 0.0, totalPaid = 0.0, totalOutstanding = 0.0; // Variables for totals.
    int studentCount = 0; // Count of active students.

    // Loop through all students to calculate totals.
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (CurrStudents[i].isActive) {
            totalAssigned += CurrStudents[i].totalFees; // Add their fees.
            totalPaid += CurrStudents[i].amountPaid; // Add their payments.
            totalOutstanding += CurrStudents[i].getBalance(); // Add their balance.
            studentCount++; // Count the student.
        }
    }

    // Show the summary.
    cout << "\n--- Fee Summary for Current Students ---\n";
    cout << "Total Students: " << studentCount << "\n";
    cout << "Total Fees Assigned: $" << totalAssigned << "\n";
    cout << "Total Fees Paid: $" << totalPaid << "\n";
    cout << "Total Outstanding Balance: $" << totalOutstanding << "\n";

    // Ask if the user wants to save the summary to a file.
    char saveToFile;
    cout << "\nWould you like to save this summary to a file? (Y/N): ";
    cin >> saveToFile;
    if (toupper(saveToFile) == 'Y') {
        string filename = "fee_summary.txt"; // Create filename.
        ofstream outFile(filename); // Open file.
        if (!outFile.is_open()) { // Check if it opened.
            cout << "Failed to create output file.\n";
            return;
        }

        // Write summary to the file.
        outFile << "Fee Summary for Current Students\n";
        outFile << "Total Students: " << studentCount << "\n";
        outFile << "Total Fees Assigned: $" << totalAssigned << "\n";
        outFile << "Total Fees Paid: $" << totalPaid << "\n";
        outFile << "Total Outstanding Balance: $" << totalOutstanding << "\n";
        outFile.close(); // Close the file.
        cout << "Fee summary saved to file: " << filename << "\n";
    }
}

// This function handles grade and report card options.
void manageGrades() {
    int choice; // Variable for the user’s choice.
    cout << "\n-- Grade Management --\n";
    cout << "1. Enter student marks\n";
    cout << "2. Generate report card\n";
    cout << "3. Return to main menu\n";
    cout << "Choice: ";
    cin >> choice; // Get choice.

    // Do different things based on the choice.
    switch (choice) {
        case 1:
            enterMarks(); // Enter marks for a student.
            break;
        case 2:
            generateReportCard(); // Create a report card.
            break;
        case 3:
            return; // Go back to main menu.
        default:
            cout << "Invalid choice!\n";
    }
}

// This function lets the user enter marks for a student.
void enterMarks() {
    string id; // Variable for the student’s ID.
    cout << "Enter Student ID (e.g., FR-A001): ";
    cin >> id; // Get ID.

    for (int i = 0; i < MAX_STUDENTS; i++) { // Search for the student.
        if (CurrStudents[i].isActive && CurrStudents[i].id == id) { // If found.
            cout << "Entering marks for " << CurrStudents[i].Fname << " " << CurrStudents[i].Lname << ":\n";
            
            // Loop through each of the 8 subjects.
            for (int j = 0; j < NUM_SUBJECTS; j++) {
                do { // Keep asking until valid marks are entered.
                    cout << SUBJECT_NAMES[j] << " marks (0-100): ";
                    cin >> CurrStudents[i].marks[j]; // Get marks.
                    if (CurrStudents[i].marks[j] < 0 || CurrStudents[i].marks[j] > 100) { // Check if valid.
                        cout << "Invalid marks! Please enter between 0-100.\n";
                    }
                } while (CurrStudents[i].marks[j] < 0 || CurrStudents[i].marks[j] > 100); // Repeat if invalid.
            }
            
            cout << "Marks entered successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n"; // If not found.
}

// This function creates a report card for a student.
void generateReportCard() {
    string id; // Variable for the student’s ID.
    cout << "Enter Student ID (e.g., FR-A001): ";
    cin >> id; // Get ID.

    for (int i = 0; i < MAX_STUDENTS; i++) { // Search for the student.
        if (CurrStudents[i].isActive && CurrStudents[i].id == id) { // If found.
            displayReportCard(CurrStudents[i]); // Show the report card.
            
            char choice; // Variable for save choice.
            cout << "\nSave to file? (Y/N): ";
            cin >> choice;
            if (toupper(choice) == 'Y') { // If user wants to save.
                saveReportCardToFile(CurrStudents[i]); // Save to file.
            }
            return;
        }
    }
    cout << "Student not found!\n"; // If not found.
}

// This converts a mark (0-100) to a letter grade (A, B, C, D, F).
char calculateLetterGrade(double marks) {
    if (marks >= 90) return 'A'; // 90+ = A.
    if (marks >= 80) return 'B'; // 80-89 = B.
    if (marks >= 70) return 'C'; // 70-79 = C.
    if (marks >= 60) return 'D'; // 60-69 = D.
    return 'F'; // Below 60 = F.
}

// This calculates a student’s GPA based on their marks.
double calculateGPA(const Student& student) {
    double totalPoints = 0.0; // Sum of GPA points.
    int validSubjects = 0; // Count of subjects with valid marks.
    
    // Loop through each subject’s marks.
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        if (student.marks[i] >= 0) { // If marks are valid.
            // Check which grade the marks fall into.
            for (int j = 0; j < 5; j++) {
                if (student.marks[i] >= GRADE_SCALE[j][0]) {
                    totalPoints += GRADE_SCALE[j][1]; // Add GPA points (e.g., 4.0 for A).
                    validSubjects++; // Count the subject.
                    break;
                }
            }
        }
    }
    
    // Calculate average GPA, or return 0 if no valid subjects.
    return (validSubjects > 0) ? (totalPoints / validSubjects) : 0.0;
}

// This shows a student’s report card on the screen.
void displayReportCard(const Student& student) {
    cout << "\n\n=== REPORT CARD ===\n";
    cout << "Name: " << student.Fname << " " << student.Lname << "\n"; // Show name.
    cout << "ID: " << student.id << "\n"; // Show ID.
    cout << "Grade: " << student.grade << student.section << "\n"; // Show grade and section.
    cout << "----------------------------------------\n";
    cout << "SUBJECT\t\tMARKS\tGRADE\n"; // Header for table.
    cout << "----------------------------------------\n";
    
    // Loop through each subject.
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        // Show subject name, marks, and letter grade.
        cout << left << setw(16) << SUBJECT_NAMES[i] 
             << right << setw(4) << student.marks[i] << "\t"
             << calculateLetterGrade(student.marks[i]) << "\n";
    }
    
    cout << "----------------------------------------\n";
    cout << fixed << setprecision(2); // Show GPA with 2 decimal places.
    cout << "GPA: " << calculateGPA(student) << "\n";
    cout << "========================================\n";
}

// This saves a student’s report card to a file.
void saveReportCardToFile(const Student& student) {
    string filename = "report_card_" + student.id + ".txt"; // Create filename, e.g., "report_card_FR-A001.txt".
    ofstream outFile(filename); // Open file.
    
    if (!outFile.is_open()) { // Check if it opened.
        cout << "Error creating report card file!\n";
        return;
    }
    
    // Write report card to the file.
    outFile << "=== REPORT CARD ===\n";
    outFile << "Name: " << student.Fname << " " << student.Lname << "\n";
    outFile << "ID: " << student.id << "\n";
    outFile << "Grade: " << student.grade << student.section << "\n";
    outFile << "----------------------------------------\n";
    outFile << "SUBJECT\t\tMARKS\tGRADE\n";
    outFile << "----------------------------------------\n";
    
    // Write each subject’s details.
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        outFile << left << setw(16) << SUBJECT_NAMES[i] 
                << right << setw(4) << student.marks[i] << "\t"
                << calculateLetterGrade(student.marks[i]) << "\n";
    }
    
    outFile << "----------------------------------------\n";
    outFile << fixed << setprecision(2);
    outFile << "GPA: " << calculateGPA(student) << "\n";
    outFile << "========================================\n";
    
    outFile.close(); // Close the file.
    cout << "Report card saved to " << filename << "\n";
}
