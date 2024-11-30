// Exponent question
#include <iostream>
using namespace std;
int main() {
    int base ,exponent,power=1 ;
    cout<<"Enter the base that you want to calculate :";
    cin>>base;
    cout<<"Enter the exponent you want to calculate : ";
    cin>>exponent;
    for (int i =1;i<=exponent;i++){
        power*=base;
        
    }
    cout<<"your final number is "<<base<<"^"<<exponent<<"is :"<<power;
    
    return 0;
}
