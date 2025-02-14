# Catalog Assessment

## Problem Statement

This project implements a simplified version of Shamir's Secret Sharing algorithm using Lagrange interpolation.

### Understanding the Polynomial
Consider an unknown polynomial of degree \( m \). To determine its coefficients, you need at least \( m+1 \) points, which is represented as \( k = m + 1 \). The polynomial can be expressed as:

\[ f(x) = a_m x^m + a_{m-1} x^{m-1} + \dots + a_1 x + c \]

Where:
- \( f(x) \) is the polynomial function.
- \( m \) is the degree of the polynomial.
- \( a_m, a_{m-1}, ..., a_1, c \) are real coefficients.
- \( a_m \neq 0 \) to ensure the polynomial is of degree \( m \).
- The constant term \( c \) is the secret value to be determined.

### Objective
The goal is to reconstruct the secret constant term \( c \) of the polynomial from the given data points, which are formatted in a specific way.

## Implementation

### Steps
1. **Parse JSON Test Case**: Read and decode a JSON file containing the keys and data points.
2. **Extract Points**: Convert data points into numerical format for interpolation.
3. **Apply Lagrange Interpolation**: Compute the polynomial's value at \( x = 0 \) to reveal the secret constant term \( c \).
4. **Output the Secret Code**: Compute and display the result for different test cases.

## How to Run the Project

### Prerequisites
- Node.js installed on your system.
- JSON test cases structured as:
  ```json
  {
    "keys": { "n": 5, "k": 3 },
    "1": { "value": "101", "base": "2" },
    "2": { "value": "12", "base": "10" },
    "3": { "value": "F", "base": "16" }
  }
  ```

### Running the Code
1. Clone the repository:
   ```sh
   git clone <repository-url>
   cd <repository-folder>
   ```
2. Install dependencies (if any required):
   ```sh
   npm install
   ```
3. Run the script:
   ```sh
   node script.js
   ```

## Expected Output
The program will output the secret codes for the provided test cases:
```
Secret code for Test Case 1: <computed_value>
Secret code for Test Case 2: <computed_value>
```

