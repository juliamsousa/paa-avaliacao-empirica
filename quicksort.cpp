#include "utils.hpp"
#include "quicksort.hpp"

void quicksort (int* vector, int n) {
		quicksort_ordenada (vector, 0, n-1);
}

void quicksort_ordenada (int* vector, int esq, int dir){
	int i,j;

	quicksort_particao (vector, esq, dir, &i, &j);

	if (esq<j)
		quicksort_ordenada (vector, esq, j);

	if (i<dir)
		quicksort_ordenada (vector, i, dir);
}

void quicksort_particao(int* vector, int esq, int dir, int *i, int* j) {
	int pivo, aux;
	*i = esq;
	*j = dir;

	pivo = vector[(*i+*j)/2]; //obtem o pivo

	do {
		while (!(pivo <= vector[*i])) {
			(*i)++;
		}

		while (pivo < vector[*j]) {
			(*j)--;
		}

		if (*i <= *j) {
			aux = vector[*i];

			vector[*i] = vector[*j];
			vector[*j] = aux;

			(*i)++;
			(*j)--;
		}
	} while (*i<=*j);
}