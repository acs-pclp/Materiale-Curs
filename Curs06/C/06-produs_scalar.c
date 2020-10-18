/* Programarea Calculatoarelor CA, 2020-2021

   Calcularea produsului scalar a doi vectori */

#include <stdio.h>
#define NMAX 100

void read_array(int n, int *v)
{
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
}

int dot_product(int n, int *u, int *v)
{
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += u[i] * v[i];
	}
	return s;
}

int main(void)
{
	int n, u[NMAX], v[NMAX];
	scanf("%d", &n);
	read_array(n, u);
	read_array(n, v);
	int s = dot_product(n, u, v);
	printf("Produsul scalar este %d\n", s);
	return 0;
}

/* compile: gcc 06-produs_scalar.c -o produs_scalar
   run    : ./produs_scalar

   Exemplu:

   input  : 
   3 3
   1 0 0
   0 1 0

   output : 
   Produsul scalar este 0

   input  : 
   2 2
   4 0
   6 0

   output : 
   Produsul scalar este 24

   input  : 
   3 3
   4 1 0
   5 5 5

   output : 
   Produsul scalar este 25 */
