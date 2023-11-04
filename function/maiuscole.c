#include <stdio.h>

char toUpperCase(char c){
    if(c >='a' && c <= 'z'){
        c = c+ ('A' - 'a'); 
    }
    return c; 
}

int main(){
    char c; 

    do{
        scanf("%c", &c); 
        printf("%c", toUpperCase(c)); 
    }while(c != '\n');

    return 0; 
}