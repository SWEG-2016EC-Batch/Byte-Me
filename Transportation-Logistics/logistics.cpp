
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
        case 1: { // Premium Ride
            if (premiumCounter < premiumLimit) {
                for (int i = 0; i < premiumLimit; i++) { // loop error
                    if (logistics[i][0].empty()) { 
                        cout << "Enter your name: ";
                        cin >> logistics[i][0];
                        cout << "Enter your pickup location: ";
                        cin >> logistics[i][1];
                        cout << "Enter your destination: ";
                        cin >> logistics[i][2];
                        logistics[i][3] = "Premium";
                        rideExist[i] = true;
                        premiumCounter++;
                        currentTicketCode = TicketCodes[custNum];
                        logistics[i][4] = currentTicketCode;

                        cout << "\n\tYour Ticket\n";
                        cout << "\tName: " << logistics[i][0] << "\n";
                        cout << "\tPickup Location: " << logistics[i][1] << "\n";
                        cout << "\tDestination: " << logistics[i][2] << "\n";
                        cout << "\tRide Type: " << logistics[i][3] << "\n";
                        cout << "\tRide code (car code): " << rideCodes[i] <<"\n";
                        cout << "\tTicket code: " << logistics[i][4] << "\n";
                        ++custNum;
                        break;
                    }
                }
            } else {
                cout << "No Premium rides available. Please try another option.\n";
            }
            sleep(3);
            break;
        }

case 2: { // Standard Ride
            if (standardCounter < standardLimit) {
                for (int i = premiumLimit; i < premiumLimit + standardLimit; i++) {
                    if (logistics[i][0].empty()) {
                        cout << "Enter your name: ";
                        cin >> logistics[i][0];
                        cout << "Enter your pickup location: ";
                        cin >> logistics[i][1];
                        cout << "Enter your destination: ";
                        cin >> logistics[i][2];
                        logistics[i][3] = "Standard";
                        rideExist[i] = true;
                        standardCounter++;
                        logistics[i][4] = TicketCodes[custNum];
                         
                        cout << "\n\tYour Ticket\n";
                        cout << "\tName: " << logistics[i][0] << "\n";
                        cout << "\tPickup Location: " << logistics[i][1] << "\n";
                        cout << "\tDestination: " << logistics[i][2] << "\n";
                        cout << "\tRide Type: " << logistics[i][3] << "\n";
                        cout << "\tRide code (car code): " << rideCodes[i] <<"\n";
                        cout << "\tTicket code: " << logistics[i][4] << "\n";
                        ++custNum;
                        break;
                    }
                }
            } else {
                cout << "No Standard rides available. Please try another option.\n";
            }
            sleep(3);
            break;
        }
  
        case 3: { // Private Ride
            if (privateCounter < privateLimit) {
                for (int i = premiumLimit + standardLimit; i < totalRides; i++) {
                    if (logistics[i][0].empty()) {
                        cout << "Enter your name: ";
                        cin >> logistics[i][0];
                        cout << "Enter your pickup location: ";
                        cin >> logistics[i][1];
                        cout << "Enter your destination: ";
                        cin >> logistics[i][2];
                        logistics[i][3] = "Private";
                        rideExist[i] = true;
                        privateCounter++;
                        
                        cout << "\nYour Ticket\n";
                        cout << "\tName: " << logistics[i][0] << "\n";
                        cout << "\tPickup Location: " << logistics[i][1] << "\n";
                        cout << "\tDestination: " << logistics[i][2] << "\n";
                        cout << "\tRide Type: " << logistics[i][3] << "\n";
                        cout << "\tRide code (car code): " <<rideCodes[i] <<"\n";
                        break;
                    }
                }
            } else {
                cout << "No Private rides available. Please try another option.\n";
            }
            sleep(5);
            break;
        }

        case 4: { // Cancel Ride
            string name;
            cout << "Enter your name to cancel the ride: ";
            cin >> name;

            bool nameFound = false;
            for (int i = 0; i < totalRides; i++) {
                if (logistics[i][0] == name) {
                    string rideType = logistics[i][3];
                    logistics[i][0].clear();
                    logistics[i][1].clear();
                    logistics[i][2].clear();
                    logistics[i][3].clear();

                    if (rideType == "Premium") premiumCounter--;
                    else if (rideType == "Standard") standardCounter--;
                    else if (rideType == "Private") privateCounter--;

                    cout << "\nYour ride has been canceled.\n";
                    nameFound = true;
                    break;
                }
            }
            if (!nameFound) {
                cout << "No booking found under your name.\n";
            }
            sleep(5);
            break;
        }

        case 5: { // search booking
            string name;
            cout << "Enter your name to search booking: ";
            cin >> name;bool nameFound = false;
            for (int i = 0; i < totalRides; i++) {
                if (logistics[i][0] == name) {
                    cout << "\nYour Ticket\n";
                    cout << "\tName: " << logistics[i][0] << "\n";
                    cout << "\tPickup Location: " << logistics[i][1] << "\n";
                    cout << "\tDestination: " << logistics[i][2] << "\n";
                    cout << "\tRide Type: " << logistics[i][3] << "\n";
                    cout << "\tRide code (car code): " <<rideCodes[i] <<"\n";
                    nameFound = true;
                    break;
                }
            }
            if (!nameFound) {
                cout << "No booking found under your name.\n";
            }
            sleep(5);
            break;
        }
        case 0: // Exit
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            sleep(2);
            break;
        }

    }


  return 0;
}
    
