
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

    } else if(iAm == 'B' || iAm == 'b'){
        
    cout << "Reached at destination:press: 1 \n";
    cout << "Cancel a ride: press 2 \n";
    cin >> driversChoice;
    switch (driversChoice)
    {
    case 1: // reached at destination 
       codeFound = false;
        cout << "Enter your ride code: ";
        cin >> rideCode;
        
        for(int j=0; j < totalRides; j++){
        if(rideCodes[j] == rideCode)
        {
                codeFound = true;
                string rideType = logistics[j][3];
                logistics[j][0].clear();
                logistics[j][1].clear();
                logistics[j][2].clear();
                logistics[j][3].clear();

                if (rideType == "Premium")
                {
                    premiumCounter--;
                } 
                else if (rideType == "Standard")
                {
                    standardCounter--;
                } 
                else if (rideType == "Private")
                {
                     privateCounter--;
                }

            }
        }
        if(!codeFound) {
            cout << "your code is not found\n";
        }
        break;

    case 2:   //  cancel ride
    codeFound = false;
        cout << "Enter your ride code: ";
        cin >> rideCode;
        j=0;
        for(j; j < totalRides; j++){
        if(rideCodes[j] == rideCode)
        {
               codeFound = true;
                string rideType = logistics[j][3];
                logistics[j][0].clear();
                logistics[j][1].clear();
                logistics[j][2].clear();
                logistics[j][3].clear();

                if (rideType == "Premium")
                {
                    premiumCounter--;
                } 
                else if (rideType == "Standard")
                {
                    standardCounter--;
                } 
                else if (rideType == "Private")
                {
                     privateCounter--;
                }

            }
        }
        if(!codeFound) {
            cout << "your code is not found\n";
        }
        sleep(5);
    break;      
    default:
    cout << "\nYou have entered a wrong input\n";
        break;
    }

    }
 else if( iAm == 'C' || iAm == 'c'){ // manager
        
    int passWord;
    cout << "Enter your password: ";
    cin >> passWord;
    if(passWord == managerPassword)
    {
        cout << "Access granted. Welcome, Manager.\n";
                cout << "1. Check Vehicle Status\n";
                cout << "2. View Ride Summary\n";
                cout << "3. View if rides are occupied\n";
                cout << "4. To exit the program\n";
                cout << "Enter your choice: ";
                int managerChoice;
                cin >> managerChoice; switch (managerChoice)
                {
                case 1: // Check vehicle status
                    cout << "Vehicle Status:\n";
                    cout << "Premium Rides Available: " << premiumLimit- premiumCounter << "\n";
                    cout << "Standard Rides Available: " << standardLimit -standardCounter << "\n";
                    cout << "Private Rides Available: " << privateLimit- privateCounter << "\n";
                    sleep(5);
                    break;


         case 2: // View ride summary
                    cout << "Ride Summary:\n";
                    cout << "Customer name" << setw(30) << "Ride Type" << setw(30)<< " Ride Code"<< setw(30) << "PickUp Location"<< setw(30) << "Destination\n";

                    for(k=0;k<totalRides;k++){
                        if(!logistics[k][0].empty()){
                        cout << logistics[k][0] << setw(30) << logistics[k][3] <<setw(30) << rideCodes[k] << setw(30) << logistics[k][1] << setw(30) << logistics[k][2] << endl;
            }
        }
    sleep(5);
    break;

    case 3:
    cout << "Ride Code" << setw(30) << "Ride occupation\n";
    for(int m =0; m < totalRides; m++){
        if(!rideExist[m]){
            occupation = "Un-occupied";
        } else if(rideExist[m]) {
            occupation = "Occupied";
        }

        cout << rideCodes[m] << setw(30) << occupation << endl << endl;
    }
    break;

    case 4:
    return 0;
    break;
        default:
    cout << "You have entered a wrong input\n";
    sleep(5);
        break;
                }
    
    }
    } else{
        cout << "You have entered a wrong input\n";
        sleep(5);
    }

}


  return 0;
}
    
