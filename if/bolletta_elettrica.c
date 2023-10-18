#include <stdio.h>

int main()
{
    printf("Inserisci il numero di KWh di questo mese: \n");
    float kwh;
    scanf("%f", &kwh);

    float euro = 0;
    if (kwh < 200)
    {
        euro = kwh * 1;
    }
    else if (kwh > 200 && kwh < 400)
    {
        euro = (200 * 1) + ((kwh - 200) * 2);
    }
    else if (kwh > 400 && kwh < 600)
    {
        euro = (200 * 1) + (200 * 2) + ((kwh - 400) * 3);
    }
    else if (kwh > 600)
    {
        euro = (200 * 1) + (200 * 2) + (200 * 3) + ((kwh - 600) * 4);
    }

    printf("La bolletta costerà: %f\n", euro);
}