/*
	File: test.cpp
	Author: Michael Clugston
	Date: 4/16/2025
	Uses the Matrix class defined in matrix.cpp to perform matrix operations
*/

#include "matrix.h"
#include <iostream>

int main() {

	Matrix A(2, 2);
	A.set(0, 0, 6);
	A.set(0, 1, 4);
	A.set(1, 0, 8);
	A.set(1, 1, 3);
	std::cout << "A =\n";
	A.printMatrix();

	Matrix B(2, 3);
	B.set(0, 0, 1);
	B.set(0, 1, 2);
	B.set(0, 2, 3);
	B.set(1, 0, 4);
	B.set(1, 1, 5);
	B.set(1, 2, 6);
	std::cout << "\nB =\n";
	B.printMatrix();

	Matrix C(2, 3);
	C.set(0, 0, 2);
	C.set(0, 1, 4);
	C.set(0, 2, 6);
	C.set(1, 0, 1);
	C.set(1, 1, 3);
	C.set(1, 2, 5);
	std::cout << "\nC =\n";
	C.printMatrix();

	Matrix B3 = 3 * B;
	std::cout << "\n3 * B =\n";
	B3.printMatrix();

	Matrix C_T = C.transpose();
	std::cout << "\nC^T =\n";
	C_T.printMatrix();

	Matrix B3C_T = B3 * C_T;
	std::cout << "\n(3 * B) * C^T =\n";
	B3C_T.printMatrix();

	Matrix AB3C_T = A + B3C_T;
	std::cout << "\nA + (3 * B) * C^T =\n";
	AB3C_T.printMatrix();

	std::cout << "\n(All operations in one line) D =\n";
	Matrix D = A + (3 * B) * C.transpose();
	D.printMatrix();

	return 0;
}