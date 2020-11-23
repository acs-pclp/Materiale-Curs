/* Programarea Calculatoarelor CA, 2020-2021

  Afisare adrese matrice dinamica */

#include <stdio.h>
#include <stdlib.h> // malloc, calloc, realloc, free

#define NMAX 3

int **alloc_matrix(int n, int m)
{
	int **mat = (int **)malloc(n * sizeof(int *));
	if (!mat) {
		fprintf(stderr, "malloc failed()");
		return NULL;
	}

	for (int i = 0; i < n; i++) {
		mat[i] = (int *)malloc(m * sizeof(int));
		if (!mat[i]) {
			// daca una din alocari a esuat, trebuie sa dezaloc tot ce am alocat
			fprintf(stderr, "malloc() for line %d failed\n", i);
			for (int j = 0; j < i; j++) {
				free(mat[j]);
			}
			free(mat);
			*mat = NULL;
			break;
		}
	}

	return mat;
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
	int **mat, a[NMAX][NMAX];
	int n = NMAX, m = NMAX;
	mat = alloc_matrix(n, m);
	if (!mat) {
		return -1;
	}

	printf("Matrice alocata static:\n");
	for (int i = 0; i < NMAX; i++) {
		for (int j = 0; j < NMAX; j++) {
			printf("%p ", &a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Matrice alocata dinamic:\n");
	for (int i = 0; i < NMAX; i++) {
		for (int j = 0; j < NMAX; j++) {
			printf("%p ", &mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	free_matrix(NMAX, mat); // eliberez memoria alocata

	return 0;
}

/* compile: gcc -Wall -Wextra -o 03-afisare_adrese 03-afisare_adrese.c
	run   : ./03_afisare_adrese

	output:
	Matrice alocata static:
	0x7ffc2ac84380 0x7ffc2ac84384 0x7ffc2ac84388
	0x7ffc2ac8438c 0x7ffc2ac84390 0x7ffc2ac84394
	0x7ffc2ac84398 0x7ffc2ac8439c 0x7ffc2ac843a0

	Matrice alocata dinamic:
	0x55dbf2bcf2c0 0x55dbf2bcf2c4 0x55dbf2bcf2c8
	0x55dbf2bcf2e0 0x55dbf2bcf2e4 0x55dbf2bcf2e8
	0x55dbf2bcf300 0x55dbf2bcf304 0x55dbf2bcf308
*/
