#include <iostream>
using namespace std;

int main() {
    int choice, rows, cols;

    cout << "Select a pattern to display:\n";
    cout << "1. Numbers in a grid\n";
    cout << "2. Alphabet pattern\n";
    cout << "3. Right-angled triangle of numbers\n";
    cout << "4. Pyramid of numbers\n";
    cout << "5. Right-angled triangle of alphabets\n";
    cout << "6. Full grid of lowercase letters\n";
    cout << "7. Hollow square of stars\n";
    cout << "8. Inverted triangle of stars\n";
    cout << "9. Full pyramid of stars\n";
    cout << "10. Inverted pyramid of stars\n";
    cout << "11. Hollow diagonal square\n";
    cout << "12. Hollow diamond pattern\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\n";

    switch (choice) {
        case 1:
            // Numbers in a grid
            for (int i = 1; i <= rows; i++) {
                for (int j = 1; j <= cols; j++) {
                    cout << j << " ";
                }
                cout << endl;
            }
            break;

        case 2:
            // Alphabet pattern
            for (char ch = 'A'; ch < 'A' + rows * cols && ch <= 'Z'; ch++) {
                cout << ch << " ";
                if ((ch - 'A' + 1) % cols == 0) cout << endl;
            }
            break;

        case 3:
            // Right-angled triangle of numbers
            for (int i = 1; i <= rows; i++) {
                for (int j = 1; j <= i; j++) {
                    cout << j << " ";
                }
                cout << endl;
            }
            break;

        case 4:
            // Pyramid of numbers
            for (int i = 1; i <= rows; i++) {
                for (int j = i; j <= rows; j++) {
                    cout << " ";
                }
                for (int j = 1; j <= i; j++) {
                    cout << j;
                }
                cout << endl;
            }
            break;

        case 5:
            // Right-angled triangle of alphabets
            for (char ch = 'A'; ch < 'A' + rows; ch++) {
                for (char c = 'A'; c <= ch; c++) {
                    cout << c << " ";
                }
                cout << endl;
            }
            break;

        case 6:
            // Full grid of lowercase letters
            for (int i = 1; i <= rows; i++) {
                for (char ch = 'a'; ch < 'a' + cols; ch++) {
                    cout << ch << " ";
                }
                cout << endl;
            }
            break;

        case 7:
            // Hollow square of stars
            for (int i = 1; i <= rows; i++) {
                for (int j = 1; j <= cols; j++) {
                    if (i == 1 || i == rows || j == 1 || j == cols) {
                        cout << "* ";
                    } else {
                        cout << "  ";
                    }
                }
                cout << endl;
            }
            break;

        case 8:
            // Inverted triangle of stars
            for (int i = 1; i <= rows; i++) {
                for (int j = i; j <= rows; j++) {
                    cout << "* ";
                }
                cout << endl;
            }
            break;

        case 9:
            // Full pyramid of stars
            for (int i = 1; i <= rows; i++) {
                for (int j = i; j <= rows; j++) {
                    cout << " ";
                }
                for (int j = 1; j <= i; j++) {
                    cout << "*";
                }
                for (int j = 1; j <= i - 1; j++) {
                    cout << "*";
                }
                cout << endl;
            }
            break;

        case 10:
            // Inverted pyramid of stars
            for (int i = 1; i <= rows; i++) {
                for (int j = 1; j <= i; j++) {
                    cout << " ";
                }
                for (int j = i; j <= rows; j++) {
                    cout << "*";
                }
                for (int j = i; j <= rows - 1; j++) {
                    cout << "*";
                }
                cout << endl;
            }
            break;

        case 11:
            // Hollow diagonal square
            for (int i = 1; i <= rows; i++) {
                for (int j = 1; j <= cols; j++) {
                    if (i == 1 || j == cols || i == j) {
                        cout << "* ";
                    } else {
                        cout << "  ";
                    }
                }
                cout << endl;
            }
            break;

        case 12:
            // Hollow diamond pattern
            for (int i = 1; i <= rows; i++) {
                for (int j = i; j <= rows; j++) {
                    cout << " ";
                }
                for (int j = 1; j <= i; j++) {
                    if (j == 2 || (i == rows && j != 1)) {
                        cout << "*";
                    } else {
                        cout << " ";
                    }
                }
                for (int j = 1; j <= i; j++) {
                    if (j == i || i == rows) {
                        cout << "*";
                    } else {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            break;

        default:
            cout << "Invalid choice!\n";
    }

    return 0;
}
