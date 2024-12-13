 Problem Analysis
  
 Input
- Number (num)
- Choice of operation
- Decision to continue or exit
 
 Output
- Result based on the chosen operation (e.g., reversed number, digit count, product of even digits, etc.)
  
 Operation
- Reverse a number
- While num is not zero:
- Get remainder: rem = num % 10
- Build reversed number.
- Update num.
- Count digits of a number
- While num is not zero:
- Increment digit count.
- Update num.
- Product of even digits
- While num is not zero:
- Get remainder.
- If even, multiply with product.
- Update num.
- First and last digit and their sum
- Get last digit.
- While num is not zero:
- Update first digit.
- Update num.
- Calculate sum of first and last digits.
- Swap first and last digit
- Count digits.
- Calculate new swapped number using first and last digits.
- Check if number is palindrome
- Build palindrome by reversing the number.
- Compare with original.
- Check if number is strong
- While num is greater than zero:
- Calculate factorial of each digit and sum.
- Compare with original.
- Check if number is perfect
- For each integer from 1 to num:
- Check divisibility and sum proper divisors.
- Compare with original.
- Frequency of first digit
- Count total digits.
- Determine first digit.
- Count occurrences of the first digit in the original number.
  
- Pseudo Code
  
Step 1: Start

Step 2: Declare variables

Step 3: Begin main loop (do while loop)

     `Repeat the following steps until the user decides to stop
text`

   Step 3.1: Read a number
          - initialize 
                  orginal number = number

   Step 3.2: Display operation options

              Display options for operations:
              "The Reverse of a number press '1'"
              "The count the digits of a number press '2'"
              "The product of even digits of a given number press '3'"
              "The first and last digit of the number and their sum press '4'"
              "To swap the first and last digit press '5'"
              "To know if the number is palindrome press '6'"
              "To know if the number is strong or not press '7'"
              "To know if the number is perfect press '8'"
              "To know the frequency of the first digit press '9'"

   Step 3.3: Read choice 

   Step 3.4: Execute operation based on choice
       Case 1: Reverse a given number
           While number is not zero:
                rem = number % 10
               reversedNumber += rem

               Update reversedNumber and num
               Print reversedNumber


       Case 2: Count digits of a number

           If number is a single-digit
                      digit_count = 1
           Else:
               While num is not zero:
                   Increment digit_count
                   Divide num by 10

           Print  digit_count

       Case 3: Product of even digits of a given number

           While num is not zero:
               remainder = num % 10
               If remmainder is even, multiply with product

               Divide num by 10
               Print  product

       Case 4: First and last digit and their sum
                last digit = num % 10
           While num is not zero:
                remainder = num % 10

               If number > 0 and < 9  or < 0 and > -9 
                 first digit = remainder
               Divide num by 10
               Print first digit, last digit, and their sum

       Case 5: Swap first and last digit
           Get last digit.
           While num is not zero:
               Increment digit count.
               Divide num by 10.
           Calculate new swapped value based on first and last digits.
           Print swapped value.

       Case 6: Check if number is palindrome
           While num is not zero:
               remainder = number % 10.
               Build palindrome.
               Compare palindrome with originalNum.
               Print result.

       Case 7: Check if number is strong
           While num > 0:
               remainder = Number % 10.
               Calculate factorial of remainder.
               Add to isStrong.
               Divide num by ten.
               Compare isStrong with originalNum.
              Print result.

       Case 8: Check if number is perfect
           For each integer from 1 to num:
               If it divides num, add to isPerfect.

                Compare isPerfect with num.
                Print result.

       Case 9: Frequency of first digit
           Count total digits in originalNum.
           Determine first digit.
           Count occurrences of first digit in originalNum.
           Print frequency.

   Step 3.5: Ask to continue or exit
              Prompt user: "Do you want to stay in this program (Enter 10 to exit):"
              Read input into decision

              Step 3.5.1: if decision != 10
                            go to step 3
              Step 3.5.2: else
                            go to step 4
Step 4: Stop
