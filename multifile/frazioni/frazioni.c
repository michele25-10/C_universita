#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int num; 
    int den; 
} Frazione; 

// algoritmo di euclide
int mcd(int a, int b){
    while(b != 0){
        int q = a / b;
        int r = a % b; 
        a = b; 
        b = r;
    }
    return a; 
}

Frazione semplifica(int n, int d){
    int divisore = mcd(n, d);
    Frazione fr; 
    fr.num = n/divisore; 
    fr.den = d/divisore; 

    return fr;  
} 

Frazione frazione(int n, int d){
    return semplifica(n, d);
}

Frazione somma(Frazione f1, Frazione f2){
    Frazione result; 
    result.num = (f1.num * f2.den) + (f2.num * f1.den);
    result.den = f1.den * f2.den; 

    return semplifica(result.num, result.den);
}

Frazione sottrazione(Frazione f1, Frazione f2){
    Frazione result; 
    result.num = (f1.num * f2.den) - (f2.num * f1.den);
    result.den = f1.den * f2.den; 

    return semplifica(result.num, result.den);
}

Frazione moltiplicazione(Frazione f1, Frazione f2){
    Frazione result; 
    result.num = f1.num * f2.num; 
    result.den = f1.den * f2.den; 

    return semplifica(result.num, result.den);
}

Frazione reciproco(int n, int d){
    Frazione reciproca; 
    reciproca.num = d; 
    reciproca.den = n; 

    return reciproca; 
}

Frazione divisione(Frazione f1, Frazione f2){
    Frazione result; 
    f2 = reciproco(f2.num, f2.den);
    result = moltiplicazione(f1, f2);

    return semplifica(result.num, result.den);
}