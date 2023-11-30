#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIM 50

typedef struct {
    char nome[20];
    char cognome[20];
    char tel[10];
} Contatto;

void stampaRubrica(Contatto r[], int dl){
    for(int i = 0; i < dl; i++){
        printf("\n%s %s \t%s ", r[i].nome, r[i].cognome, r[i].tel);
    }
}

void inserisciNuovoContatto(Contatto r[], int dl){
    printf("\nInserisci nome: \n");
    scanf("%s", r[dl].nome);
    printf("\nInserisci cognome: \n");
    scanf("%s", r[dl].cognome);
    printf("\nInserisci numero di telefono: \n");
    scanf("%s", r[dl].tel);
}

void stampaContatto(Contatto r){
    printf("\n%s %s \t%s\n", r.nome, r.cognome, r.tel);
}

void cercaContatto(Contatto* r, int dl){
    printf("\nInserisci nome: \n");
    char nome[20];
    scanf("%s", nome);
    printf("Inserisci cognome: \n");
    char cognome[20];
    scanf("%s", cognome);
    for(int i = 0; i < dl; i++){
        if(strcmp(r[i].nome, nome) == 0 && strcmp(r[i].cognome, cognome) == 0){
            stampaContatto(r[i]);
        }
    }
}

int main(){
    char c;
    Contatto rubrica[DIM];
    int count = 0;
    printf("\nCosa vuoi fare (q per uscire)?");
    printf("\n\ta. Stampa l'intera rubrica");
    printf("\n\tb. Inserisci un nuovo contatto in rubrica");
    printf("\n\tc. Cerca un contatto in rubrica\n");
    scanf(" %c", &c);
    while(c != 'q' && count <= DIM){
        switch(c){
            case 'a':
                stampaRubrica(rubrica, count);
                break; 

            case 'b':
                inserisciNuovoContatto(rubrica, count);
                count++;
                break; 

            case 'c':
                cercaContatto(rubrica, count);
                break;
        }    

        printf("\nCosa vuoi fare (q per uscire)?");
        printf("\n\ta. Stampa l'intera rubrica");
        printf("\n\tb. Inserisci un nuovo contatto in rubrica");
        printf("\n\tc. Cerca un contatto in rubrica\n");
        scanf(" %c", &c);
    }

    return 0;
}