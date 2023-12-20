# Puntatori

Sono variabili il cui valore corrisponde all'indirizzo di memoria di un'altra variabile.
Ovvero una funzione punta a una posizione specifica di memoria.
```c
int *i = &tmp; 
//i punta alla cella di memoria di tmp
```

# Array e funzioni
Un array viene memorizzato in locazioni di memoria sequenziali.
Gli array vengono passati alle funzioni per riferimento, quindi la funzione riceve un puntatore all'array piuttosto che una copia dei dati.
Le modifiche apportate ai valori dell'array all'interno della funzione sarà riflessa nell'array originale passato alla funzione.
```c
void modificaArray(int arr[], int lunghezza){/*...*/}

int main(){
    /*...*/
    modificaArray(array, n); 
}
```

# Stringhe e funzioni
Le stringhe in C corrispondo ad un array di caratteri, anch'essi nella chiamata della funzione vengono passati per riferimento.
Le modifiche apportate nella funzione saranno riflesse anche nella variabile originale.
```c
void modificheArrayChar(char *array){/*...*/}

int main(){
    char frase[] = "Hello World!"; 
    modificheArrayChar(frase); 
}
```

