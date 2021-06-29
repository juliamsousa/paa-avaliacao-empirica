#include "mergesort.hpp"

void mergeSortIntercala (int* vetor, int esquerda, int meio, int direita)
{
	int i, j, k;
	
	int ta = meio-esquerda+1;
	int tb = direita-meio;
	
	int* a = new int [ta];
	int* b = new int [tb];
	
	for (i=0; i<ta; i++)
		a[i] = vetor[i+esquerda]; 
	for (i=0; i<tb; i++) 
		b[i] = vetor[i+meio+1];
	
	for (i=0, j=0, k=esquerda; k<=direita; k++)
	{
		if (i==ta)
			vetor[k] = b[j++];
		else
			if (j == tb)
				vetor[k] = a[i++];
			else
				if (a[i]<b[j])
					vetor[k] = a[i++];
				else
					vetor[k] = b[j++];
	}
	
	delete[] a;
	delete[] b;
}

void mergeSortOrdena (int* vetor, int esquerda, int direita)
{
	if (direita<=esquerda)
		return;
	
	int meio = (direita+esquerda)/2;
	
	mergeSortOrdena(vetor, esquerda, meio);
	mergeSortOrdena(vetor, meio+1, direita);
	mergeSortIntercala (vetor, esquerda, meio, direita);
	
	return;
}

void mergesort (int* vetor, int tamanho)
{
	int esquerda, direita;
	int n=1;
	
	while (n<tamanho)
	{
		esquerda =0;
		
		while (esquerda+n<tamanho)
		{
			direita = esquerda+2*n;
			
			if (direita>tamanho)
				direita = tamanho;
			
			mergeSortIntercala (vetor, esquerda, esquerda+n-1, direita-1);
			
			esquerda = esquerda+2*n; 
		}
		
		n*=2;
	}
}