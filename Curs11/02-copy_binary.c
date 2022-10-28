/* Programarea Calculatoarelor CA, 2022-2023

	Program care realizeaza copierea unui fisier binar.

*/

#include <stdio.h>

#define COPY_BUFFER_SIZE 1024

int main()
{
	FILE* copyfrom;
	FILE* copyto;

	char filename[100];

	int readCount = 0, writeCount = 0;

	// Size of file can be very big -> use a buffer
	unsigned char buffer[COPY_BUFFER_SIZE];

	printf("File to copy: ");
	scanf("%s", filename);
	copyfrom = fopen(filename, "rb");

	if (copyfrom == NULL)
	{
		fprintf(stderr, "%s", "No such file! Exiting...");
		return -1;
	}

	printf("Copy to: ");
	scanf("%s", filename);
	copyto = fopen(filename, "wb");

	do
	{
		readCount = fread(buffer, 1, COPY_BUFFER_SIZE, copyfrom);
		writeCount = fwrite(buffer, 1, readCount, copyto);

		//	Error check for:
		//		1. If the number of bytes read is different from the number of bytes written.
		//		2. If the program couldn't read the whole buffer but EOF was not reached.
		if ((readCount != writeCount) || 
			((readCount < COPY_BUFFER_SIZE) && (feof(copyfrom) == 0)))
		{
			fprintf(stderr, "Error copying. Exiting...");

			fclose(copyfrom);
			fclose(copyto);

			return -1;
		}


	} while (feof(copyfrom) == 0);
	
	fclose(copyfrom);
	fclose(copyto);

	return 0;
}

/*

	compile: gcc 02-copy_binary.c -o copy_binary
	run: ./copy_binary

	Output:

		File to copy: {a.exe}
		Copy to: {b.exe}

*/