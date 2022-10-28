/* Programarea Calculatoarelor CA, 2022-2023

	Program care realizeaza copierea unui fisier text.

*/

#include <stdio.h>

int main()
{
	FILE* copyfrom;
	FILE* copyto;

	char filename[100];
	int read = 0;

	printf("File to copy: ");
	scanf("%s", filename);
	copyfrom = fopen(filename, "r");

	if (copyfrom == NULL)
	{
		fprintf(stderr, "%s", "No such file! Exiting...");
		return -1;
	}

	printf("Copy to: ");
	scanf("%s", filename);
	copyto = fopen(filename, "w");

	// Go character by character
	read = fgetc(copyfrom);
	while (read != EOF)
	{
		fputc(read, copyto);

		read = fgetc(copyfrom);
	}

	return 0;
}

/*

	compile: gcc 01-copy_text.c -o copy_text
	run: ./copy_text

	Output:

		File to copy: {01-copy_text.c}
		Copy to: {test.c}

*/