#include "genGenerator.h"
#include "nextGen.h"

int** generateNext(int** array, int h, int w){

	 int **x = (int**) malloc(h*sizeof(int*));

	for(int i=0; i< h;i++)
	          x[i] = (int*)malloc(w*sizeof(int));
					         
	for(int i = 0; i<h; i++)
		for(int j = 0; j<w;j++){
			//zmiana stanu komórki w zależności od liczby sąsiadów i jej aktualnego stanu
			if(array[i][j] == 1){
				if(MooreCnt(array, i, j) != 2 && MooreCnt(array, i, j) != 3){
					x[i][j] = 0;}
				else x[i][j] = 1;}
			else if (array[i][j] == 0){
				if(MooreCnt(array,i,j) == 3){
					x[i][j] = 1;}
				else x[i][j] = 0;}
			else x[i][j] = 2;
		}
	return x;	
}
