/* Programarea Calculatoarelor CA, 2020-2021

  Functionala similara filter */

#include <stdio.h>
#include <stdlib.h>

int is_odd(int x)
{
	return (x % 2 == 1);
}

int is_power_of_two(int x)
{
	return (x != 0 && (x & (x - 1)) == 0);
}

int *filter(const int n, int *m, int * const v, int (*f_ptr)(int))
{
	*m = 0;
	int *result = (int *)malloc(n * sizeof(int));
	if (!result) {
		return NULL;
	}
	for (int i = 0; i < n; i++) {
		if (f_ptr(v[i])) {
			result[(*m)++] = v[i];
		}
	}
	
	int *tmp = (int *) realloc(result, *m * sizeof(int));
	if (!tmp) {
		free(result);
		return NULL;
	}

	result = tmp;
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
	int v[] = {1, 2, 3, 4, 5};
	int n = sizeof(v) / sizeof(v[0]);
	int m, *res;

	res = filter(n, &m, v, is_odd);
	print_vector(m, res);
	free(res);

	res = filter(n, &m, v, is_power_of_two);
	print_vector(m, res);
	free(res);
	return 0;
}

/*
    output:
    3
    1 3 5
    3
    1 2 4
*/
