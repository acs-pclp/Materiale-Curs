/* Programarea Calculatoarelor CA, 2020-2021

   Să se verifice de cate ori a fost apelată o funcție într-un program. */

#include<stdio.h>

void func(void)
{
	static int inc = 1;
	printf("Apelul %d al functiei.\n", inc);
	printf("...do something!\n");
	inc++;
}

int main(void)
{
	func();
	func();
	func();
	return 0;
}

/* compile: gcc 05-inc_func.c -o inc_func
   run    : ./inc_func

   output:	Apelul 1 al functiei.
			...do something!
			Apelul 2 al functiei.
			...do something!
			Apelul 3 al functiei.
			...do something! */
