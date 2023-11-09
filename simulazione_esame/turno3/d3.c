#include <stdio.h>

int main(){
 int i = 10000;
 while(i > 0){
    if(i % 3){
        i /= 3;
    } else {
        i--;
    }
 }
 return 0;
}