#include <iostream>
using namespace std;
int main(){

    cout << "Employee's Salary Calculator \n\n";
    float weekly_working_hour;
    float bonus_rate_per_hour;
    float base_salary;
    string name;
    float pension_rate = 0.05;
    float tax_rate= 0.15;
    char decision;

    do{

        cout << "Enter your name: ";
        cin >> name;

        cout << "Enter your weekly working hour: ";
        cin >> weekly_working_hour;

        if(cin.fail() || weekly_working_hour < 0){
            cout << "Invalid input.";
            break;
        }
        cout << "Enter your bonus rate per hour in birr: ";
        cin >> bonus_rate_per_hour;

        if(cin.fail() || bonus_rate_per_hour < 0){
            cout << "Invalid input.";
            break;
        }
        cout << "Enter your base salary: ";
        cin >> base_salary;

        if(cin.fail() || base_salary < 0){
            cout << "Invalid input.";
            break;
        }
        
        int bonus_payment = weekly_working_hour * 4 * bonus_rate_per_hour;
        int gross_salary = base_salary + bonus_payment;
        int pension = gross_salary * pension_rate;
        int tax = (gross_salary - pension) * tax_rate;
        int total_deduction = pension + tax;
        int net_salary = gross_salary - total_deduction;
        cout << endl;

        cout << "Dear " << name <<", " << "your bonus payment is " << bonus_payment << " birr,\n\n\t your gross salary is "<< gross_salary <<" birr and \n\n\t your net salary is " <<net_salary << " birr.\n" << endl;

        cout << "Do you want to keep claculating others salary?\n\n If you do enter \"Y/y\"\n If you don't enter other keys." ;
        cin >> decision;

        cout << endl;

 

    }while(decision == 'Y' || decision == 'y');
}