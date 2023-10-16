#include <stdio.h>

int main()
{

    int a;

increment:
    printf("Numero in input: \n");
    scanf("%d", &a);

    if (a == 0)
    {
        printf("\nFINE\n");
    }

    if (a > 0)
    {
        printf("\nIl numero duplicato è: %d\n", a * 2);
        goto increment;
    }

    return 0;
}