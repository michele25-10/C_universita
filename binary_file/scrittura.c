#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char cognome[30];
    char nome[30];
    char sesso; 
    int anno;
} Persona; 

Persona leggiel(){
    Persona e; 
    printf("\n");
    printf("Cognome:\n");
    scanf("%s", e.cognome);
    printf("Nome:\n");
    scanf("%s", e.nome);
    printf("Sesso:\n");
    scanf(" %c", &e.sesso);
    printf("Anno nascita:\n");
    scanf("%d", &e.anno);
    return e; 
}

int main(){

    Persona e; 
    FILE *fp;
    fp = fopen("people.dat", "wb");
    if(fp == NULL){
        exit(-1);
    }
    int fine = 0; 
    while(fine == 0){
        e = leggiel(); 
        fwrite(&e, sizeof(Persona), 1, fp);
        printf("\nVuoi chiudere? (SI=1 NO=0)\n");
        scanf("%d", &fine); 
    }
    fclose(fp);
    return 0;
}