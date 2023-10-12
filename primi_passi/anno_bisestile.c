#include <stdio.h>

int main()
{
    printf("Inserisci l'anno: \n");
    int anno;
    scanf("%d", &anno);

    if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)){
        printf("\nL'anno %d è bisestile\n", anno);
    } else {
        printf("\nL'anno %d NON è bisestile\n", anno);
    }

    return 0;
}