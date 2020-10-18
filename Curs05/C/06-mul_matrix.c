/* Programarea Calculatoarelor CA, 2020-2021

   Să se inmulteasca doua matrice, una de dimenisune n * p si cealalta de
   dimensiune p * m, citite de la tastatura */

#include <stdio.h>
#define NMAX 25

int main(void)
{
	/* cele trei matrice și dimensiunile */
	int a[NMAX][NMAX], b[NMAX][NMAX], c[NMAX][NMAX], n, m, p;

	/* citim matricile a și b de dimensiuni n x p și p x m */
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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c[i][j] = 0;
			for (int k = 0; k < p; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	/* afișarea rezultatului */
	printf("Matricea produc c = a x b de dimensiuni %d x %d:\n", n, m);
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
	Matricea produc c = a x b de dimensiuna 2 x 3:
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
