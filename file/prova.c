#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIM 30

int main(){
    FILE *fp;
    fp = fopen("prova.txt", "w+t");
    if(fp == NULL){
        printf("\nFile prova.txt non trovato\n");
        exit(-1);
    }

    char str[DIM];

    printf("\nInserisci le parole da mettere nel file txt, finchè non inserisci la parola 'fine'");
    scanf("%s", str);

    while(strcmp(str, "fine") != 0){
        fprintf(fp, "%s\n", str);

        printf("\nInserisci le parole da mettere nel file txt: ");
        scanf("%s", str);
    }

    fclose(fp);

    printf("\nFATTO\n");

    return 0;
}
