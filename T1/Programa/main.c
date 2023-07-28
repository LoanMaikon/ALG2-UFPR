#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "ordenacao.h"

int aleat (int min, int max)
{
    return (min + (rand() % (max - min + 1)));
}

int *copia_vetor(int *v, int tam)
{
	int *copia = malloc(tam * sizeof(int));
	int i;

	i = 0;
	while (i < tam)
	{
		copia[i] = v[i];
		i++;
	}

	return copia;
}

int *cria_vetor_ordenado(int tam)
{
	int i;
	int *v = malloc(tam * sizeof(int));

	i = 0;
	while (i < tam)
	{
		v[i] = i;
		i++;
	}

	return v;
}

int *cria_vetor_contrario(int tam)
{
	int i, j;
	int *v = malloc(tam * sizeof(int));

	j = 0;
	i = tam - 1;
	while (i >= 0)
	{
		v[j] = i;
		j++;
		i--;
	}

	return v;
}

int *cria_vetor_aleatorio(int tam)
{
	int i;
	int *v = malloc(tam * sizeof(int));

	i = 0;
	while (i < tam)
	{
		v[i] = aleat(0,tam-1);
		i++;
	}

	return v;
}

void imprime_vetor (int *v, int tam)
{
	int i = 0;

	while (i < tam)
	{
		printf("%d", v[i]);
		if (i != tam - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void buscaSeq (int *vOrd, int *vContra)
{
	int nComps;
	clock_t start, end;
	int posicao;
	double total;

	printf("\nBUSCA SEQUENCIAL\n");

	nComps = 0;
	printf("\nTestando Busca Sequencial pelo número 0 em um vetor ordenado de tamanho 100000\n");
	start = clock();
	posicao = buscaSequencial(vOrd,100000,0,&nComps);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Posição = %d\n", posicao+1);
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	nComps = 0;
	printf("\nTestando Busca Sequencial pelo número 0 em um vetor ordenado ao contrário de tamanho 100000\n");
	start = clock();
	posicao = buscaSequencial(vContra,100000,0,&nComps);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Posição = %d\n", posicao+1);
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);
}

void buscaBin (int *vOrd, int *vContra)
{
	int nComps;
	clock_t start, end;
	int posicao;
	double total;

	printf("\n\n\nBUSCA BINARIA\n");

	nComps = 0;
	printf("\nTestando Busca Binária pelo número 0 em um vetor ordenado de tamanho 100000\n");
	start = clock();
	posicao = buscaBinaria(vOrd,100000,0,&nComps);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Posição = %d\n", posicao+1);
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	nComps = 0;
	printf("\nTestando Busca Binária pelo número 99999 em um vetor ordenado de tamanho 100000\n");
	start = clock();
	posicao = buscaBinaria(vOrd,100000,99999,&nComps);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Posição = %d\n", posicao+1);
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);
	
	nComps = 0;
	printf("\nTestando Busca Binária pelo número 49999 em um vetor ordenado de tamanho 100000\n");
	start = clock();
	posicao = buscaBinaria(vOrd,100000,49999,&nComps);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Posição = %d\n", posicao+1);
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);
}

