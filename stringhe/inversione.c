#include <stdio.h>

#define DIM 10

int main(){
    char str[DIM]; 
    printf("\nInserisci stringa: \n"); 
    scanf("%s", str); 


    int dim_str = 0; 
    for(int i = 0; str[i]!='\0'; i++){
        dim_str++; 
    }

    char str_inv[dim_str]; 
    int k = 0; 
    for(int i = dim_str -1; i >= 0; i--){
        str_inv[k] = str[i];     
        k++; 
    }

    printf("\nStringa inversa: %s\n", str_inv);

    return 0;  
}