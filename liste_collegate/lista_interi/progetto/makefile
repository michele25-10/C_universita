main: lista_interi.o liste.o
	gcc -g -o main lista_interi.o liste.o

lista_interi.o: lista_interi.c liste.h
	gcc -g -c lista_interi.c

liste.o: liste.c liste.h
	gcc -g -c liste.c