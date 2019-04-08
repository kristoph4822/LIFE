#include "genGenerator.h"
#include "nextGen.h"
#include<stdio.h>
#include<stdlib.h>

int main() {

	int width = 15;
        int height = 15;
        int **array = (int**) malloc(height*sizeof(int*));

        for(int i=0; i< height;i++){
                array[i] = (int*)malloc(width*sizeof(int));
        }

        for(int i=0; i<height; i++)
                for(int j = 0; j<width; j++) array[i][j] = 0;
        for(int i=1; i<width-1; i++) {
                array[i][i] = 1;
                array[i][width-1-i] = 1;
                }

        for(int j = 0; j < height; j++)
        {
                array[j][0] = 2;
                array[j][height-1] = 2;
        }

        for(int k = 0; k <width ; k++){
                array[0][k] = 2;
                array[width-1][k] = 2;
        }
	 printf("\nPierwotna generacja: \n");

	 for(int i=0;i<height;i++) {
                for( int j = 0; j<width;j++)
        printf("%d ",array[i][j]);
        printf("\n"); 
	 }

	
	 printf("\nNowa generacja: \n");
	array = generateNext(array, height, width);

	for(int i=0;i<height;i++) {
		for( int j = 0; j<width;j++)
	printf("%d ",array[i][j]);
	printf("\n"); }
	return 0;
}
