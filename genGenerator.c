#include "genGenerator.h"
#include "nextGen.h"

int** generateNext(int** array, int h, int w){

	 int **x = (int**) malloc(h*sizeof(int*));

	for(int i=0; i< h;i++)
	          x[i] = (int*)malloc(w*sizeof(int));
					         
	for(int i = 0; i<h ; i++)
                for(int j = 0; j<w ;j++){
                        if(array[i][j] != 2){
                                x[i][j] = takeAction(array[i][j], MooreCnt(array, i, j));}
                                //zmiana stanu komórki w zależności od liczby sąsiadów i jej aktualnego stanu
                        else x[i][j] = 2;		
	}

	return x;	
}
