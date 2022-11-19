/* Programarea Calculatoarelor CA, 2022-2023
*
*	Program care realizeaza copierea unui fisier binar.
*
*/

#include <stdio.h>

#define BUFFER_SIZE 1024
#define FILENAME_LENGTH 101

/// <summary>
/// Copies the binary from <paramref name="source" /> to <paramref name="dest" />.
/// </summary>
/// <param name="source">The source file.</param>
/// <param name="dest">The destination file.</param>
/// <returns>The numbers of bytes copied.</returns>
int binary_copy(FILE* const source, FILE* const dest)
{
	int bytes = 0, read_count = 0, write_count = 0;

	// Size of file can be very big -> use a buffer
	unsigned char buffer[BUFFER_SIZE];

	do
	{
		read_count = 0;
		write_count = 0;

		read_count = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, source);
		write_count = fwrite(buffer, sizeof(unsigned char), read_count, dest);

		//	Error check for:
		//		1. If the number of bytes read is different from the number of bytes written.
		//		2. If the program couldn't read the whole buffer but EOF was not reached.
		if ((read_count != write_count) ||
			((read_count < BUFFER_SIZE) && (feof(source) == 0)))
		{
			fprintf(stderr, "Error copying. Exiting...\n");

			fclose(source);
			fclose(dest);

			return -1;
		}

	} while (feof(source) == 0);

	return bytes;
}

int main()
{
	FILE *copy_from, *copy_to;
	char filename[FILENAME_LENGTH];
	int bytes = 0;

	printf("File to copy: ");
	scanf("%100s", filename);
	
	if ((copy_from = fopen(filename, "rb")) == NULL)
	{
		fprintf(stderr, "%s", "No such file! Exiting...\n");
		return -1;
	}

	printf("Copy to: ");
	scanf("%100s", filename);
	
	if ((copy_to = fopen(filename, "wb")) == NULL)
	{
		fprintf(stderr, "%s", "Cannot open/create %s file! Exiting...\n",
			filename);
		return -1;
	}

	bytes = binary_copy(copy_from, copy_to);
	printf("Copied %d bytes.\n", bytes);
	
	fclose(copy_from);
	fclose(copy_to);

	return 0;
}

/*
*
*	compile: gcc 02-copy_binary.c -o copy_binary
*	run: ./copy_binary
*
*	Input:
*		File to copy: a.bin
*		Copy to: b.bin
* 
*	Output:
*		Copied N bytes.
*
*/
