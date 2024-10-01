/* Programarea Calculatoarelor CA, 2020-2021

Definiţi o funcţie pentru generarea de numere întregi aleatoare.

Un generator congruenţial de numere aleatoare este definit printr-o
relaţie de forma:
	xn+1 =(a*xn + b) % c,
în care x0 poartă numele de sămânţa (seed) generatorului. a, b şi x_{0} sunt
numere prime, care asigură o distribuţie aleatoare a numerelor în secvenţa
x_{n}. c oferă domeniul în care se generează numerele aleatoare şi se alege,
de obicei, tot un număr prim. Funcţia generator de numere aleatoare calculează
cu relaţia de mai sus pe x_{n+1} şi-l întoarce ca rezultat. Valoarea xn
trebuie să provină din apelul precedent al funcţiei, aşa că va fi declarată ca
variabilă statică, iniţializată cu valoarea sămânţei x_{0}. Iniţializarea va fi
făcută numai la primul apel al funcţiei, la fiecare din apelurile următoare se
preia valoarea rămasă din apelul precedent. Se remarcă faptul că se generează
întotdeauna aceeaşi secvenţă de numere aleatoare! Pentru a genera de fiecare
dată o altă secvenţă aleatoare, sămânţa ar trebui generată aleator.
*/

#include <stdio.h>

unsigned long aleator(unsigned long c)
{
	static unsigned long x = 113;
	static const unsigned long a = 121369, b = 179953;
	x = (a * x + b) % c;
	return x;
}

int main(void)
{
	/* programul generează n numere aleatoare mai mici decât MAX */
	long MAX, n;
	scanf("%ld%ld", &MAX, &n);

	for (long i = 1; i <= n; i++) {
		printf("%ld ", aleator(MAX));
	}
	printf("\n");
	return 0;
}

/* compile: gcc 06-aleator.c -o aleator
   run    : ./aleator

   Exemplu: aleator

   input  :
   100 5

   output :
   50 3 60 93 70

   input  :
   100 7
   output :
   50 3 60 93 70 83 80

   input  :
   50 7
   output :
   0 3 10 43 20 33 30 */

