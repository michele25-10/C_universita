#include <stdio.h>
#include <string.h>

int main()
{
    int numero;

    do
    {
        printf("Inserisci un numero decimale compreso tra 0 e 255: \n");
        scanf("%d", &numero);
    } while (numero > 255);

    char stringa_binaria[8] = "00000000";

    if (numero >= 128)
    {
        numero -= 128;
        stringa_binaria[7] = '1';
    }
    if (numero >= 64)
    {
        numero -= 64;
        stringa_binaria[6] = '1';
    }
    if (numero >= 32)
    {
        numero -= 32;
        stringa_binaria[5] = '1';
    }
    if (numero >= 16)
    {
        numero -= 16;
        stringa_binaria[4] = '1';
    }
    if (numero >= 8)
    {
        numero -= 8;
        stringa_binaria[3] = '1';
    }
    if (numero >= 4)
    {
        numero -= 4;
        stringa_binaria[2] = '1';
    }
    if (numero >= 2)
    {
        numero -= 2;
        stringa_binaria[1] = '1';
    }
    if (numero == 1)
    {
        numero -= 1;
        stringa_binaria[0] = '1';
    }

    printf("\nIl numero in binario è: %s\n", stringa_binaria);

    return 0;
}