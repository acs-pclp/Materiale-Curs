/* Programarea Calculatoarelor CA, 2019-2020

   Programul transforma un numar de secunde in zile, ore, minute, secunde. */

#include <stdio.h>

#define SECUNDE_PE_MIN 60
#define SECUNDE_PE_ORA (60 * SECUNDE_PE_MIN)
#define SECUNDE_PE_ZI  (24 * SECUNDE_PE_ORA)

int main(void)
{
	unsigned int n;
	scanf("%u", &n);

	unsigned int zile = n / SECUNDE_PE_ZI;
	n %= SECUNDE_PE_ZI;

	unsigned int ore = n / SECUNDE_PE_ORA;
	n %= SECUNDE_PE_ORA;

	unsigned int minute = n / SECUNDE_PE_MIN;
	n %= SECUNDE_PE_MIN;

	unsigned int secunde = n;

	printf("%u zile %u ore %u minute %u secunde\n",
		   zile, ore, minute, secunde);

	return 0;
}

/*  compile: gcc 05-secunde.c -o secunde
    run    : ./secunde

    Exemplu:
    input : 225888
    output: 2 zile 14 ore 44 minute 48 secunde

    input: 90061
    outut: 1 zile 1 ore 1 minute 1 secunde  */
