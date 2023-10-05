#include <stdio.h>

int Giorno_Giuliano(int giorno, int mese, int anno) {
    int N_zero = (mese - 14) / 12;

    int N_uno = (1461 * (anno + 4800 + N_zero)) / 4;

    int N_due = (367 * (mese - 2 - (12 * N_zero)))/12;

    int N_tre = (3 * (anno + 4900 + N_zero))/400;

    int giorno_giuliano = N_uno + N_due - N_tre + giorno - 32075;

    return giorno_giuliano; 
}

int main(){
    int giorno1, mese1, anno1;

    printf("Inserisci la PRIMA data\n");
    do {
        printf("Inserisci il primo giorno: \n");
        scanf("%d", &giorno1);
    }while(giorno1 > 31);

    do {
        printf("\nInserisci il mese: \n");
        scanf("%d", &mese1);
    }while(mese1 > 12);

    do{
        printf("\nInserisci l'anno: \n");
        scanf("%d", &anno1);
    }while(anno1 < 0);

    int giorno2, mese2, anno2;
    printf("\n\nInserisci la SECONDA data\n");
    do {
        printf("Inserisci il primo giorno: \n");
        scanf("%d", &giorno2);
    }while(giorno2 > 31);

    do {
        printf("\nInserisci il mese: \n");
        scanf("%d", &mese2);
    }while(mese2 > 12);

    do{
        printf("\nInserisci l'anno: \n");
        scanf("%d", &anno2);
    }while(anno2 < 0);

    int differenza = Giorno_Giuliano(giorno1, mese1, anno1) - Giorno_Giuliano(giorno2, mese2, anno2);

    printf("\nLa differenza è: %d\n", differenza); 
}