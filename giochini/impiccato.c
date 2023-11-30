#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TENTATIVI 8
#define DIM 20

void secret_str (char *str, char *secret){
    short int length= strlen(str);
    for(int i = 0; i < length; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            secret[i] = '+';
        }else{
            secret[i] = '-';
        }
    } 
}

void check(char *crypt_str, char *str, char c){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == c){
            crypt_str[i] = c;
        }
    }
}

unsigned short int vittoria(char *crypt_str){
    for(int i = 0; i < strlen(crypt_str); i++){
        if(crypt_str[i] == '-' || crypt_str[i] == '+'){
            return 0;
        }
    }
    return 1; 
}

int main(){
    char str[DIM] = "pippo";
    char crypt_str[DIM];
    secret_str(str, crypt_str);

    printf("Giochimao, hai 8 tentativi!\n");
    printf("Parola \t%s\n", crypt_str); 

    int count = 0; 
    char c;

    while(count < TENTATIVI){
        printf("Inserisci una lettera: ");
        scanf(" %c", &c);
        check(crypt_str, str, c);
        printf("\n%s\t(tentativo numero: %d)\n", crypt_str, (count + 1));
        if(vittoria(crypt_str) == 1){
            break; 
        }
        count++;
    }

    if(vittoria(crypt_str) == 1){
        printf("\nHai vinto!!\n");
    } else {
        printf("\nHai perso!!\n");
    }

    return 0;

}