#include "listaParole.h"

void toLower(char *str){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] >=  'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32; 
        } 
    }
}

void insTesta(Lista *l, char *str){
    toLower(str); 
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo)); 
    strcpy(aux->parola, str); 
    aux->next = *l; 
    *l = aux; 
}

int checkPresenza(Lista *lista, char *str){ 
    Nodo *check = *lista; 
    while(check){
        if(strcmp(check->parola, str) == 0){
            return 1;
        }
        check = check->next; 
    }

    return 0; 
}

void salvataggioContenutoFile(char *nameFile, Lista *ParoleDaEvitare, Lista *contenutoFile){
    FILE *fp; 
    fp = fopen(nameFile, "r"); 
    if(fp == NULL){
        printf("\nNome File dichiarato inesistente in questa directory\n"); 
        exit(-1); 
    }

    char tmp[DIM];
    while(feof(fp) == 0){
        fscanf(fp, "%s ", tmp);
        toLower(tmp); 
        if(checkPresenza(ParoleDaEvitare, tmp) == 0){
            insTesta(contenutoFile, tmp); 
        }
    }

    fclose(fp);
}

void listaStringheAscendente(Lista *stringhe, Lista *stringheNoDoppioni){
    Nodo *l = *stringhe; 
    Nodo *k; 
    char tmp[DIM]; 
    while(l){
        k = l->next; 
        while(k){
            if(strlen(k->parola)>strlen(l->parola)){
                strcpy(tmp, l->parola); 
                strcpy(l->parola, k->parola); 
                strcpy(k->parola, tmp); 
            }
            k = k->next; 
        }

        if(checkPresenza(stringheNoDoppioni, l->parola) == 0){
            insTesta(stringheNoDoppioni, l->parola);
        }

        l = l->next;  
    }
}

int countStringa(Lista stringhe, char *str){
    int count = 0; 

    toLower(str); 

    while(stringhe){
        if(strcmp(str, stringhe->parola) == 0){
            count++; 
        }
        stringhe = stringhe->next; 
    }

    return count; 
} 

void Stampa(Lista stringhe, Lista stringheNoDoppioni){
    int qta; 
    while(stringheNoDoppioni){
        qta = countStringa(stringhe, stringheNoDoppioni->parola); 
        if(qta >= 4){
            printf("\n%s: %d", stringheNoDoppioni->parola, qta); 
        }
        stringheNoDoppioni = stringheNoDoppioni->next; 
    }
}