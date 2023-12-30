#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

int main(){
    int tmp = 0;
    Lista list = NULL; 
    do{
        printf("\nInserisci numero:\n"); 
        scanf("%d", &tmp); 
    }while(tmp < 0); 
    
    //Popolamento della lista
    while(tmp != 0){
        insHeadLista(&list, tmp); 
        do{
            printf("\nInserisci numero:\n"); 
            scanf("%d", &tmp); 
        }while(tmp < 0); 
    }

    //lunghezza della lista
    int length = lunghezzaLista(list); 

    //Somma degli elementi della lista 
    int sum = sommaElementiLista(list); 

    //stampo i risultati in output
    printf("\nLa somma degli elementi della lista è: %d\nIl numero degli elementi della lista è: %d\n", sum, length); 
    
    printf("\nStampo tutti gli elementi della lista:\n"); 
    Stampa(list); 
    
    int deleteNumber; 
    do{
        printf("\nInserisci numero da eliminare:\n"); 
        scanf("%d", &deleteNumber); 
    }while(deleteNumber<=0); 
    
    eliminazioneElementoLista(list, deleteNumber); 
    
    printf("\nStampo tutti gli elementi della lista dopo l'eliminazione:\n"); 
    Stampa(list); 

    return 0; 
}