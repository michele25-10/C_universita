scontrini: main.o listino.o
	gcc -g -o scontrini main.o listino.o

listino.o: listino.c listino.h
	gcc -g -c listino.c

main.o: main.c listino.h
	gcc -g -c main.c