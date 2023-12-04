#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIM 20

typedef struct {
    char nome[DIM];
    char cognome[DIM];
    int matricola;
} studente;

void riordina(studente *studenti, int count){
    studente tmp; 
    for(int i = 0; i < count; i++){
        for(int j = i; j < count; j++){
            if(studenti[i].matricola < studenti[j].matricola){
                tmp.matricola = studenti[i].matricola; 
                strcpy(tmp.nome, studenti[i].nome);
                strcpy(tmp.cognome, studenti[i].cognome);
                studenti[i].matricola = studenti[j].matricola;
                strcpy(studenti[i].nome, studenti[j].nome);
                strcpy(studenti[i].cognome, studenti[j].cognome);
                studenti[j].matricola = tmp.matricola;
                strcpy(studenti[j].nome, tmp.nome);
                strcpy(studenti[j].cognome, tmp.cognome);
            }
        }
    }
}

int main(){
    FILE *fp; 
    fp = fopen("nomi.txt", "r");
    if(fp == NULL){
        printf("Documento non esistente");
        exit(-1);
    }

    studente studenti[DIM];
    int count = 0;
    while(feof(fp) != 0){
        fscanf(fp, "%s %s %d", studenti[count].nome, studenti[count].cognome, studenti[count].matricola);
        count++; 
    }

    fclose(fp);

    riordina(studenti, count);
    FILE *ordinati;
    ordinati = fopen("ordinati.txt", "wt");
    if(ordinati == NULL){
        printf("Documento non esistente");
        exit(-1);
    }

    for(int k = 0; k < count; k++){
        fprintf(ordinati, "%s %s %d\n", studenti[k].nome, studenti[k].cognome, studenti[k].matricola);
    }

    fclose(ordinati);

    printf("TERMINATO\n");

    return 0;
}