#include <iostream>
using namespace std;

int main() {
   
    const double Tax_Rate = 0.15,  Pension_Rate = 0.05;
    double weekly_working_hours, base_salary, bonus_rate;
    double gross_salary, net_salary, bonus_payment;

    
    cout << "Enter weekly working hours: ";
    cin >> weekly_working_hours;

    cout << "Enter the base salary (in Birr): ";
    cin >> base_salary;

    cout << "Enter the bonus rate (per hour): ";
    cin >> bonus_rate;

   
    bonus_payment = weekly_working_hours * bonus_rate;
    gross_salary = base_salary + bonus_payment;
    net_salary = gross_salary - (gross_salary * Tax_Rate) - (base_salary * Pension_Rate);

  
    cout << "\n Gross Salary: " << gross_salary << " Birr\n";
    cout << "Bonus Payment: " << bonus_payment << " Birr\n";
    cout << "Net Salary: " << net_salary << " Birr\n";

    return 0;
}
