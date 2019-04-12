#include "pngCreator.h"
#include "arrayCreator.h"

#include<stdio.h>
#include<stdlib.h>

int main() {

int width = 10;
int height = 10;
int j = 15;
char *in = "TEST_arrayCreator";
int** array = arrayCreator(in, width, height);

process_file(width, height, array);
write_png_file(file_name(1));


return 0;
}



