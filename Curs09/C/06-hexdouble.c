/*
Definiţi o funcţie care afişează reprezentarea internă a
unui număr real.
*/

#include <stdio.h>

void hexdouble(double x)
{
	union {double d; char c; } u;
	unsigned int n = sizeof(double);
	char *p = &u.c;
	u.d = x;
	while (n--)
		printf("%02x ", *p++);
	printf("\n");
}

int main(void)
{
	double x;

	scanf("%lf", &x);
	hexdouble(x);

	return 0;
}

/*  compile: gcc 06-hexdouble.c -o 06-hexdouble
    run    : ./06-hexdouble

    Exemple:

	2.45
	ffffff9a ffffff99 ffffff99 ffffff99 ffffff99 ffffff99 03 40

	-3.5
	00 00 00 00 00 00 0c ffffffc0

	0
	00 00 00 00 00 00 00 00

	12
	00 00 00 00 00 00 28 40

	1.33333
	2f 69 ffffff8c ffffffd6 51 55 fffffff5 3f
*/
