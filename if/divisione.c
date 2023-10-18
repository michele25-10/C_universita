#include <stdio.h>

int main()
{

    int a, b;
    printf("Inserisci il numero da dividere: \n");
    scanf("%d", &a);

    printf("\nInserisci il divisore: \n");
    scanf("%d", &b);

    if (b == 0)
    {
        printf("\nNon puoi dividere un numero per 0\n");
    }
    else
    {
        if (a % b == 0)
        {
            printf("\nIl risultato della divisione è: %d\n", (a / b));
        }
        else
        {
            printf("\nIl risultato della divisione è: %d con resto: %d\n", (a / b), (a % b));
        }
    }

    return 0;
}