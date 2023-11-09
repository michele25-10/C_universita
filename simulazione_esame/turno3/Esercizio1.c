#include <stdio.h>

int primo(int n)
{
    int i, potenzialmente_primo;
    potenzialmente_primo = n % 2 || n == 2;
    i = 3;
    while (potenzialmente_primo && i * i <= n)
    {
        if (n % i == 0)
            potenzialmente_primo = 0;
        i += 2;
    }

    return potenzialmente_primo;
}

int f(int n, int flag_count)
{
    int i = 2;
    int count = 0;
    int max;
    while (i <= n)
    {
        if (primo(i) == 1)
        {
            count++;
            max = i;
        }
        i++;
    }
    if (flag_count == 0)
    {
        return max;
    }
    else
    {
        return count;
    }
}

int main()
{
    int m;
    printf("Inserisci numero M\n");
    scanf("%d", &m);
    int n;
    for (n = 2; n <= m; n++)
    {
        printf("\n%d %d %d", n, f(n, 0), f(n, 1));
    }

    printf("\n"); 

    return 0;
}