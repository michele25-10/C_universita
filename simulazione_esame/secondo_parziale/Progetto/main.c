#include "listaParole.h"

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("\nNon sono stati inseriti argomenti a sufficienza!\n"); 
        exit(-1); 
    }
    
    Lista ParoleDaEvitare = NULL; 
    
    if(argc > 2){
        int m = 2; 
        while(m < argc){
            insTesta(&ParoleDaEvitare, argv[m]); 
            m++; 
        }
    }

    Lista stringheFile = NULL;  
    Lista stringheNoDoppioni = NULL; 
    
    salvataggioContenutoFile(argv[1], &ParoleDaEvitare, &stringheFile); 

    //Ordino le due liste
    listaStringheAscendente(&stringheFile, &stringheNoDoppioni); 
    listaStringheAscendente(&stringheNoDoppioni, &stringheNoDoppioni); 

    Stampa(stringheFile, stringheNoDoppioni); 

    return 0; 
}