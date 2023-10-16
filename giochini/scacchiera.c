#include <stdio.h>

int main()
{
    printf("Scacchiera da 8X8 verrà fornito in output il colore della scacchiera\n");

    int x, y;
input:
    printf("Inserisci la coordinata X: \n");
    scanf("%d", &x);

    printf("Inserisci la coordinata Y: \n");
    scanf("%d", &y);

    if (x > 8 || x < 0)
    {
        goto input;
    }
    if (y > 8 || y < 0)
    {
        goto input;
    }

    if (y % 2 == 0)
    {
        if (x % 2 == 0)
        {
            printf("\nBianco\n");
        }
        else
        {
            printf("\nNero\n");
        }
    }
    else
    {
        if (x % 2 == 0)
        {
            printf("\nNero\n");
        }
        else
        {
            printf("\nBianco\n");
        }
    }

    return 0;
}