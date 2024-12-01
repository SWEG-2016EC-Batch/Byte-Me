#include <iostream>
using namespace std;

int main(){

    cout << "File transmission time Calculator \n\n";
    cout << "This program calculates how long it takes for a serial transmission line to transmit a file \n\n When this line transmits 960 characters per second \n\n \"1 character = 1 byte\" \n\n";

    int transmission_rate = 960;
    float file_size;
    int transmission_time;

    cout << "Enter the size of file: ";
    cin >> file_size;
    cout << endl;

    transmission_time = file_size / transmission_rate;

    if(cin.fail() || file_size < 0){
        cout << "invalid input";
    }

    else if(file_size <= 960){
        cout << "It will take 1 or less than 1 second transmit the file" << endl;
    }

    else if(transmission_time < 3600){
        int minutes = (transmission_time / 60);
        int seconds = (transmission_time % 60);
        cout << "The serial transmission line will take " << transmission_time << " seconds to send " << file_size << " bytes of file \n\nwhich means " << minutes << " minutes and " << seconds << " seconds\n";

    } else if(transmission_time >= 3600 && transmission_time < 86400){
        int hours = (transmission_time / 3600);
        int minutes = (transmission_time % 3600)/60;
        int seconds = (transmission_time % 3600)%60;

        cout << "The serial transmission line will take " << transmission_time << " seconds to send " << file_size << " bytes of file \n\nwhich means " <<hours << " hours, "<< minutes << " minutes and " << seconds << " seconds\n";

        cout << hours << endl;
        cout << minutes << endl;
        cout << seconds << endl;
    } else if(transmission_time >= 86400){
        int days = transmission_time / 86400;
        int hours = (transmission_time % 86400)/3600;
        int minutes = ((transmission_time % 86400)%3600)/60;
        int seconds = ((transmission_time % 86400)%3600)%60;

        cout << "The serial transmission line will take " << transmission_time << " seconds to send " << file_size << " bytes of file \n\nwhich means " <<days << " days, "<<hours << " hours, "<< minutes << " minutes and " << seconds << " seconds\n";


    }
    return 0;
}