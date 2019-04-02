#include "module.h"

int main (int argc, char **argv){

	if(argc < 3){
		fprintf(stderr, "Dwa pierwsze argumenty:\n- nazwa pliku do odczytu\n- nazwa pliku do zapisu\n są obowiązkowe.\n");
		return -1;
	}	
	int  width = argc > 3 ? atoi(argv[3]) : WIDTH;
	int  height = argc > 4 ? atoi(argv[4]) : HEIGHT;
	int  n_gen = argc > 5 ? atoi(argv[5]) : N_GEN;
	
	int** array = arrayCreator(argv[1], width, height);

	printf("\nPierwsza generacja");
	print2screen(array, width, height);

	for(int i=0; i< n_gen; i++){
		array = generateNext(array, height, width);}
	
	printf("\nOstatnia generacja");
	print2screen(array, width, height);
	write2txt(array, argv[2], width, height);
	process_file(width, height, array);
	write_png_file("out.png");

	return 0;
}
