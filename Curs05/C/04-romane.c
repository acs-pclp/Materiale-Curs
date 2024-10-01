/* Programarea Calculatoarelor CA, 2020-2021

Scrieţi un program care converteşte un şir de caractere reprezentând un număr
scris cu cifre romane  în corespondentul său cu cifre arabe.

Notaţia cu cifre romane este un sistem nepoziţional, care foloseşte cifrele:
M, D, C, L, X, V, I, având respectiv valorile: 1000, 500, 100,50, 10, 5, 1.
Pentru a obţine valoarea numărului, se pleacă cu acesta de la 0 şi se adaugă
pe rând contribuţiile cifrelor astfel: dacă valoarea cifrei romane curente
este mai mare sau egală cu cifra care urmează, atunci valoarea cifrei curente
se adaugă la valoarea numărului arab, altfel se scade din acesta.
*/

#include <stdio.h>

int conv(char c, char roman[], int arab[])
{
	int j = 0;
	while (roman[j++] != c && j < 8);
	if (j < 8) {
		return arab[--j];
	} else {
		return -1;
	}
	return 0;
}

int main(void)
{
	/* tablourile de caractere romana / corespondentul in cifre arabe */
	char roman[] = "MDCLXVI";
	int arab[] = {1000, 500, 100, 50, 10, 5, 1};

	char nrom[15];
	int n = 0; /* n = lungimea numarului scris cu cifre romane*/
	int narab = 0;
	int crt, urm;

	while ((nrom[n++] = getchar()) != '\n');
	for (int i = 0; i < n - 1; i++) {
		crt = conv(nrom[i], roman, arab);
		urm = conv(nrom[i + 1], roman, arab);
		if (crt >= urm) {
			narab += crt;
		} else {
			narab -= crt;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		printf("%c", nrom[i]);
	}
	printf(" = %d\n", narab);
	return 0;
}

/* compile: gcc 04-romane.c -o romane
   run    : ./romane

   Exemplu:

   input  :
   MCMXCVIII

   output :
   MCMXCVIII = 1998

   input  :
   MDCLXVI

   output :
   MDCLXVI = 1666

   input  :
   MMXX

   output :
   MMXX = 2020 */
