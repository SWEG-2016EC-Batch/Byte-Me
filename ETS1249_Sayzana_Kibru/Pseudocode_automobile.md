Problem analysis Tank Capacity and Range Calculation Program

The program calculates how far a vehicle can travel based on its fuel tank capacity and miles-per-gallon (mpg) efficiency. It includes input validation and allows the user to continue using the program after each calculation.

Key points:

Input Validation: Ensuring the user enters valid values for tank capacity and mpg (both should be positive).
Range Calculation: The program multiplies tank capacity by mpg to calculate the range the vehicle can travel.
Flow Control: The use of the goto statement here is not ideal, as it can make the program harder to understand and maintain.
Retry Mechanism: The program allows the user multiple chances to enter valid input (3 attempts), ensuring flexibility.


# Pseudocode for Tank Capacity and Range Calculation Program

**Start**

1. **Initialize Variables**:
   - Set `count = 3` for retry attempts.
   - Set `preference` for user input on continuing or exiting.

2. **Loop for User Input** (start from label `a`):
   - Prompt the user to input `tank_capacity` (gallons).
   - Prompt the user to input `mpg` (miles per gallon).

3. **Input Validation**:
   - If the input is invalid (non-positive values for `tank_capacity` or `mpg` or invalid input format):
     - Clear error flags and ignore bad input.
     - Decrease `count` by 1.
     - If `count > 0`, ask the user to input the values again.
     - If `count = 0`, display an error message and **exit the program**.

4. **Calculate Range**:
   - Calculate `range = tank_capacity * mpg`.

5. **Display Results**:
   - Output the calculated range (distance the vehicle can drive without refueling).

6. **Ask User if They Want to Continue**:
   - Prompt the user to input 'Y' or 'y' to continue, or anything else to exit.

7. **Loop or Exit**:
   - If the user wants to continue, return to step 2.
   - Otherwise, **exit the program**.

**End**
