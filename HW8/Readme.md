Michael Clugston
UMBC CMSC313@1430 mon/wed
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
- 'make matrixTest' will create the runnable matrixTest from c++ code (matrix.h, matrix.cpp, test.cpp)
- 'make matrix.o' to create just the matrix.o dependency
- 'make matrixTestC' will create the runnable matrixTestC from c code (matrixC.h, matrixC.c, testC.c)
- 'make matrixC.o' to create just the matrixC.o dependency


Unit testing of every function ensures they operate as intended
