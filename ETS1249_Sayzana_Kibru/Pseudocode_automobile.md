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
