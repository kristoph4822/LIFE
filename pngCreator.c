#include "pngCreator.h"

void write_png_file(char* file_name) {
//funkcja tworząca plik png

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

void process_file(int w, int h, int **array) {
//funkcja konfigurująca tablicę kolorów dla funkcji write_png_file

  width = w*CELL_SIZE;
  height = h*CELL_SIZE;//szerokość i wysokość tablicy w pikselach
  
  bit_depth = 8;
  color_type = PNG_COLOR_TYPE_GRAY;
  number_of_passes = 7;

  row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
  for (y=0; y<height; y++)
    row_pointers[y] = (png_byte*) malloc(sizeof(png_byte) * width);

  for(int a = 0; a < h; a++)
	  for(int b = 0; b < w; b++){
	            for (int i = 0; i<CELL_SIZE;i++){
			png_byte* row = row_pointers[a*CELL_SIZE+i];
			for (int j = 0; j < CELL_SIZE; j++){
				if(array[a][b] == 0){
		    	        	row[b*CELL_SIZE+j] = 255;}
				else if(array[a][b] == 1){
					row[b*CELL_SIZE+j] = 100;}
				else row[b*CELL_SIZE+j] = 0;}
		    }
	  }
}		

char* file_name(int i){
	
	char* fname = malloc(sizeof(char)*9);
        fname[0] = 'g';
        fname[1] = 'e';
        fname[2] = 'n';
        fname[3] = i + 'A';
        fname[4] = '.';
        fname[5] = 'p';
        fname[6] = 'n';
        fname[7] = 'g';
	fname[8] = '\0';

	return fname;
}
