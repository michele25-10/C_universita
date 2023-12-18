#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef char array[100000][31];
typedef char stringa[31]; 

int parolaCasuale(){
    srand(time(NULL)); 
    return rand()%100000 + 0; 
}

void secret(stringa parolaCasuale, stringa secret_str){
    for(int i = 0; i < strlen(parolaCasuale); i++){
        secret_str[i] = '_';
    }
}

int check(stringa parola, stringa secret_str, char lettera){
    int check = 0; 
    for(int i = 0; i < strlen(parola); i++){
        if(parola[i] == lettera){
            check = 1; 
            secret_str[i] = lettera;        
        }
    }
    return check; 
}

int indovinata(stringa secret_str){
    int check = 0; 
    for(int i = 0; i < strlen(secret_str); i++){
        if(secret_str[i] == '_'){
            check = 1; 
        }
    }   
    return check; 
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
    
    char lettera; 
    int indice = parolaCasuale(); 
    stringa secret_str;
    secret(contentFile[indice], secret_str);  
    int errori = 0; 
    

    while(1){
        printf("\nInserisci lettera: ");
        scanf(" %c", &lettera);  

        if(check(contentFile[indice], secret_str, lettera) == 0){
            errori++; 
        }

        printf("Parola: %s\n", secret_str); 
        printf("Errori: %d\n", errori); 
        
        if(indovinata(secret_str) == 0){
            printf("Parola indovinata!!\n\n"); 
            break; 
        }

        if(errori > 5){
            printf("Hai perso!!\n\n"); 
            break; 
        }
    }

    return 0; 
}