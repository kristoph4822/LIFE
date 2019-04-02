#ifndef MODULE_H
#define MODULE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include <png.h>

#define WIDTH 10
#define HEIGHT 10
#define N_GEN 10


int x, y;

int width, height;
png_byte color_type;
png_byte bit_depth;

png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
png_bytep * row_pointers;

int** arrayCreator(char* in_file, int width, int height);
			
void print2screen (int** x, int width, int height);

void write2txt(int **x, char* outfile, int width, int height);

int MooreCnt(int** array, int i, int j);

int** generateNext(int** array, int height, int width);

void write_png_file(char* file_name);

void process_file(int width, int height, int **array);  

#endif