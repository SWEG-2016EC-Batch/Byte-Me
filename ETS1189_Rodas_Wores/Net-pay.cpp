#include <iostream>
using namespace std;

int main()
{
    float basicSalary, workedHour, bonusRate, grossSalary, bonus, netSalary,taxRate, tax,overTimeWorkedHour;
    float pensionRate = 0.07, pension;
    char decision;
    string name;
    
    do{

    
        cout << "Enter employees name: ";
        cin >> name;

        cout << "Enter employee's basic salary: ";
        cin >> basicSalary;
        if(cin.fail() || basicSalary < 0){
            cin.clear();
            cin.ignore();
            break;
        }

        
        if(basicSalary < 200){
            taxRate = 0;
        } else if(basicSalary >= 200 && basicSalary < 600){
            taxRate = 0.1;
        } else if(basicSalary >= 600 && basicSalary < 1200){
            taxRate = 0.15;
        } else if(basicSalary >= 1200 && basicSalary < 2000){
            taxRate = 0.2;
        } else if(basicSalary >= 2000 && basicSalary < 3000){
            taxRate = 0.25;
        } else if(basicSalary >= 3000){
            taxRate = 0.3;
        }

        cout << "Enter employee's worked hour: ";
        cin >> workedHour;
        if(cin.fail() || workedHour < 0){
            cin.clear();
            cin.ignore();
            break;
        }

        if(workedHour < 40){
            overTimeWorkedHour = 0;
            bonus = 0;
        } else{
            cout << "Enter employee's bonus rate in birr: ";
            cin >> bonusRate;
            if(cin.fail() || bonusRate < 0){
                cin.clear();
                cin.ignore();
                break;
            }
        overTimeWorkedHour = workedHour - 40;
        bonus = overTimeWorkedHour * bonusRate;
        }

        grossSalary = basicSalary + bonus;
        pension = grossSalary * pensionRate;
        tax = grossSalary * taxRate;
        netSalary = grossSalary - pension - tax;

        cout << endl << endl << endl;

        cout << "Summerized information about an employee\n\n";
        cout << "Employee name: "<< name << endl;
        cout << "Basic Salary: "<< basicSalary << endl;
        cout << "Worked hour: "<< workedHour << endl;
        cout << "Extra worked hour: "<< overTimeWorkedHour << endl;
        cout << "Bonus payment: "<< bonus << endl;
        cout << "Net salary: " << netSalary << endl << endl << endl;
      

        cout << "Do you want to keep Calculating Employee's Net Salary??";
        cin >> decision; 
    }while(decision == 'Y'|| decision == 'y');

    return 0;

}
