#include <stdio.h>
#include <stdlib.h>

// matrice di char
typedef char matrice_char[50][60]; 

//matrice di int
typedef int riga[3];
typedef riga matrice[3];

typedef struct {
    char marca[15]; 
    int cilindrata; 
    char anno[5]; 
    char nome; 
    char cognome; 
} Automobile;

//le matrici vengono passate per riferimento
int matriceInt(matrice m){}

int matriceChar(matrice_char mc){}

//array di struct viene passato con il puntatore
void arrayDiStruct(Automobile *arr){}

void structNormale(Automobile a){}

int main(){
    matrice m; 
    matrice_char mc; 
    Automobile a; 
    return 0; 
}