/*
Să se sorteze o listă de nume. Fiecare nume se citește pe un rând,
iar pe ultimul rând se va citi caracterul # pentru a încheia lista.
Folosirea unui tablou de şiruri de caractere este lipsită
de eficienţă, deoarece şirurile sunt de lungimi
diferite. Vom folosi un tablou de pointeri la şiruri de
caractere. Prin sortare nu se vor schimba şirurile
de caractere, ci pointerii către acestea.
*/

#include <stdio.h>
#include <string.h>

#define MAX 100
/*
Citirea şirurilor de caractere presupune: rezervarea de spaţiu
pentru şiruri și iniţializarea tabloului de pointeri cu adresele
şirurilor. Pentru rezervarea de spaţiu se foloseşte funcţia:
	char *strdup(char *s);
care salvează şirul indicat de s într-o zonă de memorie disponibilă,
alocată dinamic și întoarce un pointer către zona respectivă sau NULL.
*/

int read_string(char *tabp[])
{
	int n = 0;
	char tab[MAX];
	while (1) {
		fgets(tab, MAX, stdin);
		if (tab[0] == '#')
			break;

		// fgets include și caracterul '\n'
		tab[strlen(tab) - 1] = '\0';
		tabp[n++] = strdup(tab);
	}
	return n;
}

/*
Sortarea o vom realiza cu algoritmul bulelor: dacă şirul de nume
ar fi ordonat, atunci două nume consecutive s-ar afla în relaţia
< sau ==. Vom căuta aşadar relaţiile >, schimbând de fiecare dată
între ei pointerii corespunzători (schimbare mai eficientă decât
schimbarea şirurilor). Se fac mai multe parcurgeri ale listei de
nume; la fiecare trecere, o variabilă martor – sortat, iniţializată
la 1 este pusă pe 0, atunci când se interschimbă doi pointeri.
Lista de nume va fi sortată în momentul în care în urma unei
parcurgeri a listei se constată că nu s-a mai făcut nici o schimbare
de pointeri.
*/

void sort_list(char *tp[], int n)
{
	int done;
	char *tmp;

	do {
		done = 1;
		for (int j = 0; j < n - 1; j++) {
			if (strcmp(tp[j], tp[j + 1]) > 0) {
				tmp = tp[j];
				tp[j] = tp[j + 1],
				tp[j + 1] = tmp;
				done = 0;
			}
		}
	} while (done);
}

void print_list(char *tp[], int n)
{
	for (int j = 0; j < n; j++) {
		if (tp[j])
			puts(tp[j]);
	}
}

int main(void)
{
	int n;
	char *names[100];
	n = read_string(names);
	sort_list(names, n);
	print_list(names, n);
	return 0;
}

/*  compile: gcc 06-sort_list.c -o 06-sort_list
    run    : ./06-sort_list

    Exemplu:
    input :
    ana
    mihai
    ion
    #
    output:
	ana
	ion
	mihai
*/
