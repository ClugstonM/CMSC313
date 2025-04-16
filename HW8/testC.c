
#include <stdio.h>
#include <stdlib.h>
#include "matrixC.h"

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
	printf("\nB:\n");
	printMatrix(B, 2, 3);

	int* C = mallocMatrix(2, 3);
	C[0] = 2;
	C[1] = 4;
	C[2] = 6;
	C[3] = 1;
	C[4] = 3;
	C[5] = 5;
	printf("\nC:\n");
	printMatrix(C, 2, 3);

	int* C_T = transpose(C, 2, 3);
	printf("\nC^T:\n");
	printMatrix(C_T, 3, 2);

	int* B3 = scalarMultiply(B, 2, 3, 3);
	printf("\n3 * B:\n");
	printMatrix(B3, 2, 3);

	int* B3C_T = matrixMultiply(B3, 2, 3, C_T, 3, 2);
	printf("\n(3 * B) * C^T:\n");
	printMatrix(B3C_T, 2, 2);

	int* D = matrixAdd(A, B3C_T, 2, 2);
	printf("\nA + (3 * B) * C^T:\n");
	printMatrix(D, 2, 2);

	free(A);
	free(B);
	free(C);
	free(C_T);
	free(B3);
	free(B3C_T);
	free(D);

	return 0;
}