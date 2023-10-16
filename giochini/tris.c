#include <stdio.h>

int main()
{
    int x1, y1;
    printf("Inserisci la prima X: \n");
    scanf("%d", &x1);
    printf("\nInserisci la prima Y: \n");
    scanf("%d", &y1);

    int x2, y2;
    printf("\nInserisci la seconda X: \n");
    scanf("%d", &x2);
    printf("\nInserisci la seconda Y: \n");
    scanf("%d", &y2);

    int x3, y3;
    printf("\nInserisci la seconda X: \n");
    scanf("%d", &x3);
    printf("\nInserisci la seconda Y: \n");
    scanf("%d", &y3);

    if (x1 == x2 && x2 == x3)
    {
        printf("\nTRIS\n");
    }
    else if (y1 == y2  && y2 == y3)
    {
        printf("\nTRIS\n");
    }
    else if (x1 == y1 && x2 == y2 && x3 == y3)
    {
        printf("\nTRIS\n");
    }
    else if (x1 == y3 && x2 == y2 && x3 == y1)
    {
        printf("\nTRIS\n");
    }
    else{
        printf("\nNon è una combinazione vincente\n");
    }

    return 0;
}