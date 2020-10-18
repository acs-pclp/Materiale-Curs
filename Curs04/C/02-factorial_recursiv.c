/* Programarea Calculatoarelor CA, 2020-2021

   Programul calculeaza recursiv factorialul unui numar dat  */

#include <stdio.h>

int factorial(int n)
{
	if (n <= 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d! = %d\n", n, factorial(n));

	return 0;
}

/* compile: gcc 02-factorial_recursiv.c -o factorial_recursiv
   run    : ./factorial_recursiv
   Exemplu: factorial_recursiv
   input : 5
   output: 5! = 120
   input : 7
   output: 7! = 5040
   input : 0
   output : 0! = 1 */
