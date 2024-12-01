flowchart TD
    A[Start] --> B[Input number of persons (size)]
    B --> C{Is i <= size?}
    C -- Yes --> D[Input weight and height of person i]
    D --> E[Calculate BMI as weight / (height * height)]
    E --> F[Output BMI]
    F --> G{BMI Category}
    G -- Underweight (BMI < 18.5) --> H[Output "Underweight"]
    G -- Healthy (18.5 <= BMI < 25) --> I[Output "Healthy weight range"]
    G -- Overweight (25 <= BMI < 30) --> J[Output "Overweight"]
    G -- Obese (BMI >= 30) --> K[Output "Obese"]
    H --> L[Increment i]
    I --> L
    J --> L
    K --> L
    L --> C
    C -- No --> M[End]
