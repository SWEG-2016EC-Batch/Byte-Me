### Problem Analysis
**Input**
-Fuel amount in fuel tank in gallon
-Miles driven per gallon

**Output**
-Total miles driven with out refueling

**Operation**
-Total miles = Fuel amount in fuel tank * miles driven per gallon

### Pseudo Code

Step 1: Start
Step 2: Read Fuel amount in gallon
Step 3: check if input fail 
```
     Step 3.1: if true
                    print "Wrong input"
                    go to step 
    Step 3.2: else
                   go to step 4 
```
Step 4: Read miles driven per gallon
Step 5: Check if input fails
```
    Step 5.1: if true
                    print "Wrong input"
    Step 5.2: else 
                    go to step 6 
```
Step 6: Calculate total miles driven
```
                    total miles driven = fuel amount * miles driven per gallon
```

Step 7: Print total miles driven
Step 8: Prompt user if s/he wants to continue
Step 9: Read decision
```
        Step 9.1: check if decision != '0'
               Step 9.1.1: if true
                                 go to step 2
              Step 9.1.2: else
                                 go to step 10
```
Step 10: Stop

### Flow Chart
![Automobile Capacity](./automobile_capacity.png)