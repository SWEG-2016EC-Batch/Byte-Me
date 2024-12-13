#include <iostream>
#include <cmath>
using namespace std;

int main(){
    
    int choice;
    int reversedNumber = 0, digit_count = 0, product = 1 , last, first, remNum , power;
    int last_digit, first_digit, swapped =0 , palindrome = 0, isStrong = 0, isPerfect = 0, countFirstDigit = 0;
    int num;
    int decision;
    
    do{
        
    cout << "Enter a number: ";
    cin >> num;
    int orginalNum = num;
    int num1 = num;

    cout << "Enter what you want to operate if you want   \n The Reverse of a number press '1' \n The count the digits of a number press '2' \n The product of even digits of a given number press '3' \n The first and last digit of the number and their sum press '4'\n To swap the first and last digit press '5'\n To know if the number is palindrome press '6'\n To know if the number is strong or not press '7'\n To know if the number is perfect press '8'\n To know the frequency of the first digit press '9' \n";
    cin >> choice;

    switch(choice){
        
        // Reversing a given number

        case 1:
         while(num > 0 || num < 0){
        int rem = num % 10;
        reversedNumber += rem;
        if(num > 0 && num < 9 || num < 0 && num > -9){
            break;
        }

        reversedNumber *= 10;
        num /= 10;
    }
    cout << "Reversed Number = " << reversedNumber;
    break;

    // Counting the digits of a number

    case 2:
        if(num > 0 && num < 9 || num < 0 && num > -9){
            digit_count = 1;
            }else{
                 while(num > 0 || num < 0){ 
                    digit_count++;
                    num /= 10; 
                 }
            }
            cout <<"Number of digits = " <<digit_count;
            break;

    // The product of the even digits of a given number
    
    case 3:
    while(num > 0 || num < 0){
        int rem = num % 10;
        if(rem % 2 == 0){
            product *= rem;
            }
            num /= 10;
            }
        cout << "The product of the even digits of a number is: " << product;
        break;

        //  Finding the first and last digit of a number and the sum of first and last digit

    case 4:
    last = num % 10;
    while(num != 0){
        int rem = num % 10;
        if(num > 0 && num < 9 || num < 0 && num > -9){
            first = rem;
            }
            num /= 10;
            }

            cout << "The First digit of a number is: " << first << endl;
            cout << "The last digit of a number is: "<< last << endl;
            cout << "The sum of the first and the last digits of a number is: "<< first + last << endl;
            break;

            // Swapping the first and last digit of a number

    case 5:
    last_digit = num % 10;
    while(num != 0){
        digit_count++;
        num /= 10;
    }

    orginalNum /= 10;
    power = pow(10, digit_count-2);
    remNum = orginalNum % power;
    first_digit = orginalNum / power;
    swapped += last_digit;
    swapped *= power;
    swapped += remNum;
    swapped *= 10;
    swapped += first_digit;

      cout << "When the first and the last digits swap the number will be: "<< swapped;
      break;

    //   Checking if a number is palindrom or not
    //  A palindromic number is a number that remains the same when its digits are reversed. In other words, it has reflectional symmetry across a vertical axis. 

      case 6:

       while(num > 0 || num < 0){
        int rem = num % 10;
        palindrome += rem;
        if(num > 0 && num < 9 || num < 0 && num > -9){
            break;
        }
        palindrome *= 10;
        num /= 10;
     }

     if(palindrome == orginalNum){
        cout << "The Number is Palindrome" << endl;
     } else {
        cout << "The number is not palindrome" << endl;
     }

     break;

     // checking if a number is strong or not
     // A strong number is a special number whose sum of the factorial of digits is equal to the original number.

     case 7:
     while(num > 0){
         int rem = num % 10;
         int product = 1;
        for(int i = 1; i <= rem; i ++){
            product *= i;
        }
        isStrong += product;

        num /=10;
     }
     
     if(isStrong == orginalNum){
        cout << "The number is Strong number" << endl;
     } else{
        cout << "The number is not strong number" << endl;
     }
     break;

    //  Check if a number is perfect or not
    // A perfect number is a positive integer that is equal to the sum of its proper divisors, excluding the number itself.

     case 8:
     for(int i = 1; i < num; i++){
        if(num % i == 0){
            isPerfect += i;
            }
            }
            if(isPerfect == num){
                cout << "The number is perfect number"<< endl;
                } else {
                    cout << "The number is not perfect number" << endl;
                    }
                    break;

                    // Finding the frequency of a number

    case 9:
    while(num != 0){
        digit_count++;
        num /= 10;
    }
    power = pow(10, digit_count-1);
    first_digit = orginalNum / power;
    while(orginalNum != 0){ 
        int rem = orginalNum % 10;
        if(rem == first_digit){
            countFirstDigit++;
        }
        orginalNum /= 10;
    }

    cout << "The frequency of the first digit is: "<< countFirstDigit;
    break;
}
cout << "\n\n";

cout << "Do you want to stay in this program(Enter 10 to exit): ";
cin >> decision;
    }while(decision != 10);

    return 0;

}
