#include <iostream>
using namespace std;

int main()
{
  cout << "BMI(Body Mass Index) Calculator \n" << endl;
  cout << "Body mass index (BMI) is a calculation that estimates body size and weight relative to height\n" << endl;
  cout << "BMI is calculated as weight / (height * height) \n" << endl;
  cout << "The values of height and weight should be positive numbers.\n" << endl;
    float height;
    float weight;
    float BMI;
    char charcter;
    int i = 1;

    do{

      cout << "Person " << i << endl;

      cout << "Enter your heigth in meter: ";
      cin >> height;

      if(cin.fail() || height <= 0){
         cout << "You have entered a wrong input.\n";
         break;
      }

      cout << "Enter your weight in kilogram: ";
      cin >> weight;

      if(cin.fail() || weight <= 0){
         cout << "You have entered a wrong input.\n";
         break;
      }

      BMI = weight/(height * height);
      cout << "Your BMI is " << BMI << endl << endl;


      if(BMI < 18.5){
      cout << "You are underweight. \n" << endl;
    } else if(BMI >= 18.5 && BMI < 24.9){
      cout << "You are in a healthy weight.\n" << endl;
    } else if(BMI >= 24.9 && BMI <= 29.9){
      cout << "You are overweight. \n" << endl;
    } else if(BMI > 30){
      cout << "You have obesity.\n" << endl;
    } 

     {cout << "Do you want to continue? \n"
     << "Press \"0\" to quit\n"
     << "Press any other key to continue\n";
     cin >> charcter;
     cout << endl;}

     i++;

    }while(charcter != '0');


    return 0;
}