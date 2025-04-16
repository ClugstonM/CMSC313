matrixTest: matrix.o test.cpp
	g++ -Wall matrix.o test.cpp -o matrixTest

matrix.o: matrix.h matrix.cpp
	g++ -Wall -c matrix.cpp


matrixTestC: matrixC.o
	gcc -Wall -std=c99 matrixC.o testC.c -o matrixTestC

matrixC.o: matrixC.h matrixC.c
	gcc -Wall -std=c99 -c matrixC.c