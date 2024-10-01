/* Programarea Calculatoarelor CA, 2020-2021

Verificaţi „conjectura lui Goldbach”, potrivit căreia orice număr par poate fi
scris ca cel puţin o sumă a două numere prime. Programul va genera şi afişa
descompunerile tuturor numerelor pare până la o limită dată L. Vom considera
şi pe 1 ca număr prim. Exceptând primele două descompuneri: 2=1+1 şi 4=1+3=2+2,
celelalte descompuneri vor avea termenii numere prime impare. Pentru un număr
par p, o eventuală descompunere, având termenii a şi p-a impune ca acestea
să fie prime şi impare.
*/

#include <stdio.h>

int prim(long n)
{
	for (long d = 2; d * d <= n;) {
		if (n % d == 0) {
			return 0;
		}
		if (d == 2) {
			d = 3;
		} else {
			d += 2;
		}
	}
	return 1;
}

int main(void)
{
	long L, nd;
	scanf("%ld", &L);

	/* scrierea primelor doua descompuneri */
	printf("2 = 1 + 1\n4 = 1 + 3 = 2 + 2\n");

	for (long p = 6; p <= L; p += 2) {
		printf("%ld", p);
		nd = 0;
		for (long a = 1; a <= p / 2; a += 2) {
			if (prim(a) && prim(p - a)) {
				nd++;
				printf(" = %ld + %ld", a, p - a);
			}
		}

		if (nd == 0) {
			printf("nu verifica conjectura\n");
		} else {
			printf("\n");
		}
	}
	return 0;
}

/*  compile: gcc 04-goldbach.c -o goldbach
    run    : ./goldbach

    Exemplu:

    input :
	10
    output:
	2 = 1 + 1
	4 = 1 + 3 = 2 + 2
	6 = 1 + 5 = 3 + 3
	8 = 1 + 7 = 3 + 5
	10 = 3 + 7 = 5 + 5

    */
