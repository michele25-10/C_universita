#include <stdlib.h>
#include <stdio.h>
#include "frazioni.h"

int main(){
    Frazione f1; 
    int num1, den1; 
    printf("Inserisci numeratore\n"); 
    scanf("%d", &num1); 
    do{
        printf("Inserisci denominatore\n");
        scanf("%d", &den1); 
    }while(den1 == 0);
    f1 = frazione(num1, den1); 
    
    printf("\n-------------------\n");

    Frazione f2;
    int num2, den2; 
    printf("\nInserisci numeratore\n"); 
    scanf("%d", &num2); 
    do{
        printf("Inserisci denominatore\n");
        scanf("%d", &den2); 
    }while(den2 == 0);
    f2 = frazione(num2, den2); 
    
    int menu; 
    do{
        printf("\nChe operazione vuoi eseguire:\n-1. somma;\n-2. sottrazione;\n-3. moltiplicazione;\n-4. divisione\n");
        scanf("%d", &menu); 
    }while(menu < 1 || menu > 4);

    Frazione risultato; 
    switch (menu)
    {
    case 1:
        risultato = somma(f1, f2); 
        break;
    
    case 2:
        risultato = sottrazione(f1, f2); 
        break;
    
    case 3:
        risultato = moltiplicazione(f1, f2); 
        break;

    case 4:
        risultato = divisione(f1, f2);
        break; 
    }

    printf("\n---------------------\nIl risultato è: %d/%d\n", risultato.num, risultato.den);

    return 0;
}