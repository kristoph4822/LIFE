#include "txtCreator.h"

#include<stdio.h>
#include<stdlib.h>

int main() {
	
	char *out = "TEST_txtCreator";	
	int w = 10;
	int h = 10;
	
	int **array = (int**) malloc(h*sizeof(int*));

	for(int i=0; i< h;i++){
		array[i] = (int*)malloc(w*sizeof(int));
	}

	for(int i=0; i<h; i++)
		for(int j = 0; j<w; j++) array[i][j] = 0;
	for(int i=1; i<w-1; i++) {
	       	array[i][i] = 1;
       		array[i][w-1-i] = 1;
 		}
	
	for(int j = 0; j < h; j++)
	{
		array[j][0] = 2;
		array[j][h-1] = 2;
	} 
	
	for(int k = 0; k <w ; k++){
		array[0][k] = 2;
		array[w-1][k] = 2;
	}
	printf("Efekt dzialania funkcji print2screen:\n");
	print2screen(array, w, h);
	write2txt(array, out, w, h);
	printf("\nEfektem dzialania funkcji write2txt jest plik TEST_txtCreator.txt\n"); 
	return 0;
}
	
