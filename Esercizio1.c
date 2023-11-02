#include <stdio.h>

int MCD(int a, int b)
{
    int t;
    if (a > b)
    {
        t = b;
        b = a;
        a = t;
    }
    int m = 1;
    int i = 2;

    while (i <= a)
    {
        if (a % i == 0)
        {
            if (b % i == 0)
            {
                m = i;
            }
        }
        i++;
    }

    return m;
};

int main()
{
    const int array_length = 10;
    int vett[array_length];
    int m;

    printf("Inserisci numero maggiore di 0\n");

    do
    {
        printf("\nNumero: \n");
        scanf("%d", &m);
    } while (m < 0);

    for (int i = 1; i <= array_length; i++)
    {
        printf("MCD(%d, %d) = %d\n", m, i, MCD(m, i)); 
    }

    return 0;
}
