/* Programarea Calculatoarelor CA, 2020-2021

  Formarea unei propozitii din mai multe cuvinte*/

#include <stdio.h>
#include <string.h>

#define BUF_LEN 1000
#define WORD_LEN 10
#define NUM_WORDS 50

void make_sentence(int n, const char words[][WORD_LEN], char sentence[BUF_LEN])
{
	for (int i = 0; i < n; i++) {
		size_t len = strlen(words[i]);
		strncat(sentence, words[i], len * sizeof(char));
		strcat(sentence, " ");
	}
}

int main(void)
{
	const char words[][WORD_LEN] = {"Gigel", "invata", "bine", "la", "PC", "!"};
	char buffer[BUF_LEN] = {0};
	size_t len = sizeof(words) / sizeof(words[0]);
	make_sentence(len, words, buffer);
	printf("Propozitia este: %s\n", buffer);

	return 0;
}

/* compile: gcc 02-concatenare_cuvinte.c -o concatenare_cuvinte
	run   : ./concatenare_cuvinte

    output:
    Propozitia este: Gigel invata bine la PC !

	*/
