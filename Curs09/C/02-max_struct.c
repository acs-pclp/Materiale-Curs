/* Programarea Calculatoarelor CA, 2022-2023
*
*	Crearea unei structuri cu 2 campuri (nume si nota) si 
*		afisarea numelui cu cea mai mare nota. 
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMES_COUNT 5
#define MAX_NAME_LENGTH 8

struct Student
{
	char Name[MAX_NAME_LENGTH];
	float Grade;
};

struct Student* get_random_students(const char names_array[][MAX_NAME_LENGTH])
{
	struct Student* elevi = malloc(sizeof(struct Student) * NAMES_COUNT);
	if (elevi == NULL)
	{
		fprintf(stderr, "Out of memory! Exiting...\n");
		exit(-11);
	}

	for (int i = 0; i < NAMES_COUNT; i++)
	{
		strncpy(elevi[i].Name, names_array[i], MAX_NAME_LENGTH);

		elevi[i].Grade = (rand() % 1000) / 100.0;
	}

	return elevi;
}

int main()
{
	const char names_array[NAMES_COUNT][MAX_NAME_LENGTH] = { 
		"Popescu", "Stan", "Andrei", "Ion", "Darina" };

	struct Student* students = get_random_students(names_array);
	struct Student max_grade_student = students[0];
	
	printf("\nStudentii inregistrati:\n");

	for (int i = 0; i < NAMES_COUNT; i++)
	{
		printf("(%8s,%8.2f)\n", students[i].Name, students[i].Grade);

		if (max_grade_student.Grade < students[i].Grade)
		{
			max_grade_student = students[i];
		}

	}

	printf("\nStudentul cu cea mai mare nota: %s\n", max_grade_student.Name);
	free(students);
	return 0;
}

/*
*
*	compile: gcc 02-max_struct.c -o max_struct
*	run: ./max_struct
*
*	Output:
*		Studenti inregistrati:
*			( Popescu,    0.41)
*			(    Stan,    4.67)
*			(  Andrei,    3.34)
*			(     Ion,    5.00)
*			(  Darina,    1.69)
*
*		Studentul cu cea mai mare nota: Ion
*
*/
