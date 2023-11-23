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