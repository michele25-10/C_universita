#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char nome[10];
    float stipendio; 
} Persona;

int main(){
    Persona v[50]; 
    FILE *fb;
    fb = fopen("stipendio.dat", "r+");
    if(fb == NULL){
        exit(-1);
    } 

    int count = 0; 
    fseek(fb, 0, SEEK_SET);
    while(fread(&v[count], sizeof(Persona), 1, fb) > 0){
        printf("%s, %2.f\n", v[count].nome, v[count].stipendio);
        if(v[count].stipendio < 1000){
            v[count].stipendio += ((v[count].stipendio)/100)*10; 
            fseek(fb, ftell(fb)-sizeof(Persona), SEEK_SET);
            fwrite(&v[count], sizeof(Persona), 1, fb);
        }
        count ++;
    }

    printf("\n\n\n\n");

    count = 0;  
    rewind(fb);
    while(fread(&v[count], sizeof(Persona), 1, fb) > 0){
        printf("%s, %2.f\n", v[count].nome, v[count].stipendio);
        count ++;
    }

    fclose(fb);
    return 0;
}