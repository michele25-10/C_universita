#include <stdlib.h>
#include <stdio.h>

#define NRIGHE 4
#define NCOLONNE 6
#define PROBMINA 0.2

typedef char Campo[NRIGHE][NCOLONNE];

double rnd(){
    return 0.0 + ((double)rand() /RAND_MAX) * (1.0-0.0); 
}

void inizializza(Campo c){
    for(int i = 0; i < NRIGHE; i++){
        for(int j = 0; j < NCOLONNE; j++){
            if(rnd() <= PROBMINA){
                c[i][j] = '*';
            }else{
                c[i][j] = ' ';
            }
        }
    }
}

void stampa(Campo c){
    for(int i = 0; i < NRIGHE; i++){
        for(int j = 0; j < NCOLONNE; j++){
            printf("%c\t", c[i][j]);
        }
        printf("\n");
    }
}

int main(){
    Campo c;
    inizializza(c);
    stampa(c);
    return 0;
}