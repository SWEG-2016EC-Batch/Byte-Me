Problem Analysis for Salary Calculation Program
The program aims to calculate the salary details for an employee, considering the following inputs:

Weekly Working Hours: This is the total number of hours the employee worked in a week.
Base Salary: This is the fixed amount the employee earns per week, regardless of the number of hours worked.
Bonus Rate: This is the additional amount paid per hour worked.

Steps Involved:
Bonus Calculation: The bonus is calculated by multiplying the weekly_working_hours by the bonus_rate.
Gross Salary: The total amount earned by the employee, including the base salary and the bonus, is calculated by adding the base_salary to the bonus_payment.
Tax Deduction: A tax of 15% is deducted from the gross salary.
Pension Deduction: A pension deduction of 5% is applied on the base salary.
Net Salary: The final salary after the tax and pension deductions is calculated.


The goal is to compute and display:

Gross Salary: The total earnings before deductions.
Bonus Payment: The extra earnings based on the hours worked.
Net Salary: The earnings after tax and pension deductions.
Inputs:
Weekly working hours (e.g., 40 hours)
Base salary (e.g., 5000 Birr)
Bonus rate per hour worked (e.g., 50 Birr)

Outputs:
Gross salary (e.g., 6000 Birr)
Bonus payment (e.g., 2000 Birr)
Net salary after tax and pension deductions (e.g., 5100 Birr)
Assumptions:
The program assumes the user inputs valid numeric values for weekly working hours, base salary, and bonus rate.
The tax and pension rates are fixed constants (15% and 5% respectively) and cannot be modified by the user.

This program efficiently calculates the salary details based on simple mathematical operations. It provides essential information to both the employee and the employer regarding the gross earnings, bonus, and the final net salary after deductions.

# Pseudocode for Salary Calculation Program

1. **Start**
2. **Define constants**:
   - `Tax_Rate = 0.15`
   - `Pension_Rate = 0.05`

3. **Input**:
   - Prompt user to input `weekly_working_hours`
   - Prompt user to input `base_salary`
   - Prompt user to input `bonus_rate`

4. **Calculate**:
   - `bonus_payment = weekly_working_hours * bonus_rate`
   - `gross_salary = base_salary + bonus_payment`
   - `net_salary = gross_salary - (gross_salary * Tax_Rate) - (base_salary * Pension_Rate)`

5. **Output**:
   - Display `Gross Salary: gross_salary`
   - Display `Bonus Payment: bonus_payment`
   - Display `Net Salary: net_salary`

6. **End**
