#include <iostream>

using namespace std;

int main()
{  int cont=0;

while(cont==0){
    int transmission_Rate = 960;
    int file_Size;
  double time_In_Seconds,In_Minutes,In_Hours,In_days;

   a :cout<<"Enter the file size to be transferred in byte: ";
    cin>>file_Size;
   if (cin.fail() || file_Size <= 0) {
        cin.clear();
        cin.ignore();
        cout << "Invalid Input! Try Again."<<endl;
        goto a;
    }

     time_In_Seconds =file_Size / transmission_Rate;
     cout << "amount of time take to transfer file in Seconds: " << time_In_Seconds << " seconds" << endl;

     In_Minutes = time_In_Seconds / 60;
     cout << "amount of time take to transfer file in minutes: " << In_Minutes<< " minutes" << endl;
     In_Hours =In_Minutes / 60;
     cout << "amount of time take to transfer file in hour: " << In_Hours<< " hours" << endl;
     In_days=In_Hours/24;
     cout << "amount of time take to transfer file in days: " << In_days<< " days" << endl;

    cout <<"do you want to continue?if yes press 0 ,if not press 1:";
    cin>>cont;

}

    return 0;
}
