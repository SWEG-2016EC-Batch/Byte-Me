#include <iostream>
using namespace std;

int main () {
    int base, exp, result, count=3;
    char preference;
 do {
    result = 1;
    cout << "Enter the base and exponents respectively: ";
    cin >> base >> exp;

    while (cin.fail()) {
        cin.clear();
        cin.ignore();

        if (count > 0) {
            cout << "Please enter an integer value only. \n";
            cout << count << " trails left. \n";
            count--;

           cout << "Enter the base and exponents respectively: ";
           cin >> base >> exp; 
        }
        else {
            cout << "you have failed to enter a valid input. \n";
            cout << "No more trails left. exiting the program...";
            return 0;
        }
    }

    for (int i =1; i <= exp; i++) {
        result*= base;
    }

    cout << base << " raised to " << exp << " is " << result << endl;

    cout << "Do you want to continue using the program? if yes, enter y or Y else enter anything:";
    cin >> preference;
    
} while(preference == 'y' || preference == 'Y');
}
