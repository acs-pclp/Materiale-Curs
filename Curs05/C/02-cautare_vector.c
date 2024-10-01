/* Programarea Calculatoarelor CA, 2020-2021

   Programul verifica, prin cautare liniara, daca un numar se afla intr-un vector */

#include <stdio.h>
#define NMAX 10

void read_array(int n, int v[NMAX])
{
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
}

int find_array(int n, int v[NMAX], int x)
{
	for (int i = 0; i < n; ++i) {
		if (v[i] == x) {
			return i;
		}
	}
	return -1;
}

int find_array_binarysearch(int n, int v[NMAX], int x)
{
	int left  = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		/* am gasit elementul cautat */
		if (v[mid] == x) {
			return mid;
		/* elementul curent e mai mare decat cel cautat, trebuie sa ma uit
			in intervalul [v[left], v[mid - 1]) */
		} else if (x < v[mid]) {
			right = mid - 1;
		/* elementul curent e mai mare decat cel cautat, trebuie sa ma uit
			in intervalul [v[mid + 1], v[right]) */
		} else {
			left = mid + 1;
		}
	}

	return -1;
}

int main(void)
{
	int n, x, v[NMAX]; /* n - numar elemente vector, x - elementul de cautat */
	scanf("%d", &n);
	read_array(n, v);
	scanf("%d", &x);
	printf("Elementul cautat se afla pe pozitia %d\n", find_array(n, v, x));
	printf("Elementul cautat, folosind cautare binara, se afla "
						"pe pozitia %d\n", find_array_binarysearch(n, v, x));
	return 0;
}

/* compile: gcc 02-cautare_vector.c -o cautare_vector
   Exemplu: cautare_vector
   input : 4
		   1 2 3 4
		   5
   output : Elementul cautat se afla pe pozitia -1
			Elementul cautat, folosind cautare binara, se afla pe pozitia -1
   input  : 5
			2 3 5 7 9
			2
   output : Elementul cautat se afla pe pozitia 0
			Elementul cautat, folosind cautare binara, se afla pe pozitia 2
   input  : 3
			3 6 12
			6
   output : Elementul cautat se afla pe pozitia 1
			Elementul cautat, folosind cautare binara, se afla pe pozitia 1 */
