#include <iostream> // Include necessary libraries for input-output operations
#include <unistd.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main()
{
      // Constants for ride limits
     const int PREMIUM_LIMIT = 17, STANDARD_LIMIT = 23, PRIVATE_LIMIT = 10;
     const int TOTAL_RIDES = PREMIUM_LIMIT + STANDARD_LIMIT + PRIVATE_LIMIT;

     // Counters for the number of rides booked
     int premiumCounter = 0, standardCounter = 0, privateCounter = 0;  // Ride counters
     int driversChoice; // drivers decision
     const int managerPassword = 2345; 
     int custNum = 0; // number of customers

     // Ride code prefixes and arrays to hold generated ride codes
    string premiumCode = "PRM ", standardCode = "STD ", privateCode = "PRV ",  rideCode; // Ride Code
    string rideCodes[TOTAL_RIDES]; 
    bool rideExist[TOTAL_RIDES]={false};// Array to track if rides are booked
    string logistics[TOTAL_RIDES][5]; // // Array to hold booking details [Name, Pickup, Destination, RideType, Ticket code]
    string occupation; // for ride occupation
    int decision; // for customer to decide whether s/he wants to choose another ride type

    // Generate unique ride codes
    bool codeFound = false;
    int k=0, j = 0;  

    for(k; k < TOTAL_RIDES; k++){
        if(k < PREMIUM_LIMIT){
            rideCodes[k] = premiumCode + to_string(k);// Generate Premium ride code
            }else if(k < STANDARD_LIMIT + PREMIUM_LIMIT){
                rideCodes[k] = standardCode + to_string(k);// Generate Standardride code
                }else{
                    rideCodes[k] = privateCode + to_string(k);// Generate Private ride code
                    }
                    }

    const int MAX = 10000; // Maximum number of customers to give each customer a unique code
    string TicketCodes[MAX]; // Array to hold unique ticket codes for customers
    string TicketCode = "TCD ", currentTicketCode; // Prefix for ticket codes

  // Generate unique ticket codes for customers
    for(int n = 0; n < MAX; n++){
        TicketCodes[n] = TicketCode + to_string(n);
        }

    char iAm;// Variable to store user type (Customer, Driver, Manager)

    while(true)
    {
        cout << "Transporation Logistics\n";
        system("clear");// Clear the console screen
        cout << "Choose what you are: press: \n";
        cout  << "A if you are a customer: \n";
        cout << "B if you are a driver: \n";
        cout << "C if you are a manager: \n";
        cin >> iAm;
    // Input validation
        if(cin.fail()){
            cout << "You have entered a wrong input\n";
            cin.clear();
            cin.ignore();
            continue;
            sleep(03);
            }

            if(iAm == 'A' || iAm == 'a'){ // customer
            cout << "Which ride do you prefer: ";
            cout << "\n 1. Premium Ride";
            cout << "\n 2. Standard Ride";
            cout << "\n 3. Private Ride";
            cout << "\n 4. Cancel Ride";
            cout << "\n 5. Search Booking";
            cout << "\n 0. Exit Program\n";

            int rideChoice;
            cin >> rideChoice;

            if (cin.fail() ||  rideChoice < 0  || rideChoice >5) { 
                cin.clear();
                cin.ignore();
                cout << "Invalid input. Please enter a valid number.\n";
                sleep(03);
                continue;
                }

        switch (rideChoice) {

        case 1: { // Premium Ride
        if(premiumCounter == PREMIUM_LIMIT && standardCounter == STANDARD_LIMIT && privateCounter == PRIVATE_LIMIT){
            cout << "We are out of rides now please try again later!!\n";
        } else{
            if (premiumCounter < PREMIUM_LIMIT) {
                for (int i = 0; i < PREMIUM_LIMIT; i++) { // loop error
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

                        // Printing ticket
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
            } else{
                cout << "We are out of Premium ride please try the other option\n";
                cout << "Do you want to choose other ride?\n";
                cout << "Press 1: to choose standard ride\n";
                cout << "Press 2: to choose private ride\n";
                cout << "Press 0: to exit\n";
                cin >> decision;

                if(cin.fail()){
                    cout << "You have entered wrong input\n";
                    cin.clear();
                    cin.ignore();
                    sleep(03);
                    continue;
                }

                switch(decision){
                    case 1:{ // Standard Ride
                    if (standardCounter < STANDARD_LIMIT) {
                        for (int i = PREMIUM_LIMIT; i < PREMIUM_LIMIT + STANDARD_LIMIT; i++) {
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
                                } else{
                                    cout << "We are out of Standard Ride too!\n";
                                    }
                                    sleep(03);
                                    break;
        }

        case 2:  { // Private Ride
        if (privateCounter < PRIVATE_LIMIT) {
            for (int i = PREMIUM_LIMIT + STANDARD_LIMIT; i < TOTAL_RIDES; i++) {
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
                    logistics[i][4] = TicketCodes[custNum];
                        
                    cout << "\n\tYour Ticket\n";
                    cout << "\tName: " << logistics[i][0] << "\n";
                    cout << "\tPickup Location: " << logistics[i][1] << "\n";
                    cout << "\tDestination: " << logistics[i][2] << "\n";
                    cout << "\tRide Type: " << logistics[i][3] << "\n";
                    cout << "\tRide code (car code): " <<rideCodes[i] <<"\n";
                    cout << "\tTicket code: " << logistics[i][4] << "\n";
                    ++custNum;
                    break;
                    }
                }
            }else{
                cout << "We are out of Private Ride too!\n";
            } 
            sleep(03);
            break;
        }
        case 0:{ //EXIT
            return -1;
        }                  
        default:
        cout << "You have intered invalid Number\n";
        break;

        }
        }
        }

        sleep(03);
        break;
        }

        case 2: { // Standard Ride

        if(premiumCounter == PREMIUM_LIMIT && standardCounter == STANDARD_LIMIT && privateCounter == PRIVATE_LIMIT){
            cout << "We are out of rides now please try again later!!\n";
            } else{
                if (standardCounter < STANDARD_LIMIT) {
                    for (int i = PREMIUM_LIMIT; i < PREMIUM_LIMIT + STANDARD_LIMIT; i++) {
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
            } else{

                cout << "We are out of Standard ride please try the other option\n";
                cout << "Do you want to choose other ride?\n";
                cout << "Press 1: to choose premium ride\n";
                cout << "Press 2: to choose private ride\n";
                cout << "Press 0: to exit\n";
                cin >> decision; // accepting decision from a customer if they want to choose another ride other than standard ride

                if(cin.fail()){ // input validation
                    cout << "You have entered wrong input\n";
                    cin.clear();
                    cin.ignore();
                    sleep(03);
                    continue;
                }
                switch (decision)
                {
                case 1:{
                    if (premiumCounter < PREMIUM_LIMIT) {
                        for (int i = 0; i < PREMIUM_LIMIT; i++) { 
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
                    }else{
                        cout << "We are out of Premium Ride too!\n";
                        }
                        sleep(03);
                        break;
                        }

                case 2:  { // Private Ride
                if (privateCounter < PRIVATE_LIMIT) {
                    for (int i = PREMIUM_LIMIT + STANDARD_LIMIT; i < TOTAL_RIDES; i++) {
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
                            logistics[i][4] = TicketCodes[custNum];
                        
                            cout << "\n\tYour Ticket\n";
                            cout << "\tName: " << logistics[i][0] << "\n";
                            cout << "\tPickup Location: " << logistics[i][1] << "\n";
                            cout << "\tDestination: " << logistics[i][2] << "\n";
                            cout << "\tRide Type: " << logistics[i][3] << "\n";
                            cout << "\tRide code (car code): " <<rideCodes[i] <<"\n";
                            cout << "\tTicket code: " << logistics[i][4] << "\n";
                            ++custNum;
                            break;
                        }
                    }
                } else{
                    cout << "We are out of Private Ride too!\n";
                  }
                sleep(03);
                 break;
             }
                case 0: {
                return -1;
                }

                default:
                cout << "You have intered invalid Number\n";
                break;
                }
            }

            }
            
            sleep(03);
            break;
        }

        case 3: { // Private Ride
        if(premiumCounter == PREMIUM_LIMIT && standardCounter == STANDARD_LIMIT && privateCounter == PRIVATE_LIMIT){
            cout << "We are out of rides now please try again later!!\n";
            } else {
                if (privateCounter < PRIVATE_LIMIT) {
                    for (int i = PREMIUM_LIMIT + STANDARD_LIMIT; i < TOTAL_RIDES; i++) {
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
                            logistics[i][4] = TicketCodes[custNum];
                        
                            cout << "\n\tYour Ticket\n";
                            cout << "\tName: " << logistics[i][0] << "\n";
                            cout << "\tPickup Location: " << logistics[i][1] << "\n";
                            cout << "\tDestination: " << logistics[i][2] << "\n";
                            cout << "\tRide Type: " << logistics[i][3] << "\n";
                            cout << "\tRide code (car code): " <<rideCodes[i] <<"\n";
                            cout << "\tTicket code: " << logistics[i][4] << "\n";
                            ++custNum;
                            break;
                       }
                   }

            } else {

                cout << "We are out of Private ride please try the other option\n";
                cout << "Do you want to choose other ride?\n";
                cout << "Press 1: to choose Premium ride\n";
                cout << "Press 2: to choose Standard ride\n";
                cout << "Press 0: to exit\n";
                cin >> decision;

                if(cin.fail()){
                    cout << "You have entered wrong input\n";
                    cin.clear();
                    cin.ignore();
                    sleep(03);
                    continue;
                }   
                switch (decision)
                {
                case 1:{
                if (premiumCounter < PREMIUM_LIMIT) {
                    for (int i = 0; i < PREMIUM_LIMIT; i++) { 
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
                } else{
                    cout << "We are out of Premium Ride too!\n";
                    }
                 sleep(03);
                 break;
                }

                case 2:{ // Standard Ride
                if (standardCounter < STANDARD_LIMIT) {
                    for (int i = PREMIUM_LIMIT; i < PREMIUM_LIMIT + STANDARD_LIMIT; i++) {
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
                } else{
                    cout << "We are out of Standard Ride too!\n";
                    }
                sleep(03);
                break;
               }   

             case 0:{
                return -1;
            }
             default:
             cout << "You have Entered invalid Number\n";

             }
            }
            }
            sleep(03);
            break;
        }

        case 4: { // Cancel Ride
        /* changed the name by customer ticket code because many customers can have the same name*/
            string customerTickedCode;
            cout << "Enter your your ticket code to cancel the ride: "; 
            cin.ignore();
            getline(cin, customerTickedCode);

            bool ticketFound = false;
            for (int i = 0; i < TOTAL_RIDES; i++) {
                if (TicketCodes[i] == customerTickedCode) {

                    string rideType = logistics[i][3];
                    logistics[i][0].clear();
                    logistics[i][1].clear();
                    logistics[i][2].clear();
                    logistics[i][3].clear();

                    if (rideType == "Premium") premiumCounter--;
                    else if (rideType == "Standard") standardCounter--;
                    else if (rideType == "Private") privateCounter--;

                    cout << "\nYour ride has been canceled.\n";
                    ticketFound = true;
                    break;
                }
            }
            if (!ticketFound) {
                cout << "No booking found under your name.\n";
                } 
                sleep(03);
                break;
        }

        case 5: { // search booking
         /* changed the name by customer ticket code because many customers can have the same name*/
         string customerTickedCode;
         cout << "Enter your ticket code to search booking: ";
         cin.ignore();
         getline(cin, customerTickedCode);
         bool ticketFound = false;
         for (int i = 0; i < TOTAL_RIDES; i++) {
            if (TicketCodes[i] == customerTickedCode) {
                cout << "\n\tYour Ticket\n";
                cout << "\tName: " << logistics[i][0] << "\n";
                cout << "\tPickup Location: " << logistics[i][1] << "\n";
                cout << "\tDestination: " << logistics[i][2] << "\n";
                cout << "\tRide Type: " << logistics[i][3] << "\n";
                cout << "\tRide code (car code): " <<rideCodes[i] <<"\n";
                cout << "\tTicket code: " << logistics[i][4] << "\n";
                ticketFound = true;
                break;
            }
          }
            if (!ticketFound) {
                cout << "No booking found under your ticket.\n";
            }
            sleep(03);
            break;
        }
        case 0: // Exit
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            sleep(03);
            break;
        }

    } else if(iAm == 'B' || iAm == 'b'){ 
        cout << "Reached at destination:press: 1 \n";
        cout << "Cancel a ride: press 2 \n";
        cin >> driversChoice;
        if (cin.fail()) { 
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a valid number.\n";
            sleep(03);
            continue;
            }

        switch (driversChoice)
        {
            case 1: // reached at destination 
            cout << "Enter your ride code: ";
            cin.ignore();
            getline(cin, rideCode);

            for(int j=0; j < TOTAL_RIDES; j++){
                if(rideCodes[j] == rideCode){
                    codeFound = true;
                    string rideType = logistics[j][3];
                    logistics[j][0].clear();
                    logistics[j][1].clear();
                    logistics[j][2].clear();
                    logistics[j][3].clear();

                    cout << "Marked as completed\n";

                    if (rideType == "Premium"){
                        premiumCounter--;
                    } else if (rideType == "Standard"){
                        standardCounter--;
                    } else if (rideType == "Private"){
                        privateCounter--;
                    }
               }
           }

           if(!codeFound) {
            cout << "your code is not found\n";
           }
           sleep(03);
           break;

          case 2:   //  cancel ride
          codeFound = false;
          cout << "Enter your ride code: ";
          cin.ignore();
          getline(cin, rideCode);

          j=0;
          for(j; j < TOTAL_RIDES; j++){
            if(rideCodes[j] == rideCode){
                codeFound = true;
                string rideType = logistics[j][3];
                logistics[j][0].clear();
                logistics[j][1].clear();
                logistics[j][2].clear();
                logistics[j][3].clear();
                
                cout << "Ride canceled\n";

                if (rideType == "Premium"){
                    premiumCounter--;
                } else if (rideType == "Standard"){
                    standardCounter--;
                } else if (rideType == "Private"){
                     privateCounter--;
                }

            }
        }

          if(!codeFound) {
            cout << "your code is not found\n";
           }
           sleep(03);
        break;      
        default:
        cout << "\nYou have entered a wrong input\n";
        break;
    }

    } else if( iAm == 'C' || iAm == 'c'){ // manager
        int passWord;
        cout << "Enter your password: ";
        cin >> passWord;
        if(passWord == managerPassword){
            cout << "Access granted. Welcome, Manager.Press: \n";
            cout << "1. Check Vehicle Status\n";
            cout << "2. View Ride Summary\n";
            cout << "3. View if rides are occupied\n";
            cout << "0. To exit the program\n";
            cout << "Enter your choice: ";
            int managerChoice;
            cin >> managerChoice;

            if(cin.fail()){
                cout << "You have entered wrong input\n";
                cin.clear();
                cin.ignore();
                sleep(03);
                continue;
                }

                switch (managerChoice)
                {
                case 1:{ // Check vehicle status
                    cout << "\n\tVehicle Status:\n";
                    cout << "\tPremium Rides Available: " << PREMIUM_LIMIT- premiumCounter << "\n";
                    cout << "\tStandard Rides Available: " << STANDARD_LIMIT -standardCounter << "\n";
                    cout << "\tPrivate Rides Available: " << PRIVATE_LIMIT- privateCounter << "\n";
                    cout << "\tNumber of customers who booked using the program: " << custNum << "\n";
                    sleep(10);
                    break;
                }


                case 2: {// View ride summary
                 int n =0;
        // for the summary to be in tabular form
                 string row1 = "Customer Name",
                        row2 = "Ride Type",
                        row3 = "Ride Code",
                        row4 = "Ticket Code",
                        row5 = "PickUp Location",
                        row6 = "Destination";

                 int width1 = max(row1.length(),logistics[n][0].length()),
                    width2 = max(row2.length(),logistics[n][3].length()),
                    width3 = max(row3.length(),rideCodes[n].length()),
                    width4 = max(row4.length(),logistics[n][4].length()),
                    width5 = max(row5.length(),logistics[n][1].length()),
                    width6 = max(row6.length(),logistics[n][2].length()),
                    totalWidth = width1 + width2 + width3 + width4 + width5 + width6 ;
            
                    cout << "\nRide Summary:\n";

                    for(int h = 0; h <= totalWidth + 16; h++){
                        cout << "-";
                    }
                    cout << endl;

                    cout << left << setw(width1) << row1 << " | " << left << setw(width2) << row2 << " | "<< left << setw(width3) << row3 << " | " << left << setw(width4) << row4 << " | "<< left << setw(width5) << row5 << " | " << left << setw(width6) << row6 << " | \n";

                    for(int h = 0; h <= totalWidth + 16; h++){
                        cout << "-";
                    }
                    cout << endl;


                    for(int k = 0; k < TOTAL_RIDES; k++){
                        if(!logistics[k][0].empty()){
                        cout <<left << setw(width1) << logistics[k][0]<<" | "<<left << setw(width2) << logistics[k][3] << " | " << left <<setw(width3) << rideCodes[k]  << " | " << left << setw(width4) <<logistics[k][4] << " | " << left << setw(width5)<< logistics[k][1] << " | " << left << setw(width6) << logistics[k][2] << " | " << endl; 
                        for(int h = 0; h < totalWidth + 16; h++){
                            cout << "-";
                        }
                        cout << endl;
                        }
                    }
               sleep(03);
               break;
                }

                case 3:{ // checking occupation of rides

              // for the occupation summary be in tabular form
                string row1 = "Ride code",
                       row2= "Ride Occupation";
                int n =0;
                int width1 = max(row1.length(),logistics[n][0].length()),
                width2 = max(row2.length(), logistics[n][0].length()),
                totalWidth = width1 + width2;

                for(int h = 0; h <= totalWidth+4; h++){
                    cout << "-";
                    }
                cout << endl;
                cout << left << setw(width1) << row1 << " | " << left << setw(width2) << row2 << " | \n";

                for(int h = 0; h<totalWidth+4; h++){
                        cout << "-";
                    }
                    cout << endl;
                for(int m =0; m < TOTAL_RIDES; m++){
                    if(!rideExist[m]){
                        occupation = "Un-occupied";
                        } else if(rideExist[m]) {
                            occupation = "Occupied";
                            }

                cout << left << setw(width1) <<  rideCodes[m]  << " | " << left << setw(width2) << occupation  << " | "<< endl ;
                for(int h = 0; h <= totalWidth+4; h++){
                    cout << "-";
                    }
                cout << endl;
                }

                sleep(03);
                break;
                }

               case 0:
               return -1;
               break;
               default:
               cout << "You have entered a wrong input\n";
               sleep(3);
               break;
        }
    
      }

    } else{ // if The customer pressed any other key other than A,B or c
        cout << "You have entered a wrong input\n";
        sleep(03);
    }

}
return 0;
}
