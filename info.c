#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct record{
    int dato; 
    char str[100]; 
}Record; 

typedef struct nodo{
    int dato; 
    char str[100]; 
    struct nodo *next; 
}Nodo; 

typedef Nodo* Lista; 

// enumeratore di una variabile booleana
typedef enum { false, true } Boolean;

void insTesta(Lista *i, Record r){
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = r.dato; 
    strcpy(aux->str, r.str);
    aux->next = *i;
    *i = aux; 
} 

Lista* ricercaCoda(Lista *i){
    while(*i){
        i = &(*i)->next; 
    }
    return i; 
}

void insCoda(Lista *i, Record r){
    i = ricercaCoda(i);
    insTesta(i, r); 
}

void popolamentoLista(Lista *i, FILE *cf){
    Record r; 
    //fread(inidirizzo salvataggio, dimensione elemento da leggere, quantità, file); 
    while(fread(&r, sizeof(r), 1, cf)){
        insTesta(i, r); 
    }
}

Lista* ricerca(Lista *i, char *str){
    Nodo* aux = *i;
    while(aux){
        if(strcmp(aux->str, str) == 0 ){
            return aux; 
        }
        aux = aux->next; 
    } 
    return 0; 
} 

void aggiornamentoLista(Lista *i){
    Nodo *aux = ricerca(i, "pippo"); 
    aux->dato = 0; 
}

void eliminazioneNodo(Lista *i){
    Nodo* pre = *i; 
    Nodo *aux = pre->next; 
    if(pre->dato == 0){
        free(pre); 
        *i = aux;     
    }
    while(aux){
        if(aux->dato == 0){
            pre->next = aux->next;
            free(aux); 
        }
        pre = pre->next; 
        aux = aux->next;
    }
}

void stampa(Lista i){
    while(i){
        printf("\n%d", i->dato);
        i = i->next;
    }
}

Boolean controlloEstensioneFileCorretta(char *nomeFile, char *estensione){
    int lunghezzaEstensione = strlen(estensione); 
    int lunghezzaNomeFile = strlen(nomeFile); 

    int k = 0; 
    for(int i = lunghezzaNomeFile - lunghezzaEstensione; i < lunghezzaNomeFile; i++){
        if(nomeFile[i] != estensione[k]){
            return false; 
        }
        k++; 
    }
    return true; 
}

int main(int argc, char *argv[]){
    
    if(argc != 3){
        exit(-1);
    }

    if(controlloEstensioneFile(argv[1], ".dat") == false){
        printf("Il file inserito non è dell'estensione adatta\n"); 
        exit(-1); 
    }

    //Lettura dal file
    FILE *cf = fopen(argv[1], "rb"); 
    if(cf == NULL){
        exit(-1); 
    } 
    Lista i = NULL; 
    popolamentoLista(&i, cf); 
    fclose(cf);

    aggiornamentoLista(&i); 

    eliminazioneNodo(&i); 

    stampa(i); 
}

/*-------------------------------------------------*/
/*
operazioni con i puntatori, ricordati le parentesi
(*count_error)++;
*/

/*-------------------------------------------------*/
/*FILE BINARI
while(fread(&v[count], sizeof(Persona), 1, fb) > 0){}
fwrite(&e, sizeof(Persona), 1, fp);
*/
/*FILE TESTUALI
fprintf(fp, "%s\n", str);
fscanf(fp, "%d\n", &dato);
*/
/*Modalita di apertura 
-r -> sola lettura
-w -> sola scrittura
-a -> sola scrittura aggiungendo alla fine
-t -> file testuale
-b -> file binario
-+ -> file aperto in lettura e scrittura
*/

/*------------------------------------------------*/
/*
MAKEFILE:
palestra: main.o listaUtenti.o
	gcc -g -o palestra main.o listaUtenti.o

main.o: main.c listaUtenti.h
	gcc -g -c main.c

listaUtenti.o: listaUtenti.c listaUtenti.h
	gcc -g -c listaUtenti.c
*/

int rnd_int (int min , int max ) {
	//ricordati di importare libreria <time.h>
	srand(time(NULL)); 
	return min + rand () % ( max - min + 1) ;
}
