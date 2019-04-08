#include "argsReader.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char**argv) {
	char *in_file, *out_file;
	int width, height, n_gen, n_pics;
	search4args(argc, argv, &width, &height, &in_file, &out_file, &n_gen, &n_pics);
	printf("\n Parametry wywolania programu: ");
	printf("\n Szerokosc planszy: %d \n Wysokosc planszy: %d \n Nazwa pliku wejsciowego: %s \n Nazwa wyjsciowego pliku tekstowego: %s \n Liczba przeprowadzonych generacji: %d \n Liczba wygenerowanych plikow PNG: %d \n", width, height, in_file, out_file, n_gen, n_pics); 
	return 0; 
}
