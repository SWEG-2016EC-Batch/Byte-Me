#include <iostream>
using namespace std;

int main()
{
    for(int i = 1; i <=5; i++){
        for(int j =1; j <=5; j++){
            cout << j << " ";
        } 
         cout << endl;
    }

    cout << "\n\n";

    for(char ch = 'A'; ch <= 'X'; ch++){
    
        cout << ch << " ";
         if(ch == 'F' || ch == 'L' || ch == 'R'){
            cout << endl;
            }   
    }

    cout << "\n\n";

    for(int i = 1; i <=5; i++){
        for(int j = 1; j <=i ;j++){
            cout << j << " ";
        }
         cout << endl;
    }

    cout << "\n\n";

for(int i = 1; i<= 5; i++){
    for(int j = i; j<=5; j++){
        cout << " ";
    }
    for(int j = 1; j <= i; j++){
        cout  << j ;
    }
    cout << endl;
}
cout << "\n\n";

for(char ch ='A'; ch <= 'E'; ch++){
    for(char c = 'A'; c <= ch; c++){
        cout << c << " ";
    }
    cout << endl;
}
cout << "\n\n";
for(char ch = 'a'; ch <= 'e'; ch++){
    for(char c = 'a'; c <= 'e'; c++){
        cout << c << " ";
    }
    cout << endl;
}
cout << "\n\n";

for(int i = 1; i <= 8; i++){
    for(int j =1; j<=8;j++){
        if(i == 1 || i == 8 || j == 1 || j == 8){
            cout << "* ";

        }else{
            cout << "  ";
        }
    }
    cout << endl;
}

cout << "\n\n";

for(int i = 1; i <= 6; i++){
    for(int j = i; j <=6; j++){
        cout << "* ";
    }
    cout << endl;
}

cout << "\n\n";

    for(int i =1; i<=6; i++){
        for(int j=i; j<=6; j++){
            cout << " ";
        }

        for(int j = 1; j <=i; j++){
            cout << "*";
        }

        for(int j = 1; j <= i-1; j++){
            cout << "*";
        }

        cout<< endl;
    }

    cout << "\n\n";

    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= i; j++){
            cout << " ";
        } 
        for(int j=i;j<=6;j++){
            cout << "*";
        }
        for(int j=i;j<=6-1;j++){
            cout << "*";
        }
        cout << endl;
    }

    cout << "\n\n";

        for(int i = 1; i <= 6; i++){
        for(int j = 6; j >= 1; j--){
            if(i==1 || j == 6 || i == j){
                cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << "\n\n";

    
    for(int i = 1; i <=6; i++){
        for(int j = i; j<=6; j++){
            cout << " ";
        }
        for(int j = 1; j <= i; j++){
            if(j == 2 || (i == 6 && j != 1)){
                cout << "*";
            }else{
                cout << " ";
            }            
        }

        for(int j = 1; j <= i; j++){
            if(j == i || i == 6){
                cout << "*";
            }else{
                cout << " ";
            }
        }

        cout << endl;
    }



}
