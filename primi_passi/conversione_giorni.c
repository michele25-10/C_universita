#include <stdio.h>

int main()
{
    const int settimane_annue = 52;
    const int mesi_annui = 12;
    const int giorni_annui = 365;
    
    printf("Inserisci il numero di giorni:\n");
    int numero_giorni;
    scanf("%d", &numero_giorni);

    int numero_settimane = numero_giorni / settimane_annue;
    printf("\nIl numero di settimane sono: %d", numero_settimane);

    int numero_mesi = numero_giorni/mesi_annui;
    printf("\nIl numero di mesi sono: %d", numero_settimane);

    int numero_anni = numero_giorni/giorni_annui;
    printf("\nIl numero di anni sono: %d\n", numero_anni);
}