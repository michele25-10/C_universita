#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int num; 
    int den; 
} Frazione; 

int mcd(int a, int b);

Frazione semplifica(int n, int d);

Frazione frazione(int n, int d);

Frazione somma(Frazione f1, Frazione f2);

Frazione sottrazione(Frazione f1, Frazione f2);

Frazione moltiplicazione(Frazione f1, Frazione f2);

Frazione reciproco(int n, int d);

Frazione divisione(Frazione f1, Frazione f2);