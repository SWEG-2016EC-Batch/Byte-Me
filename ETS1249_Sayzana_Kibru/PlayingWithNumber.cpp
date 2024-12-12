#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int choice;
    int num, original_num;

    cout << "Enter a number: ";
    cin >> num;
    original_num = num;

    cout << "Choose an operation:\n"
         << "1. Reverse the number\n"
         << "2. Count the digits\n"
         << "3. Product of even digits\n"
         << "4. First and last digit and their sum\n"
         << "5. Swap first and last digit\n"
         << "6. Check if palindrome\n"
         << "7. Check if strong number\n"
         << "8. Check if perfect number\n";
    cin >> choice;

    switch (choice) {
        case 1: {  // Reverse the number
            int reversed_number = 0;
            while (num != 0) {
                reversed_number = reversed_number * 10 + num % 10;
                num /= 10;
            }
            cout << "Reversed Number = " << reversed_number << endl;
            break;
        }

        case 2: {  // Count the digits
            int digit_count = 0;
            do {
                digit_count++;
                num /= 10;
            } while (num != 0);
            cout << "Number of digits = " << digit_count << endl;
            break;
        }

        case 3: {  // Product of even digits
            int product = 1;
            bool has_even = false;
            while (num != 0) {
                int digit = num % 10;
                if (digit % 2 == 0) {
                    product *= digit;
                    has_even = true;
                }
                num /= 10;
            }
            cout << "Product of even digits = " << (has_even ? product : 0) << endl;
            break;
        }

        case 4: {  // First and last digit and their sum
            int last_digit = original_num % 10;
            int first_digit = original_num;
            while (first_digit >= 10) {
                first_digit /= 10;
            }
            cout << "First digit = " << first_digit << endl;
            cout << "Last digit = " << last_digit << endl;
            cout << "Sum of first and last digits = " << (first_digit + last_digit) << endl;
            break;
        }

        case 5: {  // Swap first and last digit
            int last_digit = original_num % 10;
            int first_digit = original_num;
            int digit_count = 0;

            while (first_digit >= 10) {
                first_digit /= 10;
                digit_count++;
            }

            int power = pow(10, digit_count);
            int middle_part = (original_num % power) / 10;

            int swapped_number = last_digit * power + middle_part * 10 + first_digit;
            cout << "Swapped number = " << swapped_number << endl;
            break;
        }

        case 6: {  // Check if palindrome
            int reversed_number = 0;
            int temp_num = original_num;
            while (temp_num != 0) {
                reversed_number = reversed_number * 10 + temp_num % 10;
                temp_num /= 10;
            }
            if (reversed_number == original_num) {
                cout << "The number is a palindrome" << endl;
            } else {
                cout << "The number is not a palindrome" << endl;
            }
            break;
        }

        case 7: {  // Check if strong number
            int strong_sum = 0;
            int temp_num = original_num;
            while (temp_num > 0) {
                int digit = temp_num % 10;
                int factorial = 1;
                for (int i = 1; i <= digit; ++i) {
                    factorial *= i;
                }
                strong_sum += factorial;
                temp_num /= 10;
            }
            if (strong_sum == original_num) {
                cout << "The number is a strong number" << endl;
            } else {
                cout << "The number is not a strong number" << endl;
            }
            break;
        }

        case 8: {  // Check if perfect number
            int sum_of_divisors = 0;
            for (int i = 1; i <= original_num / 2; ++i) {
                if (original_num % i == 0) {
                    sum_of_divisors += i;
                }
            }
            if (sum_of_divisors == original_num) {
                cout << "The number is a perfect number" << endl;
            } else {
                cout << "The number is not a perfect number" << endl;
            }
            break;
        }

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
