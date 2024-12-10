//Prints the first and the last digit of the number and find their sum.
#include <iostream>
using namespace std;
int main(){
    int number ;
    cout<<"Enter your number ";
    cin>>number;
    number = abs(number);
    lastDigit = number % 10;

    firstDigit = number;
    while (firstDigit >= 10) {
        firstDigit /= 10; 
    }
    sum = firstDigit + lastDigit;

    cout << "First digit: " << firstDigit << endl;
    cout << "Last digit: " << lastDigit << endl;
    cout << "Sum of first and last digits: " << sum << endl;

    return 0;
}
