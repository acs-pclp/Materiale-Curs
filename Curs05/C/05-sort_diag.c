/*  Programarea Calculatoarelor CA, 2020-2021

	Sortarea diagonalei principale prin schimbarea de linii / coloane.
*/

#include <stdio.h>
#define NMAX 100

void swap_lines(int a[][NMAX], int n, int l1, int l2)
{
	for (int i = 0; i < n; i++) {
		int aux = a[l1][i];
		a[l1][i] = a[l2][i];
		a[l2][i] = aux;
	}
}

void swap_columns(int a[][NMAX], int n, int c1, int c2)
{
	for (int i = 0; i < n; i++) {
		int aux = a[i][c1];
		a[i][c1] = a[i][c2];
		a[i][c2] = aux;
	}
}

int main(void)
{
	int a[NMAX][NMAX], n, ok;

	/* citire matrice */
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	/* sortare dupa diagonala principala */
	do {
		ok = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[i][i] > a[i + 1][i + 1]) {
				swap_lines(a, n, i, i + 1);
				swap_columns(a, n, i, i + 1);
				ok = 1;
			}
		}
	} while (ok);

	/* afisare matrice sortata */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*  compile: gcc 05-sort_diag.c -o sort_diag
    run    : ./sort_diag

    Exemplu:

    input  :
	4
	1 2 3 4
	4 3 2 1
	1 3 2 4
	2 3 4 1

	output :
	1   4   3   2
	2   1   4   3
	1   4   2   3
	4   1   2   3  */
