#include <stdio.h>
#include <stdlib.h>

typedef int riga[3];
typedef riga matrice[3];

unsigned short int simm(matrice M){
    if(M[2][0] != M[0][2]){
        return 0;
    }
    if(M[1][0] != M[0][1]){
        return 0;
    }
    if(M[2][1] != M[1][2]){
        return 0;
    }

    return 1;
}

int main(){
    matrice M;

    for(int i = 0; i < 3; i++){
        printf("\nInserisci il valore della %d° matrice", i + 1);
        printf("\nValore 1: ");
        scanf("%d", &M[i][0]);
        printf("\nValore 2: ");
        scanf("%d", &M[i][1]);
        printf("\nValore 3: ");
        scanf("%d", &M[i][2]);
    }

    if(simm(M) == 1){
        printf("\nLa matrice è simmetrica\n");
    }else{
        printf("\nLa matrice non è simmetrica\n");
    }
    
    return 0;
}