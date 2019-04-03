#include "module.h"

int main (int argc, char **argv){

	if(argc < 3){
		fprintf(stderr, "Dwa pierwsze argumenty:\n- nazwa pliku do odczytu\n- nazwa pliku do zapisu\n są obowiązkowe.\n");
		return -1;
	}

	int  width = argc > 3 ? atoi(argv[3])+2 : WIDTH+2;
	int  height = argc > 4 ? atoi(argv[4])+2 : HEIGHT+2;
       	//zwiększamy wysokosć i szerokość o 2 ze względu na ramki
	int  n_gen = argc > 5 ? atoi(argv[5]) : N_GEN;
	
	int** array = arrayCreator(argv[1], width, height);

	printf("\nPierwsza generacja");
	print2screen(array, width, height);
	
	int i = 0;

	for(i=0; i< n_gen; i++){

		array = generateNext(array, height, width);

		if(i<25){

		process_file(width, height, array);
		write_png_file(file_name(i));}
	}

	printf("\nOstatnia generacja");
	print2screen(array, width, height);
	write2txt(array, argv[2], width, height);
	process_file(width, height, array);
	write_png_file(file_name(i));

	return 0;
}
