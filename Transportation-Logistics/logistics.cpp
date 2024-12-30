
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main()
{
     // Constants for ride limits
     const int premiumLimit = 17, standardLimit = 23, privateLimit = 10;
     const int totalRides = 50;

     // Ride counters
     int premiumCounter = 0, standardCounter = 0, privateCounter = 0, driversChoice;
     int managerPassword = 2345;

     int k=0, j = 0;  
     string premiumCode = "PRM ", standardCode = "STD ", privateCode = "PRV ", premiumCodes[17], standardCodes[23], privateCodes[10], rideCode; // Ride Code
     string rideCodes[50]; 
     bool rideExist[50]={false};
     string occupation; // for ride occupation

     // code generator
     bool codeFound = false;
     for(k; k < 50; k++)
     {
        if(k < premiumLimit)
        {
            rideCodes[k] = premiumCode + to_string(k);
        }
        
        else if(k < standardLimit + premiumLimit)
        {
            rideCodes[k] = standardCode + to_string(k);

        }else{
            rideCodes[k] = privateCode + to_string(k);
        }
    }

    // Logistics array for booking details
    string logistics[totalRides][4]; // [Name, Pickup, Destination, RideType,]

    char iAm;

    while(true)
    {
        system("clear");
        cout << "Choose what you are: press: \n";
        cout  << "A if you are a customer: \n";
        cout << "B if you are a driver: \n";
        cout << "C if you are a manager: \n";
        cin >> iAm;

        if(cin.fail()){
            cout << "You have entered a wrong input\n";
            cin.clear();
            cin.ignore();
            sleep(5);
            }
         
    }

  return 0;
}
    
