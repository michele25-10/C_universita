#include <stdio.h>

int main()
{
    int x;
    printf("Inserisci un numero e verrà restituito il valore assoluto\n");
    scanf("%d", &x);

    printf("\nValore Assoluto: %d\n", (x >= 0 ? x : (x * -1)));

    return 0;
}