#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef char array[100000][31];

int parolaCasuale(array contentFile){
    srand(time(NULL)); 
    return rand()%100000 + 0; 
}

int main(){
    FILE *fp = fopen("words.italian.txt", "r"); 
    if(fp == NULL){
        exit(-1); 
    }
    array contentFile; 
    int i = 0; 
    while(feof(fp) == 0){
        fscanf(fp, "%s ", contentFile[i]); 
        i++; 
    }

    printf("\nParola Casuale:\n%s\n", contentFile[parolaCasuale(contentFile)]); 

    return 0; 
}