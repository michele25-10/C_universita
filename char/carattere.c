#include <stdio.h>

int main()
{
    char carattere;
    printf("Inserisci un carattere: \n");
    scanf("%c", &carattere);

    int ascii = carattere;
    if (ascii > 64 && ascii < 91)
    {
        printf("\nLa lettera è maiuscola\n");
    }
    else if (ascii > 96 && ascii < 123)
    {
        printf("\nLa lettera è minuscola\n");
    }
    else if (ascii > 47 && ascii < 58)
    {
        printf("\nIl carattere è un numero\n");
    }

    return 0;
}