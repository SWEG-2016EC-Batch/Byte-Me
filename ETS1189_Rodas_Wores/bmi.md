//Problem Analysis and Algorithm Design for 1st question
- Question
- Make a program that calculates the Body Mass Index (BMI) of a person and determine weather the person is in normal weight, under weight or over weight. BMI is calculated as (BMI = w/h*h). Make the program to work for multiple person before terminated.

- Problem analysis

1,Input:
- Height of the person 
- Weight of the person

2,Output:
- BMI of the person

3, process:
- Taking the height and weight from the input to calculate
- If the person has BMI of less than or equal to 18.5 the person is underweight
- If the person has BMI from 18.5 to 24.9 the person has normal weight
- If the person has BMI from 25 to 29.9 then the person is over weight 
- If the person has BMI morethan 30 the the person is obese
- Asking if the person wants to enter another person’s height and weight to calculate their BMI (Enter 0 to terminate, other number to continue)
- After this process to make this easy to code and compile let me write the pseudocode (false code)

  - pseudocode:

- Step 1:start
- Step 2: enter your height
- Step 3:enter your weight
- Step 4:BMI← Weight/(Height*Height)
- Step 5:print BMI
- Step 6:Enter 0 if you want to terminate, other number if you want to continue and add another person’s height and weight /*Ask if the person wants to enter anothers person height and weight to calculate BMI of another person */
- Step 7:If the numbered entered is different from zero go to step 2
- Step 8:else print you have finished calculating
- Step 9: stop
