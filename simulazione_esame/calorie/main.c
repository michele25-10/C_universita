#include "funzioni.h"

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Mancano argomenti\n"); 
        exit(-1); 
    }

    TabellaCalorie tc = NULL; 
    Etichetta e; 

    FILE *fc = fopen(argv[1], "rb"); 
    if(fc == NULL){
        exit(-1); 
    }

    while(fread(&e, sizeof(Etichetta), 1, fc)){
        insTestaCalorie(&tc, e); 
    }
    fclose(fc); 

    FILE *fp = fopen(argv[2], "r"); 
    if(fp == NULL){
        exit(-1); 
    }
    Pasti p = NULL; 

    popolamentoPasti(fp, &p); 
    fclose(fp); 

    printf("\nLe calorie di questi pasti sono le seguenti: %.2f\n", calcoloCalorie(p, tc)); 

    return 0;
}