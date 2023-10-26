#include <stdio.h>

int main()
{
    int n1, n2; 
    int a, b, resto; 
    printf("Inserisci il primo numero: \n");
    scanf("%d", &n1);

    printf("\nInserisci il secondo numero (0 <= b <a): \n");
    scanf("%d", &n2);

    a = n1; 
    b = n2; 

    while (b != 0)
    {
        resto = a%b; 
        a = b; 
        b = resto; 
    }

    printf("\nL'MCD di (%d, %d) è: %d\n", n1, n2, a);

    return 0; 
}