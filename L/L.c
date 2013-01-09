/*
 *      L.c
 *      Copyright 2012 JoÃ£o Ferreira <joao@void>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nPairs, nBoys, nGirls, max_student, max_pair, SOURCE = 0, SINK, flowSize;
int **flow, *visited;

int path(int current, int actual_flow) {
	
	if (current == SINK)
		return actual_flow;
	
	int i, new_flow, res;
	
	visited[current] = 1;
	
	for (i = 0; i < flowSize; i++) {
		
		if (visited[i] != 1 && flow[current][i] > 0) {
			
			if (actual_flow > flow[current][i] || actual_flow == -1)
				 new_flow = flow[current][i];
			else
				new_flow = actual_flow;
			
			res = path(i, new_flow);
			
			if (res > 0) {
				
				flow[current][i] -= res;
				flow[i][current] += res;
				
				return res;
			}
		}
	}
	
	return 0;
}

void solve() {
	
	int max = 0, f = -1;
	
	do
	{
		memset(visited, 0, flowSize*sizeof(int));
		f = path(SOURCE, -1);
		max += f;
		
	} while (f > 0);
	
	printf("%d\n", max);
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int main(int argc, char** argv)
{
	int i, boy, girl;
	
	while ( scanf("%d %d %d", &nPairs, &nBoys, &nGirls) != EOF ) {
		
		flowSize = nBoys+nGirls+2;
		SINK = flowSize - 1;
		
		visited = (int*) calloc (flowSize, sizeof(int));
		flow = (int**) malloc (flowSize*sizeof(int*));
		for (i = 0; i < flowSize; i++)
			flow[i] = (int*) calloc (flowSize, sizeof(int));
		
		
		scanf("%d %d", &max_student, &max_pair);
		
		for (i = 1; i < nBoys+1; i++)
			flow[0][i] = max_student;
		
		for (i = nBoys+1; i < flowSize-1; i++)
			flow[i][flowSize-1] = max_student;
		
		int m = min(max_student, max_pair);
		
		for (i = 0; i < nPairs; i++) {
			scanf("%d %d", &boy, &girl);
			flow[boy][nBoys+girl] = m;
		}
		
		solve();
	}
	
	return 0;
}
