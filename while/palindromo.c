#include <stdio.h>

int main()
{
    int n, num;
    int reversed, digit;

    printf("Inserire un numero \n");
    scanf("%d", &n);

    num = n;
    reversed = 0;

    while (num > 0)
    {
        digit = num % 10;
        reversed = reversed * 10 + digit;
        num = num / 10;
        printf("\ndigit = %d\n", digit);
        printf("\nreversed = %d\n", reversed);
        printf("\nnum = %d", num);
        printf("\n\n");
    }

    if (n == reversed)
    {
        printf("%d è palindromo\n", n);
    }
    else
    {
        printf("%d non è plaindromo\n", n); 
    }

    return 0; 
}