/*
    Exemple de lucru cu functii de modificare
	a memoriei: memcpy, memmove, memset, memcmp
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NMAX 100

int main(void)
{
	/* void *memcpy (void *destination, const void *source, size_t num)
	Copiaza primii num byte-i de la zona de memorie indicata de source,
	la adresa de memorie indicata de destination.
	Functia returneaza destinatia. */
	char phrase[] = "Lorem Ipsum";
	char *dummy = (char *)malloc(NMAX * sizeof(char));
	if (!dummy) {
		fprintf(stderr, "malloc() failed\n");
		return -1;
	}
	memcpy(dummy, phrase, strlen(phrase));
	printf("%s\n", dummy);
	free(dummy);

	/* void *memmove(void *destination, const void *source, size_t num)
	Copiaza un numar de num caractere de la sursa, la zona de memorie
	indicata de destinatie. Copierea are loc ca si cum ar exista un buffer
	intermediar, deci sursa si destinatia se pot suprapune. Functia nu
	verifica terminatorul de şir la sursa, copiaza mereu num bytes, deci
	pentru a evita depasirea, trebuie ca dimensiunea sursei sa fie mai mare
	ca num. Functia returneaza destinatia. */
	char wish[] = "We wish you a merry Christmas!",
		 new_year[] = "a happy new year!";
	memmove(wish + 12, new_year, strlen(new_year));
	printf("%s\n", wish);

	/* void *memset(void *ptr, int val, size_t num)
	In zona de memorie data de pointerul ptr, sunt setate primii num octeti
	la valoarea data de val. Pentru siruri de caractere - in care fiecare
	element ocupa 1 octet - aceasta are ca rezultat inlocuirea primelor 'num'
	valori cu cea data ca argument. */
	memset(wish + 12, '*', strlen(new_year));
	printf("%s\n", wish);

	/* int memcmp (const void *str1, const void *str2, size_t num)
	Compara primii num byte-i de la zona de memorie indicata de str1,
	cu primii num byte-i de la adresa de memorie indicata de str2.
	Functia returneaza un numar intreg cu semnificatia:
		- 0, daca str1 = str2
		- > 0, daca str1 > str2
		- < 0, daca str1 < str2
	*/
	int result = memcmp("Last Christmas, I gave you my heart",
						"Last Christmas, you gave it away", 15);
	if (!result)
		printf("The strings are equal\n");
	else if (result > 0)
		printf("The first string is greater\n");
	else
		printf("The second string is greater\n");

	return 0;
}

/*  compile: gcc 05-memory_functions.c -o 05-memory_functions
    run    : ./05-memory_functions

	output:
	Lorem Ipsum
	We wish you a happy new year!!
	We wish you *****************!
	The strings are equal
*/
