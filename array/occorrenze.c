#include <stdlib.h>
#include <stdio.h>

int occorrenze(int arr[],int len, int *rip){
    int count = 0; 
    int num = 0; 
    for(int i = 0; i < len; i++){
        for(int k = 0; k < len; k++){
            if(arr[k] == arr[i]){
                count++;
            }
        }
        if(count > *rip){
            *rip = count;
            count = 0; 
            num = arr[i]; 
        }
        count = 0; 
    }

    return num; 
}

int main(){
    int n, k; 
    do{
        printf("\nInserisci n <= 100: \n");
        scanf("%d", &n);
    }while(n < 0 || n > 100);
    
    do{
        printf("\nInserisci valore k < n: \n");
        scanf("%d", &k);
    }while(k > n || k < 0);
    
    int arr[n];
    for(int i = 0; i < n; i++){
        do{
        printf("\nnumero %d°: ", i + 1);
        scanf("%d", &arr[i]);
        }while(arr[i]<0 || arr[i] > k-1);
    }

    int ripetizioni = 0; 
    int num = occorrenze(arr, n, &ripetizioni);

    printf("Il numero che si ripete %d volte è %d\n", ripetizioni, num);

    return 0;
}