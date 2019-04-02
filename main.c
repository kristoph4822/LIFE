#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10
#define N_GEN 10

int** arrayCreator(char* in_file, int width, int height){

	FILE *in = fopen(in_file, "r");
	int h = height + 2;
	int w = width + 2;
	int **x = (int**) malloc(h*sizeof(int*));
	
	for(int i=0; i< h;i++){
		x[i] = (int*)malloc(w*sizeof(int));
	}
	
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w ; j++){
			if(i==0 || i==h-1 || j==0 || j==w-1) x[i][j] = 2;
			else x[i][j] = 0;
		}
	
	int tmp1, tmp2;
	while (fscanf (in, "%d %d", &tmp1, &tmp2) == 2){
		x[tmp1][tmp2] = 1;
	}

	fclose(in);
	return x;
}

void print2screenArray (int** x, int width, int height){
	
	int h = height + 2;
	int w = width + 2;
	
	for(int i = 0; i<h; i++){
		for(int j = 0; j<w; j++)
			printf("%d ", x[i][j]);
		printf("\n");
	}
}

void points2file (int **x, char* outfile, int width, int height){
	
	int h = height+2;
	int w = width+2;

	FILE *out = fopen(outfile, "w");

	for(int i = 1; i<h-1; i++)
		for(int j = 1; j<w-1;j++){
			if(x[i][j] == 1){
				fprintf(out,"%d	%d\n", i, j);}
		}
}


int searchNeighbours(int** array, int i, int j){
	int x = 0;
	if(array[i][j+1] == 1) x++;
	if(array[i][j-1] == 1) x++;
	if(array[i+1][j+1] == 1) x++;
	if(array[i+1][j] == 1) x++;
	if(array[i+1][j-1] == 1) x++;
	if(array[i-1][j+1] == 1) x++;
	if(array[i-1][j] == 1) x++;
	if(array[i-1][j-1] == 1) x++;

	return x;
}

int** nextGen(int** array, int height, int width){

	int h = height+2;
	int w = width+2;

	 int **x = (int**) malloc(h*sizeof(int*));

	for(int i=0; i< h;i++)
	          x[i] = (int*)malloc(w*sizeof(int));
					         
	for(int i = 0; i<h; i++)
		for(int j = 0; j<w;j++){
			if(array[i][j] == 1){
				if(searchNeighbours(array, i, j) != 2 && searchNeighbours(array, i, j) != 3){
					x[i][j] = 0;}
				else x[i][j] = 1;}
			else if (array[i][j] == 0){
				if(searchNeighbours(array,i,j) == 3){
					x[i][j] = 1;}
				else x[i][j] = 0;}
			else x[i][j] = 2;
		}
	return x;	
}


int main (int argc, char **argv){
	
	int  width = argc > 3 ? atoi(argv[3]) : WIDTH;
	int  height = argc > 4 ? atoi(argv[4]) : HEIGHT;
	int  n_gen = argc > 5 ? atoi(argv[5]) : N_GEN;
	
	int** array = arrayCreator(argv[1], width, height);
	print2screenArray(array, width, height);

	for(int i=0; i< n_gen; i++){
		array = nextGen(array, height, width);}

	print2screenArray(array, width, height);
	points2file(array, argv[2], width, height);

	return 0;
}
