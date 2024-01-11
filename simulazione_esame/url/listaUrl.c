#include "listaUrl.h"

Info* ricercaURL(Lista *c, char *url){
    Info *aux = *c;
    while(aux){
        if(strcmp(aux->url, url) == 0){
            return aux; 
        }
        aux = aux->next; 
    }
    return NULL; 
}

void insTesta(Lista *c, Visite r){
    Info *aux = (Info*)malloc(sizeof(Info)); 
    strcpy(aux->url, r.url); 
    aux->ora = r.ora; 
    aux->minuti = r.minuti; 
    aux->views = 1;
    aux->next = *c; 
    *c = aux;   
}

void popolamentoLista(Lista *c, FILE *v){
    Visite record; 
    Info *aux = NULL; 
    while(fread(&record, sizeof(record), 1, v)){
        if(ricercaURL(c, record.url) == NULL){
            //se il record non esiste lo inserisco nella lista
            insTesta(c, record); 
        } else {
            //se il record esiste modifico le views ed eventualmente l'orario
            aux = ricercaURL(c, record.url); 
            aux->views += 1; 
            if(record.ora > aux->ora){
                aux->ora = record.ora; 
                aux->minuti = record.minuti; 
            } else if(record.ora == aux->ora){
                if(record.minuti > aux->minuti){
                    aux->minuti = record.minuti; 
                }
            }
        }
    }
}

void stampa(Lista c){
    while(c){
        if(c->views >= 5){
            printf("%s %d %d:%d\n", c->url, c->views, c->ora, c->minuti); 
        }
        c = c->next; 
    }
}

void listaOrdinataViewsDrecrescente(Lista *c){
    Info *primo = *c; 
    Info *secondo = primo->next; 
    Visite tmp; 
    int tmp_views; 
    //ordino la lista, la funzione è così lunga per gestire lo swap nelle varie situaizoni
    while(primo){
        while(secondo){
            if(secondo->views > primo->views){
                strcpy(tmp.url, secondo->url); 
                strcpy(secondo->url, primo->url); 
                strcpy(primo->url, tmp.url); 
                tmp.ora = secondo->ora; 
                secondo->ora = primo->ora; 
                primo->ora = tmp.ora; 
                tmp.minuti = secondo->minuti; 
                secondo->minuti = primo->minuti; 
                primo->minuti = tmp.minuti; 
                tmp_views = secondo->views; 
                secondo->views = primo->views; 
                primo->views = tmp_views; 
            } else if(secondo->views == primo->views){
                if(secondo->ora > primo->ora){
                    strcpy(tmp.url, secondo->url); 
                    strcpy(secondo->url, primo->url); 
                    strcpy(primo->url, tmp.url); 
                    tmp.ora = secondo->ora; 
                    secondo->ora = primo->ora; 
                    primo->ora = tmp.ora; 
                    tmp.minuti = secondo->minuti; 
                    secondo->minuti = primo->minuti; 
                    primo->minuti = tmp.minuti; 
                } else if(secondo->ora == primo->ora){
                    if(secondo->minuti > primo->minuti){
                        strcpy(tmp.url, secondo->url); 
                        strcpy(secondo->url, primo->url); 
                        strcpy(primo->url, tmp.url); 
                        tmp.minuti = secondo->minuti; 
                        secondo->minuti = primo->minuti; 
                        primo->minuti = tmp.minuti; 
                    }
                }
            }
            secondo = secondo->next; 
        }
        primo = primo->next;
        if(primo){
            //se primo è diverso da null allora assegno il valore al puntatore secondo
            secondo = primo->next; 
        }
    }
}
