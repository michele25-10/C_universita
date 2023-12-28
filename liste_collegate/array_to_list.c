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

int main()
{

    int arr[] = {1, 2, 5, 6, 7};
    int dim = 5;

    Lista list = arrayToList(arr, dim);

    stampa(list);

    return 0;
}