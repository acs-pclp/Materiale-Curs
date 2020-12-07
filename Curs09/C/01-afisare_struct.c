/* Programarea Calculatoarelor CA, 2020-2021

  Afisarea dimensiunii unei structuri */

#include <stdio.h>

// sizeof(example_unpacked_t) = 24
typedef struct {
	char a[3];   // 4
	short int b; // 4
	long c;  // 8
	char d[3];   // 8
} example_unpacked_t;

// sizeof(example_packed_t) = 16
typedef struct __attribute__((packed))
{
	char a[3];   // 3
	short int b; // 2
	long c;  // 8
	char d[3];   // 3
} example_packed_t;

int main(void)
{
	printf("unpacked = %lu\n", sizeof(example_unpacked_t));
	printf("packed = %lu\n", sizeof(example_packed_t));
	return 0;
}
