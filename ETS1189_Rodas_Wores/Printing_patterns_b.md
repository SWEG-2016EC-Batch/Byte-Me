Problem Analysis

Input
- Number of rows
- Number of columns

Output
- Various patterns:
- Grid of numbers
- Characters from 'A' to 'X' with line breaks
- Right-angled triangle of numbers
- Inverted right-angled triangle of numbers
- Right-angled triangle of letters
- Grid of lowercase letters
- Hollow square of asterisks
- Right-aligned triangle of asterisks
- Pyramid shape of asterisks
- Inverted pyramid shape of asterisks
- Hollow inverted half pyramid
- Hollow full pyramid

Operation
- Nested loops are used to generate the patterns.

Pseudo Code
Step 1: Start

Step 2: Read rows and columns

Pattern 1: Grid of Numbers

Step 3: For i from 1 to row: // start outer loop
   Step 3.1: For j from 1 to column: // start inner loop
           print j
           End inner for loop 
    Print a newline
    End outer for loop

Pattern 2: Characters

Step 4: For each character from 'A' to 'X':
        Print the character
   Step 4.1: If the character is 'F', 'L', or 'R':
        Print a newline
        End for loop

Pattern 3: Right-Angled Triangle of Numbers

Step 5: For i from 1 to row // outer loop
   Step 5.1: For j from 1 to current row // inner loop
       Print the column number
       End inner for loop
      Print a newline
End outer for loop

Pattern 4: Inverted Right-Angled Triangle of Numbers

Step 6: for i from 1 to row  // outer loop
   Step 6.1: for j from 1 to column // inner loop
       Print spaces for the current row number
       End inner loop
   Step 6.2: for j from i down to 1: // another inner loop
       print j
       End inner loop
       Print a newline

Pattern 5: Pyramid of Letters

Step 7: for character from 'A' to 'E'// outer loop 
    Step 7.1: for char from 'A' to charcter in the current row // inner loop
         print char
         End inner for loop
    Print new line
    End outer for loop

Pattern 6: Lowercase Letters Grid

Step 8: for ch from 'a' to 'e' // outer loop
    Step 8.1: for c from 'a' to 'e' // inner loop
          print c
          End inner for loop
    print new line 
    End outer for loop

Pattern 7: Hollow Square

Step 9: for i from 1 to row //  outer loop
    Step 9.1: for j from 1 to column // inner loop
    Step 9.2: if i == 1 or i == row or j == column or j == 1;
            print "*"
            else 
               print  space
            End inner for loop
    print new line
    End outer for loop

Pattern 8: Right-Aligned Triangle of Asterisks

Step 10: for i = 1 to row
     Step 10.1: for j to column
        print "*"
        End inner for loop
    print new line
    End outer for loop
     
Pattern 9: Pyramid Shape of Asterisks

Step 11: for i = 1 to row // outer loop
     Step 11.1: for j = 1 to column // inner loop
         Print " "
         End inner loop
     Step 11.2: for j = 1 to i // another inner loop
         Print "*"
         End inner for loop
     Step 11.3: for j = 1 to i-1 // another inner loop
         print "*"
         End inner for loop
    print new line
    End outer for loop

Pattern 10: Inverted pyramid shape of Asterisks

Step 12: for i = 1 to row;
     Step 12.1: for j = column downto 1
     Step 12.2: if i == 1 or j == column or j == i
           print "*"
                else
                  print space
            End inner for loop
     Print new line
     End outer for loop
Pattern 11: Hollow inverted half pyramid

Step 13: for i = 1 to row // outer loop
     Step 13.1: for j = column down to 1 // inner loop
     Step 13.2: if i = 1 or j = column or j = i
               print "*"
               else 
                  print space
              End inner for loop
     print new line
     End outer for loop

Pattern 12: Hollow Full Pyramid
 
Step 14: for i = 1 to row  // outer loop
     Step 14.1: for j = 1 to column  // inner loop
              print space
              End inner for loop
     Step 14.2: for j = 1 to i(current row) // another inner loop
     Step 14.3: if j = 2 or (i = row and  j != 1)
              print "*"
               else 
                  print space
                  end inner for loop 
    Step 14.4: for j = 1 to i 
    Step 14.5: if j == i or i = 6 // another inner loop
             print "*"
             else
               print ""
               end inner for loop
    print new line
    End outer for loop
Step 15: Stop
