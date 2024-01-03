#include "listino.h"

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Mancano degli argomenti"); 
        exit(-1); 
    }

    FILE *l_file = fopen(argv[1], "rb"); 
    if(l_file == NULL){
        printf("Errore apertura del file"); 
        exit(-1); 
    }
    Listino l = NULL; 
    popolamentoListino(&l, l_file); 
    fclose(l_file); 

    Codici c = NULL; 
    popolamentoCodici(&c); 

    FILE *scontrino = fopen("scontrino.txt", "wt"); 
    creazioneScontrino(l, c, scontrino); 
    fclose(scontrino); 

    return 0;
}