/* Programarea Calculatoarelor CA, 2020-2021

   Programul verifica daca un numar este prim */

#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	if (n < 2) {
		printf("Numarul nu este numar prim\n");
	} else {
		int ok = 1; /* presupunem ca numarul este prim */
		for (int i = 2; 1L * i * i <= n; ++i) {
			if (n % i == 0) {
				ok = 0; /* am gasit un divizor al numarului */
				break;
			}
		}
		if (ok == 1) {
			printf("Numarul este numar prim\n");
		} else {
			printf("Numarul nu este numar prim\n");
		}
	}
	return 0;
}

/* compile: gcc 05-numar_prim.c -o prim
   run    : ./prim
   Exemplu: prim
   input : 2
   output: Numarul este numar prim
   input : 4
   output: Numarul nu este numar prim
   input : 17
   output : Numarul este numar prim  */
