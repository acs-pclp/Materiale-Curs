/* Programarea Calculatoarelor CA, 2019-2020

   Programul realizeaza interschimbarea a 2 numere prin diferite metode */

#include <stdio.h>

int main(void)
{
    // interschimbare cu auxiliar
	int a, b, aux;
	scanf("%d%d", &a, &b);
	aux = a;
	a = b;
	b = aux;
	printf("%d %d\n", a, b);

    // interschimbare cu xor
	int x, y;
	scanf("%d%d", &x, &y);
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
	printf("%d %d\n", x, y);

    // interschimbare cu adunari
	int m, n;
	scanf("%d%d", &m, &n);
	m = m + n;
	n = m - n;
	m = m - n;
	printf("%d %d\n", m, n);

	return 0;
}

/* compile: gcc 02-interschimbare.c -o interschimbare
   run    : ./interschimbare

   Exemplu:
   input : 2 5
   output: 5 2

   input : 13 -4
   output: -4 13

   input : 12 13
   output: 13 12        */
