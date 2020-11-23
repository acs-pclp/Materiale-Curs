/*
Citiţi de la intrarea standard un şir de caractere de lungime
necunoscută într-un vector alocat dinamic. Alocarea de memorie
se va face progresiv, în incremente de lungime INC,
după citirea a INC caractere se face o realocare.
*/

#include <stdio.h>
#include <stdlib.h>

#define INC 10

char *dynamic_read(void)
{
	char *p, *q;
	unsigned int size = INC;
	int n;

	p = (char *)malloc(size * sizeof(char));
	if (!p) {
		fprintf(stderr, "malloc() failed\n");
		return NULL;
	}
	q = p;

	for (n = 1; (*p = getchar()) != '\n' && *p != EOF; n++) {
		if (n % INC == 0) {
			size += INC;
			p = realloc(q, size * sizeof(char));
			if (!p) {
				fprintf(stderr, "realloc() failed\n");
				free(q);
				return NULL;
			}

			q = p;
			p += n;
			continue;
		}
		p++;
	}
	*p = '\0';

	p = realloc(q, n * sizeof(char));
	if (!p) {
		fprintf(stderr, "realloc() failed\n");
		free(q);
		return NULL;
	}

	return p;
}

int main(void)
{
	char *text = dynamic_read();
	puts(text);
	free(text);

	return 0;
}

/*  compile: gcc 06-inc_alloc.c -o 06-inc_alloc
    run    : ./06-inc_alloc

	input:
	Am zis o data pe luna, sa ducem o viata buna!
	output:
	Am zis o data pe luna, sa ducem o viata buna!
*/
