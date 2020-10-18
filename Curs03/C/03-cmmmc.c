/* Programarea Calculatoarelor CA, 2020-2021

   Programul calculeaza cmmmc a doua numere a si b */

#include <stdio.h>

int main(void)
{
	int a, b, cmmmc; /* produs va contine produsul a * b */
	scanf("%d%d", &a, &b);

	int produs = a * b;
	while (a != b) {
		if (a > b) {
			a = a - b;
		} else {
			b = b - a;
		}
	}
	cmmmc = produs / a;
	printf("Cel mai mic multiplu comun este %d\n", cmmmc);
	return 0;
}

/* compile: gcc 03-cmmmc.c -o cmmmc
   run    : ./cmmmc
   Exemplu: cmmmc
   input : 4
		   5
   output: Cel mai mic multiplu comun este 20
   input : 6
		   14
   output: Cel mai mic multiplu comun este 42
   input : 14
		   14
   output : Cel mai mic multiplu comun este 14 */
