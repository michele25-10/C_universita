#include <stdio.h>

void star()
{
    printf("********************\n");
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        star();
    }

    return 0;
}