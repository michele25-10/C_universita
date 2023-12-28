#include <stdlib.h>
#include <stdio.h>

typedef int Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void insTesta(Lista *l, Dato d)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    if (aux == NULL)
    {
        exit(-1);
    }
    aux->dato = d;
    aux->next = *l;
    *l = aux;
}

Lista arrayToList(int arr[], int dim)
{
    int i = 0;
    Lista l = NULL;
    while (i < dim)
    {
        insTesta(&l, arr[i]);
        i++;
    }
    return l;
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%d \n", l->dato);
        l = l->next;
    }
}

void list_to_array(Lista list, int array[], int dim){
    Nodo* aux = list; 
    for(int i = 0; i < dim; i++){
        array[i] = aux->dato; 
        aux = aux->next; 
    } 
}

int main()
{
    int arr[] = {1, 2, 5, 6, 7};
    int dim = 5;

    Lista list = arrayToList(arr, dim);


    int array[5]; 
    list_to_array(list, array, 5); 

    for(int i = 0; i < 5; i++){
        printf("%d\n", arr[i]); 
    }

    return 0;
}