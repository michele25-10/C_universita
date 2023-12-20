#include <stdio.h>
#include <stdlib.h>

typedef int Dato; 

typedef struct nodo{
    Dato dato;
    struct nodo* next;  
} Nodo; 

typedef Nodo* Lista;  

void azzera(Lista *l){
    Nodo* puntatore = (Nodo*)l; 
    while(puntatore){
        puntatore->dato = 0; 
        puntatore = puntatore->next; 
    }
}

void listaNonOrdinata(Lista *pl, int n){
    int a[] = {6,2,3,2,4,7,0,2,5,1};  
    Nodo* p = (Nodo*)pl; 
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

void stampa(Lista *l){
    printf("Dati:\n");
    Nodo* p = (Nodo*)l; 
    while(p){
        printf("%d\t", p->dato); 
        p = p->next; 
    }
}

int main(){
    Lista l;
    listaNonOrdinata(&l, 6); 
    stampa(&l);
    azzera(&l); 
    printf("\n"); 
    stampa(&l);

    return 0; 
}