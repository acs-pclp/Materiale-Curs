/* Programarea Calculatoarelor CA, 2022-2023
 *
 *	Program care realizeaza scrierea la finalul unui fisier
 *
 */

#include <stdio.h>
#include <string.h>

#define FILENAME_LENGTH 100
#define TEXT_LENGTH 100

int main(void)
{
	FILE *append_file;
	char filename[FILENAME_LENGTH + 1], buffer[TEXT_LENGTH + 1];
	size_t write_count = 0;

	printf("File to append: ");
	scanf("%s", filename);

	append_file = fopen(filename, "a");
	if (!append_file) {
		fprintf(stderr, "Cannot open/create %s file! Exiting...\n",
				filename);
		return -1;
	}

	printf("Type text:\n");
	scanf("%s", buffer);

	write_count = fwrite(buffer, sizeof(char), strlen(buffer), append_file);
	if (write_count != strlen(buffer) || ferror(append_file) != 0) {
		fprintf(stderr, "Error writing to %s! Exiting...\n",
				filename);
		fclose(append_file);
		return -1;
	}

	printf("Copied %zu bytes.\n", write_count);
	fclose(append_file);

	return 0;
}

/*
 *
 *	compile: gcc 04-append_text.c -o append_text
 *	run: ./append_text
 *
 *	Input:
 *		File to append: log.txt
 *		Type text:
 *			ana_are_mere
 *
 *	Output:
 *		Copied 12 bytes.
 *
 */
