/*
Scrieţi un program care extrage cuvintele distincte dintr-un
text, scriind în dreptul fiecărui cuvânt numărul de apariţii
ale acestuia în text (strstr, strtok, strcmp, strdup).
*/

#include <stdio.h>
#include <string.h>

#define NW 100
#define MAX_LINE 80

/*
Caută șirul p în tabloul de siruri cuv
întoarce poziâia în care se află p în cuv sau -1.
*/
int find_word(char *p, int nw, char *words[])
{
	for (int i = 0; i < nw; i++) {
		if (strcmp(p, words[i]) == 0)
			return i;
	}
	return -1;
}

int main(void)
{
	const char delim[] = " .,:;-()\t\n";	/* separatori intre cuvinte */
	char line[MAX_LINE];					/* tampon pentru citirea unei linii */
	char *words[NW], f[NW], *p;				/* tablou de cuvinte */
	int nw = 0, pos;

	freopen("text.txt", "r", stdin); /* redirectez stdin - programul va citi 
								 din text.txt: echivalent cu 05-words < text.txt */

	while (fgets(line, MAX_LINE, stdin)) {
		for (p = strtok(line, delim); p; p = strtok(NULL, delim)) {
			pos = find_word(p, nw, words);
			if (pos == -1) {
				words[nw] = strdup(p);
				f[nw++] = 1;
			} else {
				f[pos]++;
			}
		}
	}

	printf("Numar cuvinte distincte: %3d\n", nw);
	for (int i = 0; i < nw; i++)
		printf("%16s %3d\n", words[i], f[i]);

	return 0;
}

/*  compile: gcc 05-words.c -o 05-words
    run    : ./05-words

    Exemplu:
    input : (nu este nevoie de input pt aceasta problema)

	output:
	Numar cuvinte distincte:  67
		   Lorem   4
		   Ipsum   4
			  is   1
		  simply   1
		   dummy   2
			text   2
			  of   4
			 the   6
		printing   1
			 and   3
	 ......................
    */
