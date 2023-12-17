#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NRIGHE 4
#define NCOLONNE 6
#define PROBMINA 0.6

typedef char matrice[NRIGHE][NCOLONNE]; 

// typedef char colonne[NCOLONNE];
// typedef colonne matrice[NRIGHE];

unsigned short int mina(){
    //srand(time(NULL));
    double r = 0.0 + ((double)rand() /RAND_MAX) * (1.0-0.0);
    if(r > PROBMINA){
        return 1;
    }else{
        return 0;
    }
} 

int inizializza(matrice campoMinato){
    int count = 0; 
    for(int i = 0; i<NRIGHE; i++){
        for(int j = 0; j < NCOLONNE - 1; j++){
            if(mina()){
                campoMinato[i][j] = '*';
            }else{
                campoMinato[i][j] = ' ';
                count++;
            }
        }
        campoMinato[i][NCOLONNE-1] = '\0';
    }
    return count; 
}

void stampa(matrice campoMinato){
    int riga = 1;
    int colonna = 'a';
            
    int k = 0; 
    printf(" \t");
    while (k < NCOLONNE - 1){
        printf("%c ", colonna);
        colonna++;
        k++;    
    }
    printf("\n");

    for(int i = 0; i<NRIGHE; i++){
        printf("%d\t", riga);
        for(int j = 0; j < NCOLONNE - 1; j++){
            if(campoMinato[i][j] == 'X'){
                printf("X ");
            }else{
                printf("  ");
            } 
        }
        printf("\n");
        riga++;
    }
}

unsigned short int seleziona(matrice campoMinato, int riga, int colonna){
    if(campoMinato[riga][colonna] == ' '){
        campoMinato[riga][colonna] = 'X';
        return 0;
    }else{
        return 1;
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

void stampaCampoMinato(matrice campoMinato){
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

unsigned short int vittoria(matrice campoMinato, int celleVuote){
    int count = 0; 
    for(int i = 0; i<NRIGHE; i++){
        for(int j = 0; j < NCOLONNE; j++){
            if(campoMinato[i][j] == 'X'){
                count++; 
            }
        }
    }
    if(count == celleVuote){
        return 1; 
    }else{
        return 0; 
    }
}

int main(){
    matrice campoMinato; 
    int celleVuote = inizializza(campoMinato);
    stampa(campoMinato);

    char cella[2];
    while(1){
        printf("Inserisci riga e colonna es: (b5)\n");
        scanf("%2s", cella);

        if(seleziona(campoMinato, (int)(cella[1] - '1'), (int)(cella[0] - 'a')) == 1){
            printf("\n\n\n");
            stampaCampoMinato(campoMinato);
            printf("\n\n\n"); 
            printf("Hai perso!\n"); 
            break; 
        } else if(vittoria(campoMinato, celleVuote) == 1){
            printf("\n\n\n"); 
            printf("Hai VINTO!\n"); 
            break; 
        }else{
            stampa(campoMinato); 
        }
    }
    
    return 0;
}