/*
 *      K.c
 *      Copyright 2012 JoÃ£o Ferreira <joao@void>
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NODES 10000

typedef struct worker {
	int nChilds;
	int out;
	int in;
	int *childs;
	int score;
}worker;

worker *workers;
int nWorkers, *zeroed, nZeroed;

void show()
{
	int i, j;
	printf("Showing connections:\n");
	for (i=1 ; i<=nWorkers ; i++)
	{
		if (workers[i].nChilds == 0)
			continue;
		
		printf("%d:", i);
		for (j=0 ; j<workers[i].nChilds ; j++)
			printf(" %d", workers[i].childs[j]);
		printf("\n");
	}
}

void solve()
{
	int i, aux, j, aux2;
	
	for (i=0 ; i<nZeroed ; i++)
	{
		aux = zeroed[i];
		if (workers[aux].out != 0)
		{
			for (j=0 ; j<workers[aux].nChilds ; j++)
			{
				aux2 = workers[aux].childs[j];
				workers[aux].out--;
				workers[aux2].in--;
				
				if (workers[aux2].score <= workers[aux].score)
					workers[aux2].score = workers[aux].score+1;
				if (workers[aux2].in == 0)
					zeroed[nZeroed++] = aux2;
			}
		}
	}
	
	int sum = 0;
	if (nZeroed != nWorkers)
		printf ("-1\n");
	else
	{
		for (i=1 ; i<=nWorkers ; i++)
			sum += workers[i].score;
		printf ("%d\n", sum);
	}
}

int main(int argc, char** argv)
{
	int i, pairs, a, b;
	
	while (scanf("%d %d", &nWorkers, &pairs) != EOF )
	{
		workers = (worker*) malloc ((1+nWorkers)*sizeof(worker));
		zeroed = (int*) malloc ((1+nWorkers)*sizeof(int));
		
		for (i=0 ; i<= nWorkers ; i++) {
			workers[i].in = workers[i].out = workers[i].nChilds = 0;
			workers[i].score = 1;
		}
		
		for (i=0 ; i<pairs ; i++) {
			scanf("%d %d", &a, &b);
			workers[b].childs = realloc (workers[b].childs, (workers[b].nChilds+1)*sizeof(int));
			workers[b].childs[workers[b].nChilds++] = a;
			workers[b].out++;
			workers[a].in++;
		}
		
		memset(zeroed, 0, (1+nWorkers)*sizeof(int));
		nZeroed = 0;
		
		for (i=1 ; i<=nWorkers ; i++) {
			if (workers[i].in == 0)
				zeroed[nZeroed++] = i;
		}
		
		/*show();*/
		
		solve();
		
		free(workers);
		free(zeroed);
	}
	
	return 0;
}
