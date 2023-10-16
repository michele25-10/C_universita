#include <stdio.h>

int main()
{

    int a;
    printf("Esito esame: \n");
    scanf("%d", &a);

    if (a >= 18 && a <= 20)
    {
        printf("\nSufficiente\n");
    }
    else if (a >= 21 && a <= 23)
    {
        printf("\nDiscreto\n");
    }
    else if (a >= 24 && a <= 26)
    {
        printf("\nBuono\n");
    }
    else if (a >= 27 && a <= 29)
    {
        printf("\nDistinto\n");
    }
    else if (a >= 30 && a <= 32)
    {
        printf("\nOttimo\n");
    }
    else
    {
        printf("\nInsufficiente\n");
    }

    return 0;
}