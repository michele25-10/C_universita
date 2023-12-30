#include <stdlib.h>
#include <stdio.h>

typedef int Dato; 

typedef struct nodo{
    Dato dato; 
    struct nodo* next; 
}Nodo; 

typedef Nodo* Lista; 

Lista* ultimoNodo(Lista *l); 

void insTesta(Lista *l, Dato valore); 

void insCodaLista(Lista *l, Dato valore); 

int lunghezzaLista(Lista l);

int sommaElementiLista(Lista l); 

void Stampa(Lista l);

void eliminazioneElementoLista(Lista l, int delNumber);
