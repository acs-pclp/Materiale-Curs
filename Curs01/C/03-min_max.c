/* Programarea Calculatoarelor CA, 2019-2020

   Programul calculeaza minimul si maximul dintre 2 numere
   fara a compara numerele intre ele  */

#include <stdio.h>
#include <stdlib.h>  // pentru a folosi functia abs (modul)

int main(void)
{
	int a, b, min, max;
	scanf("%d%d", &a, &b);

	max = (a + b + abs(a - b)) / 2;
	min = (a + b - max);

	printf("max: %d\nmin: %d\n", max, min);
	return 0;
}

/* compile: gcc 03-min_max.c -o minmax
   run    : ./minmax

   Exemplu

   input:
   3 8
   output:
   max: 8
   min: 3   */
