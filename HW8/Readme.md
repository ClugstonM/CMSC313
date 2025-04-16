Michael Clugston  
UMBC  
CMSC313@1430 mon/wed  
HW#8  

This subdirectory contains files for a matrix library in both c and c++


1. matrixC.h : function declarations for matrixC library
2. matrixC.c : implementation of functions declared in matrixC.h
3. testC.c : test code for matrixC library, including the provided equation
4. matrix.h : declarations of members for Matrix class
5. matrix.cpp : implementation of members declared in matrix.h
6. test.cpp : test code for the Matrix class, including the provided equation
7. makefile : makefile commands for compiling both programs


To build using the makefile: 
- 'make matrixTest' will create the executable matrixTest from c++ code (matrix.h, matrix.cpp, test.cpp)
- 'make matrix.o' will create only the matrix.o dependency
- 'make matrixTestC' will create the executable matrixTestC from c code (matrixC.h, matrixC.c, testC.c)
- 'make matrixC.o' will create only the matrixC.o dependency


The c++ implementation uses a Matrix class with a 2D vector of integers and two integers for rows and columns as members. It makes use of overloaded operators for many of its behaviors.  
The c implementation exclusively uses functions that operate on a large 1D dynamically allocated integer array of size rows * columns and take two integers for the rows and columns of the corresponding matrix. The functions handle memory allocation, but remembering the dimensions of the matrix and memory deallocation are both expected to be handled by the user.
