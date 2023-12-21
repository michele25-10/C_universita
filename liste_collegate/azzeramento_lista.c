#include <stdio.h>
#include <stdlib.h>

typedef int Dato;

typedef struct nodo {
    Dato dato;
    struct nodo * next;
} Nodo;

typedef Nodo *Lista;

void azzera(Lista l){
    Nodo* p = l; 
    while(p){
        p->dato = 0; 
        p = p->next; 
    }
}

void listaNonOrdinata(Lista *p, int n){
    int a[] = {6,2,3,2,4,7,0,2,5,1};  
    int i = 0; 
    (*p) = (Nodo*)malloc(sizeof(Nodo));
    while(i < n-1){
        (*p)->dato = a[i]; 
        (*p)->next = (Nodo*)malloc(sizeof(Nodo));
        (*p) = (*p)->next; 
    }
    (*p)->dato = a[i]; 
    (*p)->next = NULL; 
}

void stampa(Lista l){
    printf("Dati:\n");
    while(l){
        printf("%d\t", l->dato); 
        l = l->next; 
    }
}

int main(){
    Lista l;
    listaNonOrdinata(&l, 6); 
    stampa(l);
    azzera(l); 
    printf("\n"); 
    stampa(l);

    return 0; 
}