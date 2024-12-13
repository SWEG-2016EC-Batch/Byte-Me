#### Probem analysis

#### Input: number of row and column
#### Process: use for loop operation to do the patterns
#### Output : display different types of patterns

##### Pseudocode 
 - Start

- Step 1. Input number of rows and columns
   - Prompt the user to input the number of rows (`row`) and columns (`col`).

- Step 2. //Pattern 1: Print a grid of numbers
   - For each row from 1 to `row`:
     - For each column from 1 to `col`:
       - Print the column index.
     - Move to the next line.
- Then repeat until the outer loop condition is satisfied.

- Step 3. //Pattern 2: Print letters 'A' to 'X' with line breaks
   - For each character from 'A' to 'X':
     - Print the character.
     - If the character is 'F', 'L', or 'R', move to the next line.

- Step 4. //Pattern 3: Print a triangle of numbers
   - For each row from 1 to `row`:
     - For each column from 1 to the current row number:
       - Print the column index.
     - Move to the next line.
- repeat until the outer loop condition is satisfied.

Correction yasfelgewal**Step 5. //Pattern 4: Print a right-aligned triangle of numbers
   - For each row from 1 to `row`:
     - Print spaces for alignment.
     - Print numbers from 1 to the current row number.
     - Move to the next line.

- Step 6. //Pattern 5: Print an uppercase letter pyramid
   - For each letter from 'A' to 'E':
     - Print letters from 'A' to the current letter on the outer loop.
     - Move to the next line. 
- then repeat until the outer loop condition is satisfied.

- Step 7. //Pattern 6: Print a grid of lowercase letters
   - For each row from 'a' to 'e':
     - Print letters from 'a' to 'e'.
     - Move to the next line.
- repeat until the loop condition is satisfied.

- Step 8. //Pattern 7: Print a hollow rectangle
   - For each row from 1 to `row`:
     - For each column from 1 to `col`:
       - Print '*' if on the border; otherwise, print a space.
     - Move to the next line.

- Step 9. //Pattern 8: Print an inverted right-aligned triangle of '*'
   - For each row from 1 to `row`:
     - Print '*' starting from the current row index to `col`.
     - Move to the next line.
- Repeat until the current row index equal to the number of row.

- Step 10. //Pattern 9: Print a centered pyramid of '*'
    - For each row from 1 to `row`:
      - Print spaces for alignment.
      - Print '*' to form the pyramid.
      - Move to the next line.

- Step 11. Pattern 10: Print an inverted centered pyramid of '*'
    - For each row from 1 to `row`:
      - Print leading spaces for alignment.
      - Print '*' to form the pyramid.
      - Move to the next line.

- Step 12. Pattern 11: Print a diagonal and border of a square
    - For each row from 1 to `row`:
      - For each column from `col` to 1:
        - Print '*' if on the border or diagonal; otherwise, print a space.
      - Move to the next line.

- Step 13. //Pattern 12: Print an arrow-like pattern
    - For each row from 1 to `row`:
      - Print leading spaces for alignment.
      - Print '*' based on specific conditions.
      - Move to the next line.

- Stop
