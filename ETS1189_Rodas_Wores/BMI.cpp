//source code for 1st question  

#include <iostream>

using namespace std;

int main()
{
    float weight ,height;
   float BMI;
   int continue_1;
 A:

  cout<<"Enter your weight: ";
   cin>>weight;
   cout<<"Enter your height: ";
   cin>>height;


   BMI=weight/(height*height);

   cout<<"YOUR BMI IS: "<<BMI<<endl;
   if(BMI<=18.5) {
    cout<<"YOU ARE UNDER WEIGHT!!"<<endl;
   }
   else if(BMI>=18.5 && BMI<=24.9) {
    cout<<"CONGRATULATIONS! YOU ARE NORMAL."<<endl;
   }
   else if(BMI>=25 && BMI<=29.9)
{
    cout<<"YOU ARE OVERWEIGHT!!"<<endl;
}

else  {
cout<<"You are obese!!"<<endl; }

cout<<"IF YOU WANT TO CONTINUE PRESS ANY NUMBER, IF NOT PRESS 0.";
cin>>continue_1;
if (continue_1!=0){
    goto A;
}
 else{
        cout<<"you have finished your calculation thank you\n";

    }
    return 0;


}
