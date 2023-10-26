#include <stdio.h>

int main()
{
    int const length = 20;
    char str[length];
    printf("Inserisci una stringa di massimo 20 caratteri: \n");
    scanf(" %s", &str);

    for (int i = 0; i < length; i++)
    {
        if(str[i] > 96 && str[i] < 123)
        {
            printf("\n%d", i); 
            printf("%c", ((int) str[i]) - 32); 
        }
        else{
            printf("%c", str[i]); 
        }
    }

    printf("\n"); 

    return 0; 
}