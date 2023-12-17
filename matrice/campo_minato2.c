#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NRIGHE 4
#define NCOLONNE 6
#define PROBMINA 0.37

typedef char colonne[NCOLONNE];
typedef colonne matrice[NRIGHE];

unsigned short int mina(){
    //srand(time(NULL));
    double r = 0.0 + ((double)rand() /RAND_MAX) * (1.0-0.0);
    if(r > PROBMINA){
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

unsigned short int mineAdiacenti(matrice campoMinato, int riga, int colonna){
    int count = 0; 
    for(int i = riga - 1; i <= riga + 1; i++){
        if(i >= 0 && i < NRIGHE){
            for(int j = colonna -1; j <= colonna + 1; j++){
                if(j >= 0 && j < NCOLONNE){
                    if(campoMinato[i][j] == '*'){
                        count++;
                    }
                }
            }
        }
    }

    return count; 
}

void stampa(matrice campoMinato){
    for(int i = 0; i<NRIGHE; i++){
        for(int j = 0; j < NCOLONNE; j++){
            if(campoMinato[i][j] == '*'){
                printf("%c", campoMinato[i][j]);
            }else{
                printf("%d", mineAdiacenti(campoMinato, i, j));
            } 
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