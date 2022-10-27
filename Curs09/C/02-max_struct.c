#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESC 5
#define NAMEL 8

struct Elev
{
	char Nume[NAMEL];
	float Nota;
};

char MulteNume[NAMESC][NAMEL] = {"Popescu", "Stan", "Andrei", "Ion", "Darina"};

struct Elev* getStudents()
{
	struct Elev* elevi = malloc(sizeof(elevi) * NAMESC);

	for (int i = 0; i < NAMESC; i++)
	{
		strncpy(elevi[i].Nume, MulteNume[i], NAMEL);

		elevi[i].Nota = (rand() % 1000) / 100.0;
	}

	return elevi;
}

int main()
{
	struct Elev* elevi = getStudents();
	struct Elev maxNota = elevi[0];
	
	printf("\nStudenti:\n");
	for (int i = 0; i < NAMESC; i++)
	{
		printf("(%8s,%8.2f)\n", elevi[i].Nume, elevi[i].Nota);

		if (maxNota.Nota < elevi[i].Nota)
		{
			maxNota = elevi[i];
		}

	}

	printf("\nStudentul cu cea mai mare nota: %s\n", maxNota.Nume);

	return 0;
}