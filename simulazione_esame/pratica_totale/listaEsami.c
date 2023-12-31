#include "listaEsami.h"

int checkEsitoEsame(int punteggio, char tipo){
    if(tipo == 'P'){
        if(punteggio >= 12){
            return punteggio; 
        } else {
            return 0; 
        }
    } else if(tipo == 'T'){
        if(punteggio >= 6){
            return punteggio; 
        } else {
            return 0; 
        }
    }
}

void insTesta(Lista *l, int matricola, int punteggio, char tipo){

    punteggio = checkEsitoEsame(punteggio, tipo); 

    Nodo* aux = (Nodo*)malloc(sizeof(Nodo)); 
    aux->matricola = matricola; 
    aux->punteggio = punteggio; 
    aux->next = *l; 
    *l = aux; 

}

int ricerca(Lista l, int matricola){
    while(l){
        if(l->matricola == matricola){
            return 1; 
        }
        l = l->next; 
    }
    return 0; 
}

void aggiornamentoPunteggio(Lista *l, int matricola, int punteggio, int tipo){

    punteggio = checkEsitoEsame(punteggio, tipo); 

    Nodo *modifica = *l; 

    while(modifica){
        if(modifica->matricola == matricola){
            if(modifica->punteggio > 0){
                modifica->punteggio += punteggio; 
            }
        }
        modifica = modifica->next; 
    }
}

void stampaLista(Lista l){
    while(l){
        printf("%d %d\n", l->matricola, l->punteggio); 
        l = l->next; 
    }
}

void stampaEsitiEsami(Lista l){
    while(l){
        if(l->punteggio >= 18 && l->punteggio <=30){
            printf("%d %d\n", l->matricola, l->punteggio); 
        } else if(l->punteggio > 30){
            printf("%d 30 e lode\n", l->matricola); 
        } else {
            printf("%d non superato\n", l->matricola); 
        }

        l = l->next; 
    }
}

void listaDecrescente(Lista *l){
    Nodo *pl = *l; 
    Nodo *k = pl->next;  

    int tmp; 

    while(pl){
        while(k){
            if(k->punteggio > pl->punteggio){
                tmp = pl->punteggio; 
                pl->punteggio = k->punteggio; 
                k->punteggio = tmp; 
            } else if(k->punteggio == pl->punteggio){
                if(k->matricola > pl->matricola); {
                    tmp = pl->matricola; 
                    pl->matricola = k->matricola; 
                    k->matricola = tmp; 
                }
            }
            k = k->next; 
        }
        pl = pl->next; 
        if(pl){
            k = pl->next;
        } 
    }
}
