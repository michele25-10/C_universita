#include <stdio.h>

int main(){
    printf("Inserisci il primo numero: \n");
    int a = 0; 
    scanf("%d", &a);

    printf("Inserisci il secondo numero: \n");
    int b = 0; 
    scanf("%d", &b);

    int somma = a+b; 
    printf("\nLa somma è: %d", somma); 

    int differenza = a-b;
    printf("\nLa differenza è: %d", differenza);

    int prodotto = a*b; 
    printf("\nIl prodotto è: %d", prodotto); 

    int divisione = a/b; 
    int modulo = a%b; 
    printf("\nLa divisione è %d mentre il modulo è %d", divisione, modulo); 

    a+= 1; 
    printf("\nValore di a incrementato: %d", a);

    b-= 1;
    printf("\nValore di b decrementato è: %d", b); 
    
    a+=5;
    printf("\nValore di a incrementato di 5: %d\n", a);
}