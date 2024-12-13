##### /*Develop a program that find the Net-Pay of an employee after deduction of pension (7%) and tax based on tax rate provided. 
The program should read the basic salary, worked hours, and bonus rate. If the employee worked hours exceed 40 hrs., 
the program prompts the user to enter an over-time bonus rate/hour.*/
##### Problem analysis :
Input:
- Basic salary 
- Worked hours 
- Bonus hours

##### Output:
- Net pay
- Bonus pay
- pension 
- Tax (with the right amount of tax rate)

##### Process:
- Bonus pay=rate*bonus hour
- Pension=basic salary*0.07
- Tax=basic salary with right amount of rate 
- Net pay=Basic salary - tax - pension + Bonus pay

##### Pseudocode 
- step 1:Start.
- Step 2:Enter Employee's name ,Weekly working hours  , Basic salary
- Step 3:If working hour is greater than 40 ask the user to enter bonus rate 
- Bonus payment =working hour *bonus rate 
- Else working bonus payment  is 0
-  Step 4:Calculate gross salary 
- Gross salary=basic salary +bonus payment 
- Step 5:Calculate Deductions(which is pension and Tax)
-  Pension: Pension= Basic salary ×0.05
- step 6:If Basic salary is up to 200birr there is no tax deduction tax =0%
-    Else if the Basic salary is in between 200-600birr tax-rate=0.1
-    Else if the Basic salary is in between 600-1200birr tax-rate=0.15
-    Else if the Basic salary is in between 1200-2000birr tax-rate=0.2
-    Else if the Basic salary is in between 2000-3500 birr tax-rate=0.25
-    Else if the Basic salary is in between 3500 and above tax-rate =0.3
-  Tax= Gross salary × tax-rate
- Step 7: Calculate Net Salary:
- Net pay=Basic salary - tax - pension + Bonus pay
- Step 8:Display the employee's name along with Basic salary, Net Pay, Pension, Tax
- Step 9: stop
