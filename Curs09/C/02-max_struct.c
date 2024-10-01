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

struct student_t {
	char name[MAX_NAME_LENGTH];
	float grade;
};

struct student_t *generate_random_grades(const char names_array[][MAX_NAME_LENGTH])
{
	struct student_t *students = malloc(sizeof(struct student_t) * NAMES_COUNT);
	if (!students) {
		fprintf(stderr, "Out of memory! Exiting...\n");
		exit(-1);
	}

	for (int i = 0; i < NAMES_COUNT; i++) {
		strncpy(students[i].name, names_array[i], MAX_NAME_LENGTH);
		students[i].grade = (rand() % 1000) / 100.0;
	}

	return students;
}

int main(void)
{
	const char names_array[NAMES_COUNT][MAX_NAME_LENGTH] = {
		"Popescu", "Stan", "Andrei", "Ion", "Darina"};

	struct student_t *students = generate_random_grades(names_array);
	struct student_t max_grade_student = students[0];

	printf("\nRegistered students:\n");

	for (int i = 0; i < NAMES_COUNT; i++) {
		printf("(%8s,%8.2f)\n", students[i].name, students[i].grade);

		if (max_grade_student.grade < students[i].grade)
			max_grade_student = students[i];
	}

	printf("\nStudent with the highest grade: %s\n", max_grade_student.name);
	free(students);
	return 0;
}

/*
 *
 *	compile: gcc 02-max_struct.c -o max_struct
 *	run: ./max_struct
 *
 *	Output:
 *		Registered students:
 *			( Popescu,    0.41)
 *			(    Stan,    4.67)
 *			(  Andrei,    3.34)
 *			(     Ion,    5.00)
 *			(  Darina,    1.69)
 *
 *		Student with the highest grade: Ion
 *
 */
