/* Programarea Calculatoarelor CA, 2020-2021

   Programul calculeaza cmmdc a doua numere a si b */

#include <stdio.h>

int main(void)
{
	int a, b, tmp;
	scanf("%d%d", &a, &b);

	while (b != 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	printf("Cel mai mare divizor comun este %d\n", a);
}

/* compile: gcc 03-euclid_impartire.c -o euclid_impartire
   run    : ./euclid_impartire
   Exemplu: euclid_impartire
   input : 4
		   5
   output: Cel mai mare divizor comun este 1
   input : 6
		   14
   output: Cel mai mare divizor comun este 2
   input : 14
		   14
   output : Cel mai mare divizor comun este 14  */
