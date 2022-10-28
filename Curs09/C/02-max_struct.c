/* Programarea Calculatoarelor CA, 2022-2023

	Crearea unei structuri cu 2 campuri (nume si nota) si 
		afisarea numelui cu cea mai mare nota. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMES_COUNT 5
#define MAX_NAME_LENGTH 8

struct Elev
{
	char Nume[MAX_NAME_LENGTH];
	float Nota;
};

struct Elev* getRandomStudents(const char MulteNume[][MAX_NAME_LENGTH])
{
	struct Elev* elevi = malloc(sizeof(elevi) * NAMES_COUNT);

	for (int i = 0; i < NAMES_COUNT; i++)
	{
		strncpy(elevi[i].Nume, MulteNume[i], MAX_NAME_LENGTH);

		elevi[i].Nota = (rand() % 1000) / 100.0;
	}

	return elevi;
}

int main()
{
	const char MulteNume[NAMES_COUNT][MAX_NAME_LENGTH] = { 
		"Popescu", "Stan", "Andrei", "Ion", "Darina" };

	struct Elev* elevi = getRandomStudents(MulteNume);
	struct Elev maxNota = elevi[0];
	
	printf("\nStudentii inregistrati:\n");

	for (int i = 0; i < NAMES_COUNT; i++)
	{
		printf("(%8s,%8.2f)\n", elevi[i].Nume, elevi[i].Nota);

		if (maxNota.Nota < elevi[i].Nota)
		{
			maxNota = elevi[i];
		}

	}

	printf("\nStudentul cu cea mai mare nota: %s\n", maxNota.Nume);

	free(elevi);

	return 0;
}

/*

	compile: gcc 02-max_struct.c -o max_struct
	run: ./max_struct

	Output:

		Studenti inregistrati:
			( Popescu,    0.41)
			(    Stan,    4.67)
			(  Andrei,    3.34)
			(     Ion,    5.00)
			(  Darina,    1.69)

		Studentul cu cea mai mare nota: Ion

*/