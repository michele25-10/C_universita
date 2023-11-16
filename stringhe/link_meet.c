#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 37

char generazione(){
    return ('a' - 1) + (rand() % ('z' - 'a' + 1));
}

int main(){
    srand(time(NULL));

    char link[DIM] = "https://meet.google.com/";

    for(int i = 24; i < DIM; i++){
        if(i==27 || i == 32){
            link[i] = '-';
        }else{
            link[i] = generazione(); 
        }
    }

    printf("\n%s\n", link); 

    return 0;

}