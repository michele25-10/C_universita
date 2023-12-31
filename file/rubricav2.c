#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIM 50

typedef struct {
    char nome[20];
    char cognome[20];
    char tel[10];
} Contatto;

void inserisciNuovoContatto(Contatto r[], int numero){
    for(int i = 0; i < numero; i++){
        printf("\nInserisci nome: \n");
        scanf("%s", r[i].nome);
        printf("\nInserisci cognome: \n");
        scanf("%s", r[i].cognome);
        printf("\nInserisci numero di telefono: \n");
        scanf("%s", r[i].tel);
    }
}

void riordina(Contatto* r, int numero){
    Contatto tmp; 
    for(int i = 0; i < numero - 1; i++){
        for(int k = i + 1; k < numero; k++){
            for(int l = 0; l < strlen(r[i].cognome) && l < strlen(r[k].cognome); l++){
                if(r[k].cognome[l] < r[i].cognome[l]){
                    strcpy(tmp.nome, r[i].nome);
                    strcpy(tmp.cognome, r[i].cognome);
                    strcpy(tmp.tel, r[i].tel);
                    strcpy(r[i].nome, r[k].nome);
                    strcpy(r[i].cognome, r[k].cognome);
                    strcpy(r[i].tel, r[k].tel);
                    strcpy(r[k].nome, tmp.nome);
                    strcpy(r[k].cognome, tmp.cognome);
                    strcpy(r[k].tel, tmp.tel);
                    break; 
                } else if(r[k].cognome[l] == r[i].cognome[l]){
                    continue;
                }else{
                    break; 
                }
            }
        }
    }
}

int main(){
    int numero;
    printf("Quanti contatti vuoi inserire: ");
    scanf("%d", &numero);

    Contatto rubrica[numero];
    inserisciNuovoContatto(rubrica, numero);

    riordina(rubrica, numero);

    FILE *fp; 
    fp = fopen("rubrica.txt", "wt");
    if(fp == NULL){
        printf("Errore");
        exit(-1); 
    }

    for(int i = 0; i < numero; i++){
        fprintf(fp, "%s %s %s\n", rubrica[i].nome, rubrica[i].cognome, rubrica[i].tel);
    }

    fclose(fp);

    return 0;
}