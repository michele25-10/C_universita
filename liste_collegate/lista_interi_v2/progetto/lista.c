#include "lista.h"

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
