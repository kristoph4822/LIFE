#include "nextGen.h"

int MooreCnt(int** array, int i, int j){
//liczenie sąsiadów (sąsidztwo Moore'a) komórki o współrzędnych (i,j)

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

