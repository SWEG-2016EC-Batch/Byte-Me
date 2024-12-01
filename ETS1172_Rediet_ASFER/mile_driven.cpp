#include <iostream>

using namespace std;

int main()
{
    int cont=0;

    while (cont==0){
     a: float gallon,mile_per_gallone,miles_driven;
    cout<<"enter your fuel tanker capacity in gallon:";
    cin>>gallon;
    
      cout <<"enter miles per gallon:";
    cin >>mile_per_gallone;
    
      if (cin.fail() || gallon <= 0 || mile_per_gallone<=0) {
        cin.clear();
        cin.ignore();
        cout << "Invalid Input! Try Again.\n";
        goto a;
    }
    
      miles_driven=gallon*mile_per_gallone;
    cout<<"your car driven amount mile in the amount of gallon gas you have is:"<<miles_driven<<endl;
    cout<<"Do you want to continue? if you want press 0,if not press 1:";
    cin>>cont;
    }
    return 0;
    return 0;
}

