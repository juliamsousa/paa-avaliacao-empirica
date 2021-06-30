#include <iostream>
#include <time.h>
#include <string> 
#include <cstdlib>

#include "utils.hpp"
#include "mergesort.hpp"
#include "radix.hpp"
#include "insertion.hpp"

using namespace std;

// Driver Code
int main (int argc, char *argv[]) {
  int metodo, quantidade, situacao;
  metodo = atoi(argv[1]);
  quantidade = atoi(argv[2]);
  situacao = atoi(argv[3]);
  
  Experimentos* experimentos= new Experimentos;

  int *vector = new int[quantidade];

  gerador(vector, quantidade, situacao);

  switch (metodo) {
    case 1: {
      cout<<"Testando o MergeSort..."<<endl;
      clock_t c2, c1; /* variáveis que contam ciclos do processador */

      c1=clock(); /* coloque aqui o código que você quer medir o tempo de execução */
      mergeSort(vector, quantidade);
      c2=clock();

	    experimentos->tempo=(c2-c1)*1000/CLOCKS_PER_SEC;/* agora tempo guarda o tempo de execução em milisegundos */
      
      printVector(vector, quantidade);
    } break;

    case 2: {
      cout<<"Testando o InsertionSort..."<<endl;

      clock_t c2, c1; /* variáveis que contam ciclos do processador */

      c1=clock(); /* coloque aqui o código que você quer medir o tempo de execução */
      insertionsort(vector, quantidade);
      c2=clock();

	    experimentos->tempo=(c2-c1)*1000/CLOCKS_PER_SEC;/* agora tempo guarda o tempo de execução em milisegundos */

      printVector(vector, quantidade);
    } break;

    case 3: {
      cout<<"Testando o RadixSort..."<<endl;

      clock_t c2, c1; /* variáveis que contam ciclos do processador */

      c1=clock(); /* coloque aqui o código que você quer medir o tempo de execução */
      radixsort(vector, quantidade);
      c2=clock();

	    experimentos->tempo=(c2-c1)*1000/CLOCKS_PER_SEC;/* agora tempo guarda o tempo de execução em milisegundos */

      printVector(vector, quantidade);
    } break;

    default: {
      printVector(vector, quantidade);
    } break;
  }

  cout<<"-----------------------------------------------";
  cout<<"\nTempo de execucao...........: "<<experimentos->tempo<<" milissegundos";
  cout<<"\n-----------------------------------------------"<<endl;
   
  delete [] vector;

  return 0;
}