/*
	Fiind dat o fraza de cuvinte (format din litere si caractere speciale,
	citit de la tastatura), să se înlocuiască cu "*" toate caracterele
	din cuvânt care se regăsesc într-un alfabet (citit de la tastatura)
*/

#include <stdio.h>
#include <string.h>

#define NMAX 100

/* inlocuieste toate aparitiile caracterului c in
   sirul de caractere word cu caracterul replacement
*/
void replace_char(char *string, char c, char replacement)
{
	char *position;
	while ((position = strchr(string, c)))
		*position = replacement;
}

int main(void)
{
	char phrase[NMAX], alphabet[NMAX];

	fgets(phrase, NMAX, stdin);
	fgets(alphabet, NMAX, stdin);

	int size = strlen(alphabet);
	// pentru fiecare caracter din alpfabet,
	// inlocuim apariitile lui in phrase cu "*"
	for (int i = 0; i < size - 1; ++i)
		replace_char(phrase, alphabet[i], '*');
	printf("%s\n", phrase);

	return 0;
}

/*  compile: gcc 03-replace_chars.c -o 03-replace_chars
    run    : ./03-replace_chars

    Exemplu:
    input :
	Alina a mers la piata si a cumparat 10 kg de mere.
	abcdefghijkl
    output:
	A**n* * m*rs ** p**t* s* * *ump*r*t 10 ** ** m*r*.*

	input :
	C-3PO && R2-D2 R b35t fr13nd5
	abcdefghijklmnopqrstuvwxyz-
    output:
	C*3PO && R2*D2 R *35* **13**5*
*/
