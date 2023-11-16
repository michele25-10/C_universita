#include <stdio.h>

#define DIM 15

int main(){
    char s1[DIM];
    char s2[DIM];

    printf("Prima stringa:\n");
    scanf("%s", s1);

    printf("\nSeconda stringa: \n");
    scanf("%s", s2);

    int check = 0; 

    for(int i = 0; s2[i] != '\0'; i++){
        if(s1[0] == s2[i]){
            check = 1;
            for(int j = 1; s1[j] != '\0'; j++){
                i++;
                if(s2[i] == s1[j]){
                    check = 1;
                }else{
                    check = 0;
                    break;
                }
            }
        }
    }

    if(check == 1){
        printf("\nContenuta\n");
    }else{
        printf("\nNON Contenuta\n"); 
    }

    return 0;

}