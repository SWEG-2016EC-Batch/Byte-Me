// A serial transmission line can transmit 960 characters a second. Write a program that will calculate how long
//it will take to send a file, given the file size. Test your program on a 400MB (419,430,400 byte) file which may
//take days.

#include <iostream>
using namespace std;
int main() {
   long int file_size,speed,min,hour;
   cout<<"What is the file size that you want to send(using MB) ";
   cin>>file_size;
   file_size *=1048576;
   speed =file_size/960;
   min=speed/60;
   hour=min/60;
   cout<<"your file size is "<<file_size<<"its going to take "<<speed<<"sec\n"<<"or"<<min<<"min\n"<<"or"<<hour<<"hours";
   cout<<"thanks ";
   
   return 0;
}
