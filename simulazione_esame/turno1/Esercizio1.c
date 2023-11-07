#include <stdio.h>

float valoreAssoluto(float numero)
{
    if (numero < 0)
    {
        return numero * (-1);
    }
    else
    {
        return numero;
    }
}

float radice(float a)
{
    float x = 1.0;
    while (valoreAssoluto(x * x - a) > 1e-5)
    {
        x = (x + a / x) / 2.0;
    }
    return x;
}

float f(int n)
{
    return radice((float)(n - 1) / (n + 1));
}

int main()
{
    int a, b;
    do
    {
        printf("\nInserisci numero A: \n");
        scanf("%d", &a);
    } while (a < 0);

    do
    {
        printf("\nInserisci numero B: \n");
        scanf("%d", &b);
    } while (b < 0);

    while (a <= b)
    {
        if (a % 2 == 1)
        {
            printf("\n%d\n", a);
        }
        else
        {
            printf("%f", f(a));
        }
        a++;
    }

    return 0;
}