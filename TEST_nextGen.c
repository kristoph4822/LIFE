#include"nextGen.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int **array = (int**) malloc(3*sizeof(int*));

        for(int i=0; i< 3;i++){
                array[i] = (int*)malloc(3*sizeof(int));
        }

        for(int i=0; i<3; i++)
                for(int j = 0; j<3; j++) array[i][j] = 0;
        for(int i=0; i<3; i++) {
                array[i][i] = 1;
                array[i][2-i] = 1;
                }	

	//int tab[3][3] = {{1,1,0},{0,1,1},{0,0,1}};
	int a = MooreCnt(array,1,1);
	int b = takeAction(array[1][1], a);
	printf("\nTablica:\n");
	for(int i=0 ; i<3; i++){
		for( int j=0; j<3; j++)
		printf("%d ",array[i][j]);
	printf("\n");
	}	
	printf("\n Ilosc sasiadow komorki na polu (1,1) - Jej stan w nastepnej generacji\n");
	printf("%d - %d\n", a, b);
return 0;
}

