#include <stdio.h>

int main()
{
    printf("Inserisci il numero di km da convertire: \n");
    float numero_km;
    scanf("%f", &numero_km);

    float mm = numero_km * (1000000);
    float cm = numero_km * (100000);
    float dm = numero_km * (10000);
    float m = numero_km * (1000);
    printf("\nConversioni: \n-\t%f mm;\n-\t%f cm;\n-\t%f dm;\n-\t%f m", mm, cm, dm, m);
    return (0);
}