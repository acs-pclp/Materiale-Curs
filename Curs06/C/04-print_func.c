/* Programarea Calculatoarelor CA, 2020-2021
    Definiţi o funcţie care afişează o valoare ce poate aparţine unuia din
    tipurile: char, int, double. */

#include<stdio.h>

enum tip {caracter, intreg, real};

void afisare(void *px, enum tip t)
{
	switch (t) {
	case caracter:
		printf("%c\n", *(char *)px);
		break;
	case intreg:
		printf("%d\n", *(int *)px);
		break;
	case real:
		printf("%lf\n", *(double *)px);
		break;
	}
}

int main(void)
{
	char c = 'X';
	int i = 10;
	double d = 2.5;
	afisare(&c, caracter);
	afisare(&i, intreg);
	afisare(&d, real);
	return 0;
}

/* compile: gcc 04-print_func.c -o print_func
	run   : ./print_func
		
	output: 
	X
	10
	2.500000 */
