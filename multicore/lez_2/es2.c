/*Si scriva un programma che legge in input un
numero intero “a”.
1) Il programma stampa tutti i numeri da 0 ad
“a” in ordine crescente.
2) Il programma stampa tutti i numeri da 0 ad
“a” in ordine decrescente.
N.B. per svolgere l’esercizio si utilizzino cicli FOR*/

#include <stdio.h>

int main(){

    int a=0;
    scanf("%d",&a);
    printf("Ordine crescente\n");
    for(int i=0;i<=a;i++){
        printf("%d\t",i);
    }
    int i=0;
    printf("\nOrdine decrescente\n");
    for(i=a;i>=0;i--){
        printf("%d\t",i);
    }


    return 0;
}