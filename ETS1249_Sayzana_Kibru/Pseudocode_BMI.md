Problem analysis for BMI Calculator:
 The purpose of this code is to calculate the BMI (Body Mass Index) for multiple people based on their weight and height. The program categorizes individuals into different weight categories (underweight, healthy weight, overweight, obese) based on their BMI value.


Design Considerations:
The program accepts multiple entries for BMI calculations in a loop, enhancing its usability.
The logic for categorizing BMI values into different weight categories is straightforward, making the code easy to maintain and modify.

# Pseudocode for BMI Calculator

**Start**

1. **Input**: Ask the user to enter the number of persons (`size`) for whom BMI needs to be calculated.
   
2. **Loop**: For each person from `1` to `size`:
   - Prompt the user to enter the `weight` (in kilograms) and `height` (in meters) of the person.
   - Calculate BMI using the formula:
    **bmi = weight/(height*height)**
   - Print the BMI value rounded to two decimal places.

3. **Classification**: Based on the BMI value:
   - If BMI < 18.5, print "Underweight."
   - Else if BMI >= 18.5 and BMI < 25, print "Healthy weight range."
   - Else if BMI >= 25 and BMI < 30, print "Overweight."
   - Else, print "Obese."

4. Repeat Step 2 and Step 3 for all persons.

5. Print a completion message after all BMI calculations are done.

**End**
