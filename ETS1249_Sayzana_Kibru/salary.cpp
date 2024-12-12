#include <iostream>
using namespace std;

int main() {
    float basic_salary, worked_hour, bonus_rate, gross_salary, bonus, net_salary, tax_rate, tax, overtime_worked_hour;
    float pension_rate = 0.07, pension;
    char decision;
    string name;

    do {
        cout << "Enter employee's name: ";
        cin >> name;

        cout << "Enter employee's basic salary: ";
        while (!(cin >> basic_salary)) {
            cin.clear();  
            cin.ignore();  
            cout << "Invalid input! Please enter a valid basic salary: ";
        }

        if (basic_salary < 200) {
            tax_rate = 0;
        } else if (basic_salary < 600) {
            tax_rate = 0.1;
        } else if (basic_salary < 1200) {
            tax_rate = 0.15;
        } else if (basic_salary < 2000) {
            tax_rate = 0.2;
        } else if (basic_salary < 3000) {
            tax_rate = 0.25;
        } else {
            tax_rate = 0.3;
        }

        cout << "Enter employee's worked hour: ";
        while (!(cin >> worked_hour)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input! Please enter a valid worked hour: ";
        }

        if (worked_hour <= 40) {
            bonus = 0;
            overtime_worked_hour = 0;
        } else {
            overtime_worked_hour = worked_hour - 40;
            cout << "Enter employee's bonus rate in birr: ";
            while (!(cin >> bonus_rate)) {
                cin.clear();
                cin.ignore();
                cout << "Invalid input! Please enter a valid bonus rate: ";
            }
            bonus = overtime_worked_hour * bonus_rate;
        }

        gross_salary = basic_salary + bonus;
        pension = gross_salary * pension_rate;
        tax = gross_salary * tax_rate;
        net_salary = gross_salary - pension - tax;

        cout << "\n\n--- Summarized Information ---\n";
        cout << "Employee Name: " << name << endl;
        cout << "Basic Salary: " << basic_salary << endl;
        cout << "Worked Hours: " << worked_hour << endl;
        cout << "Overtime Hours: " << overtime_worked_hour << endl;
        cout << "Bonus Payment: " << bonus << endl;
        cout << "Gross Salary: " << gross_salary << endl;
        cout << "Pension Deduction: " << pension << endl;
        cout << "Tax Deduction: " << tax << endl;
        cout << "Net Salary: " << net_salary << "\n\n";

        cout << "Do you want to calculate another employee's net salary? (Y/N): ";
        cin >> decision;

    } while (decision == 'Y' || decision == 'y');

    return 0;
}
