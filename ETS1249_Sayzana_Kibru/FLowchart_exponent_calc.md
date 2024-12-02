```mermaid
 graph TD
    A[Start] --> B[Set result = 1]
    B --> C[Input base and exponent]
    C --> D{Is input valid?}
    D -->|No| E[Decrement count by 1]
    E --> F{Is count > 0?}
    F -->|Yes| G[Output-Invalid input, retry]
    G --> C
    F -->|No| H[Output-No more trials left, exiting program]
    H --> I[End]
    D -->|Yes| J[For i = 1 to exp, multiply result by base]
    J --> K[Output base raised to exp and result]
    K --> L[Ask Continue using the program?]
    L --> M{Is preference Y or y?}
    M -->|Yes| B
    M -->|No| N[End]
```
