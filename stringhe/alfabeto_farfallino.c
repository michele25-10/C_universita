#include <stdio.h>

#define DIM 100

int str_len(char *str){
    int dim_str = 0;
    int i = 0; 
    for (i = 0 ; str[i] != '\0'; i++)
    {
        dim_str++;
    }
    return dim_str; 
}

int main()
{
    char str[DIM];
    printf("Inserisci stringa\n");
    scanf("%s", str);

    int dim_str = str_len(str); 

    printf("\nLa parola %s è lunga %d caratteri\n\nALFABETO FARFALLINO\n", str, dim_str); 

    char str_farf[DIM]; 
    int k = 0; 
    for(int i = 0; i < dim_str; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            str_farf[k] = str[i];
            k++;
            str_farf[k] = 'f';
            k++;
            str_farf[k] = str[i];
            k++;
        }else{
            str_farf[k] = str[i];
            k++;
        }
    }

    printf("La parola in farfallese è %s di lunghezza %d\n", str_farf, str_len(str_farf)); 

    return 0; 
}