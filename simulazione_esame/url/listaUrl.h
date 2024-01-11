#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//struttura contenuta nel dile dat
typedef struct visite{
    char url[100];
    int ora; 
    int minuti; 
}Visite; 

//struct della lista contente info delle views
typedef struct info{
    char url[100];
    int views;
    int ora; 
    int minuti; 
    struct info* next; 
} Info; 

typedef Info* Lista; 

Info* ricercaURL(Lista *c, char *url); 

void insTesta(Lista *c, Visite r); 

void popolamentoLista(Lista *c, FILE *v); 

void stampa(Lista c);

void listaOrdinataViewsDrecrescente(Lista *c); 
