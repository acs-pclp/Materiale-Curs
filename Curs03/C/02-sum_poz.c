/* Programarea Calculatoarelor CA, 2020-2021

    O secvenţă de numere întregi este terminată prin 0.
		Să se calculeze suma termenilor pozitivi din secvenţă. */

#include <stdio.h>

int main(void)
{
	int n, suma;

	for (suma = 0, scanf("%d", &n); n; scanf("%d", &n)) {
		if (n < 0) {
			continue;
		}
		suma += n;
	}

	printf("Suma termenilor pozitivi = %d\n", suma);

	return 0;
}

/* compile: gcc 02-sum_poz.c -o sum_poz
   run    : ./sum_poz

   Exemplu: sum_poz

   input : 
   4 5 6 -9 1 0

   output: 
   Suma termenilor pozitivi = 16

   input : 
   1 3 5 7 -2 0

   output: 
   Suma termenilor pozitivi = 16

   input : 
   -1 -1 -1 0
   
   output: 
   Suma termenilor pozitivi = 0 */

