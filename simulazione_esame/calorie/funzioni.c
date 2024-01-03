#include "funzioni.h"

void insTestaCalorie(TabellaCalorie *tc, Etichetta e){
    RecordCalorico *rc = (RecordCalorico*)malloc(sizeof(RecordCalorico)); 
    rc->cibo = e; 
    rc->next = *tc; 
    *tc = rc; 
}

void popolamentoPasti(FILE *fp, Pasti *p){
    while(!feof(fp)){
        Pasto *aux = (Pasto*)malloc(sizeof(Pasto)); 
        fscanf(fp, "%s %d ", aux->nome, &aux->grammi); 
        aux->next = *p; 
        *p = aux; 
    }
}

float ricercaEtichetta(TabellaCalorie tc, char *nome){
    float cal = 0; 
    unsigned short int trovato = 0; 
    while(tc){
        if(strcmp(tc->cibo.nome, nome) == 0){
            trovato = 1; 
            cal = tc->cibo.calorie; 
        }
        tc = tc->next; 
    }

    if(trovato == 1){
        return (float)cal; 
    } else {
        return -1.00; 
    }
}

float calcoloCalorie(Pasti p, TabellaCalorie tc){
    float tot = 0; 
    float cal = 0; 
    while(p){   
        cal = ricercaEtichetta(tc, p->nome); 
        if(cal == -1){
            printf("\nIl seguente alimento '%s' non è presente nel file delle calorie\n", p->nome); 
            exit(-1); 
        } else {
            tot += cal * (float)(p->grammi / 100.0); 
        }
        p = p->next; 
    }

    return tot; 
}
