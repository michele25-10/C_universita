#include "listaUrl.h"

    //controllo l'estensione del file
Boolean controlloEstensioneFile(char *nomeFile, char *estensione){
    int lunghezzaEstensione = strlen(estensione); 
    int lunghezzaNomeFile = strlen(nomeFile); 

    int k = 0; 
    for(int i = lunghezzaNomeFile - lunghezzaEstensione; i < lunghezzaNomeFile; i++){
        if(nomeFile[i] != estensione[k]){
            return false; 
        }
        k++; 
    }
    
    return true; 
}

int main(int argc, char *argv[]){
    //se non ci sono due elementi negli argomenti allora comunico l'errore
    if(argc != 2){
        printf("Mancano dei campi dato\n"); 
        exit(-1); 
    }
    //validazione input
    if(controlloEstensioneFile(argv[1], ".dat") == false){
        printf("Il file inserito non è dell'estensione adatta\n"); 
        exit(-1); 
    }

    //apertura file
    FILE *v = fopen(argv[1], "rb");
    if(v == NULL){
        printf("Errore apertura file\n"); 
        exit(-1);
    }  
    Lista c = NULL; 
    //popolo la lista con i dati interni al file
    popolamentoLista(&c, v);
    fclose(v); 


    //output
    printf("\nCronologia:\n"); 
    stampa(c); 

    listaOrdinataViewsDrecrescente(&c); 
    printf("\nCronologia ordinata:\n"); 
    stampa(c); 
    return 0; 
}