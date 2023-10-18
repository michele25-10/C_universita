#include <stdio.h>

int main()
{
    int n;
    printf("Inserisci un numero: \n");
    scanf("%d", &n);

    int i, fattorizzazione = 1;
    for (i = n; i > 0; i--)
    {
        fattorizzazione *= i;
    }

    printf("\nLa fattorizzazione è: %d\n", fattorizzazione);

    return 0;
}