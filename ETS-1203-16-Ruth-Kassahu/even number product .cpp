//Find the product of even digits of the a given number (e.g. input=4,923 prod=8)
#include <iostream>
using namespace std;
int main(){
    int number,orginal_number,num,product=1;
    cout<<"enter a number ";
    cin>>number ;
    orginal_number=number;
   do{
       
    num =number%10;
    number/=10;
    if (num%2==0){
        product*=num;
    }
    else {
        continue;
    }
    }
     while (number !=0);
    cout<<"Your number "<<orginal_number <<" with even numbers product is  "<<product<<endl;
    return 0;
}
