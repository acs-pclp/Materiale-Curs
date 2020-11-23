/* Programarea Calculatoarelor CA, 2020-2021

  Alocare vector intr-o functie si intoarcerea pointer-ului aferent */

#include <stdio.h>
#include <stdlib.h> // malloc, calloc, realloc, free

int *read_vec(int *n)
{
	scanf("%d", n);

	int *v = (int *)malloc(*n * sizeof(int));
	if (!v) { // daca nu pot aloca, opresc executia si afisez un mesaj
		fprintf(stderr, "malloc() failed\n");
		return NULL;
	}

	for (int i = 0; i < *n; ++i) {
		scanf("%d", &v[i]);
	}
	return v;
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

	v = read_vec(&n);
	if (!v) { // daca alocarea a esuat, termin cu cod de eroare
		return -1;
	}

	print_vec(n, v);

	free(v); // eliberez memoria alocata
	return 0;
}

/* compile: gcc -Wall -Wextra -o 04-alocare_vector_f 04-alocare_vector_f.c
	run   : ./05-alocare_vector_f

	input:
	3
	1 2 3

	output:
	1 2 3
*/
