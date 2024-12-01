#include <iostream>
using namespace std;

int main(){

  cout << "POWER CALCULATOR\n\n";
    int base;
    int exponent;

    do{

      int power = 1;
     cout << "Enter the base of the number: ";
    cin >> base;

    if(cin.fail()){
        cout << "invalid input";
        break;
      } 
      

    cout << "Enter the exponent of the number: ";
    cin >> exponent;

   if(cin.fail()){
        cout << "invalid input";
        break;
      }

    for(int i = 1; i <= exponent; i++){
        power *= base;
    }


    cout << base << " the power of " << exponent << " is " << power << endl << endl;
    }while(base != 0);


}