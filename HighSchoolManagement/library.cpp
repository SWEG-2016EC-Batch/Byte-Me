#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

struct Student {
    int id;
    string name;
};

vector<Book> books;
vector<Student> students;

bool studentExists(int id) {
    for (auto& s : students)
        if (s.id == id) return true;
    return false;
}

void readBooksFromFile() {
    fstream file("books.txt", ios::in);
    if (!file) return;

    string line;
    while (getline(file, line)) {
        Book b;
        stringstream ss(line);
        ss >> b.id;
        ss.ignore();
        getline(ss, b.title, '|');
        getline(ss, b.author, '|');
        books.push_back(b);
    }
    file.close();
}

void writeBooksToFile() {
    fstream file("books.txt", ios::out | ios::trunc);
    for (auto& b : books) {
        file << b.id << " " << b.title << "|" << b.author << "|\n";
    }
    file.close();
}

void addBook() {
    Book b;
    cout << "Enter Book ID: "; cin >> b.id; cin.ignore();
    cout << "Enter Title: "; getline(cin, b.title);
    cout << "Enter Author: "; getline(cin, b.author);
    books.push_back(b);

    fstream file("books.txt", ios::app);
    file << b.id << " " << b.title << "|" << b.author << "|\n";
    file.close();

    cout << "Book added and saved.\n";
}

void issueBook() {
    int bookId, studentId;
    cout << "Enter Book ID to issue: ";
    cin >> bookId;
    cout << "Enter Student ID: ";
    cin >> studentId;

    if (!studentExists(studentId)) {
        cout << "Student not found.\n";
        return;
    }

    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i].id == bookId) {
            // Remove book after issuing
            books.erase(books.begin() + i);
            writeBooksToFile();

            cout << "Book issued to student ID " << studentId << " and removed from inventory.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void searchBook() {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;
    for (auto& b : books) {
        if (b.id == id) {
            cout << "Found: " << b.title << " by " << b.author << "\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void listBooks() {
    cout << "\n--- Available Books ---\n";
    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }
    for (auto& b : books) {
        cout << "ID: " << b.id << ", Title: " << b.title << ", Author: " << b.author << "\n";
    }
}

int main() {
    // Load students
    fstream studentFile("student.txt", ios::in);
    if (!studentFile) {
        cout << "Failed to open student.txt\n";
        return 1;
    }
    string line;
    while (getline(studentFile, line)) {
        Student s;
        stringstream ss(line);
        ss >> s.id;
        getline(ss, s.name);
        if (!s.name.empty() && s.name[0] == ' ') s.name.erase(0, 1);
        students.push_back(s);
    }
    studentFile.close();
    cout << students.size() << " students loaded.\n";

    // Load books
    readBooksFromFile();

    string userType;
    cout << "Are you a Manager or Student? (M/S): ";
    cin >> userType;

    if (userType == "M" || userType == "m") {
        int choice;
        do {
            cout << "\n--- Manager Menu ---\n";
            cout << "1. Add Book\n2. View Book List\n3. Exit\nChoice: ";
            cin >> choice;
            switch (choice) {
                case 1: addBook(); break;
                case 2: listBooks(); break;
                case 3: cout << "Exiting...\n"; break;
                default: cout << "Invalid choice.\n";
            }
        } while (choice != 3);

    } else if (userType == "S" || userType == "s") {
        int choice;
        do {
            cout << "\n--- Student Menu ---\n";
            cout << "1. Issue Book\n2. Search Book\n3. View Available Books\n4. Exit\nChoice: ";
            cin >> choice;
            switch (choice) {
                case 1: issueBook(); break;
                case 2: searchBook(); break;
                case 3: listBooks(); break;
                case 4: cout << "Exiting...\n"; break;
                default: cout << "Invalid choice.\n";
            }
        } while (choice != 4);
    } else {
        cout << "Invalid user type.\n";
    }

    return 0;
}
