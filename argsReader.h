#ifndef ARGSREADER_H
#define ARGSREADER_H

#define WIDTH 10
#define HEIGHT 10
#define N_GEN 10
#define N_PICS 2

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void search4args(int args, char** argv, int* w, int* h, char** inf, char** outf, int* n, int* p);

#endif
