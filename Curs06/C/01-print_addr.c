/* Programarea Calculatoarelor CA, 2020-2021

  Afisarea adreselor de memorie */

#include <stdio.h>

int main(void)
{
	int x[5];

	printf("%p\n", x);
	printf("%p\n", x + 1);
	printf("%p\n", &x);
	printf("%p\n", &x + 1);
	printf("%p\n", &x[0]);
	return 0;
}

/* compile: gcc 01-print_addr.c -o print_addr
	run   : ./print_addr

	output: 
	0x7ffeea2bab00
	0x7ffeea2bab04
	0x7ffeea2bab00
	0x7ffeea2bab14
	0x7ffeea2bab00

	Atentie!! Adresele de la output se modifica la fiecare rulare a programului
	De ce? */
