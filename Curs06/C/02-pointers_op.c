/* Programarea Calculatoarelor CA, 2020-2021

  Operatii cu pointeri */

#include <stdio.h>

int main(void)
{
	int **p, q;

	p = (int **)5;
	q = 10;

	printf("%p - %d\n", q + p, (int) (q + p));

	return 0;
}

/* compile: gcc 02-pointers_op.c -o pointers_op
	run   : ./pointers-op

	output:
	0x55 - 85


	In acest exemplu sizeof(int*) este 8 (rulat pe 64 biti).
	*/
