#include <iostream>

using namespace std;

int main()
{
     int cont=0,trial=0;
    float weight,height,BMI;
    while(cont==0){

    a:cout<<"enter weight in KG:";
    cin>>weight;
    cout<<"enter height in meter:"<<endl;
    cin>>height;
    if (cin.fail() || weight<0 || height<=0){

        cin.clear();
        cin.ignore();
        trial+=1;
        cout<<"invalid!please,enter valid input"<<endl;
        if(trial<3){
            goto a;
        }
    }
    else{
    BMI=weight/(height*height);
    cout<<"your body mass index(BMI) is:"<<BMI<<endl;
    if(BMI<18.5){
        cout <<"you are under weight!"<<endl;
    }
    else if(BMI>=18.5 && BMI<25){
        cout<<"you are normal!"<<endl;
    }
        else  {
            cout<<"you are over weight!"<<endl;
        }

            cout<<"Do you want to continue?if you want press (0) ,if not press other than (0):";
            cin>>cont;
    }
    }


    return 0;
}
