#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIM 31

typedef struct etichetta{
    char nome[DIM]; 
    float calorie; 
}Etichetta; 

typedef struct recordcalorico{
    Etichetta cibo; 
    struct recordcalorico* next; 
}RecordCalorico; 

typedef RecordCalorico* TabellaCalorie; 

typedef struct pasto{
    char nome[DIM]; 
    int grammi; 
    struct pasto* next; 
} Pasto;

typedef Pasto* Pasti; 

void insTestaCalorie(TabellaCalorie *tc, Etichetta e); 

void popolamentoPasti(FILE *fp, Pasti *p); 

float ricercaEtichetta(TabellaCalorie tc, char *nome); 

float calcoloCalorie(Pasti p, TabellaCalorie tc); 
