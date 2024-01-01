#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define DIM 30

typedef struct nodo{
    char parola[DIM]; 
    struct nodo* next; 
}Nodo; 

typedef Nodo* Lista; 

void toLower(char *str);

void insTesta(Lista *l, char *str);

int checkPresenza(Lista *lista, char *str);

void salvataggioContenutoFile(char *nameFile, Lista *ParoleDaEvitare, Lista *contenutoFile);

void listaStringheAscendente(Lista *stringhe, Lista *stringheNoDoppioni); 

int countStringa(Lista stringhe, char *str); 

void Stampa(Lista stringhe, Lista stringheNoDoppioni);