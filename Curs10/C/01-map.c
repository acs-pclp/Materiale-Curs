/* Programarea Calculatoarelor CA, 2020-2021

  Functionala similara map */

#include <stdio.h>
#include <stdlib.h>

int add1(int x)
{
	return 2 * x + 3;
}

int add2(int x)
{
	return 3 * x + 7;
}

int *map(int n, int *v, int (*f_ptr)(int))
{
	int *result = (int *)malloc(n * sizeof(int));
	if (!result) {
		return NULL;
	}
	for (int i = 0; i < n; i++) {
		result[i] = f_ptr(v[i]);
	}

	return result;
}

void print_vector(int n, int *v)
{
	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main(void)
{
	int v[] = {2, 3, 4};
	size_t n = sizeof(v) / sizeof(v[0]);
	int *res = map(n, v, add1);
	if (!res) {
		fprintf(stderr, "map failed()\n");
		return -1;
	}
	print_vector(n, res);
	free(res);

	res = map(n, v, add2);
	if (!res) {
		fprintf(stderr, "map failed()\n");
		return -1;
	}
	print_vector(n, res);
	free(res);

	return 0;
}

/*
    output:
    3
    7 9 11
    3
    13 16 19
*/
