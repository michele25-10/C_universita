#include <stdlib.h>
#include <stdio.h>

typedef int Dato; 

typedef struct nodo{
    Dato dato; 
    struct nodo* next; 
}Nodo; 

typedef Nodo* Lista; 

Lista* ultimoNodo(Lista *l){
    while(*l){
        l= &(*l)->next; 
    }
    return l; 
}

void insTesta(Lista *l, Dato valore){
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo)); 
    aux->dato = valore; 
    *l = aux; 
}


void insCodaLista(Lista *l, Dato valore){
    l = ultimoNodo(l);
    insTesta(l, valore);  
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
    Nodo* del = NULL;
    
    if(pre->dato == delNumber){
        l = dopo; 
        del = pre;
        free(del);
        pre = l;  
        dopo = pre->next; 
    }
    int eliminato = 0;
    while(dopo){
        if(dopo->dato == delNumber){
            eliminato = 1; 
            pre->next = dopo->next; 
            del = dopo; 
            free(del); 
        }
        
        if(eliminato == 0){
            pre = pre->next; 
        }

        eliminato = 0; 
        if(pre || pre->next!=NULL){
            dopo = pre->next;
        } else {
            dopo = NULL; 
        } 
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
        insCodaLista(&list, tmp); 
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