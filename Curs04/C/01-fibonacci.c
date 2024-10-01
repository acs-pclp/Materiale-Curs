/* Programarea Calculatoarelor CA, 2020-2021

   Calcularea unui termen din sirul lui Fibonacci, recursiv + iterativ */

#include <stdio.h>
#include <time.h>

long fibo_r(int n)
{
	if (n == 0 || n == 1) {
		return 1;
	}
	return fibo_r(n - 1) + fibo_r(n - 2);
}

long fibo_i(int n)
{
	long f0 = 1, f1 = 1;

	if (n == 0 || n == 1) {
		return 1;
	}
	for (int i = 2; i <= n; i++) {
		long f = f1 + f0;
		f0 = f1;
		f1 = f;
	}

	return f1;
}

int main(void)
{
	clock_t start, end;
	double cpu_time_used_r, cpu_time_used_i;

	int n;
	long fn_r, fn_i;
	scanf("%d", &n);

	start = clock();
	fn_i = fibo_i(n);
	end = clock();
	cpu_time_used_i = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("%ld - calculat in %lf secunde\n", fn_i, cpu_time_used_i);

	start = clock();
	fn_r = fibo_r(n);
	end = clock();
	cpu_time_used_r = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("%ld - calculat in %lf secunde\n", fn_r, cpu_time_used_r);

	return 0;
}

/* compile: gcc 01-fibonacci.c -o fibo
   run    : ./fibo

   Exemplu: fibo

   input :
   40

   output:
   165580141 - calculat in 0.000003 secunde
   165580141 - calculat in 0.594261 secunde

   input :
   30
   output:
   1346269 - calculat in 0.000005 secunde
   1346269 - calculat in 0.032210 secunde

   input : 45
   output:
   1836311903 - calculat in 0.000004 secunde
   1836311903 - calculat in 7.281272 secunde */
