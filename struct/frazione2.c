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
    Frazione fr; 
    fr = semplifica(n, d);

    return fr; 
}

int main(){
    Frazione f1; 
    int num, den; 
    printf("Inserisci numeratore\n"); 
    scanf("%d", &num); 
    printf("\nInserisci denominatore\n");
    scanf("%d", &den); 

    f1 = frazione(num, den); 
    
    printf("\nFrazione: %d/%d\n", f1.num, f1.den);

    return 0;
}