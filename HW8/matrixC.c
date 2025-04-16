/*
	File: matrixC.c
	Author: Michael Clugston
	Date: 4/16/2025
	Uses functions with 1D arrays to perform matrix operations
*/

#include <stdio.h>
#include <stdlib.h>

// Matrix is represented in one long array
int* mallocMatrix(int rows, int cols) {
	int* output = malloc(rows * cols * sizeof(int));
	return output;
}

// Returns the transpose of a matrix
int* transpose(int* matrix, int rows, int cols) {

	int* output = malloc(rows * cols * sizeof(int));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			output[(rows * j + i)] = matrix[(cols * i + j)];
		}
	}

	return output;
}

// Returns a scaled matrix
int* scalarMultiply(int* matrix, int rows, int cols, int scalar) {
	int* output = malloc(rows * cols * sizeof(int));
	
	for (int i = 0; i < rows * cols; i++) {
		output[i] = matrix[i] * scalar;
	}

	return output;
}

// Returns the sum of two matrices
// Sizes of matrices must be identical
int* matrixAdd(int* matrix1, int* matrix2, int rows, int cols) {
	int* output = malloc(rows * cols * sizeof(int));
	
	for (int i = 0; i < rows * cols; i++) {
		output[i] = matrix1[i] + matrix2[i];
	}

	return output;
}

// Returns the matrix product of two matrices
// #cols of matrix1 must equal #rows of matrix2
int* matrixMultiply(int* matrix1, int rows1, int cols1, int* matrix2, int rows2, int cols2) {
	if (cols1 != rows2) {
		return NULL;
	}

	int* output = malloc(rows1 * cols2 * sizeof(int));
	int sumOfRow = 0;

	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols2; j++) {
			for (int k = 0; k < rows2; k++) {
				sumOfRow += (matrix1[cols1 * i + k] * matrix2[cols2 * k + j]);

			}
			output[rows1 * i + j] = sumOfRow;
			sumOfRow = 0;
		}
	}



	return output;
}

void printMatrix(int* matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", matrix[(cols * i + j)]);
		}
		printf("\n");
	}
}

int main() {

	int* A = mallocMatrix(2, 2);
	A[0] = 6;
	A[1] = 4;
	A[2] = 8;
	A[3] = 3;
	printf("A:\n");
	printMatrix(A, 2, 2);

	int* B = mallocMatrix(2, 3);
	B[0] = 1;
	B[1] = 2;
	B[2] = 3;
	B[3] = 4;
	B[4] = 5;
	B[5] = 6;
	printf("B:\n");
	printMatrix(B, 2, 3);

	int* C = mallocMatrix(2, 3);
	C[0] = 2;
	C[1] = 4;
	C[2] = 6;
	C[3] = 1;
	C[4] = 3;
	C[5] = 5;
	printf("C:\n");
	printMatrix(C, 2, 3);

	int* C_T = transpose(C, 2, 3);
	printf("C^T:\n");
	printMatrix(C_T, 3, 2);

	int* B3 = scalarMultiply(B, 2, 3, 3);
	printf("3 * B:\n");
	printMatrix(B3, 2, 3);

	int* B3C_T = matrixMultiply(B3, 2, 3, C_T, 3, 2);
	printf("(3 * B) * C^T:\n");
	printMatrix(B3C_T, 2, 2);

	int* D = matrixAdd(A, B3C_T, 2, 2);
	printf("A + (3 * B) * C^T:\n");
	printMatrix(D, 2, 2);

	return 0;
}
