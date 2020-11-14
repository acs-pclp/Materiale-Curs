/* Programarea Calculatoarelor CA, 2020-2021

  Copierea unui sir de caractere s in d */

#define NMAX 50
#include <stdio.h>
#include <string.h>

void remove_trailing_newline(char s[])
{
	size_t len = strlen(s);
	if (len > 0) {
		s[len - 1] = 0; // scot caracterul '\n'
	}
}

int main(void)
{
	char s[NMAX];
	char d[NMAX];
	fgets(s, NMAX, stdin);
	remove_trailing_newline(s);
	strcpy(d, s);
	printf("Sursa = %s\n", s);
	printf("Destinatie = %s\n", d);

	return 0;
}

/* compile: gcc 01-copiere_sir.c -o copiere_sir
	run   : ./copiere_sir

    input   :
    programare

    output  :
    Sursa = programare
    Destinatie = programare

    input   :
    Gigel e student la programare!

    output  :
    Sursa = Gigel e student la programare!
    Destinatie = Gigel e student la programare!

    input   :
    cuvantfoartefoartefoartefoartefoartelungcarenuincapeindimensiuneainitiala
    output  :
    Sursa = cuvantfoartefoartefoartefoartefoartelungcarenuin
    Destinatie = cuvantfoartefoartefoartefoartefoartelungcarenuin

	*/
