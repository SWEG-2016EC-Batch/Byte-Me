#include<iostream>
using namespace std;

int main(){
    float fuelAmount;
    float milesPerGallon;
    float milesDriven;

    cout << "Miles calculator \n" << endl;
    cout << "This program calculates the miles that can be driven by an automobile based on \nthe amount of fuel that is in the automobile fuel tank\n\t\t\t and \nthe miles that can be driven by the automobile per gallon \n" << endl;

    cout << "Enter the amount of fuel in the automobile fuel tank in gallons: ";
    cin >> fuelAmount;

    if(cin.fail() || fuelAmount < 0){
        cout << "You have entered a wrong input.\n";
    }
     else if(fuelAmount == 0){
        cout << "This automobile cannot be driven anywhere.\n";
    }
    
     else{
    cout << "Enter the miles that the automobile can be drive per gallon: ";
    cin >> milesPerGallon;

    if(cin.fail() || milesPerGallon <= 0){
        cout << "You have entered the a wrong input.\n";
    } }
    

    milesDriven = fuelAmount * milesPerGallon;
    cout << "The amount of miles that this automobile can be driven when it has " << fuelAmount << " gallons fuel and can be driven " << milesPerGallon <<" miles per gallon is " << milesDriven << " miles"; 
    

    return 0;
}