#include <stdio.h>

int main(){
    int i = 1;

    while (i < 1000000){
        i += i % 4 ? 3 : 5;
    }

    return 0;
}