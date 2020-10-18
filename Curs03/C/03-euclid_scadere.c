/* Programarea Calculatoarelor CA, 2020-2021

   Programul calculeaza cmmdc a doua numere a si b */

#include <stdio.h>

int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);

	while (a != b) {
		if (a > b) {
			a = a - b;
		} else {
			b = b - a;
		}
	}
	printf("Cel mai mare divizor comun este %d\n", a); /* a si b sunt egale */
	return 0;
}

/* compile: gcc 03-euclid_scadere.c -o euclid_scadere
   run    : ./euclid_scadere
   Exemplu: euclid_scadere
   input : 4
		   5
   output: Cel mai mare divizor comun este 1
   input : 6
		   14
   output: Cel mai mare divizor comun este 2
   input : 14
		   14
   output : Cel mai mare divizor comun este 14  */
