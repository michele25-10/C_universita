#include <stdio.h>

int primo(int n)
{
    int count = 0;
    int i;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int n;
    printf("Inserisci un numero: \n");
    scanf("%d", &n);

    int count = 0; 

    for (int i = 1; i <= n; i++)
    {
        if (primo(i) == 1)
        {
            printf("Il numero %d è primo\n", i);
            count ++;
        }
        else
        {
            printf("Il numero %d NON è primo\n", i);
        }
    }

    printf("\n\n------------------------------------\nI numeri primi più piccoli di %d sono: %d\n", n, count); 

    return 0;
}
