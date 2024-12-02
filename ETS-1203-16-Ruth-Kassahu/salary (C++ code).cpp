// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;
int main() {
  string  name ;
   float weekly_workinghour,base_salary,bonus_payment,gross_salary,pension,tax, net_salary,bonus_rate;
    
    cout<<"what is the employee's name ?\n";
    cin>>name;
    cout<<"what is your weekly working hour ?\n";
    cin>> weekly_workinghour;
    cout<<"What is your base salary ?\n";
    cin>> base_salary;
    cout<<"What is your bonus rate  ?\n";
    cin>> bonus_rate;
    bonus_payment=weekly_workinghour*bonus_rate;//additional payment outside salary
    gross_salary=base_salary+bonus_payment;//bonus payment along the first payment 
    pension=gross_salary*0.05; //since we are told pension is 5%
    tax=gross_salary*0.15; //15% of gross salary is tax deducted by the governemnt 
    net_salary= gross_salary-(pension+tax);
cout<<"The employee "<< name <<" with Gross salary "<<gross_salary<<" has ";
cout<<"Bonus payment "<<bonus_payment<<endl;
cout<<"Getting the above information there is deduction which is Pension and Tax"<<endl;
cout<<"pension :"<< pension <<"and Tax "<<tax;
cout<<"After the deduction of Pension and tax from the Gross salary the totalNet salary is :"<<net_salary<<endl;
    return 0;
}
