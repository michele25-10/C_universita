#include <stdio.h>

int potenza(int base, int esponente){
    int a = 1; 
    int tot = 1; 
    while(a <= esponente){
        tot *= base; 
        a++; 
    }
    return tot; 
}

int main(){
    int indice; 
    printf("\nInserisci indice: \n"); 
    scanf("%d", &indice);

    int array[indice]; 

    for(int i = 0; i <= indice; i++){
        if(i % 2 == 0){
            array[i] = potenza(i, 2);
        } else {
            array[i] = potenza(i, 3); 
        }

        printf("%d \t", array[i]); 
    }

    return 0; 
}