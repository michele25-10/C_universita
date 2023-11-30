#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void elimina(char stringa[], char deleteC){
    int lunghezza = strlen(stringa);
    int j = 0;
    for(int i = 0; i < lunghezza; i++){
        if(stringa[i] != deleteC){
            stringa[j] = stringa[i];
            j++;
        }
    }

    stringa[j] = '\0';
}

int rimuoviDuplicati(char *str, char *str2){
    int countDel = 0; 
    int count = 0;
    for(int i = 0; i < strlen(str2); i++){
        for(int j = 0; j < strlen(str); j++){
            if(str[j] == str2[i]){
                elimina(str, str2[i]);
                countDel++;
            }
        }
    }

    return countDel;
}

int main(){
    char a1[100];
    char a2[100];

    printf("Inserisci prima stringa: \n");
    scanf("%s", a1);

    printf("Inserisci secodna stringa: \n");
    scanf("%s", a2); 

    int eliminati = rimuoviDuplicati(a1, a2);

    printf("%s \t eliminati: %d", a1, eliminati);

    return 0;
}