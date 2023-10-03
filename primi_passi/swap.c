#include <stdio.h>

int main() {
    int a = 4;
    int b = 7;
    printf("PRIMA: a-->%d \t b-->%d", a, b);

    int tmp = a;
    a = b;
    b = tmp; 

    printf("\nDOPO:  a-->%d \t b-->%d\n", a, b);
}