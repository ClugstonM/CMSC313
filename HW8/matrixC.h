#ifndef MATRIX_H
#define MATRIX_H

int* mallocMatrix(int rows, int cols);
int matrixGet(int* matrix, int rows, int cols, int row, int col);
void matrixSet(int* matrix, int rows, int cols, int row, int col, int val);
int* transpose(int* matrix, int rows, int cols);
int* scalarMultiply(int* matrix, int rows, int cols, int scalar);
int* matrixAdd(int* matrix1, int* matrix2, int rows, int cols);
int* matrixMultiply(int* matrix1, int rows1, int cols1, int* matrix2, int rows2, int cols2);
void printMatrix(int* matrix, int rows, int cols);


#endif