/* Programarea Calculatoarelor CA, 2020-2021

O pereche de numere naturale a şi b se numesc numere prietene, dacă suma
divizorilor unuia dintre numere este egală cu celălalt număr. De exemplu,
220 şi 284 sunt numere prietene deoarece:
sd(220) = 1+2+4+5+10+11+20+22+44+55+110 = 284
sd(284) = 1+2+4+71+142 = 220

a) Scrieţi o funcţie având ca parametri un număr natural, care întoarce suma
   divizorilor numărului.
b) Scrieţi o funcţie având ca parametri două numere naturale, care întoarce
   1 sau 0, după cum cele două numere sunt sau nu prietene.
c) Scrieţi o funcţie main(), care în intervalul x, y dat găseşte toate
   perechile de numere prietene şi le afişează.
*/

#include <stdio.h>

/* funcţie având ca parametri un număr natural, care întoarce suma
	divizorilor numărului */
long sum_div(long n)
{
	long i, s = 1;
	for (i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			s += i + n / i;
		}
	}
	if (i * i == n) {
		s = s - n / i;
	}
	return s;
}

int prietene(long a, long b)
{
	return (sum_div(a) == b) && (sum_div(b) == a);
}

int main(void)
{
	long x, y;
	scanf("%ld%ld", &x, &y);

	/* varianta directa cu formarea produsului cartezian */
	for (long i = x; i <= y; i++) {
		for (long j = x; j <= y; j++) {
			if (prietene(i, j)) {
				printf("[%9ld,%9ld]\n", i, j);
			}
		}
	}

	/* varianta optimizata */
	/*
	for (long i = x; i <= y; i++) {
		long j = sum_div(i);
		if(j <= y && sum_div(j) == i){
			printf("[%9ld,%9ld]\n", i, j);
		}
	}
	*/

	return 0;
}

/*  compile: gcc 03-prietene.c -o prietene
    run    : ./prietene

    Exemplu: prietene

    input :
	1 1000

    output:
	[        1,        1]
	[        6,        6]
	[       28,       28]
	[      220,      284]
	[      284,      220]
	[      496,      496] */
