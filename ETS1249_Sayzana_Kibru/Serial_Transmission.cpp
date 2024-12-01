#include <iostream>
using namespace std;

int main() {
 
    const int transmission_rate = 960; 
    int file_size, total_seconds ,days, hours, minutes, seconds;  

    
    cout << "Enter the file size in bytes: ";
    cin >> file_size;

    
    if (file_size <= 0) {
        cout << "File size must be a positive number.\n";
        return 0;  
    }

    
    total_seconds = file_size / transmission_rate;

    if (file_size % transmission_rate != 0) {
        total_seconds += 1; 
    }

    
    days = total_seconds / (24 * 3600);  
    total_seconds %= (24 * 3600);  
    hours = total_seconds / 3600;  
    total_seconds %= 3600; 
    minutes = total_seconds / 60; 
    seconds = total_seconds % 60; 

    cout << "Time to send the file: \n";
    cout << days << " days, " <<  hours <<" hours, " << minutes << " minutes, "<< seconds << " seconds.\n";

    return 0;
}
