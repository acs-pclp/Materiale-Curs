/* Programarea Calculatoarelor CA, 2022-2023
 *
 *	Suma elementelor parametrilor liniei de comanda
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isnumber(const char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (!isdigit(str[i]))
			return 0;

	return 1;
}

int main(int argc, char **argv)
{
	int s = 0;

	for (int i = 1; i < argc; i++) {
		if (!isnumber(argv[i])) {
			fprintf(stderr, "Invalid input");
			return 0;
		}
		s += atoi(argv[i]);
	}

	printf("%d\n", s);

	return 0;
}

/*
 *	compile: gcc 03-params_sum.c -o params_sum
 *	run: ./params_sum 1 2 3 4 5
 *
 *	Output:
 *		15
 *
 */
