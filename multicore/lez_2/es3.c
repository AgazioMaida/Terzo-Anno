/*Si scriva un programma che legge in input un
numero intero “a”.
1) Il programma stampa tutti i numeri da 0 ad “a”
in ordine crescente.
2) Il programma stampa tutti i numeri da 0 ad “a”
in ordine decrescente.
N.B. per svolgere l’esercizio si utilizzino cicli WHILE
*/

#include<stdio.h>

int main(){
    int a=0;
    scanf("%d",&a);
    int i=0;
    printf("Ordine crescente\n");
    while(i<=a){
        printf("%d\t",i);
        i++;
    }
    printf("\nordine decrescente\n");
    --i;
    while(i>=0){
        printf("%d\t",i);
        i--;
    }
    printf("\n");

    return 0;
}