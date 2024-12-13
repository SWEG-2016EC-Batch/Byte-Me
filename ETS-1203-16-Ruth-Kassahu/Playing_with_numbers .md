
#### Problem Analysis

##### 1. Input
   - An integer number from the user.
   - User's choice from the menu to select the desired operation.

##### 2. Output
   - Reversed number.
   - Count of digits in the number.
   - Product of even digits.
   - Sum of the first and last digit.
   - Number with swapped first and last digit.
   - Palindrome check result.
   - Frequency of each digit in the number.
   - Strong number check result.
   - Perfect number check result.

##### 3. Operations for Each Task
 ##### a) Prints the Reversed Number
- Input 
  - An integer `number`.

- Output
  - The reversed number.
- Operation:
         -  1. Initialize `reversed` to 0.
         -  2. While `number` is not 0:
                  - Extract the last digit.
                  - Append the digit to `reversed`.
                  - Remove the last digit from `number`.
            - 3. Print `reversed`.

##### b) Counts the Number of Digits
- Input: 
  - An integer `number`.
- Output:
  - The count of digits.
- Operation:
          1. Initialize `count` to 0.
          2. While `number` is not 0:
                     - Remove the last digit.
                     - Increment `count`.
  3. Print `count`.

##### c) Find the Product of Even Digits
- Input: 
  - An integer `number`.
- Output
  - The product of even digits.
- Operation:
           -  1. Initialize `product` to 1.
            - 2. Initialize `has Even` to false.
            - 3. While `number` is not 0:
                          - Extract the last digit.
                          - If the digit is even:
                          - Multiply the digit with `product`.
                           - Set `has Even` to true.
                          - Remove the last digit from `number`.
            -  4. If `has Even` is false:
                          - Print 0.
            -  5. Else:
                          - Print `product`.


##### d) Prints the First and Last Digit and Find Their Sum
- Input: 
         - An integer `number`.
- Output
        - The first digit, the last digit, and their sum.
- Operation:
                  -1. Extract the last digit and store in `last Digit`.
          -2. While `number` is greater than or equal to 10:
                            - Remove the last digit.
                  - 3. Store `number` in `first Digit`.
                  - 4. Calculate `sum` as `first Digit + last Digit`.
       - 5. Print `first Digit`, `last Digit`, and `sum`.

##### e) Swap the First and Last Digit
- Input 
        - An integer `number`.
- Output 
         - The number with the first and last digits swapped.
- Operation
                - 1. Extract the last digit and store in `last Digit`.
                - 2. While `number` is greater than or equal to 10:
                         - Remove the last digit.
                - 3. Store `number` in first   Digit.
                - 4. Calculate `new  Number` as `last Digit * 10^(numDigits-1) + middle Part * 10 + first Digit`.
-  5. Print `newNumber`.

##### g) Check Whether the Number is a Palindrome
- Input 
      - An integer `number`.
- Output
     - Boolean result indicating if the number is a palindrome.

- Operation:
         -  1. Check if `number` equals `reverseNumber(number)`.
         -  2. Print the result.

##### h) Find the Frequency of Each Digit in a Given Integer and Print in Table Format
- Input
      - An integer `number`.
- Output
     - The frequency of each digit in the number.
- Operation
          -   1. Initialize an array `freq` of size 10 with all elements as 0.
          -   2. While `number` is not 0:
                  - Extract the last digit.
                  - Increment the frequency of the digit in `freq`.
                  - Remove the last digit from `number`.
           -  3. Print the frequency of each digit.

#####  i) Check if a Number is Strong or Not
- Input: 
     - An integer `number`.
- Output:
     - Boolean result indicating if the number is a Strong number.
- Operation
            -  1. Initialize `sum` to 0.
             - 2. Store the original `number` in `temp`.
             - 3. While `temp` is not 0:
                      - Extract the last digit.
                      - Calculate the factorial of the digit and add to `sum`.
                      - Remove the last digit from `temp`.
             - 4. Check if `sum` equals `number`.
 - 5. Print the result.

 ##### j) Check if a Number is Perfect Number or Not
