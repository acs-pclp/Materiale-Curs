/* Programarea Calculatoarelor CA, 2020-2021

   Interschimbarea a doua valori / doi pointeri, folosind functii */

#include <stdio.h>

void swap_ptrs(int **a, int **b)
{
	int *tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int a, b, *p_a, *p_b;
	scanf("%d%d", &a, &b);
	p_a = &a;
	p_b = &b;

	printf("Inainte de schimbarea valorilor\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	swap_ints(&a, &b);
	printf("Dupa schimbarea valorilor\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);

	printf("Inainte de schimbarea adreselor\n");
	printf("p_a = %p\n", p_a);
	printf("p_b = %p\n", p_b);
	swap_ptrs(&p_a, &p_b);
	printf("Dupa schimbarea adreselor\n");
	printf("p_a = %p\n", p_a);
	printf("p_b = %p\n", p_b);
	return 0;
}

/* compile: gcc 03-interschimbare.c -o interschimbare
   run    : ./interschimbare

	Exemplu:

	input : 
	4 5
	
	output:
	Inainte de schimbarea valorii
	a = 4
	b = 5
	Dupa schimbarea valorii
	a = 5
	b = 4
	Inainte de schimbarea adresei
	p_a = 0x7ffc358c5cd0
	p_b = 0x7ffc358c5cd4
	Dupa schimbarea adresei
	p_a = 0x7ffc358c5cd4

	Atentie!! Adresele de la output se modifica la fiecare rulare a programului
	De ce? */
