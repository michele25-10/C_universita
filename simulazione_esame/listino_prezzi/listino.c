#include "listino.h"

void popolamentoListino(Listino *l, FILE *fp){
    Articolo a; 
    while(fread(&a, sizeof(Articolo), 1, fp)){
        Lista* aux = (Lista*)malloc(sizeof(Lista)); 
        aux->art = a; 
        aux->next = *l; 
        *l = aux; 
    }
}

void popolamentoCodici(Codici *c){
    int tmp = 0;
    printf("Inserisci codici:\n"); 
    scanf("%d", &tmp); 
    while(tmp >= 0){
        Codice *cod = (Codice*)malloc(sizeof(Codice)); 
        cod->codice = tmp; 
        cod->next = *c; 
        *c = cod; 
        scanf("%d", &tmp); 
    }
}

int contaArticoli(int codice, Codici c){
    int count = 0; 
    while(c){
        if(c->codice == codice){
            count++; 
        }
        c = c->next;  
    }
    return count; 
}

Articolo ArticoloInfo(int codice, Listino l){
    while(l){
        if(l->art.codice == codice){
            return l->art; 
        }
        l = l->next; 
    }
}

void creazioneScontrino(Listino l, Codici c, FILE *scontrino){
    Codici doppioni = NULL; 
    float totale = 0; 
    int n_articoli; 
    Articolo a; 
    while(c){
        if(contaArticoli(c->codice, doppioni) == 0){
            n_articoli = contaArticoli(c->codice, c); 
            a = ArticoloInfo(c->codice, l); 
            fprintf(scontrino, "%d x %.2f (%s) = %.2f\n", n_articoli, a.prezzo, a.descrizione, (float)(a.prezzo * n_articoli)); 
            totale += (float)(a.prezzo * n_articoli); 
            // popolo la lista dei doppioni 
            Codice *cod = (Codice*)malloc(sizeof(Codice)); 
            cod->codice = c->codice; 
            cod->next = doppioni; 
            doppioni = cod;
        }
        c = c->next; 
    }
    fprintf(scontrino, "Totale: %.2f\n", totale); 
}