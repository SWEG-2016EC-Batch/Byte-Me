// Prints the reverses of the number (e.g. input = 4637215 Output=5217364).
#include <iostream>
using namespace std;
int main() {
   int number,reverse=0,hold;
   cout<<"enter a number ";
   cin>>number ;
   while (number !=0){
       
   hold=number%10;
   reverse =reverse*10+hold;
   number=number /10;
   }
   cout<<"The reverse number is "<< reverse<<endl;
    return 0;
}
