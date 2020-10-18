/* Programarea Calculatoarelor CA, 2020-2021

   Programul determina ultima zi din luna.*/

#include <stdio.h>

int main(void)
{
	int luna, an;
	scanf("%d%d", &luna, &an);

	switch (luna) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		printf("Luna are 31 de zile.\n");
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		printf("Luna are 30 de zile.\n");
		break;
	case 2:
		if ((an % 4 == 0 && an % 100 != 0) || (an % 400 == 0)) {
			printf("Luna are 29 de zile, deoarece anul e bisect.\n");
		} else {
			printf("Luna are 28 de zile, deoarece anul nu e bisect.\n");
		}
		break;
	default:
		printf("Nu am primit o luna valida.\n");
		break;
	}
	return 0;
}

/* compile: gcc 01-numar_zile.c -o numar_zile
   run    : ./numar_zile
   Exemplu:

   input  :
   02 2100

   output :
   Luna are 28 de zile, deoarece anul nu e bisect.

   input  :
   03 2021

   output :
   Luna are 31 de zile.

   input  :
   13 2020

   output :
   Nu am primit o luna valida.
   */
