#include <stdio.h>
#include <stdlib.h>

#define DIM 30

typedef struct articolo{
    int codice; 
    char descrizione[DIM]; 
    float prezzo; 
}Articolo;

typedef struct lista{
    Articolo art; 
    struct lista* next; 
}Lista; 

typedef Lista* Listino; 

typedef struct codice{
    int codice; 
    struct codice *next;   
}Codice; 

typedef Codice *Codici; 

void popolamentoListino(Listino *l, FILE *fp); 

void popolamentoCodici(Codici *c); 

int contaArticoli(int codice, Codici c); 

Articolo ArticoloInfo(int codice, Listino l); 

void creazioneScontrino(Listino l, Codici c, FILE *scontrino);