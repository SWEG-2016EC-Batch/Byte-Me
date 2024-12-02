-  Question 6: A serial transmission line can transmit 960 characters a second. Write a program that will calculate how long it will take to send a file, given the file size.
 Test your program on a 400MB (419,430,400 byte) file which may take days. 
 - So breaking down the problem that has been given into:

1.1 Input:
- Enter the file size that you want to send.
1.2 Output:
- The time that its going to take for you to transfer the file.
1.3 process:
- Take the entered value (file size) then Multiply it to the number of bytes in 1 MB.
- Then divide the total file size by time that its going to take to send 1 MB file .
- After this process to make this easy to code and compile let me write the pseudocode .

1.4 pseudocode:
- Step 1:Start
- Step 2 Enter the file size that you want to send(size).
- Step 3 1MB=1,048,576byte.
- Step 4: Total size =size* 1 MB.
- Step 5:Speed =Total size /960 (to find the speed of some file we use this as calculation)
- Step 6:Display speed
- Step 7: Display speed /60 (in minute)
- Step 8:Display speed (in minute)/60 (hour)
- Step 9: stop
// to make the displaying a little understandable for people that is going to use it its going to be displayed in second ,minute ,hours
