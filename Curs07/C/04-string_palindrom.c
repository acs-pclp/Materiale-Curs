/*
    Verificarea că un text format din cuvinte separate
    doar prin spații este palindrom (se elimină spațiile
    și se transformă majusculele în minuscule)
*/

#include <stdio.h>
#include <string.h>

#define NMAX 100

/*  copiaza caracterele din stringul src in stringul dst,
    cu exceptia spatiilor si a sfarsitului de linie,
    transformand majusculele in minuscule
*/
void remove_spaces_and_uncapitalize(const char *src, char *dst)
{
	memset(dst, 0, NMAX);

	while (*src) {
		if (*src == ' ' || *src == '\n') {
			++src;
			continue;
		}

		if (*src >= 'A' && *src <= 'Z')
			*(dst++) = *(src++) - ('A' - 'a');
	    else
			*(dst++) = *(src++);
	}
}

// Verifica daca string este palindrom
void check_string_palindrom(const char *string)
{
	int size = strlen(string);

	for (int i = 0; i < size / 2; ++i) {
		if (string[i] != string[size - i - 1]) {
			printf("Stringul introdus NU este palindrom\n");
			return;
		}
	}
	printf("Stringul introdus este palindrom\n");
}

int main(void)
{
	char string[NMAX], sol[NMAX];

	fgets(string, NMAX, stdin);
	remove_spaces_and_uncapitalize(string, sol);

	printf("%s\n", sol);
	check_string_palindrom(sol);

	return 0;
}

/*  compile: gcc 04-string_palindrom.c -o 04-string_palindrom
    run    : ./04-string_palindrom

    Exemplu:
    input :
    Do geese see God
    output:
    dogeeseseegod
    Stringul introdus este palindrom

    input :
    Ana are mere
    output:
    anaaremere
    Stringul introdus NU este palindrom
*/
