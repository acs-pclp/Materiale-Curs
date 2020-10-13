/* Programarea Calculatoarelor CA, 2019-2020

   Determinarea minimului și maximului cu operator condițional. */

#include <stdio.h>

int main(void)
{
	int a, b, min, max;
	scanf("%d%d", &a, &b);

	a < b ? (min = a, max = b) : (min = b, max = a);

	printf("min = %d\nmax = %d\n", min, max);

	return 0;
}

/*  2342 435524
min = 2342
max = 435524
*/
