Problem analysis for Exponent Calculation Program:

This program calculates the result of raising a base number to a specified exponent. It allows for user input and validation, ensuring only valid numeric inputs are processed.

Key Points:

Input Validation: Ensuring the user inputs valid integers for both the base and exponent.
Error Handling: The program handles invalid inputs using a retry mechanism (up to 3 attempts).
Loop Logic: The use of a do-while loop ensures that the program keeps running until the user decides to exit.


# Pseudocode for Power Calculation Program

**Start**

1. **Initialize Variables**:
   - `count = 3` (retry limit)
   - `preference` to track if the user wants to continue

2. **Repeat (do-while loop)**:
   - **Reset `result` to 1** for the current calculation.
   - **Reset `count` to 3** for retry attempts.

3. **Input Validation (while true)**:
   - Prompt the user to **input `base` and `exponent`**.
   - If input is invalid (`cin.fail()` or `exponent < 0`):
     - Clear the error and ignore invalid input.
     - Decrease `count` by 1.
     - If `count` becomes 0:
       - Display an error message.
       - **Exit the program**.
   - If input is valid:
     - Exit the validation loop.

4. **Calculate Power**:
   - For each `i` from 1 to `exponent`:
     - Multiply `result` by `base`.

5. **Display Result**:
   - Output `base` raised to the power of `exponent` and its result.

6. **Ask User to Continue**:
   - Prompt the user for input (`y`/`Y` to continue, anything else to exit).

7. Repeat the above steps until the user chooses to exit.

8. Display a **thank-you message** and exit the program.

**End**
