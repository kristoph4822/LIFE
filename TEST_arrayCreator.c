#include "arrayCreator.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv ) {

	int width = 10; 
       	int height = 10;
	char *in = "TEST_arrayCreator";
	int** array = arrayCreator(in, width, height);

	printf("\n Wczytano tablice: \n");
	for(int i=0; i<height; i++) {
		for(int j=0; j<width; j++)
			printf("%d ", array[i][j]);
	printf("\n");
	}
return 0;
}
