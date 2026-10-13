# Matrix Determinant Calculator

This simple CLI program implements a function that accepts a 2-dimensional vector of numbers as a mathematical square matrix, and returns its determinant value.

### Why did I make this

Learning basic C++ programming and math in general.

### Compile command

```
g++ (cat compile_flags.txt) src/main.cpp -o build/matrixDet
```

### How I made this

All the helper functions (printMatrix, getDeterminant and isSquareMatrix) are all entirely hand-written, by hand. I used AI to write testing/main.cpp as a unit test of the helper functions.

The executable compiled from testing/main.cpp takes the build/testCases.txt file, reads the test cases and completes them using my hand-written helper functions.

In other words, made the actual project myself, delegated the testing to AI.