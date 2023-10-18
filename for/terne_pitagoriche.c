#include <stdio.h>

int main()
{
    int n;
    printf("Inserisci un numero: \n");
    scanf("%d", &n);

    int m;
    for (m = 1; m < n; m++)
    {
        if (m % 2 == 1)
        {
            int a = m;
            int b = (m * m - 1) / 2;
            int c = (m * m + 1) / 2;
            if (c <= n)
            {
                printf("\nTerna (%d, %d, %d)\n", a, b, c);
            }
            else
            {
                break; 
            }
        }
    }

    return 0;
}