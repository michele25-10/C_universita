#include <stdio.h>

int MCD(int a, int b)
{
    while (a != b)
    {
        if (a < b)
        {
            b = b - a;
        }
        else
        {
            a = a - b;
        }
    }
    return a;
}

int main()
{
    int m;
    printf("Inserisci un numero M: \n");
    scanf("%d", &m);

    int j, i;
    for (i = 1; i <= m; i++)
    {
        printf("\n");
        for (j = 1; j <= m; j++)
        {
            printf("%.3f\t", (float)1/MCD(i, j)); 
        }
    }

    return 0; 
}