// question 2: Write a program that prompts the capacity in gallons of an automobile fuel tank and the miles per gallons
//the automobiles can be driven. The program outputs the number miles the automobile cam be driven
//without refueling.


#include <iostream>
using namespace std;

int main() {
    float tankCapacity;  // Capacity of the fuel tank in gallons
    float milesPerGallon;  // Miles the automobile can be driven per gallon
    float totalmiles;  // Total miles the automobile can be driven without refueling

    cout << "Enter the capacity of the fuel tank (in gallons): ";
    cin >> tankCapacity;

    cout << "Enter the miles per gallon the automobile can be driven: ";
    cin >> milesPerGallon;

    totalmiles = tankCapacity * milesPerGallon;

    cout << "The automobile can be driven " << totalmiles
         << " miles without refueling." << endl;

  if (totalmiles <= 35){
      cout<<"WARNING !! YOU SHOULD REFUEL YOUR CAR SOON !!\n";
  }
  else {
      cout<<"You have good miles ahead ";
  }

   return 0;
}
