#include <stdlib.h>
#include <stdio.h>

typedef int Dato; 

typedef struct nodo{
    Dato dato; 
    struct nodo* next; 
}Nodo; 

typedef Nodo* Lista; 

void insHeadLista(Lista *l, int valore){
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo)); 
    aux->dato = valore; 
    aux->next = *l; 
    *l = aux; 
}

int lunghezzaLista(Lista l){
    Nodo* aux = l; 
    int length = 0; 
    while(aux){
        length++; 
        aux = aux->next; 
    }
    return length; 
}

int sommaElementiLista(Lista l){
    Nodo* aux = l; 
    int sum = 0; 
    while(aux){
        sum += aux->dato; 
        aux = aux->next; 
    }
    return sum; 
}

void Stampa(Lista l){
    Nodo* pl = l; 
    while(pl){
        printf("%d\n", pl->dato); 
        pl = pl->next;     
    }
}

void eliminazioneElementoLista(Lista l, int delNumber){
    Nodo* pre = l; 
    Nodo* dopo = pre->next; 
    
    if(pre->dato == delNumber){
        l->next = dopo; 
        free(pre);
        pre = l;  
        dopo = l->next; 
    }

    while(dopo){
        if(dopo->dato == delNumber){
            pre->next = dopo->next; 
            free(dopo); 
        }
        pre = pre->next; 
        dopo = dopo->next; 
    }
}

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