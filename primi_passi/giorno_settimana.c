#include <stdio.h>

int main(){
    int giorno, mese, anno;

    do {
        printf("Inserisci il giorno: \n");
        scanf("%d", &giorno);
    }while(giorno > 31);

    do {
        printf("\nInserisci il mese: \n");
        scanf("%d", &mese);
    }while(mese > 12);

    do{
        printf("\nInserisci l'anno: \n");
        scanf("%d", &anno);
    }while(anno < 0);

    int N_zero = (mese - 14) / 12;

    int N_uno = (1461 * (anno + 4800 + N_zero)) / 4;

    int N_due = (367 * (mese - 2 - (12 * N_zero)))/12;

    int N_tre = (3 * (anno + 4900 + N_zero))/400;

    int giorno_giuliano = N_uno + N_due - N_tre + giorno - 32075;

    int giorno_settimana = giorno_giuliano%7;

    switch (giorno_settimana)
    {
    case 0:
        printf("\nIl giorno della settimana è LUNEDI'\n");
        break;
    case 1:
        printf("\nIl giorno della settimana è MARTEDI'\n");
        break;
    case 2:
        printf("\nIl giorno della settimana è MERCOLEDI'\n");
        break;
    case 3:
        printf("\nIl giorno della settimana è GIOVEDI'\n");
        break;
    case 4:
        printf("\nIl giorno della settimana è VENERDI'\n");
        break;
    case 5:
        printf("\nIl giorno della settimana è SABATO'\n");
        break;
    case 6:
        printf("\nIl giorno della settimana è DOMENICA'\n");
        break;
    }

    return 0;
}