#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
/*3.9. Write an MPI program that implements multiplication of a vector by a scalar
and dot product. The user should enter two vectors and a scalar, all of which are
read in by process 0 and distributed among the processes. The results are
calculated and collected onto process 0, which prints them. You can assume that n,
the order of the vectors, is evenly divisible by comm sz.*/
#define N 30
int main(){
    MPI_Init(NULL,NULL);
    int size, rank;
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    int* buffer_vecA=(int* )malloc((N/size)*sizeof(int));
    int* buffer_vecB=(int* )malloc((N/size)*sizeof(int));
    int A[N];
    int B[N];
    int x;
    int resultA[N];
    int resultB[N];
    int result_scalare;
    if(rank==0){
        x=rand()%10;
        for (int i = 0; i < N; i++) {
            A[i] = rand() % 10;
            B[i] = rand() % 10;
}
        
    }
    MPI_Bcast(&x,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(A,N/size,MPI_INT,buffer_vecA,N/size,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(B,N/size,MPI_INT,buffer_vecB,N/size,MPI_INT,0,MPI_COMM_WORLD);
    int D=N/size;
    int buff_prod_A[D];
    int buff_prod_B[D];
    int scalare=0;
    for(int i=0;i<D;i++){
        buff_prod_A[i]=x*buffer_vecA[i];
        buff_prod_B[i]=x*buffer_vecB[i];
        scalare+= buffer_vecA[i]*buffer_vecB[i];

    }
    MPI_Reduce(&scalare,&result_scalare,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    MPI_Gather(buff_prod_A,D,MPI_INT,resultA,D,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Gather(buff_prod_B,D,MPI_INT,resultB,D,MPI_INT,0,MPI_COMM_WORLD);
    if(rank==0){
        printf("-------x * A---------x * B------");
        for(int i=0;i<N;i++){

            printf(" %d\t %d\n",resultA[i],resultB[i]);
        }
        printf("scalare: %d\n",result_scalare);
        free(buffer_vecA);
        free(buffer_vecB);
    }
    MPI_Finalize();
    



    return 0;
}