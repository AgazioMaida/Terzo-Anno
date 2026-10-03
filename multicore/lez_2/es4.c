/*Si scriva un programma che legge in input 5
numeri interi e li salva in un array
1) Il programma stampa il numero più grande e il
numero più piccolo
2) Il programma stampa la somma di tutti I numeri
N.B. per svolgere l’esercizio si deve utilizzare un
array e I cicli FOR*/
#include<stdio.h>
#define LEN 5

int main(){
int array[LEN];

for(int i=0;i<LEN;i++){
    scanf("%d",&array[i]);
    
}
int max,min,somma=array[0];
int min=array[0];
int somma=array[0];
for(int i=1;i<LEN;i++){
    somma+=array[i];
    if(array[i]>max){
        max=array[i];
    }
    else if(array[i]<min){
        min=array[i];
    }
}
 printf("min=%d, max=%d somma=%d\n",min,max,somma);
return 0;


}