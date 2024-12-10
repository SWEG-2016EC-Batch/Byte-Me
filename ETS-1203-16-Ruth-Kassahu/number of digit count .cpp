//Counts the number of digits in a given number (e.g. 23,498 has five digits)
#include <iostream>
using namespace std;
int main(){
    int number,num,size=0;
    cout<<"enter a number ";
    cin>>number ;
    num=number;
   do{
    number =number/10;
    
    size ++;
   
    }
     while (number !=0);
    cout<<"your number "<<num <<" has "<<size<<"digits"; 
    return 0;
}
