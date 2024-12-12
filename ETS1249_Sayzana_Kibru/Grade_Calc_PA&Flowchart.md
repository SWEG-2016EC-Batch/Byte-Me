## Problem Analysis

### Problem Description
The program calculates the grade of a student based on their performance in various assessments. It allows the input of multiple courses and computes the grade based on a total score derived from test, quiz, project, assignment, and final exam results. The program continues calculating grades until the user decides to stop.

### Inputs
* Student's name (string)
* Number of courses for the semester (integer)
* For each course:
  * Course name (string)
  * Test result (float, out of 15)
  * Quiz result (float, out of 5)
  * Project result (float, out of 20)
  * Assignment result (float, out of 10)
  * Final exam result (float, out of 50)
* Decision to continue (char: 'Y' or 'N')

### Outputs
* Student's name
* Course name
* Test, quiz, project, assignment, and final exam results
* Total marks (sum of all the assessments)
* Grade based on total marks (A+, A, B+, B, C+, C, D, F)
* Option to calculate for another student

### Processing Steps
1. **Input:** Prompt the user to input the student's name and the number of courses.
2. **Validation:** Validate the number of courses to ensure it's positive.
3. **Course Loop:**
   * For each course:
     * Prompt the user to input the course name and individual assessment scores.
     * Validate the assessment scores to ensure they are within the specified ranges.
     * Calculate the total marks by summing up all the assessment scores.
     * Determine the grade based on the total marks using a predefined grading scale.
     * Display the course name, individual scores, total marks, and grade.
4. **Loop:** Ask the user if they want to calculate the grades for another student. If yes, repeat from step 1. Otherwise, terminate the program.

5. ```mermaid
   flowchart TD
    Start[Start] --> InputDetails[Input Student Details]
    InputDetails --> CourseCount[Enter Number of Courses]
    CourseCount -->|Validate Size| Validation[Is Size Valid?]
    Validation -->|No| Error[Display Error and Retry]
    Validation -->|Yes| CourseLoop[For Each Course]
    CourseLoop --> InputCourseName[Input Course Name]
    InputCourseName --> InputTest[Input Test Result]
    InputTest -->|Invalid Input| ErrorTest[Display Error and Retry]
    InputTest --> InputQuiz[Input Quiz Result]
    InputQuiz -->|Invalid Input| ErrorQuiz[Display Error and Retry]
    InputQuiz --> InputProject[Input Project Result]
    InputProject -->|Invalid Input| ErrorProject[Display Error and Retry]
    InputProject --> InputAssignment[Input Assignment Result]
    InputAssignment -->|Invalid Input| ErrorAssignment[Display Error and Retry]
    InputAssignment --> InputFinalExam[Input Final Exam Result]
    InputFinalExam -->|Invalid Input| ErrorFinalExam[Display Error and Retry]
    InputFinalExam --> CalculateTotalMarks[Calculate Total Marks]
    CalculateTotalMarks --> DetermineGrade[Determine Grade Based on Marks]
    DetermineGrade --> DisplayResults[Display Course Results]
    DisplayResults --> Continue[Do You Want to Continue?]
    Continue -->|Y| InputDetails
    Continue -->|N| End[End]
   ```
