##### Chapter two practical questions:
Question 5: Design an algorithm and write a to read an employee name weekly working hours, bonus rate per hour and base salary and find the employees gross-salary, net salary and bonus payment. (Hint: pension rate – 5%,tax: 15%).
So breaking down the problem that has been given into :
##### 1.1 Input:
- Weekly Working Hours
- Base Salary
- Bonus Rate 

##### 1.2 Output:
- Gross salary 
- Net –salary 
- Bonus payment  
 
##### 1.3	process:
-  Bonus Calculation: Multiply the weekly working hours by the bonus rate to calculate the bonus payment.
-  Gross Salary Calculation: Add the base salary and the bonus payment to calculate the gross salary.
-  Deduction Calculation: Compute pension as 5% of the gross salary and Compute tax as 15% of the gross salary.
- Net Salary Calculation: Subtract the pension and tax from the gross salary to get the net salary.
 After this process to make this easy to code and compile let me write the pseudocode (false code)
##### 1.4	pseudocode:
- step 1:Start.
- Step 2:Enter Employee's name ,Weekly working hours ,Bonus rate per hour ,Base salary .
- Step 3:Calculate Bonus Payment with calculation
-	BonusPayment=HoursWorked*BonusRate
- Step 4:Calculate Gross Salary:with calculation
- GrossSalary=BaseSalary+BonusPayment
- Step 5:Calculate Deductions(which is pension and Tax)
-	Pension: Pension=GrossSalary×0.05
- Tax: Tax=GrossSalary×0.15
- Step 6: Calculate Net Salary:
- NetSalary=GrossSalary−(Pension+Tax)
- Step 7:Display the employee's name along with GrossSalary, BonusPayment, Pension, Tax, and NetSalary.
- Step 8: stop
 

