#include "txtCreator.h"
#include <stdio.h>
#include <stdlib.h>

void print2screen (int** x, int w, int h){
	
	printf("\n");
	for(int i = 0; i<h; i++){
		for(int j = 0; j<w; j++)
			printf("%d ", x[i][j]);
		printf("\n");
	}
}

void write2txt(int **x, char* outfile, int w, int h){
//wypisywanie do pliku konfiguracji żywych komórek w postaci ich współrzędnych
//
	FILE *out = fopen(outfile, "w");
	if(!out){
		fprintf(stderr,"Nie moĹĽna otworzyÄ‡ pliku do zapisu\n");
		exit(-3);
	}
		
	for(int i = 1; i<h-1; i++)
		for(int j = 1; j<w-1;j++){
			if(x[i][j] == 1){
				fprintf(out,"%d	%d\n", i, j);}
		}
}

