#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NRIGHE 4
#define NCOLONNE 6
#define PROBMINA 0.3

typedef char righe[NRIGHE];
typedef righe matrice[NCOLONNE];

unsigned short int mina(){
    srand(time(NULL));
    if((0.0 + ((double)rand() /RAND_MAX) * (1.0-0.0)) > PROBMINA){
        return 1;
    }else{
        return 0;
    }
} 

void inizializza(matrice campoMinato){
    for(int i = 0; i<NRIGHE; i++){
        for(int j = 0; j < NCOLONNE; j++){
            if(mina()){
                campoMinato[i][j] = '*';
            }else{
                campoMinato[i][j] = ' ';
            }
        }
    }
}

void stampa(matrice campoMinato){
    for(int i = 0; i<NRIGHE; i++){
        for(int j = 0; j < NCOLONNE; j++){
            printf("%c", campoMinato[i][j]); 
        }
        printf("\n");
    }
}


int main(){
    matrice campoMinato; 
    inizializza(campoMinato);
    stampa(campoMinato);
    
    return 0;
}