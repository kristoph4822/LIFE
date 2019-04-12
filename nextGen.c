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

int takeAction(int status, int neighbours){

        if(status == 1){
                if(neighbours != 2 && neighbours != 3){
                        return 0;}
                else return 1;}
        else {
                if(neighbours == 3){
                        return 1;}
                else return 0;}
}
