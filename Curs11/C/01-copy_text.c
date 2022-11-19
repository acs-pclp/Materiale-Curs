/* Programarea Calculatoarelor CA, 2022-2023
*
*	Program care realizeaza copierea unui fisier text.
*
*/

#include <stdio.h>

#define FILENAME_LENGTH 101

/// <summary>
/// Copies the contents from <paramref name="source" /> to <paramref name="dest" />.
/// </summary>
/// <param name="source">The source file.</param>
/// <param name="dest">The destination file.</param>
/// <returns>The numbers of bytes copied.</returns>
int file_copy(FILE* const source, FILE* const dest)
{
	int bytes = 0, read = 0;

	// Go character by character
	read = fgetc(source);
	while (read != EOF)
	{
		fputc(read, dest);
		bytes++;

		read = fgetc(source);
	}

	return bytes;
}

int main()
{
	FILE *copy_from, *copy_to;
	char filename[FILENAME_LENGTH];
	int bytes_read = 0;

	printf("File to copy: ");
	scanf("%100s", filename);

	if ((copy_from = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "%s", "No such file! Exiting...\n");
		return -1;
	}

	printf("Copy to: ");
	scanf("%100s", filename);
	
	if ((copy_to = fopen(filename, "w")) == NULL)
	{
		fprintf(stderr, "%s", "Cannot open/create %s file! Exiting...\n",
			filename);
		return -1;
	}

	bytes_read = file_copy(copy_from, copy_to);

	fclose(copy_from);
	fclose(copy_to);

	printf("Copied %d bytes.\n", bytes_read);

	return 0;
}

/*
*
*	compile: gcc 01-copy_text.c -o copy_text
*	run: ./copy_text
*
*	Input:
*		File to copy: 01-copy_text.c
*		Copy to: test.c
*
*	Output:
*		Copied N bytes.
*
*/
