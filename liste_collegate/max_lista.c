#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato; 
    struct nodo* next; 
} Nodo; 

typedef Nodo* Lista; 

void popolaLista(Lista *l, int qta){
    for (int i = 0; i < qta; i++){
        (*l)->dato = i; 
        (*l)->next = (Nodo*)malloc(sizeof(Nodo)); 
        l = &(*l)->next; 
    }
}

int maxLista(Lista l){
    int max = l->dato; 
    Nodo *p = l->next; 
    while(p){
        if(p->dato > max){
            max = p->dato;
        }
        p = p->next; 
    }
    return max; 
}

int main(){
    Lista l; 
    popolaLista(&l, 10);
    int max = maxLista(l); 
    printf("\nIl numero massimo della lista è: %d\n", max); 
    return 0; 
}