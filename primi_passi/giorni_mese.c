#include <stdio.h>

int main()
{
    printf("Inserisci il mese: \n");
    int mese;
    scanf("%d", &mese);

    printf("Inserisci l'anno: \n");
    int anno;
    scanf("%d", &anno);

    if (mese == 2)
    {
        if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0))
        {

            printf("\nI giorni sono 29\n");
        }
        else
        {
            printf("\nI giorni sono 28\n");
        }
    }

    if (mese == 1 || mese == 3 || mese == 5 || mese == 7 || mese == 8 || mese == 10 || mese == 12)
    {
        printf("\nI giorni sono 31\n");
    }

    if (mese == 4 || mese == 6 || mese == 9 || mese == 11)
    {
        printf("\nI giorni sono 30\n");
    }

    return 0;
}