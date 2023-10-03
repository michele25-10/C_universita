#include <stdio.h>

int main()
{
    const int giorni_settimane = 7;
    const int giorni_mesi = 30;
    const int giorni_annui = 365;
    
    printf("Inserisci il numero di giorni:\n");
    int numero_giorni;
    scanf("%d", &numero_giorni);

    int numero_settimane = numero_giorni / giorni_settimane;
    printf("\nIl numero di settimane sono: %d", numero_settimane);

    int numero_mesi = numero_giorni/giorni_mesi;
    printf("\nIl numero di mesi sono: %d", numero_mesi);

    int numero_anni = numero_giorni/giorni_annui;
    printf("\nIl numero di anni sono: %d\n", numero_anni);
}
