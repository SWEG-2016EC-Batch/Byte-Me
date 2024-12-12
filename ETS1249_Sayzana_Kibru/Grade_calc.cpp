#include <iostream>
using namespace std;

int main()
{
    string name, grade, courseName;
    float test, quiz, project, assignment, finalExam, totalMarks;
    char decision;
    int size;

    cout << "Grade Calculator \n\n";

    do{

    cout << "Enter Student's name: ";
    cin >> name;

    cout << "Enter the number of course you take this Semester: ";
    cin >> size;

    if(cin.fail() || size < 0){
        cout << "Invalid Input";
    }

    for(int i = 1; i <= size; i++){

        cout << "Enter course name " << i << " : ";
        cin >> courseName;

        cout << "Enter Student's Test result out of 15: ";
        cin >> test;

        if(cin.fail() || test < 0 || test > 15){
            cout << "Inavalid input";
            cin.clear();
            cin.ignore();
            break;
        }
    
        cout << "Enter Student's Quiz result out of 5: ";
        cin >> quiz;

        if(cin.fail() || quiz < 0 || quiz > 5){
            cout << "Invalid input";
            cin.clear();
            cin.ignore();
            break;
        }

        cout << "Enter Student's Project result out of 20: ";
        cin >> project;

        if(cin.fail() || project < 0 || project > 20){
            cout << "Invalid input";
            cin.clear();
            cin.ignore();
            break;
        }

        cout << "Enter Student's Assignment result out of 10: ";
        cin >> assignment;

        if(cin.fail() || assignment < 0 || assignment > 10){
            cout << "Invalid input";
            cin.clear();
            cin.ignore();
            break;
        }

        cout << "Enter Student's Final Exam result out of 50: ";
        cin >> finalExam;

        if(cin.fail() || finalExam < 0 || finalExam > 50){
            cout << "Invalid input";
            cin.clear();
            cin.ignore();
            break;
        }

        totalMarks = test + quiz + project + assignment + finalExam;

        if(totalMarks >= 90 && totalMarks <= 100){
            grade = "A+";
        } else if(totalMarks >= 80 && totalMarks < 90){
            grade ="A";
        }
         else if(totalMarks >= 75 && totalMarks < 80){
            grade ="B+";
        } else if(totalMarks >= 60 && totalMarks < 75){
            grade ="B";
        } else if(totalMarks >= 55 && totalMarks < 60){
            grade ="C+";
        } else if(totalMarks >= 45 && totalMarks < 55){
            grade ="C";
        } else if(totalMarks >= 30 && totalMarks < 45){
            grade ="D";
        } else{
            grade ="F";
        }

        cout << "Summarized information\n\n";
        
        cout << "Student name: "<< name << endl;
        cout << "Course name: " << courseName << endl;
        cout << "Test result: "<< test << endl;
        cout << "Quiz result: "<< quiz << endl;
        cout << "Project result: " <<project << endl;
        cout << "Assignment result: "<< assignment << endl;
        cout << "Final exam result: "<< finalExam << endl;
        cout << "Total marks: "<< totalMarks << endl; 
        cout << "Grade: "<< grade << endl << endl;
    } 
      cout << "Do you want to keep calculating student's result?";
      cin >> decision;
    
    }while(decision == 'Y' || decision == 'y');

    return 0;
}
