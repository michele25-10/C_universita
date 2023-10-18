#include <stdio.h>

int main()
{
    int n;
    printf("Inserisci un numero: \n");
    scanf("%d", &n);

    int i;
    int check = 0;
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    check = 1;
                }
            }
            if (check == 0)
            {
                printf("\nIl numero è divisibile per il numero primo: %d\n", i);
            }
            check = 0; 
        }
    }

    return 0;
}