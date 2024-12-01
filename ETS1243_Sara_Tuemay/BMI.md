##### Make a program that calculates the Body Mass Index (BMI) of a person and determine weather the person is in normal weight, under weight or over weight. BMI is calculated as (BMI = w/h*h). Make the program to work for multiple person before terminated.

##### Problem analysis

*Input*
-	Height in meter
-	Weight in kilogram

Output 
-	BMI

OperationProblem analysis
Input 
-	Height in meter
-	Weight in kilogram
Output 
-	BMI
Operation
BMI = weight/(height * height)

#### PSEUDO CODE

Step 1: Start

Step 2: Read height in meter

Step 3: Read weight in kilograms

Step 4: Calculate BMI
```
            BMI = weight / height * height
```

Step 5: Print BMI

Step 6: Check if BMI is less than 18.5

Step 6.1: If true 
```
                    Print "You are underweight"
```

Step 6.2: Go to step 8

Step 6.3: Else go to step 7
Step 7: Check if BMI >= 18.5 and BMI < 24.9
Step 7.1: If true 
```
                     Print "You are in normal weight"
```
Step 7.2: Else 
```
                    Print "You are overweight"
```
Step 8: Stop

##### Flow Chart
![BMI](./BMI.drawio%20(1).png)
