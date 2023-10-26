#include <stdio.h>

int main()
{

    float n;
    do
    {
        printf("Inserisci un numero reale: \n");
        scanf("%f", &n);
    } while (n < 0);

    float successione = 1;

    do
    {
        successione = (successione + n / successione) / 2.0;
    } while (! (successione * successione - n > -1e-5 && successione * successione - n < 1e-5));

    printf("%.2f", successione);

    return 0;
}