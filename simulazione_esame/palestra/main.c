#include "listaUtenti.h"

int main(int argc, char *argv[]){
    if(argc != 3){
        exit(-1);
    }

    //popolo la lista degli iscritti della palestra
    FILE *cf = fopen(argv[1], "rb"); 
    if(cf == NULL){
        exit(-1); 
    } 
    Iscritti i = NULL; 
    popolamentoIscritti(&i, cf); 
    fclose(cf); 

    //Controllo degli ingressi
    FILE *ing = fopen(argv[2], "r");
    if(ing == NULL){
        exit(-1); 
    } 
    controlloIngressi(&i, ing); 
    fclose(ing); 

    //Stampa degli ingressi residui
    stampaIngressiResidui(i); 

    return 0; 
}