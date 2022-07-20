#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //tolower();

/**
   Scrivere un programma che legga una frase introdotta da tastiera.
   La frase e' terminata dall'interrutore di carattere invio.
   La frase contiene complessivamente al piu' 100 caratteri.
   Il programma dovra' stampare su schermo le seguenti informazioni:

        1) per ognuna delle lettere dell'alfabeto, il numero di volte che la lettera compare nella stringa;
        2) il numero di consonanti presenti nella stringa;
        3) il numero di vocali presenti nella stringa.

**/
void Conta_vocali_consonanti(){

    int conta_c=0; //contatore delle consonanti
    int conta_v=0; //contatore delle vocali
    int conta_s=0; //contatore degli spazi

    char *stringa=malloc(100*sizeof(char)); //la frase da inserire in Input
    char vocali[5]={'a','e','i','o','u'}; //utilizzato per diversificare l'esercizio --> array di caratteri che contiene tutte le vocali
    char *alfabeto="abcdefghilmnopqrstuvz"; //stringa che contiene tutto l'alfabeto
    int occorrenze[21]; // array delle occorrenze di dimensione uguale all'alfabeto

    /*Inserimento della parola o della frase per max 100 caratteri*/
    printf("Inserisci una frase > ");
    gets(stringa);

    system("cls"); //pulizia dello schermo


    for(int i=0; i<strlen(stringa); i++){ //il primo for, scorre tutta la stringa inserita in Input, carattere per carattere.
        /*Per ogni carattere controlla se: */

        if(stringa[i]==' '){ //il carattere che legge dalla stringa e' uno spazio
            conta_s++; // conta lo spazio
        }

        for(int j=0; j < 5; j++){ //secondo for scorre l'array di vocali uno alla volta

            /*per ogni carattere controlla se:*/
            if(tolower(stringa[i])== vocali[j]){ //controlla se il carattere letto e' una vocale  NB: tolower() mi permette di convertire il carattere da maiuscolo a minuscolo
                conta_v++;//conta le vocali
            }
        }//fine secondo for
    }//fine primo for


    /*il numro delle consonanti e' dato dalla lunghezza della stringa meno
      il numero degli spazi meno il numero delle vocali
    */
    conta_c= strlen(stringa)-conta_s-conta_v;


    for(int i=0; i<strlen(alfabeto); i++){
        int conta_o=0;
        for(int j=0; j<strlen(stringa); j++){
            if(alfabeto[i]==tolower(stringa[j])){
                conta_o++;
            }
        }
        occorrenze[i]=conta_o;
    }

    printf("La mia frase: %s\n", stringa);
    printf("il numero di vocali: %d\n", conta_v);
    printf("il numero di consonanti: %d\n", conta_c);

    printf("Occorrenze per ogni lettera dell'alfabeto\n");

    for(int i=0; i<strlen(alfabeto); i++){
            printf("%c: %d\n", alfabeto[i],occorrenze[i]);
    }

    free(stringa);

}

