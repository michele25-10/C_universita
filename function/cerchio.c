#include <stdio.h>

float diametro(int raggio){
    return raggio * 2; 
}

float perimetroCerchio(int raggio){
    return 2 * 3.14 * raggio;    
}

float areaCerchio(int raggio){
    return 3.14 * raggio * raggio; 
}

int main(){
    int raggio; 
    printf("Inserisci raggio cerchio\n"); 
    scanf("%d", &raggio); 

    printf("\nDiametro: %.2f\n", diametro(raggio)); 
    printf("Perimetro: %.2f\n", perimetroCerchio(raggio)); 
    printf("Area: %.2f\n", areaCerchio(raggio)); 

    return 0; 
}