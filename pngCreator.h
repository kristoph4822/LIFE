#ifndef PNGCREATOR_H
#define PNGCREATOR_H

#include <png.h>
#include <stdlib.h>
#include <stdio.h>

#define CELL_SIZE 16

int x, y;

int width, height;
png_byte color_type;
png_byte bit_depth;

png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
png_bytep * row_pointers;

void write_png_file(char* file_name);

void process_file(int w, int h, int **array);

char* file_name(int i);

#endif
