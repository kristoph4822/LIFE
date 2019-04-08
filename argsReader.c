#include "argsReader.h"

void search4args(int args, char** argv, int* w, int* h, char** inf, char** outf, int* n, int* p){
	
	        *w = WIDTH;
                *h = HEIGHT;
                *n = N_GEN;
		*p = N_PICS;
		*inf = NULL;
		*outf = NULL;

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

	if(*outf == NULL){
                printf("Nie podano pliku do zapisu ostatniej generacji - plik nie zostanie utworzony\n");
        }

	if(*w <= 0){
		printf("Podano nieprawidlowa szerokosc - przyjmuje wartosc domyslna szerokosci: %d\n", WIDTH);
		*w = WIDTH;
	}

	if(*h <= 0){
	 	printf("Podano nieprawidlowa wysokosci - przyjmuje wartosc domyslna wysokosci: %d\n", HEIGHT);
		*h = HEIGHT;
	}

	if(*n <= 0){
                printf("Podano nieprawidlowa liczbe generacji - przyjmuje wartosc domyslna l.generacji: %d\n", N_GEN);
                *n = N_GEN;
        }

	if(*p <= 0){
                printf("Podano nieprawidlowa liczbe generacji - przyjmuje wartosc domyslna liczby PNG: %d\n", N_PICS);
                *p = N_PICS;
        }

	if(*p > 26){
                printf("Maksymalna liczba plików PNG to 26! - przyjmuje wartosc domyslna liczby PNG: %d\n", N_PICS);
                *p = N_PICS;
        }

	if(*p > *n){
		printf("Nie mozna wygenerowac wiecej plików PNG niz generacji - przyjmuje liczbe PNG rowna liczbie generacji: %d\n", *n);
		*p = *n;
	}

	if(*inf == NULL){
		fprintf(stderr, "Blad - nie podano pliku do odczytu pierwszej generacji\n");
		exit(-4);
      	}
}

