//question 4: Design an algorithm and write a to read an employee name weekly working hours, bonus rate per hour and
//base salary and find the employees gross-salary, net salary and bonus payment. (Hint: pension rate – 5%,
//tax: 15%).

#include <iostream>
using namespace std;
int main() {

string employee_name;
double working_hours;
float bonus_rate;
float base_salary;
float gross_salary;
float net_salary;
float bonus_payment;
float tax;
float pension_payment;

cout<<"Enter employee name: ";
getline(cin, employee_name);

cout<<"Enter working hour: ";
cin>>working_hours;

cout<<"Enter bonus rate per hour: ";
cin>>bonus_rate;

cout<<"Enter base salary: ";
cin>>base_salary;

gross_salary=base_salary + (bonus_rate*working_hours);

pension_payment = gross_salary * 0.05;

tax = gross_salary * 0.15;

net_salary = gross_salary - (pension_payment + tax);

bonus_payment =bonus_rate* working_hours;

cout << "\nEmployee Name: " << employee_name << endl;
    cout << "Gross Salary: " << gross_salary << endl;
    cout << "Bonus Payment: " << bonus_payment<< endl;
    cout << "Pension Payment (5%): " << pension_payment << endl;
    cout << "Tax (15%): " << tax << endl;
    cout << "Net Salary: " << net_salary << endl;

    return 0;

}

