#include <stdio.h>

int main()
{
    int misura = 0;
    int menu = 0;

    printf("Inserisci una misura: \n");
    scanf("%d", &misura);

    while (misura > 0)
    {

        do
        {
            printf("\nDigita: \n1 --> miglia\n2 --> libbre\n");
            scanf("%d", &menu);
        } while (menu > 2 || menu < 1);

        switch (menu)
        {
        case 1:
            printf("\nMisura in km convertita in miglia: %.2f\n", (float)(misura * 0.621371));
            break;

        case 2:
            printf("\nMisura in kg convertita in libbre: %.2f\n", (float)(misura * 2.20462));
            break;
        }

        printf("\nInserisci una misura: \n");
        scanf("%d", &misura);
    }
}