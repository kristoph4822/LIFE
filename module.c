#include "module.h"
#include <png.h>
/*
int x, y;

int width, height;
png_byte color_type;
png_byte bit_depth;

png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
png_bytep * row_pointers;
*/

int** arrayCreator(char* in_file, int width, int height){

	FILE *in = fopen(in_file, "r");
	if(!in){
		fprintf(stderr,"Nie moĹĽna otworzyÄ‡ pliku do odczytu\n");
		exit(-2);
	}
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

void print2screen (int** x, int width, int height){
	
	int h = height + 2;
	int w = width + 2;
	
	printf("\n");
	for(int i = 0; i<h; i++){
		for(int j = 0; j<w; j++)
			printf("%d ", x[i][j]);
		printf("\n");
	}
}

void write2txt(int **x, char* outfile, int width, int height){
	
	int h = height+2;
	int w = width+2;

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


int MooreCnt(int** array, int i, int j){
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

int** generateNext(int** array, int height, int width){

	int h = height+2;
	int w = width+2;

	 int **x = (int**) malloc(h*sizeof(int*));

	for(int i=0; i< h;i++)
	          x[i] = (int*)malloc(w*sizeof(int));
					         
	for(int i = 0; i<h; i++)
		for(int j = 0; j<w;j++){
			if(array[i][j] == 1){
				if(MooreCnt(array, i, j) != 2 && MooreCnt(array, i, j) != 3){
					x[i][j] = 0;}
				else x[i][j] = 1;}
			else if (array[i][j] == 0){
				if(MooreCnt(array,i,j) == 3){
					x[i][j] = 1;}
				else x[i][j] = 0;}
			else x[i][j] = 2;
		}
	return x;	
}


void write_png_file(char* file_name) {
  FILE *fp = fopen(file_name, "wb");
  if (!fp)
    printf("[write_png_file] File %s could not be opened for writing", file_name);

  png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

  if (!png_ptr)
    printf("[write_png_file] png_create_write_struct failed");

  info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr)
    printf("[write_png_file] png_create_info_struct failed");

  if (setjmp(png_jmpbuf(png_ptr)))
    printf("[write_png_file] Error during init_io");

  png_init_io(png_ptr, fp);

  if (setjmp(png_jmpbuf(png_ptr)))
    printf("[write_png_file] Error during writing header");

  png_set_IHDR(png_ptr, info_ptr, width, height,
   bit_depth, color_type, PNG_INTERLACE_NONE,
   PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

  png_write_info(png_ptr, info_ptr);

  if (setjmp(png_jmpbuf(png_ptr)))
    printf("[write_png_file] Error during writing bytes");

  png_write_image(png_ptr, row_pointers);

  if (setjmp(png_jmpbuf(png_ptr)))
    printf("[write_png_file] Error during end of write");

  png_write_end(png_ptr, NULL);

  for (y=0; y<height; y++)
    free(row_pointers[y]);
  free(row_pointers);

  fclose(fp);
}

void process_file(int _width, int _height, int **array) {
  int w = (_width +2);
  int h = (_height +2);
  width = w*8;
  height = h*8;
  bit_depth = 8;
  color_type = PNG_COLOR_TYPE_GRAY;
  number_of_passes = 7;

  row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
  for (y=0; y<height; y++)
    row_pointers[y] = (png_byte*) malloc(sizeof(png_byte) * width);

  for(int a =0; a < h; a++)
	  for(int b = 0; b < w; b++){
	            for (int i = 0; i<8;i++){
			png_byte* row = row_pointers[a*8+i];
			for (int j = 0; j < 8; j++){
				if(array[a][b] == 0){
		    	        	row[b*8+j] = 255;}
				else if(array[a][b] == 1){
					row[b*8+j] = 100;}
				else row[b*8+j] = 0;}
		    }
	  }
}		
    