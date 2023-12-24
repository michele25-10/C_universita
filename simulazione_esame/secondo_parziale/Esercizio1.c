#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define DIM 100
#define DIM_STRINGA 30

typedef char contenutoFile[DIM][DIM_STRINGA]; 

int checkDoppioni(contenutoFile arr_no_doppioni, char *str){
    for(int i = 0; i < DIM; i++){
        if(strcmp(arr_no_doppioni[i], str) == 0){
            return 1;
        }
    }

    return 0; 
}

void arrayStringheAscendente(contenutoFile arr_str, contenutoFile arr_no_doppioni){
    int l = 0; 
    char tmp[DIM_STRINGA]; 
    for(int i = 0; i < DIM; i++){
        for(int j = i + 1; j < DIM; j++){
            if(strlen(arr_str[j]) > strlen(arr_str[i])){
                strcpy(tmp, arr_str[i]); 
                strcpy(arr_str[i], arr_str[j]);
                strcpy(arr_str[j], tmp);  
            }
        }

        if(checkDoppioni(arr_no_doppioni, arr_str[i]) == 0){
            strcpy(arr_no_doppioni[l], arr_str[i]); 
            l++; 
        }

    }
}

int countStringa(contenutoFile arr_str, char *str){
    int count = 0; 
    for(int i = 0; i < DIM; i++){
        if(strlen(arr_str[i]) > 0){
            if(strcmp(str, arr_str[i]) == 0){
                count++; 
            }
        }
    }
    return count; 
} 

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("\nNon sono stati inseriti argomenti a sufficienza!\n"); 
        exit(-1); 
    }

    FILE *fp = fopen(argv[1], "r"); 
    if(fp == NULL){
        printf("\nErrore nell'apertura del file\n"); 
        exit(-1); 
    }

    contenutoFile arr_str; 
    contenutoFile arr_no_doppioni; 
    int i = 0; 
    while(feof(fp) == 0){
        fscanf(fp, "%s ", arr_str[i]); 
        i++; 
    }

    arrayStringheAscendente(arr_str, arr_no_doppioni); 

    for(int k = 0; k < i; k++){
        int qta = countStringa(arr_str ,arr_no_doppioni[k]); 
        if(qta >= 4){
            printf("\n%s %d", arr_no_doppioni[k], qta); 
        }
    }

    return 0; 
}