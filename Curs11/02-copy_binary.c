/* Programarea Calculatoarelor CA, 2022-2023

	Program care realizeaza copierea unui fisier binar.

*/

#include <stdio.h>

#define BUFFER_SIZE 1024

int main()
{
	FILE *copyFrom, *copyTo;
	char filename[101];
	int readCount = 0, writeCount = 0;

	// Size of file can be very big -> use a buffer
	unsigned char buffer[BUFFER_SIZE];

	printf("File to copy: ");
	scanf("%100s", filename);
	
	if ((copyFrom = fopen(filename, "rb")) == NULL)
	{
		fprintf(stderr, "%s", "No such file! Exiting...");
		return -1;
	}

	printf("Copy to: ");
	scanf("%100s", filename);
	
	if ((copyTo = fopen(filename, "wb")) == NULL)
	{
		fprintf(stderr, "%s", "Cannot open/create %s file! Exiting...",
			filename);
		return -1;
	}

	do
	{
		readCount = fread(buffer, 1, BUFFER_SIZE, copyFrom);
		writeCount = fwrite(buffer, 1, readCount, copyTo);

		//	Error check for:
		//		1. If the number of bytes read is different from the number of bytes written.
		//		2. If the program couldn't read the whole buffer but EOF was not reached.
		if ((readCount != writeCount) || 
			((readCount < BUFFER_SIZE) && (feof(copyFrom) == 0)))
		{
			fprintf(stderr, "Error copying. Exiting...");

			fclose(copyFrom);
			fclose(copyTo);

			return -1;
		}

	} while (feof(copyFrom) == 0);
	
	fclose(copyFrom);
	fclose(copyTo);

	return 0;
}

/*

	compile: gcc 02-copy_binary.c -o copy_binary
	run: ./copy_binary

	Output:

		File to copy: {a.exe}
		Copy to: {b.exe}

*/