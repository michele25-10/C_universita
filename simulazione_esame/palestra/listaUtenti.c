#include "listaUtenti.h"

void insTesta(Iscritti *i, char *codicefiscale, int in1, int in2, int in3, int n_err, unsigned short int abilitato){
    Persona* aux = (Persona*)malloc(sizeof(Persona)); 
    strcpy(aux->CF, codicefiscale); 
    aux->ingresso1 = in1; 
    aux->ingresso2 = in2; 
    aux->ingresso3 = in3; 
    aux->n_errori = n_err; 
    aux->abilitato = abilitato; 
    aux->next = *i; 
    *i = aux; 
}

void popolamentoIscritti(Iscritti *i, FILE *cf){
    char codicefiscale[17]; 
    while(fread(&codicefiscale, sizeof(char) * 17, 1, cf)){
        insTesta(i, codicefiscale, 4, 4, 4, 0, 1); 
    }
}

Persona* ricerca(Iscritti *i, char *cf){
    Persona* aux = *i;
    while(aux){
        if(strcmp(aux->CF, cf) == 0 ){
            return aux; 
        }
        aux = aux->next; 
    } 
    return 0; 
} 


int ingresso(int n_ingressi, char *cf, char* last_cf, int *count_error, int tipo_attivita){
    if(n_ingressi > 0){
        n_ingressi--;
        return n_ingressi; 
    } else {
        printf("Codice Fiscale %s, attivita %d: Accesso Negato\n", cf, tipo_attivita); 
        if(strcmp(cf, last_cf) == 0){
            (*count_error)++;
        } else {
            *count_error = 0; 
            (*count_error)++;
        }
        return -1; 
    }
}

void controlloIngressi(Iscritti *i, FILE *ing){

    printf("\nControllo accessi:\n"); 

    char cf[17];
    char last_cf[17]; 
    int count_error = 0; 
    int tipo_att;  
    int tmp; 
    while(!feof(ing)){
        fscanf(ing, "%s %d ", cf, &tipo_att); 
        Persona *aux = ricerca(i, cf) ? ricerca(i, cf) : NULL; 
        if(aux != NULL && aux->abilitato == 1){
            switch (tipo_att){
                case 1:
                    tmp = ingresso(aux->ingresso1, cf, last_cf, &count_error, 1);
                    aux->ingresso1 = tmp != -1 ? tmp :aux->ingresso1;
                    break;
                case 2:
                    tmp = ingresso(aux->ingresso2, cf, last_cf, &count_error, 1);
                    aux->ingresso2 = tmp != -1 ? tmp :aux->ingresso2;                    
                    break;
                case 3:
                    tmp = ingresso(aux->ingresso3, cf, last_cf, &count_error, 1);
                    aux->ingresso3 = tmp != -1 ? tmp :aux->ingresso3;
                    break;
            }
        
            if(count_error == 3){
                printf("Utente %s DISABILITATO\n", cf); 
                aux->abilitato = 0; 
            }
        }
        strcpy(last_cf, cf); 
    }
}

void stampaIngressiResidui(Iscritti i){
    printf("\nIngressi residui\n");
    while(i){
        if(i->abilitato == 1){
            printf("%s %d %d %d\n", i->CF, i->ingresso1, i->ingresso2, i->ingresso3); 
        } else {
            printf("%s utente disabilitato\n", i->CF); 
        }

        i = i->next; 
    }
}
