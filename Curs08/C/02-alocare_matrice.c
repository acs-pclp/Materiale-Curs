/* Programarea Calculatoarelor CA, 2020-2021

  Alocare dinamica matrice */

#include <stdio.h>
#include <stdlib.h> // malloc, calloc, realloc, free

void read_matrix(int *n, int *m, int ***mat)
{
	scanf("%d%d", n, m);
	int **a = (int **)malloc(*n * sizeof(int *));
	if (!a) { // daca nu pot aloca, opresc executia si afisez un mesaj
		fprintf(stderr, "malloc() for matrix failed\n");
		*mat = NULL;
		return;
	}

	*mat = a;

	for (int i = 0; i < *n; i++) {
		a[i] = (int *)malloc(*m * sizeof(int));
		if (!a[i]) {
			// daca una din alocari a esuat, trebuie sa dezaloc tot ce am alocat
			fprintf(stderr, "malloc() for line %d failed\n", i);
			for (int j = 0; j < i; j++) {
				free(a[j]);
			}
			free(a);
			*mat = NULL;
			return;
		}
	}

	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}

void print_matrix(int n, int m, int **mat)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

void free_matrix(int n, int **mat)
{
	for (int i = 0; i < n; i++) {
		free(mat[i]);
	}
	free(mat);
}

int main(void)
{
	int n, m, **mat;

	read_matrix(&n, &m, &mat);
	if (!mat) { // daca alocarea a esuat, termin cu cod de eroare
		return -1;
	}

	print_matrix(n, m, mat);

	free_matrix(n, mat); // eliberez memoria alocata
	return 0;
}

/* compile: gcc -Wall -Wextra -o 01-alocare_vector 01-alocare_vector.c
	run   : ./01-alocare_vector

	input:
	3 3
	1 2 3
	4 5 6
	7 8 9

	output:
	1 2 3
	4 5 6
	7 8 9
*/
