main: main.o frazioni.o
	gcc -g -o main main.o frazioni.o

main.o: main.c frazioni.h
	gcc -g -c main.c

frazioni.o: frazioni.c
	gcc -g -c frazioni.c