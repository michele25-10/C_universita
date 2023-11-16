#include <stdio.h>

#define DIM 5

float valore_assoluto(float n){
    if (n < 0){
        return n*(-1);
    }else{
        return n; 
    }
}

int main(){
    float n[DIM]; 

    for (int i = 0; i < DIM; i++){
        printf("\nInserisci il %d° numero\n", i + 1); 
        scanf("%f", &n[i]); 
    } 

    int indice = 0;  

    for(int i = 1; i < DIM; i++){
        if(valore_assoluto(n[indice]) > valore_assoluto(n[i])){
            indice = i; 
        }
    }

    printf("\nIl numero minimo è: %.2lf\n", n[indice]);
    return 0;  

}