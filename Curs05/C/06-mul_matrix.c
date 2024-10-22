/* Programarea Calculatoarelor CA, 2020-2021

   Să se inmulteasca doua matrice, una de dimenisune n * p si cealalta de
   dimensiune p * m, citite de la tastatura */

#include <stdio.h>
#define NMAX 25

void multiply_matrix(int n, int m, int p, int a[NMAX][NMAX], int b[NMAX][NMAX], int c[NMAX][NMAX]) {
	/* Declarăm o matrice auxiliară, putem avea apeluri de forma
	multiply_matrix(a, a, a) <=> a = a * a */
	int tmp[NMAX][NMAX] = {};

	// calculez fiecare element al matricei după formula
	// tmp[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j]] + ... a[i][p - 1] * a[p - 1][j]
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < p; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	// salvez valorile obținute în matricea c
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c[i][j] = tmp[i][j];
		}
	}
}

int main(void)
{
	/* cele trei matrice și dimensiunile */
	int a[NMAX][NMAX], b[NMAX][NMAX], c[NMAX][NMAX], n, m, p;

	/* citim n, p, și matricile a și b de dimensiuni n x p și p x m */
	scanf("%d%d%d", &n, &m, &p);

	printf("Matricea a de dimensiuni %d x %d:\n", n, p);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("Matricea b de dimensiuni %d x %d:\n", p, m);
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &b[i][j]);
		}
	}

	/* înmulțirea celor 2 matrici */
	multiply_matrix(n, m, p, a, b, c);

	/* afișarea rezultatului înmulțirii celor două matrici */
	printf("Matricea produs c = a x b de dimensiuni %d x %d:\n", n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%5d ", c[i][j]);
		}
		printf("\n");
	}

	return 0;
}

/* compile: gcc 06-mul_matrix.c -o mul_matrix
	run    : ./mul_maxtrix

	input  :
	2 3 4
	2 3 4 1
	3 4 5 1
	4 5 3
	3 3 1
	3 4 6
	7 6 5

	output :
	Matricea produs c = a x b de dimensiuna 2 x 3:
	36    41    38
	46    53    48
	explicatie :

	n = 2, m = 3, p = 4
	Matricea a de dimensiuna 2 x 4:
	2 3 4 1
	3 4 5 1
	Matricea b de dimensiuna 4 x 3:
	4 5 3
	3 3 1
	3 4 6
	7 6 5  */
