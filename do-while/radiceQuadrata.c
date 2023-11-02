#include <stdio.h>

float media(float x, float y)
{
    return (x + y) / 2.0;
}

float radq(float n)
{
    float successione = 1;
    do
    {
        successione = media(successione, n / successione);
    } while (!(successione * successione - n > -1e-5 && successione * successione - n < 1e-5));
    
    return successione;
};

int main()
{

    float n;
    do
    {
        printf("Inserisci un numero reale: \n");
        scanf("%f", &n);
    } while (n < 0);

    printf("%.2f\n", radq(n));

    return 0;
}
