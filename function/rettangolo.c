#include <stdio.h>

void riga(int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int base, altezza;
    printf("Inserisci la base del rettangolo: \n");
    scanf("%d", &base);

    printf("\nInserisci l'altezza del rettangolo: \n");
    scanf("%d", &altezza);

    riga(base, altezza);

    return 0;
}