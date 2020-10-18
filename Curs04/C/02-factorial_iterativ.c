/* Programarea Calculatoarelor CA, 2020-2021

   Programul calculeaza iterativ factorialul unui numar dat  */

#include <stdio.h>

int factorial(int n)
{
	int result = 1;

	for (int i = 2; i <= n; i++) {
		result = result * i;
	}

	return result;
}

int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d! = %d\n", n, factorial(n));

	return 0;
}

/* compile: gcc 02-factorial_iterativ.c -o factorial_iterativ
   run    : ./factorial_iterativ
   Exemplu: factorial_iterativ
   input : 5
   output: 5! = 120
   input : 7
   output: 7! = 5040
   input : 0
   output : 0! = 1 */
