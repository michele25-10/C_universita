#include <stdio.h>

#define DIM 100

int main(){
    int array[DIM];

    int i = 0; 
    int numero; 
    while(i<DIM){
        printf("\nInserisci il %d° numero:\n", i+1);
        scanf("%d", &numero);
        if(numero >= 0){
            array[i] = numero; 
            i++;
        }else{
            break; 
        }
    };

    int indiceMax = 0, indiceMin = 0, tot = 0, indiceFrequenza = 0, frequenza = 0; 
    int tmp = 0; 
    for(int j = 1; j < i; j++){
        if(array[indiceMax] < array[j]){
            indiceMax = j; 
        }

        if(array[indiceMin] > array[j]){
            indiceMin = j; 
        }

        tot += array[j]; 

        for(int k = 0; k < i; k++){ 
            if(array[j] == array[k]){
                tmp++; 
            }

            if(tmp > frequenza){
                indiceFrequenza = j;
            }
        }
        tmp = 0; 
    }

    printf("\nNumero min: %d", array[indiceMin]); 
    printf("\nNumero max: %d", array[indiceMax]); 
    printf("\nMedia: %.2lf", (float) tot/i); 
    printf("\nNumero più frequente: %d", array[indiceFrequenza]);
    return 0;
}