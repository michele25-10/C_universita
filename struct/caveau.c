#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIM 20

typedef struct {
    char nome[DIM];
    int valore; 
} Pietra; 

void ordina_per_valore(Pietra *arr, int n){
    Pietra tmp; 
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i].valore < arr[j].valore){
                strcpy(tmp.nome, arr[i].nome);
                tmp.valore = arr[i].valore; 
                strcpy(arr[i].nome,arr[j].nome); 
                arr[i].valore = arr[j].valore;
                strcpy(arr[j].nome, tmp.nome); 
                arr[j].valore = tmp.valore; 
            }
        }
    }
}

int main(){
    const int k = 2;
    int n; 
    do{
        printf("\nQuante pietre sono presenti nel caveau: \n");
        scanf("%d", &n); 
    }while(n < k || n > 20); 

    Pietra caveau[n];

    for(int i = 0; i < n; i++){
        printf("\nInserisci nome pietra: \n"); 
        scanf("%s", caveau[i].nome);
        printf("\nInserisci valore pietra: \n");
        scanf("%d", &caveau[i].valore);  
    }

    ordina_per_valore(caveau, n); 

    for(int i = 0; i < k; i++){
        printf("\n%s\t%d", caveau[i].nome, caveau[i].valore); 
    }
    printf("\n"); 
    return 0;
}