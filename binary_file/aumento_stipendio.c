#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char nome[10];
    float stipendio; 
} Persona;

int main(){
    Persona v[50]; 
    FILE *fb;
    fb = fopen("stipendio.dat", "rwb");
    if(fb == NULL){
        exit(-1);
    } 

    int count = 0;  
    while(fread(&v[count], sizeof(Persona), 1, fb) > 0){
        printf("%s, %2.f\n", v[count].nome, v[count].stipendio);
        count ++;
    }

    printf("\n\n\n\n");
    count = 0; 
    fseek(fb, 0, SEEK_SET);
    while(fread(&v[count], sizeof(Persona), 1, fb) > 0){
        if(v[count].stipendio < 1000){
            v[count].stipendio += ((v[count].stipendio)/100)*10; 
            printf("%2.f\n", v[count].stipendio);
            fseek(fb, ftell(fb)-sizeof(Persona), SEEK_SET);
            fwrite(&v[count], sizeof(Persona), 1, fb);
            fseek(fb, ftell(fb) + sizeof(Persona), SEEK_SET);
        }
        count ++;
    }
    fclose(fb);

    fb = fopen("stipendio.dat", "rwb");
    count = 0;  
    fseek(fb, 0, SEEK_SET);
    while(fread(&v[count], sizeof(Persona), 1, fb) > 0){
        printf("%s, %2.f\n", v[count].nome, v[count].stipendio);
        count ++;
    }

    fclose(fb);
    return 0;
}