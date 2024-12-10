//Check whether a number is palindrome or not.
#include <iostream>
using namespace std;
int main() {
   int number,reverse=0,hold,num;
   cout<<"enter a number ";
   cin>>number ;
   num=number;
   while (number !=0){
       
   hold=number%10;
   reverse =reverse*10+hold;
   number=number /10;
   }
   
   if (num==reverse){
       cout<<"Your number is palindrome";
   }
   else{
       cout<<"Your number is not palindrome";
   }
    return 0;
}
