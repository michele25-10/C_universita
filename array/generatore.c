#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INDICE 30

int main(){
    srand(time(NULL)); 
    for(int i = 0; i<INDICE; i++){
        printf("%d\n", rand() % 31);
    }
    printf("-1"); 

    return 0;
}