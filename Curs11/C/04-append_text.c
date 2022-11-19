/* Programarea Calculatoarelor CA, 2022-2023
*
*	Program care realizeaza scrierea la finalul unui fisier
*
*/

#include <stdio.h>
#include <string.h>

#define FILENAME_LENGTH 101
#define TEXT_LENGTH 101

int main()
{
	FILE *append;
	char filename[FILENAME_LENGTH], text[TEXT_LENGTH];
	int write_count = 0;

	printf("File to append: ");
	scanf("%100s", filename);
	
	if ((append = fopen(filename, "a")) == NULL)
	{
		fprintf(stderr, "%s", "Cannot open/create %s file! Exiting...\n",
			filename);
		return -1;
	}

	printf("Type text:\n");
	scanf("%100s", text);

	write_count = fwrite(text, sizeof(char), strlen(text), append);

	if (write_count != strlen(text) || ferror(append) != 0)
	{
		fprintf(stderr, "%s", "Error writing to %s! Exiting...\n",
			filename);
		fclose(append);
		return -1;
	}

	printf("Copied %d bytes.\n", write_count);
	fclose(append);

	return 0;
}

/*
*
*	compile: gcc 04-append_text.c -o append_text
*	run: ./append_text
*
*	Input:
*		File to append: 04-append_text.c
*		Type text:
*			ana_are_mere
* 
*	Output:
*		Copied N bytes.
*
*/
