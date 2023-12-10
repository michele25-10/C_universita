main: main.o file1.o
	gcc -g -o main main.o file1.o

main.o: main.c file1.h
	gcc -g -c main.c

file1.o: file1.c
	gcc -g -c file1.c