/*  Programarea Calculatoarelor CA, 2020-2021
	Metode de sortare: selectie, metoda bulelor, interclasare */

#include <stdio.h>
#define NMAX 5

/*  Selection sort (sortare prin selectie)
	Algoritmul de sortare prin selectie realizeaza sortarea
	crescatoare a unui vector, gasind in mod repetat elementul
	minim din partea nesortata si plasandu-l de fiecare data
	pozitia pe care ar aparea daca vectorul ar fi sortat. */
void selection_sort(int v[NMAX], int n)
{
	// Cautam elementul minim din subvectorul nesortat
	for (int i = 0; i < n - 1; ++i)  {
		int min_index = i;
		for (int j = i + 1; j < n; ++j) {
			if (v[j] < v[min_index]) {
				min_index = j;
			}
		}

		// Pozitionam elementul minim gasit pe pozitia corecta
		int aux = v[min_index];
		v[min_index] = v[i];
		v[i] = aux;
	}
}

/*  Bubble sort (metoda bulelor)
	Bubble Sort este cel mai simplu algoritm de sortare.
	Functioneaza prin schimbarea in mod repetat a elementelor
	adiacente, daca acestea sunt intr-o ordine gresita. */
void bubble_sort(int v[NMAX], int n)
{
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (v[j] > v[j + 1]) {
				int aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
	}
}

/* Functie ce realizeaza algoritmul de interclasare dintre
   subvectorii lui v cu pozitiile [l ... m] si [m+1 ... r]. */
void merge(int v[NMAX], int l, int m, int r)
{
	// Copiem valorile din cele 2 intervale in 2 vectori
	int size_left = m - l + 1, size_right = r - m;
	int left_interval[NMAX], right_interval[NMAX];

	for (int i = 0; i < size_left; ++i) {
		left_interval[i] = v[l + i];
	}
	for (int i = 0; i < size_right; ++i) {
		right_interval[i] = v[m + 1 + i];
	}

	/*  Punem valorile din vectorii left_interval si right_interval
		in vectorul v, in ordine crescatoare */
	int i = 0, j = 0;
	while (i < size_left && j < size_right) {
		if (left_interval[i] < right_interval[j]) {
			v[l + i + j] = left_interval[i];
			++i;
		} else {
			v[l + i + j] = right_interval[j];
			++j;
		}
	}

	/*  In acest moment ne-a ramas cel putin un element
		in unul dintre vectori. Adaugam restul de elemente in v */
	while (i < size_left) {
		v[l + i + j] = left_interval[i];
		++i;
	}
	while (j < size_right) {
		v[l + i + j] = right_interval[j];
		++j;
	}
}

/*  Merge sort (sortare prin interclasare) este un algoritm de
	sortare de tip Divide et Impera. Functia imparte vectorul in
	2 jumatati, dupa care apeleaza pe fiecare jumatate functia de
	merge_sort (este o functie recursiva). La final realizeaza
	interclasarea dintre cele 2 jumatati sortate.
*/
void merge_sort(int v[NMAX], int left, int right)
{
	/*  continuam cat timp left < rigt,
		adica avem cel putin 2 elemente de sortat */
	if (left < right) {
		// calculam mijlocul intervalului dintre left si right
		int middle = (left + right) / 2;

		// aplicam algoritmul de sortare pentru fiecare jumatate de interval
		merge_sort(v, left, middle);
		merge_sort(v, middle + 1, right);

		// aplicam algoritmul de interclasare intre cele 2 jumatati
		merge(v, left, middle, right);
	}
}

/* Functie care afiseaza continutul unui vector */
void print_array(int v[NMAX], int size)
{
	for (int i = 0; i < size; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main(void)
{
	int v1[NMAX] = {4, 1, 6, 9, 3};
	selection_sort(v1, NMAX);
	printf("Vectorul v1 sortat:\n");
	print_array(v1, NMAX);

	int v2[NMAX] = {57, 1, 88, 156, 45};
	bubble_sort(v2, NMAX);
	printf("Vectorul v2 sortat:\n");
	print_array(v2, NMAX);

	int v3[NMAX] = {198, 0, 593, 10001, 444};
	merge_sort(v3, 0, NMAX - 1);
	printf("Vectorul v3 sortat:\n");
	print_array(v3, NMAX);

	return 0;
}

/*  compile: gcc 01-sortari-vector.c -o sortari-vector
	run   : ./sortari-vector
	output:
		Vectorul v1 sortat:
		1 3 4 6 9
		Vectorul v2 sortat:
		1 45 57 88 156
		Vectorul v3 sortat:
		0 198 444 593 10001
*/
