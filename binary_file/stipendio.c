#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char nome[10];
    float stipendio; 
} Persona; 

Persona leggiel(){
    Persona e; 
    printf("\n");
    printf("Nome:\n");
    scanf("%s", e.nome);
    printf("Stipendio:\n");
    scanf(" %f", &e.stipendio);
    return e; 
}

int main(){
    Persona e; 
    FILE *fp;
    fp = fopen("stipendio.dat", "wb");
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