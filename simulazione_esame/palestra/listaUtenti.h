#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct persona{
    char CF[17]; 
    int ingresso1;
    int ingresso2;
    int ingresso3; 
    int n_errori; 
    unsigned short int abilitato; 
    struct persona* next; 
} Persona; 

typedef Persona* Iscritti; 

void insTesta(Iscritti *i, char *codicefiscale, int in1, int in2, int in3, int n_err, unsigned short int abilitato);

void popolamentoIscritti(Iscritti *i, FILE *cf);

Persona* ricerca(Iscritti *i, char *cf); 

int ingresso(int n_ingressi, char *cf, char* last_cf, int *count_error, int tipo_attivita); 

void controlloIngressi(Iscritti *i, FILE *ing); 

void stampaIngressiResidui(Iscritti i); 
