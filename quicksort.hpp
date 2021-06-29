#ifndef ORDENADORES_HPP
#define ORDENADORES_HPP

#include "estruturas.hpp"

void quicksort (int* vector, int n);
void quicksort_ordenada (int* vector, int esq, int dir);
void quicksort_particao (int* vector, int esq, int dir, int *i, int* j);

#endif