#include <stdio.h>

int main()
{
    int n, somma;
    int max = 0; 
    int count = 0; 
    int min = 0; 
    float media;
    do
    {
        printf("Inserisci un insieme di numeri tra 1 e 100: \n");
        scanf("%d", &n);

        if (n > 0)
        {
            count++;
            somma += n;
            media = somma / count;
            if (n > max)
            {
                max = n;
            }
            if (n < min)
            {
                min = n;
            }
        }
    } while (n > 0 && n <= 100);

    printf("\nMedia dei numeri inseriti: %i\n", media);
    printf("\nSomma dei numeri inseriti: %d\n", somma);
    printf("\nMinimo: %d\n", min);
    printf("\nMassimo: %d\n", max);

    return 0;
}