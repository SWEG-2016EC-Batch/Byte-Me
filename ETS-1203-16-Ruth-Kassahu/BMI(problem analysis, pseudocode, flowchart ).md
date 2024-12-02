##### Question :
   Make a program that calculates the Body Mass Index (BMI) of a person and determine weather the person is in normal weight, under weight or over weight. BMI is calculated as (BMI = w/h*h). Make the program to work for multiple person before terminated.
##### Problem analysis :

### 1.1Input:
-Height of the person
-Wieght of the person

### 1.2 Output:
BMI of the person 
 
### 1.3 process:
-	Taking the height and weight from the input to calculate 
```	BMI=Weight/Height*Height.
```
-	If the person has BMI of less than or equal to 18 the person is underweight 
-	If the person has BMI from 18 to 24 the person is under normal weight
-	If the person has BMI of 24 and above then the person is over weight (obese)
-	Asking if the person wants to enter another person’s height and weight to calculate their BMI (Enter 0 to terminate other number to continue)
After this process to make this easy to code and compile let me write the pseudocode (false code)

#####  pseudocode:
-  Step 1:start 
-  Step 2: enter the height of the person that you want to calculate the BMI of
-  Step 3:enter the weight of the person that you want to calculate the BMI of
-  Step 4:BMI← Weight/(Height*Height)
-  step 5 :If BMI is greater or equal to 24,c="You are over weight"
-  step 6:If BMI is less than or eqaul to 18,c="You are under weight "
-  step 7:Else c="You are have normal BMI" 
-  Step 8:print BMI and 'c'
-  Step 9:Enter 0 if you want to terminate other number if you want to continue and add another person’s height and weight /*Ask if the person wants to enter anothers person height and weight to calculate BMI of another person */
-  Step 10:If the numbered entered is different from zero go to step 2
-  Step 11:else print you have finished calculating 
-  Step 12: stop

##### 1.5 Flow chart


