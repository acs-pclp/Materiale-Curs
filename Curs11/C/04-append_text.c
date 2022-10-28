/* Programarea Calculatoarelor CA, 2022-2023

	Program care realizeaza scrierea la finalul unui fisier

*/

#include <stdio.h>
#include <string.h>

int main()
{
	FILE *append;
	char filename[101], text[101];
	int read = 0;

	printf("File to append: ");
	scanf("%100s", filename);
	
	if ((append = fopen(filename, "a")) == NULL)
	{
		fprintf(stderr, "%s", "Cannot open/create %s file! Exiting...",
			filename);
		return -1;
	}

	printf("Type text:\n");
	scanf("%100s", text);

	fwrite(text, 1, strlen(text), append);

	fclose(append);

	return 0;
}

/*

	compile: gcc 04-append_text.c -o append_text
	run: ./append_text

	Output:

		File to append: {04-append_text.c}
		Type text:
			ana_are_mere

*/