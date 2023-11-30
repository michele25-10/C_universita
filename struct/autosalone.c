#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIM 5

typedef struct {
    char marca[15]; 
    int cilindrata; 
    char anno[5]; 
    char nome; 
    char cognome; 
} Automobile;

void cercaMarca(Automobile salone[], char *marca){
    for(int i = 0; i < DIM; i++){
        if(strcmp(salone[i].marca, marca) == 0){
            printf("\n%s %d %s %s %s", salone[i].marca, salone[i].cilindrata, salone[i].anno, salone[i].nome, salone[i].cognome); 
        } 
    }
}

unsigned int nAutoAnno(Automobile salone[], char *anno){
    int count = 0;
        for(int i = 0; i < DIM; i++){
        if(strcmp(salone[i].anno, anno) == 0){
            count++;
        } 
    }
    return count;
}

void cercaCilindrata(Automobile salone[], int cilindrata){
    int count = 0;
    for(int i = 0; i < DIM; i++){
        if(salone[i].cilindrata <= cilindrata){
            count++; 
            printf("\n%s %d %s %s %s", salone[i].marca, salone[i].cilindrata, salone[i].anno, salone[i].nome, salone[i].cognome); 
        }
    }
    printf("\nNumero auto: %d", count); 
}

int main(){
    Automobile salone[DIM]; 

    for(int i = 0; i < DIM; i++){
        printf("\nInserisci marca: "); 
        scanf("%s", salone[i].marca); 
        printf("\nInserisci cilindrata: "); 
        scanf("%d", &salone[i].cilindrata); 
        printf("\nInserisci anno di immatricolazione: "); 
        scanf("%s", salone[i].anno); 
        printf("\nInserisci nome automobilista: ");
        scanf("%s", salone[i].nome); 
        printf("\nInserisci cognome automobilista: ");
        scanf("%s", salone[i].cognome); 
    }

    char marca[15];
    printf("\n\nCerca una marca: ");
    scanf("%s", marca);  
    cercaMarca(salone, marca);

    char anno[4];
    printf("\n\nCerca nell'anno: ");
    scanf("%s", anno);  
    printf("\nNumero auto immatricolate nel %s: %d", anno, nAutoAnno(salone, anno));

    int cilindrata; 
    printf("\n\nVisualizza le auto fino a quella cilindrata"); 
    scanf("%d", &cilindrata);
    cercaCilindrata(salone, cilindrata); 
    
    return 0; 
}