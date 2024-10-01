/* Programarea Calculatoarelor CA, 2019-2020

   Programul calculeaza minimul si maximul dintre 2 numere
   folosind "if" */

#include <stdio.h>

int main(void)
{
	int a, b, min, max;
	scanf("%d%d", &a, &b);

	if (a > b) {
		max = a;
		min = b;
	} else {
		max = b;
		min = a;
	}

	printf("max: %d\nmin: %d\n", max, min);
	return 0;
}

/* compile: gcc 04-min_max_if.c -o minmax
   run    : ./minmax

   Exemplu:

   input:
   -9 -3
   output:
   max: -3
   min: -9   */
