#include <iostream>

using namespace std;

int main()
{
    int cont=0;

    while (cont==0){
   a: string employee_name;
    float bonus, working_hour, base_salary,bonus_rate_per_hour,pension_rate=0.05,tax_rate=0.15;
    float pension,tax;


    cout<<"Enter employee name:";
    cin>>employee_name;
    cout<<"Enter base salary of the employee:";
    cin>>base_salary;
    cout<<"Enter working hour of the employee:";
    cin>>working_hour;
    cout<<"Enter bonus rate per hour:";
    cin>>bonus_rate_per_hour;

    if (cin.fail() || base_salary <= 0 || working_hour<=0) {
        cin.clear();
        cin.ignore();
        cout << "Invalid Input! Try Again.\n";
        goto a;
    }
    bonus=bonus_rate_per_hour*working_hour;

    float gross_salary=base_salary+bonus;
    pension=pension_rate*gross_salary;
    tax=tax_rate*gross_salary;

    float net_salary=gross_salary-(tax+pension);
    cout<<"the employees net salary is:"<<net_salary<<endl;
    cout<<"Do you want to continue? if you want press 0,if you don't press 1:";
    cin>>cont;

    }

    return 0;
}

