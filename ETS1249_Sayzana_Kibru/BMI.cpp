#include <iostream>
using namespace std;

int main() {

int size;
double height, weight, bmi;

cout << "Enter the number of persons you want BMI calculated: ";
cin >> size;

for (int i =1; i <=size; i++) {

    cout << "Enter the weight(in kilograms) and height(in meters) of person " << i << ", respectively: ";
    cin >> weight >> height;

    
    bmi = weight/(height*height);
    cout << "Your bmi is " << bmi << endl;

    if (bmi < 18.5) {
        cout << "This person is underweight. \n";
    }
    else if (bmi >= 18.5 && bmi < 25) {
        cout << "This person is in healthy weight range. \n";
    }
    else if (bmi >= 25 && bmi < 30) {
        cout << "This person is overweight. \n";
    }
    else if (bmi >= 30) {
        cout << "This person is obese. \n";
    }

}
}
