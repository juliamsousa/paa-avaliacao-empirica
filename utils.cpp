#include <cstdlib>
#include <iostream>

#include "utils.hpp"
using namespace std;

void gerador (int* vector, int n, int situacao) {
  
  switch (situacao) {
    case 1: {
      // preenche o vetor de forma crescente
      for (int i=1; i<=n; i++)
        vector[i] = i;
    } break;

    case 2: {
      // preenche o vetor de forma decrescente
      for (int i=n; i>=1; i++)
        vector[i] = i;
    } break;

    case 3: {
      // preenche o vetor com numeros aleatorios
      for (int i=0; i<n; i++)
        vector[i] = rand()%n;
    } break;
  }
  return;
}

// A utility function to print an array
void printVector(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout<<endl;
}