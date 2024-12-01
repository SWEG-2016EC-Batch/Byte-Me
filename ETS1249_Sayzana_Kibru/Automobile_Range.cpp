#include <iostream>
using namespace std;


int main() {
    double tank_capacity, mpg, range;
    int count=3;
    char preference;

    a: 
    cout << "Enter the tank capacity of your automobile in gallons: ";
    cin >> tank_capacity;

    cout << "Enter milles per gallon: ";
    cin >> mpg;

    while (cin.fail()|| tank_capacity<=0 || mpg<=0) {
        cin.clear();
        cin.ignore();

        if (count > 0) {
            cout << "Please enter an integer value only. \n";
            cout << count << " trails left. \n";
            count--;

           goto a;
        }
        else {
            cout << "you have failed to enter a valid input. \n";
            cout << "No more trails left. exiting the program...";
            return 0;
        }
    }

    range = (tank_capacity*mpg);

    cout << "The automobile can be drive " << range << " miles without refueling. \n\n";

    cout << " Do you want to continue using this program? if yes enter Y or y, else enter anything: ";
    cin >> preference;

    if (preference == 'y' || preference == 'Y') {
        goto a;
    }
    else {
        return 0;
    }

    




}
