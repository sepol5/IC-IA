#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

// Leitura do ficheiro de input
// Recebe: nome do ficheiro, numero de vertices (ptr), numero de iteracoes (ptr)
// Devolve a matriz de adjacencias
int* init_dados(char *nome, int *nmoedas, int *total)
{
	FILE *f;
	int *p, *q;
	int i, j;

	f=fopen(nome, "r");
	if(!f)
	{
		printf("Erro no acesso ao ficheiro dos dados\n");
		exit(1);
	}
	// Numero de moedas
	fscanf(f, " %d", nmoedas);
	// valor a alcan�ar
	fscanf(f, " %d", total);
	//valor das n moedas
	fscanf(f, "%d",val)
	// Alocacao dinamica da matriz
	p = malloc(sizeof(int)*(*n)*(*n));
	if(!p)
	{
	    printf("Erro na alocacao de memoria\n");
	    exit(1);
	}
	q=p;
	// Preenchimento da matriz
	for(i=0; i<*n; i++)
        for(j=0; j<*n; j++)
            fscanf(f, " %d", q++);
	fclose(f);
	return p;
}

// Gera a solucao inicial
// Parametros: solucao, numero de moedas
void gera_sol_inicial(int *sol, int n)
{
	int i, x;

	for(i=0; i<n; i++)
        sol[i]=0;
	for(i=0; i<n/2; i++)
    {
        do
			x = random_l_h(0, n-1);
        while(sol[x] != 0);
        sol[x]=1;
    }
}

// Escreve solucao
// Parametros: solucao e numero de moedas
void escreve_sol(int *sol, int n)
{
	int i;

	printf("\nConjunto A: ");
	for(i=0; i<n; i++)
		if(sol[i]==0)
			printf("%2d  ", i);
	printf("\nConjunto B: ");
	for(i=0; i<n; i++)
		if(sol[i]==1)
			printf("%2d  ", i);
	printf("\n");
}

// copia vector b para a (tamanho n)
void substitui(int a[], int b[], int n)
{
    int i;
    for(i=0; i<n; i++)
        a[i]=b[i];
}

// Inicializa o gerador de numeros aleatorios
void init_rand()
{
	srand((unsigned)time(NULL));
}

// Devolve valor inteiro aleatorio entre min e max
int random_l_h(int min, int max)
{
	return min + rand() % (max-min+1);
}

// Devolve um valor real aleatorio do intervalo [0, 1]
float rand_01()
{
	return ((float)rand())/RAND_MAX;
}
