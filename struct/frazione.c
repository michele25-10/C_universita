#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int num; 
    int den; 
} Frazione; 

Frazione frazione(int n, int d){
    Frazione fr; 
    fr.num = n; 
    fr.den = d; 
    return fr; 
}

void stampaFrazionaria(Frazione fr){
    printf("Stampa frazionaria: %d/%d\n", fr.num, fr.den); 
}

float stampaDecimale(Frazione fr){
    return (float) fr.num/fr.den; 
}

int main(){
    Frazione f1; 
    int num;
    int den;
    printf("Inserisci numeratore\n"); 
    scanf("%d", &num);
    printf("\nInserisci denominatore\n");
    scanf("%d", &den); 


    f1 = frazione(num, den);

    stampaFrazionaria(f1); 
    printf("Stampa decimale: %.5f\n", stampaDecimale(f1)); 

    return 0; 
}