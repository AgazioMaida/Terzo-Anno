#include<stdio.h>
#include<mpi.h>

/*Write an MPI program that computes a tree-structured global sum. First write
your program for the special case in which comm_sz is a power of two. Then, after
you’ve gotten this version working, modify your program so that it can handle any
comm_sz*/
int main(){
  
    MPI_Init(NULL,NULL);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    double start, end;
    int dist=1;
    int attivi = size;
    
    start= MPI_Wtime(); 
    int somma_locale=rank;
    while((attivi)!=1){

        if((rank % dist) == 0 && (rank/dist)%2 ==0){
            int valore_ricevuto;
            MPI_Recv(&valore_ricevuto,1,MPI_INT,rank + dist,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            somma_locale+=valore_ricevuto;
            
        }
        else if ((rank%dist)==0 && (rank/dist)%2 != 0)
        {
            MPI_Send(&somma_locale,1,MPI_INT,rank-dist,0,MPI_COMM_WORLD);
            break;
            
        }
        
        dist *=2;
        attivi/=2;
    }
    end=MPI_Wtime();
    printf("rank: %d\n tempo impiegato: %f\n",rank,end-start);
    if(rank==0){
        printf("somma globale: %d\n",somma_locale );

    }

    MPI_Finalize();
    return 0;
}
