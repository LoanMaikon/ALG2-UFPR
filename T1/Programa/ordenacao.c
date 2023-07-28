#include "ordenacao.h"

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void getNome(char nome[]){
	//substitua por seu nome
	strncpy(nome, "Luan Marko Kujavski", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR(){
	return 20221236;
}

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){
	if (tam == 0)
		return -1;

	(*numComparacoes)++;
	if (valor == vetor[tam-1])
		return tam-1;

	return buscaSequencial(vetor,tam-1,valor,numComparacoes);
}

int buscaBinaria_aux(int vetor[], int valor, int *numComparacoes, int a, int b){ /*erro erro erro erro erro erro erro*/
	if (a > b)
		return -1;
	
	int m = floor((a + b) / 2);

	(*numComparacoes)++;
	if (valor == vetor[m])
		return m;
	
	(*numComparacoes)++;
	if (valor < vetor[m])
		return buscaBinaria_aux(vetor,valor,numComparacoes,a,m-1);
	return buscaBinaria_aux(vetor,valor,numComparacoes,m+1,b);
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){
	int inicio = 0;
	int fim = tam - 1;

	return buscaBinaria_aux(vetor,valor,numComparacoes,inicio,fim);
}

void troca (int vetor[], int a, int b){
	int aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux;
}

int insertionSort_aux(int vetor[], int tam, int *nComps)
{
	int a, b;

	if (tam <= 1)
		return 1;
	
	insertionSort_aux(vetor,tam-1,nComps);

	a = vetor[tam-1];
	b = tam - 2;

	while ((b >= 0) && (vetor[b] > a))
	{
		(*nComps)++;
		troca(vetor,b,b+1);
		b--;
	}
	(*nComps)++;
	vetor[b+1] = a;

	return 1;
}

int insertionSort(int vetor[], int tam)
{
	int nComps = 0;

	insertionSort_aux(vetor,tam,&nComps);

	return nComps;
}


int minimo (int vetor[], int a, int b, int *nComps){
	int i, j;

	j = a;
	i = a+1;
	while (i <= b)
	{
		if (vetor[i] < vetor[j])
			j = i;
		(*nComps)++;
		i++;
	}

	return j;
}

int selectionSort_aux(int vetor[], int a, int b, int *nComps){
	int min;

	if (a >= b)
		return 0;

	min = minimo(vetor,a,b,nComps);
	troca(vetor,a,min);

	selectionSort_aux(vetor,a+1,b,nComps);

	return 1;
}

int selectionSort(int vetor[], int tam){
	int inicio = 0;
	int fim = tam - 1;
	int nComps = 0;

	selectionSort_aux(vetor,inicio,fim,&nComps);

	return nComps;
}

int intercala (int vetor[], int a, int m, int b, int *nComps){
	int i, j, k;
	int *u = malloc((b - a + 1) * sizeof(int));
	int l, n;

	if (a > b)
		return 0;
	
	i = a;
	j = m + 1;
	k = 0;
	while (k <= (b - a))
	{
		if ((j > b) || ((i <= m) && (vetor[i] <= vetor[j])))
		{
			u[k] = vetor[i];
			i++;
		}
		else
		{
			u[k] = vetor[j];
			j++;
		}
		(*nComps)++;
		k++;
	}
	
	l = a;
	n = 0;
	while (l <= b)
	{
		vetor[l] = u[n];
		n++;
		l++;
	}

	free(u);

	return 1;
}

int mergeSort_aux(int vetor[], int a, int b, int *nComps){
	int m;

	if (a >= b)
		return 0;
	
	m = floor((a+b)/2);
	mergeSort_aux(vetor,a,m,nComps);
	mergeSort_aux(vetor,m+1,b,nComps);
	intercala(vetor,a,m,b,nComps);

	return 1;
}

int mergeSort(int vetor[], int tam){
	int inicio = 0;
	int fim = tam - 1;
	int nComps = 0;

	mergeSort_aux(vetor,inicio,fim,&nComps);

	return nComps;
}

int particiona(int vetor[], int a, int b, int x, int *nComps){
	int m = a - 1;
	int i = a;

	while (i <= b)
	{
		if (vetor[i] <= x)
		{
			m++;
			troca(vetor,m,i);
		}
		(*nComps)++;
		i++;
	}

	return m;
}

int quickSort_aux(int vetor[], int a, int b, int *nComps){
	int m;

	if (a >= b)
		return 0;
	
	m = particiona(vetor,a,b,vetor[b],nComps);
	quickSort_aux(vetor,a,m-1,nComps);
	quickSort_aux(vetor,m+1,b,nComps);

	return 1;
}

int quickSort(int vetor[], int tam){
	int inicio = 0;
	int fim = tam - 1;
	int nComps = 0;

	quickSort_aux(vetor,inicio,fim,&nComps);

	return nComps;
}

int maxHeapify(int v[], int i, int n, int *nComps)
{
	int esq = (i + 1) * 2 - 1;
	int dir = (i + 1) * 2;
	int maior;

	(*nComps)++;
	if ((esq <= (n - 1)) && (v[esq] > v[i]))
		maior = esq;
	else
		maior = i;
	
	(*nComps)++;
	if ((dir <= (n - 1)) && v[dir] > v[maior])
		maior = dir;
	if (maior != i)
	{
		troca(v,i,maior);
		maxHeapify(v,maior,n,nComps);
	}

	return 1;
}

int buildMaxHeap (int v[], int n, int *nComps)
{
	int i = floor((n - 1)/2);

	while (i >= 0)
	{
		maxHeapify(v,i,n,nComps);
		i--;
	}

	return 1;
}

int heapSort_aux(int vetor[], int tam, int *nComps)
{
	int i;

	buildMaxHeap(vetor,tam,nComps);

	i = tam - 1;
	while (i >= 1)
	{
		troca(vetor,0,i);
		maxHeapify(vetor,0,i,nComps);
		i--;
	}

	return 1;
}

int heapSort(int vetor[], int tam)
{
	int nComps = 0;

	heapSort_aux(vetor,tam,&nComps);

	return nComps;
}