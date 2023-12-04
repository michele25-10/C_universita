#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 20

typedef char stringa[DIM];

typedef struct {
    stringa slot1;
    stringa slot2;
    stringa slot3; 
    stringa slot4;
} Orario; 

void stampaOrarioCompleto(Orario *orario_sett, stringa *giorni){
    printf("\nGIORNO\tSLOT 1\tSLOT 2\tSLOT 3\tSLOT 4\n");
    for(int i = 0; i < 5; i++){
        printf("%s\t%s\t%s\t%s\t%s\n", 
            giorni[i], 
            orario_sett[i].slot1 != NULL ? orario_sett[i].slot1 : "Vuoto",
            orario_sett[i].slot2 != NULL ? orario_sett[i].slot2 : "Vuoto",
            orario_sett[i].slot3 != NULL ? orario_sett[i].slot3 : "Vuoto",
            orario_sett[i].slot4 != NULL ? orario_sett[i].slot4 : "Vuoto"
        );
    }
}

int main(){
    Orario orario_sett[5];
    stringa giorni[5] = {"Lunedì", "Martedì", "Mercoledì", "Giovedì", "Venerdì"};
    char menu; 
    do{
        printf("\nOpzioni:\n\ta. Stampare l'orario completo\n\tb. Stampare l'orario di un solo giorno\n\tc. Modificare l'orario\n");
        scanf(" %c", &menu);
    }while(menu != 'a' && menu != 'b' && menu != 'c');
    
    while(menu != 'q'){
        int giorno;
        switch(menu){
            case 'a':
                    stampaOrarioCompleto(orario_sett, giorni);
                break; 

            case 'b':

                do{
                    printf("\nGiorno:\n\t1. Lunedì\n\t2. Martedì\n\t3. Mercoledì\n\t4. Giovedì\n\t5.Venerdì\n");
                    scanf("%s", giorno); 
                }while(giorno < 1 || giorno > 5);

                giorno -= 1; 

                printf("\nGIORNO\tSLOT 1\tSLOT 2\tSLOT 3\tSLOT 4\n");
                printf("%s\t%s\t%s\t%s\t%s\n",
                    giorni[giorno],
                    orario_sett[giorno].slot1 != NULL ? orario_sett[giorno].slot1 : "Vuoto",
                    orario_sett[giorno].slot2 != NULL ? orario_sett[giorno].slot2 : "Vuoto",
                    orario_sett[giorno].slot3 != NULL ? orario_sett[giorno].slot3 : "Vuoto",
                    orario_sett[giorno].slot4 != NULL ? orario_sett[giorno].slot4 : "Vuoto"
                );
                break; 

            case 'c':
                do{
                    printf("\nGiorno:\n\t1. Lunedì\n\t2. Martedì\n\t3. Mercoledì\n\t4. Giovedì\n\tVenerdì\n");
                    scanf("%s", giorno); 
                }while(giorno < 1 || giorno > 5);
                giorno -= 1;

                printf("Inserisci slot1\n");
                scanf("%s", orario_sett[giorno].slot1);
                printf("\nInserisci slot2\n");
                scanf("%s", orario_sett[giorno].slot2);
                printf("\nInserisci slot3\n");
                scanf("%s", orario_sett[giorno].slot3);
                printf("\nInserisci slot4\n");
                scanf("%s", orario_sett[giorno].slot4);

                break; 
        }

        do{
            printf("\nOpzioni:\n\ta. Stampare l'orario completo\n\tb. Stampare l'orario di un solo giorno\n\tc. Modificare l'orario\n");
            scanf(" %c", &menu);
    }while(menu != 'a' && menu != 'b' && menu != 'c');
    }
    return 0;
}