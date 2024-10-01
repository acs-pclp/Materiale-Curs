/* Programarea Calculatoarelor CA, 2020-2021

   Programul verifica daca un numar este palindrom  */

#include <stdio.h>

int main(void)
{
	int n, invers = 0;
	scanf("%d", &n);

	int copie = n;
	while (copie > 0) {
		invers = invers * 10 + copie % 10;
		copie = copie / 10;
	}
	if (n == invers) {
		printf("Numarul este palindrom\n");
	} else {
		printf("Numarul nu este palindrom\n");
	}

	return 0;
}

/* compile: gcc 04-palindrom.c -o palindrom
   run    : ./palindrom
   Exemplu: palindrom
   input : 121
   output: Numarul este palindrom
   input : 321
   output: Numarul nu este palindrom
   input : 9
   output : Numarul este palindrom  */
