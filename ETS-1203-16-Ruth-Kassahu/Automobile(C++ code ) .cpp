// Automobile fuel tank
#include <iostream>
using namespace std;
int main() {
  int automobile_fuel_tank , miles_per_gallon;
  float miles ;
   cout<<"How many litters in gallon does your car have ? \n ";
   cin>>automobile_fuel_tank;
   cout<<"what is the capacity that your car can travel per gallon ?\n";
   cin>>miles_per_gallon;
   miles=automobile_fuel_tank/miles_per_gallon;
   cout<<"Before refueling your car can travel " << miles<<" miles \n";
  if (miles <= 35){
      cout<<"WARNING !! YOU SHOULD REFUEL YOUR CAR SOON !!/n";
  }
  else {
      cout<<"You have good miles ahead ";
  }
   
   return 0;
}
