#include "argsReader.h"
#include "genGenerator.h"
#include "pngCreator.h"
#include "txtCreator.h"
#include "arrayCreator.h"

int main (int argc, char **argv){

	char *in_file, *out_file;
	int width, height, n_gen, n_pics;

	search4args(argc, argv, &width, &height, &in_file, &out_file, &n_gen, &n_pics);

	int** array = arrayCreator(in_file, width, height);

	printf("\nPierwsza generacja");
	print2screen(array, width, height);
	
	int i = 0;
	int j = 0;

	for(i=0; i< n_gen; i++){

		if(i<n_pics-1){

		process_file(width, height, array);
		write_png_file(file_name(j));
		j++;
		}

		array = generateNext(array, height, width);

	}

	printf("\nOstatnia generacja");
	print2screen(array, width, height);
	write2txt(array, out_file, width, height);
	process_file(width, height, array);
	write_png_file(file_name(j));

	return 0;
}
