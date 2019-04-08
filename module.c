#include "module.h"


void search4args(int args, char** argv, int* w, int* h, char** inf, char** outf, int* n, int* p){
	
	        *w = WIDTH;
                *h = HEIGHT;
                *n = N_GEN;
		*p = N_PICS;

		for(int i = 0; i< args-1; i++){
			if(strcmp(argv[i],"--w") == 0)
				       *w = atoi(argv[i+1]);

			else if(strcmp(argv[i],"--h") == 0)
                                       *h = atoi(argv[i+1]);

			else if(strcmp(argv[i],"--n") == 0)
                                       *n = atoi(argv[i+1]);
			
			else if(strcmp(argv[i],"--p") == 0)
                                       *p = atoi(argv[i+1]);

			else if(strcmp(argv[i],"--f") == 0) *inf = argv[i+1];

			else if(strcmp(argv[i],"--o") == 0) *outf = argv[i+1];
		}

	if(*w <= 0){
		printf("Podano nieprawidlowa szerokosc\nPrzyjmuje wartosc domyslna szerokosci: %d\n", WIDTH);
		*w = WIDTH;
	}

	if(*h <= 0){
	 	printf("Podano nieprawidlowa wysokosc\nPrzyjmuje wartosc domyslna wysokosci: %d\n", HEIGHT);
		*h = HEIGHT;
	}

	if(*n <= 0){
                printf("Podano nieprawidlowa liczbe generacji\nPrzyjmuje wartosc domyslna l.generacji: %d\n", N_GEN);
                *n = N_GEN;
        }

	if(*p <= 0){
                printf("Podano nieprawidlowa liczbe generacji\nPrzyjmuje wartosc domyslna liczby PNG: %d\n", N_PICS);
                *p = N_PICS;
        }

	if(*p > 26){
	width+=2;
	width+=2;
                printf("Maksymalna liczba plików PNG to 26!\nPrzyjmuje wartosc domyslna liczby PNG: %d\n", N_PICS);
                *p = N_PICS;
        }

	if(*p > *n){
		printf("Nie mozna wygenerowac wiecej plików PNG niz generacji\nPrzyjmuje liczbe PNG rowna liczbie generacji: %d\n", *n);
		*p = *n;
	}
}

int** arrayCreator(char* in_file, int w, int h){

	FILE *in = fopen(in_file, "r");
	if(!in){
		fprintf(stderr,"Nie mozna otworzyc pliku do odczytu\n");
		exit(-2);
	}

	int **x = (int**) malloc(h*sizeof(int*));
	
	for(int i=0; i< h;i++){
		x[i] = (int*)malloc(w*sizeof(int));
	}
	
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w ; j++){
			if(i==0 || i==h-1 || j==0 || j==w-1) x[i][j] = 2;
			//jeżeli pole tablicy leży na granicy, przypsiujemy mu wartość 2 (ramka)
			else x[i][j] = 0;
			//pola planszy(martwe komórki) mają wartość 0
		}
	
	int tmp1, tmp2;
	while (fscanf (in, "%d %d", &tmp1, &tmp2) == 2){
		if(tmp1 >= h || tmp2 >= w){
			fprintf(stderr, "Wspolrzedne punktow w pliku nie zgadzaja sie z wymiarami tablicy!\n");
			exit(-3);
		}
		x[tmp1][tmp2] = 1;
		//wczytujemy z pliku współrzędne żywych komórek i oznaczamy je wartością 1
	}

	fclose(in);
	return x;
}

void print2screen (int** x, int w, int h){
	
	printf("\n");
	for(int i = 0; i<h; i++){
		for(int j = 0; j<w; j++)
			printf("%d ", x[i][j]);
		printf("\n");
	}
}

void write2txt(int **x, char* outfile, int w, int h){
//wypisywanie do pliku konfiguracji żywych komórek w postaci ich współrzędnych
//
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

int** generateNext(int** array, int h, int w){

	 int **x = (int**) malloc(h*sizeof(int*));

	for(int i=0; i< h;i++)
	          x[i] = (int*)malloc(w*sizeof(int));
					         
	for(int i = 0; i<h; i++)
		for(int j = 0; j<w;j++){
			//zmiana stanu komórki w zależności od liczby sąsiadów i jej aktualnego stanu
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
