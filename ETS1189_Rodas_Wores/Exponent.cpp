#include <iostream>
#include<cmath>
using namespace std;
int main() {

float x;  // x indicates the base
float y;  // y indicates the exponent
float result;
cout<<"Please enter the base(x) of your choice: ";
cin>>x;

cout<<"Please enter the exponent(y) of your choice: ";
cin>>y;

result = pow(x, y);  // pow(x, y) calculates x^y

cout<<x<<" raised to the power of "<<y<<" is: "<<result; 
 



return 0;

}
