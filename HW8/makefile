mainCPP: matrix.o main.cpp
	g++ -Wall matrix.o main.cpp -o mainCPP

matrix.o: matrix.h matrix.cpp
	g++ -Wall -c matrix.cpp

val:
	valgrind -s ./mainCPP


mainC: matrixC.c
	gcc -Wall -std=c99 matrixC.c -o mainC

clean:
	rm *.o*
	rm *~
	rm vgcore*