void Insertion (int *vOrd, int *vContra, int *vAleat, int *vOrd50, int *vContra50)
{
	int *vOrd_copia = copia_vetor(vOrd,100000); 
	int *vContra_copia = copia_vetor(vContra,100000); 
	int *vOrd50_copia = copia_vetor(vOrd50,50000);
	int *vContra50_copia = copia_vetor(vContra50,50000);
	int *vAleat_copia = copia_vetor(vAleat,50000); 
	int nComps;
	clock_t start, end;
	double total;

	printf("\n\n\nINSERTION SORT");

	printf("\n\nTestando Insertion Sort em um vetor ordenado de tamanho 100000\n");
	start = clock();
	nComps = insertionSort(vOrd_copia,100000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Insertion Sort em um vetor ordenado ao contrário de tamanho 100000\n");
	start = clock();
	nComps = insertionSort(vContra_copia,100000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Insertion Sort em um vetor ordenado de tamanho 50000\n");
	start = clock();
	nComps = insertionSort(vOrd50_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Insertion Sort em um vetor ordenado ao contrário de tamanho 50000\n");
	start = clock();
	nComps = insertionSort(vContra50_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Insertion Sort em um vetor aleatório de tamanho 50000\n");
	start = clock();
	nComps = insertionSort(vAleat_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	free(vOrd_copia);
	free(vContra_copia);
	free(vOrd50_copia);
	free(vContra50_copia);
	free(vAleat_copia);
}

void Selection (int *vOrd, int *vContra, int *vAleat, int *vOrd50, int *vContra50)
{
	int *vOrd_copia = copia_vetor(vOrd,100000); 
	int *vContra_copia = copia_vetor(vContra,100000);
	int *vOrd50_copia = copia_vetor(vOrd50,50000);
	int *vContra50_copia = copia_vetor(vContra50,50000);
	int *vAleat_copia = copia_vetor(vAleat,50000);
	int nComps;
	clock_t start, end;
	double total;

	printf("\n\n\nSELECTION SORT");

	printf("\n\nTestando Selection Sort em um vetor ordenado de tamanho 100000\n");
	start = clock();
	nComps = selectionSort(vOrd_copia,100000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Selection Sort em um vetor ordenado ao contrário de tamanho 100000\n");
	start = clock();
	nComps = selectionSort(vContra_copia,100000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Selection Sort em um vetor ordenado de tamanho 50000\n");
	start = clock();
	nComps = selectionSort(vOrd50_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Selection Sort em um vetor ordenado ao contrário de tamanho 50000\n");
	start = clock();
	nComps = selectionSort(vContra50_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Selection Sort em um vetor aleatório de tamanho 50000\n");
	start = clock();
	nComps = selectionSort(vAleat_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	free(vOrd_copia);
	free(vContra_copia);
	free(vOrd50_copia);
	free(vContra50_copia);
	free(vAleat_copia);
}

void Merge (int *vOrd, int *vContra, int *vAleat, int *vOrd50, int *vContra50)
{
	int *vOrd_copia = copia_vetor(vOrd,100000); 
	int *vContra_copia = copia_vetor(vContra,100000);
	int *vOrd50_copia = copia_vetor(vOrd50,50000);
	int *vContra50_copia = copia_vetor(vContra50,50000);
	int *vAleat_copia = copia_vetor(vAleat,50000); 
	int nComps;
	clock_t start, end;
	double total;

	printf("\n\n\nMERGE SORT");

	printf("\n\nTestando Merge Sort em um vetor ordenado de tamanho 100000\n");
	start = clock();
	nComps = mergeSort(vOrd_copia,100000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Merge Sort em um vetor ordenado ao contrário de tamanho 100000\n");
	start = clock();
	nComps = mergeSort(vContra_copia,100000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Merge Sort em um vetor ordenado de tamanho 50000\n");
	start = clock();
	nComps = mergeSort(vOrd50_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Merge Sort em um vetor ordenado ao contrário de tamanho 50000\n");
	start = clock();
	nComps = mergeSort(vContra50_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Merge Sort em um vetor aleatório de tamanho 50000\n");
	start = clock();
	nComps = mergeSort(vAleat_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	free(vOrd_copia);
	free(vContra_copia);
	free(vOrd50_copia);
	free(vContra50_copia);
	free(vAleat_copia);
}

void Quick (int *vOrd, int *vContra, int *vAleat, int *vOrd50, int *vContra50)
{
	int *vOrd_copia = copia_vetor(vOrd,100000); 
	int *vContra_copia = copia_vetor(vContra,100000);
	int *vOrd50_copia = copia_vetor(vOrd50,50000);
	int *vContra50_copia = copia_vetor(vContra50,50000);
	int *vAleat_copia = copia_vetor(vAleat,50000); 
	int nComps;
	clock_t start, end;
	double total;

	printf("\n\n\nQUICK SORT");

	printf("\n\nTestando Quick Sort em um vetor ordenado de tamanho 100000\n");
	start = clock();
	nComps = quickSort(vOrd_copia,100000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Quick Sort em um vetor ordenado ao contrário de tamanho 100000\n");
	start = clock();
	nComps = quickSort(vContra_copia,100000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Quick Sort em um vetor ordenado de tamanho 50000\n");
	start = clock();
	nComps = quickSort(vOrd50_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Quick Sort em um vetor ordenado ao contrário de tamanho 50000\n");
	start = clock();
	nComps = quickSort(vContra50_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Quick Sort em um vetor aleatório de tamanho 50000\n");
	start = clock();
	nComps = quickSort(vAleat_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	free(vOrd_copia);
	free(vContra_copia);
	free(vOrd50_copia);
	free(vContra50_copia);
	free(vAleat_copia);
}

void Heap (int *vOrd, int *vContra, int *vAleat, int *vOrd50, int *vContra50)
{
	int *vOrd_copia = copia_vetor(vOrd,100000); 
	int *vContra_copia = copia_vetor(vContra,100000);
	int *vOrd50_copia = copia_vetor(vOrd50,50000);
	int *vContra50_copia = copia_vetor(vContra50,50000);
	int *vAleat_copia = copia_vetor(vAleat,50000); 
	int nComps;
	clock_t start, end;
	double total;

	printf("\n\n\nHEAP SORT");

	printf("\n\nTestando Heap Sort em um vetor ordenado de tamanho 100000\n");
	start = clock();
	nComps = heapSort(vOrd_copia,100000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Heap Sort em um vetor ordenado ao contrário de tamanho 100000\n");
	start = clock();
	nComps = heapSort(vContra_copia,100000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Heap Sort em um vetor ordenado de tamanho 50000\n");
	start = clock();
	nComps = heapSort(vOrd50_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Heap Sort em um vetor ordenado ao contrário de tamanho 50000\n");
	start = clock();
	nComps = heapSort(vContra50_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	printf("\nTestando Heap Sort em um vetor aleatório de tamanho 50000\n");
	start = clock();
	nComps = heapSort(vAleat_copia,50000);
	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Número de comparações: %d\n", nComps);
	printf("Tempo percorrido: %f\n", total);

	free(vOrd_copia);
	free(vContra_copia);
	free(vOrd50_copia);
	free(vContra50_copia);
	free(vAleat_copia);
}

int main()
{
	char nome[MAX_CHAR_NOME];

	int *vOrd = cria_vetor_ordenado(100000);
	int *vContra = cria_vetor_contrario(100000);
	int *vOrd50 = cria_vetor_ordenado(50000);
	int *vContra50 = cria_vetor_contrario(50000);
	int *vAleat = cria_vetor_aleatorio(50000);

	srand(0);

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

	buscaSeq(vOrd,vContra);
	buscaBin(vOrd,vContra);
	Insertion(vOrd,vContra,vAleat,vOrd50,vContra50);
	Selection(vOrd,vContra,vAleat,vOrd50,vContra50);
	Merge(vOrd,vContra,vAleat,vOrd50,vContra50);
	Quick(vOrd,vContra,vAleat,vOrd50,vContra50);
	Heap(vOrd,vContra,vAleat,vOrd50,vContra50);

	free(vOrd);
	free(vContra);
	free(vOrd50);
	free(vContra50);
	free(vAleat);

	return 0;
}