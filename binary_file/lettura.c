#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char cognome[30];
    char nome[30];
    char sesso; 
    int anno;
} Persona; 

int main(){

    Persona v[50]; 
    FILE *fb;
    fb = fopen("people.dat", "rb");
    if(fb == NULL){
        exit(-1);
    } 
    int count = 0;  
    while(fread(&v[count], sizeof(Persona), 1, fb) > 0){
        printf("%s, %s, %c, %d\n", v[count].nome, v[count].cognome, v[count].sesso, v[count].anno);
        count ++;
    }
    fclose(fb);
    return 0;
}