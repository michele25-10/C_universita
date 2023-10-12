#include <stdio.h>

int main()
{
    printf("Inserisci il giorno\n");
    int giorno;
    scanf("%d", &giorno);

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
            if (giorno == 29)
            {
                giorno = 1;
                mese++;
                printf("Domani è il %d-%d-%d\n", giorno, mese, anno);
            }
            else
            {
                giorno++;
                printf("Domani è il %d-%d-%d\n", giorno, mese, anno);
            }
        }
        else
        {
            if (giorno == 28)
            {
                giorno = 1;
                mese++;
                printf("Domani è il %d-%d-%d\n", giorno, mese, anno);
            }
            else
            {
                printf("Domani è il %d-%d-%d\n", giorno++, mese, anno);
            }
        }
    }
    else if (mese == 1 || mese == 3 || mese == 5 || mese == 7 || mese == 8 || mese == 10)
    {
        if (giorno == 31)
        {
            giorno = 1;
            mese++;
            printf("Domani è il %d-%d-%d\n", giorno, mese, anno);
        }
        else
        {
            printf("Domani è il %d-%d-%d\n", giorno++, mese, anno);
        }
    }
    else if (mese == 4 || mese == 6 || mese == 9 || mese == 11)
    {
        if (giorno == 30)
        {
            giorno = 1;
            mese++;
            printf("Domani è il %d-%d-%d\n", giorno, mese, anno);
        }
        else
        {
            printf("Domani è il %d-%d-%d\n", giorno++, mese, anno);
        }
    }
    else
    {
        // Caso di Dicembre
        if (giorno == 31)
        {
            giorno = 1;
            mese = 1;
            anno++;
            printf("Domani è il %d-%d-%d\n", giorno, mese, anno);
        }
        else
        {
            printf("Domani è il %d-%d-%d\n", giorno++, mese, anno);
        }
    }

    return 0;
}