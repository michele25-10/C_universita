#include <stdio.h>

int main()
{
    int a, b;
    char operazione;
    do
    {
        printf("Inserisci il primo numero: \n");
        scanf("%d", &a);
        printf("\nInserisci il secondo numero: \n");
        scanf("%d", &b);
        printf("\nInserisci l'operazione da eseguire: \n");
        scanf(" %c", &operazione);

        if (a != 0 && b != 0)
        {
            switch (operazione)
            {
            case 42:
                printf("\n%d %c %d = %d\n", a, operazione, b, (a * b));
                break;
            case 43:
                printf("\n%d %c %d = %d\n", a, operazione, b, (a + b));
                break;
            case 45:
                printf("\n%d %c %d = %d\n", a, operazione, b, (a - b));
                break;
            case 47:
                if (b != 0)
                {
                    printf("\n%d %c %d = %d\n", a, operazione, b, (a / b));
                }
                else
                {
                    printf("\nIl divisore non può essere uguale a 0\n");
                }
                break;
            case 37:
                printf("\n%d %c %d = %d\n", a, operazione, b, (a % b));
                break;
            case 100:
                if (b != 0)
                {
                    printf("\n%d / %d = %.2f\n", a, b, (float)(a / b));
                }
                else
                {
                    printf("\nIl divisore non può essere uguale a 0\n");
                }
                break;
            default:
                printf("\nErrore, l'operazione inserita non è consentita\n");
            }
        }
    } while (a != 0 || b != 0);

    return 0;
}
