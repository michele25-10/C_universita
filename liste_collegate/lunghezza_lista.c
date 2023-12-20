#include <stdio.h>
#include <stdlib.h>

typedef int Dato; 

typedef struct nodo{
    Dato dato;
    struct nodo* next;  
} Nodo; 

typedef Nodo* Lista;  

void listaNonOrdinata(Lista *pl, int n){
    int a[] = {6,2,3,2,4,7,0,2,5,1};   
    Nodo* p = pl; 
    int i = 0; 
    while(i < n-1){
        p->dato = a[i]; 
        p->next = malloc(sizeof(Nodo)); 
        p = p->next; 
        i++;
    }
    p->dato = a[i]; 
    p->next = NULL; 
}

int lunghezzaLista(Lista *l){
    int count = 0; 
    Nodo* p = l; 
    while(p){
        count++; 
        p = p->next; 
    }

    return count; 
}

int main(){
    Lista l; 
    listaNonOrdinata(&l, 6); 

    printf("Lunghezza lista: %d\n", lunghezzaLista(&l)); 

    return 0; 
}