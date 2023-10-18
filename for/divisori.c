#include <stdio.h>

int main()
{
    int n;
    printf("Inserisci un numero: \n");
    scanf("%d", &n);

    int i;
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("\nIl numero è divisibile per: %d\n", i);
        }
    }

    return 0;
}