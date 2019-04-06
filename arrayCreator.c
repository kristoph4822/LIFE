#include "arrayCreator.h"

#include <stdio.h>
#include <stdlib.h>

int** arrayCreator(char* in_file, int w, int h){

	FILE *in = fopen(in_file, "r");
	if(!in){
		fprintf(stderr,"Nie mozna otworzyc pliku do odczytu\n");
		exit(-2);
	}

	int **x = (int**) malloc(h*sizeof(int*));
	
	for(int i=0; i< h;i++){
		x[i] = (int*)malloc(w*sizeof(int));
	}
	
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w ; j++){
			if(i==0 || i==h-1 || j==0 || j==w-1) x[i][j] = 2;
			//jeżeli pole tablicy leży na granicy, przypsiujemy mu wartość 2 (ramka)
			else x[i][j] = 0;
			//pola planszy(martwe komórki) mają wartość 0
		}
	int tmp1, tmp2;
	while (fscanf (in, "%d %d", &tmp1, &tmp2) == 2){
		if(tmp1 >= h || tmp2 >= w){
			fprintf(stderr, "Wspolrzedne punktow w pliku nie zgadzaja sie z wymiarami tablicy!\n");
			exit(-3);
		}
		x[tmp1][tmp2] = 1;
		//wczytujemy z pliku wspĂłĹ‚rzÄ™dne ĹĽywych komĂłrek i oznaczamy je wartoĹ›ciÄ… 1
	}

	fclose(in);
	return x;
}
