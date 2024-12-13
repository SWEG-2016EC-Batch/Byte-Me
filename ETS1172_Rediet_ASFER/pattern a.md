Problem Analysis

Input
- number of rows and columns

Output
- Various patterns
- A grid of numbers.
- Characters from 'A' to 'X'
- A right-angled triangle of numbers.
- An inverted right-angled triangle of numbers.
- A right-angled triangle of letters
- A grid of lowercase letters from 'a' to 'e'.
- A hollow square made of asterisks.
- A right-aligned triangle of asterisks.
- A pyramid shape made of asterisks.
- An inverted pyramid shape made of asterisks.
- A hollow inverted half pyramid
- A hollow full pyramid

Operation

- Nested loops are used to generate various patterns:
- Print numbers from 1 to 5 in a grid format.
- Print characters from 'A' to 'X', inserting line breaks after specific characters ('F', 'L', 'R').
- Print increasing numbers in a right-angled triangle format.
- Print decreasing numbers with leading spaces.
- Print letters from 'A' to 'E' in a pyramid shape.
- Print lowercase letters from 'a' to 'e' in a grid format.
- Print a hollow square using asterisks.
- Print right-aligned triangles using asterisk
- Print pyramids using asterisks with specific patterns.

Pseudo Code

Step 1: Start 
Step 2: Generate Patterns

Pattern 1: Grid of Numbers

Step 3: For i from 1 to 5:
    Step 3.1: For j from 1 to 5:
        Print j
        End inner for loop
    Step 3.2: Print newline
    En d outer for loop

Pattern 2: Characters 

Step 4: For ch from 'A' to 'X':
    Print ch
    If ch == 'F' or ch == 'L' or ch == 'R':
        Print newline
        End for loop

Pattern 3: Right-Angled Triangle of Numbers

Step 5: For i from 1 to 5:
    Step 5.1: For j from 1 to i:
        Print j
        End inner for loop
            Print newline
    End outer for loop

Pattern 4: Inverted Right-Angled Triangle

Step 6: For i from 1 to 5:
    Step 6.1: For j from i to 5:
        Print space
        End inner for loop
    Step 6.2: For j from i down to 1:
        Print j
        End inner for loop
         Print newline
    End outer for loop

Pattern 5: Pyramid of Letters

Step 7: For ch from 'A' to 'E':
    Step 7.1: For c from 'A' to ch:
        Print c
     Print newline

Pattern 6: Lowercase Letters Grid

Step 8: For ch from 'a' to 'e':
    Step 8.1: For c from 'a' to 'e':
        Print c
    Print newline

Pattern 7: Hollow Square

Step 9: For i from 1 to 8:
    Step 9.1: For j from 1 to 8:
        If i ==1 or i ==8 or j ==1 or j ==8:
            Print "*"
        Else:
            Print space
            End inner for loop
     Print newline
    End outer for loop

Pattern 8 : Right-Aligned Triangle of Asterisks

Step 10: For i = 1 to 6
    Step 10.1: For j = i to 6
        Print "*"
    End inner for loop
    Print New Line
End outer for loop

Pattern 9 : Pyramid Shape of Asterisks

Step 11: For i = 1 to 6
    Step 11.1: For j = i to 6
        Print " "  
    End inner for loop
    Step 11.2: For j = 1 to i // start another inner loop
        Print "*"
    End inner for loop
    Step 11.3: For j = 1 to i - 1 // start another inner loop
        Print "*"
    End inner for loop
    Print New Line
End outer loop

Pattern 10 : Inverted Pyramid Shape of Asterisks

Step 12: For i = 1 to 6
    Step 12.1: For j = 6 downto 1
        If i = 1 Or j = 6 Or i = j Then
            Print "*"
        Else
            Print " "
    End inner for loop
    Print New Line
End outer for loop

Pattern 11 : Hollow inverted Half pyramid

Step 13: For i = 1 to 6
    Step 13.1: For j = 6 downto 1
        If i = 1 Or j = 6 Or i = j Then
            Print "* " 
        Else
            Print "  "
    End inner for loop
    Print New Line
End outer for loop

Pattern 12: Hollow ful pyramid

Step 14: For i = 1 to 6
- Step 14.1: For j = i to 6
        Print " " // Print a space
    End inner for loop
- Step 14.2: For j = 1 to i // start another inner loop
        If j = 2 Or (i = 6 And j != 1) Then
            Print "*"
        Else
            Print " " // print space
        End inner for loop
- Step 14.3: For j = 1 to i // start another inner loop
        If j = i Or i = 6 Then
            Print "*"
        Else
            Print " " // print space
            End inner for loop
    Print New Line
End outer for loop

Step 15: Stop