- Input
      - An integer `number`.
- Output
      - Boolean result indicating if the number is a Perfect number.
- Operation
               - 1. Initialize `sum` to 0.
                - 2. For `i` from 1 to `number / 2`:
     - If `number` is divisible by `i`:
                     - Add `i` to `sum`.
-  3. Check if `sum` equals `number`.
               - 4. Print the result.



##### Pseudo Code
#### 1.	Start
#### 2.	Prompt the user to enter an integer.
#### 3.	Store the integer in a variable number.
#### 4.	Display the menu:          
- 1.	Reverse the number
- 2.	Count the number of digits
- 3.	Product of even digits 
- 4.	Sum of the first and last digit
- 5.	Swap the first and last digit
- 6.	Check if the number is a palindrome
- 7.	Find the frequency of each digit
- 8.	Check if the number is a Strong number
- 9.	Check if the number is a Perfect number
#### 5.	Read the user's choice into variable choice.
#### 6.	Perform the operation based on the user's choice
#### 7.	 If choice is 1: Reverse the number.
- 1.  Initialize reversed to 0.
- 2. While number  is not 0:
- 3. Extract the last digit.
- 4. Append the digit to reverse.
- 5. Remove the last digit from number.
- 6. Print reversed.
- 7. End
#### 8.	If choice is 2: Count the number of digits.
- 1. Initialize count to 0.
- 2. While number is not 0
- 3. Remove the last digit.
- 4. Increment count.
- 5.  Print count.
- 6. End
#### 9.	If choice is 3: Find the product of even digits.
- 1.	Initialize product to 1
- 2.	Initialize has Even to false.
- 3.	While number is not 0:
- 4.	Extract the last digit.
- 5.	If digit is even:
- 6.	Multiply digit with product.
- 7.	.Set has Even to true
- 8.	Remove the last digit from number
- 9.	If  has Even is false:
- 10.Print 0.
- 11.	else.Print product
- 12.	End
#### 10.	If choice is 4: Print the first and last digit, and find their sum.
- 1. Extract the last digit and store in last Digit.
- 2. While number is greater than or equal to 10:
- 3. Remove the last digit.
- 4. Store number in first Digit.
- 5. Calculate sum as first Digit + last Digit.
- 6. Print first Digit, last Digit, and sum.
- 7. End 
#### 11.	If choice is 5: Swap the first and last digit.
- 1. Extract the last digit and store in last Digit.
- 2. While number is greater than or equal to 10:
- 3. Remove the last digit.
- 4. Store number in first Digit.
- 5. Calculate new Number as lastDigit * 10^(numDigits-1) + middlePart * 10 + firstDigit.
- 6. Print new Number.
- 7. End 
#### 12.	If choice is 7: Find the frequency of each digit.
- 1. Initialize an array freq of size 10 with all elements as 0.
- 2. While number is not 0:
- 3. Extract the last digit.
- 4. Increment the frequency of the digit in freq.
- 5. Remove the last digit from number.
- 6. Print the frequency of each digit.
- 7. End
#### 13.	If choice is 8: Check if the number is a Strong number.
- 1. Initialize sum to 0.
- 2. Store the original number in temp.
- 3. While temp is not 0:
- 4. Extract the last digit.
- 5. Calculate the factorial of the digit and add to sum.
- 6. Remove the last digit from temp.
- 7. If sum equals number:
- 8. Print "The number is a Strong number".
- 9. Else Print "The number is not a Strong number".
- 10. End 
 #### 14.	If choice is 9: Check if the number is a Perfect number.
- 1. Initialize sum to 0.
- 2. For i from 1 to number / 2:
- 3. If number is divisible by i:
- 4. Add i to sum.
- 5. If sum equals number:
- 6. Print "The number is a Perfect number".
- 7. Else Print "The number is not a Perfect number".
#### 15.	Ask the user if he/she 
#### 16.	If choice is 10: Exit the program.
#### 17.	Repeat until the user chooses to exit:
#### 18.	End




 

      














