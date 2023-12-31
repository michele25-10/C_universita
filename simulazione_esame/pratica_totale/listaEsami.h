#include <stdlib.h>
#include <stdio.h>

typedef struct esame{
    int matricola; 
    int punteggio; 
    char tipo; 
} Esame; 

typedef struct nodo{
    int matricola; 
    int punteggio; 
    struct nodo* next; 
}Nodo; 

typedef Nodo *Lista; 

int checkEsitoEsame(int punteggio, char tipo); 

void insTesta(Lista *l, int matricola, int punteggio, char tipo); 

int ricerca(Lista l, int matricola); 

void aggiornamentoPunteggio(Lista *l, int matricola, int punteggio, int tipo); 

void stampaLista(Lista l); 

void stampaEsitiEsami(Lista l); 

void listaDecrescente(Lista *l); 