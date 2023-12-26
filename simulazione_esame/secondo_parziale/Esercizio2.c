#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define DIM 30

typedef struct nodo{
    char parola[DIM]; 
    struct nodo* next; 
}Nodo; 

typedef Nodo* Lista; 

void toLower(char *str){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] >=  'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32; 
        } 
    }
}

Lista listaNera(int argc, char *argv[]){
    Lista ln; 
    if(argc > 2){
        int m = 2; 
        while(m < argc - 1){
            toLower(argv[m]); 
            strcpy(ln->parola, argv[m]);  
            ln->next = (Nodo *)malloc(sizeof(Nodo));
            ln = ln->next; 
            m++; 
        }
        strcpy(ln->parola, argv[m]);
        ln->next = NULL;   
    } else {
        ln->next = NULL; 
    }

    return ln; 
}

int checkPresenza(Lista *lista, char *str){
    Nodo *l = (Nodo *)lista; 
    while(l->next != NULL){
        toLower(l->parola); 
        toLower(str); 
        if(strcmp(l->parola, str) == 0){
            return 1;
        }
        l = l->next; 
    }

    return 0; 
}

Lista salvataggioContenutoFile(char *nameFile, Lista *ParoleDaEvitare){
    FILE *fp; 
    fp = fopen(nameFile, "r"); 
    if(fp == NULL){
        printf("\nNome File dichiarato inesistente in questa directory\n"); 
        exit(-1); 
    }

    Lista contenutoFile; 
    char tmp[DIM];
    while(feof(fp) == 0){
        fscanf(fp, "%s ", tmp);
        toLower(tmp); 
        if(checkPresenza(ParoleDaEvitare, tmp) == 0){
            strcpy(contenutoFile->parola, tmp); 
            contenutoFile->next = (Nodo *)malloc(sizeof(Nodo)); 
            contenutoFile = contenutoFile->next; 
        }
    }

    fclose(fp);

    return contenutoFile; 
}

void listaStringheAscendente(Lista *stringhe, Lista *stringheNoDoppioni){
    Nodo *l = (Nodo *)stringhe; 
    Nodo *k; 
    Nodo *n_d = (Nodo *)stringheNoDoppioni; 
    char tmp[DIM]; 
    while(l != NULL){
        k = l->next; 
        while(k != NULL){
            if(strlen(k->parola)>strlen(l->parola)){
                strcpy(tmp, l->parola); 
                strcpy(l->parola, k->parola); 
                strcpy(k->parola, tmp); 
            }
            k = k->next; 
        }

        if(checkPresenza(stringheNoDoppioni, l->parola) == 0){
            strcpy(n_d->parola, l->parola); 
            n_d->next = (Nodo *)malloc(sizeof(Nodo)); 
            n_d = n_d->next; 
        }

        l = l->next;  
    }
}

int countStringa(Lista stringhe, char *str){
    int count = 0; 

    toLower(str); 

    while(stringhe->next != NULL){
        if(strcmp(str, stringhe->parola) == 0){
            count++; 
        }
        stringhe = stringhe->next; 
    }

    return count; 
} 

void Stampa(Lista stringhe, Lista stringheNoDoppioni){
    int qta; 
    while(stringheNoDoppioni->next != NULL){
        qta = countStringa(stringhe, stringheNoDoppioni->parola); 
        if(qta >= 4){
            printf("\n%s: %d", stringheNoDoppioni->parola, qta); 
        }
        stringheNoDoppioni = stringheNoDoppioni->next; 
    }
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("\nNon sono stati inseriti argomenti a sufficienza!\n"); 
        exit(-1); 
    }

    Lista ParoleDaEvitare = listaNera(argc, argv); 

    FILE *fp = fopen(argv[1], "r"); 
    if(fp == NULL){
        printf("\nErrore nell'apertura del file\n"); 
        exit(-1); 
    }

    Lista stringheFile = salvataggioContenutoFile(argv[1], &ParoleDaEvitare); 
    Lista stringheNoDoppioni; 

    listaStringheAscendente(&stringheFile, &stringheNoDoppioni); 

    Stampa(stringheFile, stringheNoDoppioni); 

    return 0; 
}