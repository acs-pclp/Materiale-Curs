/* Programarea Calculatoarelor CA, 2022-2023
 *
 *	Program care realizeaza copierea unui fisier text.
 *
 */

#include <stdio.h>

#define FILENAME_LENGTH 100

int file_copy(FILE *const source, FILE *const dest)
{
	int bytes = 0, read = 0;

	// Itereate the file character by character
	read = fgetc(source);
	while (read != EOF) {
		fputc(read, dest);
		bytes++;

		read = fgetc(source);
	}

	return bytes;
}

int main(void)
{
	FILE *copy_from, *copy_to;
	char filename[FILENAME_LENGTH + 1];
	int bytes_read = 0;

	printf("File to copy: ");
	scanf("%s", filename);

	copy_from = fopen(filename, "r");
	if (!copy_from) {
		fprintf(stderr, "%s", "No such file! Exiting...\n");
		return -1;
	}

	printf("Copy to: ");
	scanf("%s", filename);

	copy_to = fopen(filename, "w");
	if (!copy_to) {
		fprintf(stderr, "Cannot open/create %s file! Exiting...\n",
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
