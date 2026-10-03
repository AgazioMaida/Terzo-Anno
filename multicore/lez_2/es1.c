/*
Si scriva un programma che legge in input due
numeri interi.
1) Il programma deve stampare se il primo
numero è maggiore, minore o uguale al
secondo.
2) Il programma deve stampare la somma e il
prodotto dei due numeri.
*/

#include<stdio.h>

int main(){
    int x;
    int y;
    scanf("%d",&x);
    scanf("%d",&y);

    if(x>y){
        printf("x = %d > y = %d \n",x,y);
    }
    else if( x<y){
        printf("x = %d < y = %d \n",x,y);
    }
    else{
        printf(" x= %d == y = %d \n",x,y);
    }

    int somma = x+y;
    printf("somma = %d\n",somma);
   
}