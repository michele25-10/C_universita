#include <stdio.h>

int main()
{

    int x, y;
    printf("Coordinate X: \n");
    scanf("%d", &x);

    printf("Coordinate Y: \n");
    scanf("%d", &y);

    if (x == 0 && y == 0)
    {
        printf("\nOrigine\n");
    }
    else if (x == 0 && y > 0)
    {
        printf("\nAsse Y\n");
    }
    else if (x > 0 && y == 0)
    {
        printf("\nAsse X\n");
    }
    else if (x > 0 && y > 0)
    {
        printf("\nPrimo quadrante\n");
    }
    else if (x > 0 && y < 0)
    {
        printf("\nQuarto quadrante\n");
    }
    else if (x < 0 && y > 0)
    {
        printf("\nPrimo quadrante\n");
    }
    else
    {
        printf("\nTerzo quadrante\n");
    }

    return 0;
}