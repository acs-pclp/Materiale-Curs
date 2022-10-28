/* Programarea Calculatoarelor CA, 2022-2023

	Program care realizeaza copierea unui fisier text.

*/

#include <stdio.h>

int main()
{
	FILE *copyFrom, *copyTo;
	char filename[101];
	int read = 0;

	printf("File to copy: ");
	scanf("%100s", filename);

	if ((copyFrom = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "%s", "No such file! Exiting...");
		return -1;
	}

	printf("Copy to: ");
	scanf("%100s", filename);
	
	if ((copyTo = fopen(filename, "w")) == NULL)
	{
		fprintf(stderr, "%s", "Cannot open/create %s file! Exiting...",
			filename);
		return -1;
	}

	// Go character by character
	read = fgetc(copyFrom);
	while (read != EOF)
	{
		fputc(read, copyTo);

		read = fgetc(copyFrom);
	}

	fclose(copyFrom);
	fclose(copyTo);

	return 0;
}

/*

	compile: gcc 01-copy_text.c -o copy_text
	run: ./copy_text

	Output:

		File to copy: {01-copy_text.c}
		Copy to: {test.c}

*/