#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main()
{

     // Constants for ride limits
     const int premiumLimit = 17, standardLimit = 23, privateLimit = 10;
     const int totalRides = premiumLimit + standardLimit + privateLimit;

     // Counters for the number of rides booked
     int premiumCounter = 0, standardCounter = 0, privateCounter = 0;  // Ride counters
     int driversChoice; // drivers decision
     const int managerPassword = 2345; 
     int custNum = 0; // number of customers

       
    // Ride code prefixes and arrays to hold generated ride codes
    string premiumCode = "PRM ", standardCode = "STD ", privateCode = "PRV ", premiumCodes[17], standardCodes[23], privateCodes[10], rideCode; // Ride Code
    string rideCodes[totalRides]; 
    bool rideExist[totalRides]={false};// Array to track if rides are booked
    string logistics[totalRides][5]; // // Array to hold booking details [Name, Pickup, Destination, RideType, Ticket code]
    string occupation; // for ride occupation
    int decision;

    // Generate unique ride codes
    bool codeFound = false;
    int k=0, j = 0;  
    for(k; k < totalRides; k++)
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
    
    const int MAX = 10000; // for number of customer to give each customer a unique code

    string TicketCodes[MAX]; 
    string TicketCode = "TCD " , currentTicketCode;

  // Generate unique ticket codes for customers
    for(int n = 0; n < MAX; n++)
    {
        TicketCodes[n] = TicketCode + to_string(n);

    }


    char iAm;// Variable to store user type (Customer, Driver, Manager)

    while(true)
    {
        cout << "Transporation Logistics\n";
        system("clear");
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
        if(premiumCounter == premiumLimit && standardCounter == standardLimit && privateCounter == privateLimit){
            cout << "We are out of rides now please try again later!!\n";
        } else{
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
            } else{
                cout << "We are out of Standard Ride too!\n";
            }
            sleep(03);
            break;
        }
        case 2:  { // Private Ride
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
                        logistics[i][4] = TicketCodes[custNum];
                        
                        cout << "\n\tYour Ticket\n";
                        cout << "\tName: " << logistics[i][0] << "\n";
                        cout << "\tPickup Location: " << logistics[i][1] << "\n";
                        cout << "\tDestination: " << logistics[i][2] << "\n";
                        cout << "\tRide Type: " << logistics[i][3] << "\n";
                        cout << "\tRide code (car code): " <<rideCodes[i] <<"\n";
                        cout << "          Ticket code: " << logistics[i][4] << "\n";
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

case 2: { // Standard Ride
        if(premiumCounter == premiumLimit && standardCounter == standardLimit && privateCounter == privateLimit){
            cout << "We are out of rides now please try again later!!\n";
            }
            else{
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
            } else{

                cout << "We are out of Standard ride please try the other option\n";
                cout << "Do you want to choose other ride?\n";
                cout << "Press 1: to choose premium ride\n";
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
                switch (decision)
                {
                case 1:{
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
            }
             else{
                cout << "We are out of Premium Ride too!\n";
            }
            sleep(03);
            break;
            }
        case 2:  { // Private Ride
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
                        logistics[i][4] = TicketCodes[custNum];
                        
                        cout << "\n\tYour Ticket\n";
                        cout << "\tName: " << logistics[i][0] << "\n";
                        cout << "\tPickup Location: " << logistics[i][1] << "\n";
                        cout << "\tDestination: " << logistics[i][2] << "\n";
                        cout << "\tRide Type: " << logistics[i][3] << "\n";
                        cout << "\tRide code (car code): " <<rideCodes[i] <<"\n";
                        cout << "          Ticket code: " << logistics[i][4] << "\n";
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
        if(premiumCounter == premiumLimit && standardCounter == standardLimit && privateCounter == privateLimit){
            cout << "We are out of rides now please try again later!!\n";
            }
            else{
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
            } else{
                cout << "We are out of Premium Ride too!\n";
            }
            sleep(03);
            break;
            }

            case 2:{ // Standard Ride
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
            for (int i = 0; i < totalRides; i++) {
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
            for (int i = 0; i < totalRides; i++) {
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
    switch (driversChoice)
    {
    case 1: // reached at destination 
        cout << "Enter your ride code: ";
        cin.ignore();
        getline(cin, rideCode);
        
        for(int j=0; j < totalRides; j++){
     
        if(rideCodes[j] == rideCode)
        {
                codeFound = true;
                string rideType = logistics[j][3];
                logistics[j][0].clear();
                logistics[j][1].clear();
                logistics[j][2].clear();
                logistics[j][3].clear();
                
                cout << "Marked as completed\n";

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
        sleep(03);
        
        break;


    case 2:   //  cancel ride
    codeFound = false;
        cout << "Enter your ride code: ";
        cin.ignore();
        getline(cin, rideCode);
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
                
                cout << "Ride canceled\n";

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
    if(passWord == managerPassword)
    {
        cout << "Access granted. Welcome, Manager.\n";
                cout << "1. Check Vehicle Status\n";
                cout << "2. View Ride Summary\n";
                cout << "3. View if rides are occupied\n";
                cout << "4. To exit the program\n";
                cout << "Enter your choice: ";
                int managerChoice;
                cin >> managerChoice;

                switch (managerChoice)
                {
                case 1: // Check vehicle status
                    cout << "\n\tVehicle Status:\n";
                    cout << "\tPremium Rides Available: " << premiumLimit- premiumCounter << "\n";
                    cout << "\tStandard Rides Available: " << standardLimit -standardCounter << "\n";
                    cout << "\tPrivate Rides Available: " << privateLimit- privateCounter << "\n";
                    cout << "\tNumber of customers who booked using the program: " << custNum << "\n";
                    sleep(10);
                    break;


         case 2: // View ride summary
                    cout << "\nRide Summary:\n";
                    cout << "\nCustomer name" << setw(25) << "Ride Type" << setw(25)<< " Ride Code" << setw(25) << "Ticket Code "<< setw(25) << "PickUp Location"<< setw(25) << "Destination\n";

                    for(k=0;k<totalRides;k++){
                        if(!logistics[k][0].empty()){
                        cout << logistics[k][0] << setw(25) << logistics[k][3] <<setw(28) << rideCodes[k] << setw(26) <<logistics[k][4] << setw(26)<< logistics[k][1] << setw(26) << logistics[k][2] << endl;
            }
        }
    sleep(03);
    break;

    case 3: // checking occupation of rides
    cout << "\nRide Code" << setw(30) << "Ride occupation\n";
    for(int m =0; m < totalRides; m++){
        if(!rideExist[m]){
            occupation = "Un-occupied";
        } else if(rideExist[m]) {
            occupation = "Occupied";
        }

        cout << rideCodes[m] << setw(30) << occupation << endl << endl;
    }
    sleep(03);
    break;

    case 4:
    return 0;
    break;
        default:
    cout << "You have entered a wrong input\n";
    sleep(3);
        break;
    }
    
    }
    } else{
        cout << "You have entered a wrong input\n";
        sleep(03);
    }

}
return 0;
}
