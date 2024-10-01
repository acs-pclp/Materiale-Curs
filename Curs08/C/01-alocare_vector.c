/* Programarea Calculatoarelor CA, 2020-2021

  Alocare dinamica vector */

#include <stdio.h>
#include <stdlib.h> // malloc, calloc, realloc, free

void read_vec(int *n, int **v)
{
	scanf("%d", n);
	int *w = (int *)malloc(*n * sizeof(int));
	if (!w) { // daca nu pot aloca, opresc executia si afisez un mesaj
		fprintf(stderr, "malloc() failed\n");
		*v = NULL;
		return;
	}
	*v = w;

	for (int i = 0; i < *n; i++) {
		scanf("%d", &w[i]);
	}
}

void print_vec(int n, int *v)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main(void)
{
	int n, *v;

	read_vec(&n, &v);
	if (!v) { // daca alocarea a esuat, termin cu cod de eroare
		return -1;
	}

	print_vec(n, v);
	free(v); // eliberez memoria alocata
	return 0;
}

/* compile: gcc -Wall -Wextra -o 01-alocare_vector 01-alocare_vector.c
	run   : ./01-alocare_vector

	input:
	3
	1 2 3

	output:
	1 2 3
*/
