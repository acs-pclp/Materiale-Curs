/* Programarea Calculatoarelor CA, 2020-2021

   Returnarea unui pointer la prima aparitie a unui element intr-un tablou  */

#include <stdio.h>
#define NMAX 100

void read_array(int n, int *v)
{
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}
}

int *find_array(int n, int *v, int x)
{
	for (int i = 0; i < n; ++i) {
		if (v[i] == x) {
			return &v[i];
		}
	}
	return NULL;
}

/* doar pentru vector sortat */
int *find_first(int n, int *v, int x)
{
	int left = 0, right = n - 1, index = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (v[mid] == x) {
			index = mid;
			right = mid - 1;
		} else if (x < v[mid]) {
			right = mid - 1;
		} else if (x > v[mid]) {
			left = mid + 1;
		}
	}

	if (index == -1) {
		return NULL;
	}
	return &v[index];
}

int main(void)
{
	int n, x, v[NMAX];
	scanf("%d", &n);
	read_array(n, v);
	scanf("%d", &x);
	int *poz = find_array(n, v, x);
    // int* poz = find_first(n, v, x);
	if (!poz) {
		printf("Elementul nu a fost gasit\n");
	} else {
		printf("Prima aparitie se afla pe pozitia %ld\n", poz - v);
	}

	return 0;
}

/* compile: gcc 05-aparitie_element.c -o aparitie_element
   run    : ./aparitie_element

   Exemplu:

   input  :
   6
   1 1 2 2 2 3
   2

   output :
   Prima aparitie se afla pe pozitia 2

   input  :
   4
   1 2 3 4
   5

   output :
   Elementul nu a fost gasit

   input  :
   4
   2 2 2 3
   3

   output :
   Prima aparitie se afla pe pozitia 3
	*/
