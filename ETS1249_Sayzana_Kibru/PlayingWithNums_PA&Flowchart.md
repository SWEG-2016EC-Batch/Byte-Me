## Problem Analysis

### Problem Description
The program takes an integer as input and offers the user a variety of operations to perform on that number. These operations include reversing the number, counting the number of digits, checking if the number is a palindrome, checking if it's a strong number, etc.

### Inputs
* Number: An integer to perform operations on.
* Choice: An integer representing the selected operation from the list of options.

### Operations (Choices)
1. Reverse the number: Reverses the digits of the number.
2. Count the digits: Counts the number of digits in the number.
3. Product of even digits: Calculates the product of even digits in the number.
4. First and last digit and their sum: Displays the first and last digits and their sum.
5. Swap first and last digit: Swaps the first and last digits of the number.
6. Check if palindrome: Checks if the number reads the same forwards and backwards.
7. Check if strong number: Checks if the sum of the factorials of the digits equals the original number.
8. Check if perfect number: Checks if the number is a perfect number (sum of divisors equals the number).

### Outputs
* The result of the selected operation:
  * For example, the reversed number, count of digits, product of even digits, etc.

### Processing Steps
1. **Input:** Prompt the user to input an integer.
2. **Operation Choice:** Display a list of available operations and prompt the user to select one.
3. **Operation Execution:**
   * Based on the user's choice, implement the corresponding logic:
     * **Reverse:** Extract digits one by one and construct the reversed number.
     * **Count digits:** Repeatedly divide the number by 10 until it becomes 0.
     * **Product of even digits:** Iterate through the digits, checking for evenness and multiplying them.
     * **First and last digits:** Extract the first and last digits using modulo and division operations.
     * **Swap digits:** Extract the first and last digits, and then construct the new number.
     * **Palindrome check:** Reverse the number and compare it to the original.
     * **Strong number check:** Calculate the factorial of each digit and sum them.
     * **Perfect number check:** Find the divisors and sum them.
4. **Output:** Display the result of the selected operation.

```mermaid
  flowchart TD
    Start[Start] --> InputNumber[Enter Number]
    InputNumber --> ChooseOperation[Choose Operation (1-8)]
    ChooseOperation --> ReverseNumber[Reverse Number]
    ChooseOperation --> CountDigits[Count Digits]
    ChooseOperation --> ProductEvenDigits[Product of Even Digits]
    ChooseOperation --> FirstLastSum[First and Last Digit Sum]
    ChooseOperation --> SwapDigits[Swap First and Last Digits]
    ChooseOperation --> CheckPalindrome[Check if Palindrome]
    ChooseOperation --> CheckStrong[Check if Strong Number]
    ChooseOperation --> CheckPerfect[Check if Perfect Number]
    
    ReverseNumber --> DisplayResult[Display Result]
    CountDigits --> DisplayResult
    ProductEvenDigits --> DisplayResult
    FirstLastSum --> DisplayResult
    SwapDigits --> DisplayResult
    CheckPalindrome --> DisplayResult
    CheckStrong --> DisplayResult
    CheckPerfect --> DisplayResult

    DisplayResult --> End[End]
```
