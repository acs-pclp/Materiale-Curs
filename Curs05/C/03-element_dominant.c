/* Programarea Calculatoarelor CA, 2020-2021

    Programul verifica, daca exista un element dominant intr-un vector
    Un element se numeste dominant daca are cel putin n / 2 aparitii in vector,
    unde n este dimensiunea vectorului. */

#include <stdio.h>
#define NMAX 10
#define kINF 1 << 30

void read_array(int n, int v[NMAX])
{
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
}

int majority_element(int n, int v[NMAX])
{
	int count = 1;
	int element = v[0];
	for (int i = 1; i < n; i++) {
		if (v[i] == element) {
			count++;
		} else {
			count--;
		}
		if (count == 0) {
			element = v[i];
			count = 1;
		}
	}

    // Verificam ca elementul e majoritar
	count = 0;
	for (int i = 0; i < n; i++) {
		if (element == v[i]) {
			count++;
		}
	}

	printf("%d\n", count);
	if (count < n / 2) {
		return kINF;
	}

	return element;
}

int main(void)
{
	int n, v[NMAX], maj; /* n - numar elemente vector */
	scanf("%d", &n);
	read_array(n, v);
	maj = majority_element(n, v);
	if (maj == kINF) {
		printf("Vectorul nu are un element domninant\n");
	} else {
		printf("Elementul dominant este %d\n", maj);
	}
	return 0;
}

/* compile: gcc 03-element_dominant.c -o element_dominant
   Exemplu: element_dominant
   input :  9
			2 1 7 2 2 9 2 2 2
   output : Elementul dominant este 2
   input  : 7
			2 1 5 2 2 6 8
   output : Vectorul nu are un element domninant\
   input  : 8
			3 1 5 3 3 6 8 3
   output : Elementul dominant este 3 */
