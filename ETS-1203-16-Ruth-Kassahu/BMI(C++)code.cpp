//BMI calculator//
#include <iostream>
using namespace std;
int main() {
    float height,weight,BMI,num;/*num to check if the person wants to continue or not */
    a :
 cout<<"enter the height of the person that you want to calculate BMI  ";
 cin>>height;
 cout<<"enter the weight of the person that you want to calculate the BMI ";
    cin>>weight;
    BMI=weight/(height*height);
    if (BMI>=24){
        cout<<"BMI="<<BMI<<" you are overweight \n you should consider some exercise to help out with your health \n  ";
    }
    else if (BMI<=24 && BMI >=18){
        cout<<"BMI="<<BMI<<" you are normal weight \n you have a good diet \n ";
    }
    else if(BMI>=18){
        cout<<"BMI="<<BMI<<" you are underweight \n you should consider some good meal plans  to help out with your heath \n ";
    }
    cout<<"Enter any number except zero (0) to continue calculating another BMI";
    cin>>num;
    if (num!=0){
        goto a;
        
    }
    else{
        cout<<"you have finished your calculation thank you\n";
        
    }
    return 0;
}

