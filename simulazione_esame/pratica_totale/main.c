#include "listaEsami.h"

int main(int argc, char *argv[]){

    /*if(argc != 2){
        exit(-1); 
    }*/

    FILE *fp = fopen("prove.dat", "rb"); 
    if(fp == NULL){
        exit(-1); 
    }

    Esame e[100]; 

    Lista esitiEsami = NULL; 
    int i = 0; 
    
    while(fread(&e[i], sizeof(Esame), 1, fp)){
        if(ricerca(esitiEsami, e[i].matricola) == 0){
            insTesta(&esitiEsami, e[i].matricola, e[i].punteggio, e[i].tipo); 
        } else {
            aggiornamentoPunteggio(&esitiEsami, e[i].matricola, e[i].punteggio, e[i].tipo); 
        }
        i++; 
    }

    listaDecrescente(&esitiEsami); 

    stampaEsitiEsami(esitiEsami); 

    return 0; 
}