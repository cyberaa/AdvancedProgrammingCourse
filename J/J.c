/*
 *      J.c
 *      Copyright 2012 JoÃƒÂ£o Ferreira <joao@void>
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 10000
#define MAX_CHILDS 100

typedef struct node {
	int c1, c2;
	int childs[MAX_CHILDS];
}node;

node *graph;
int max, *shortest, min, *visited, *maxCandidates, *tallest, *leafs;
int nodes, connections, nShortest, max, nCandidates, nLeafs;

int compare(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

void printSolution() {
	int i;
	
	printf("Tallest:");
	for (i=1 ; i<=nodes ; i++)
		if (tallest[i])
			printf(" %d", i);
	printf("\n");
}

void findFurthest (int root, int depth) {
	
	int i, keep = 0;
	
	visited[root] = 1;
	
	for (i=0 ; i<graph[root].c1 && !keep ; i++) {
		if (visited[graph[root].childs[i]] == 0) {
			keep = 1;
		}
	}
	
	if (depth > 0 && !keep) {
		if (depth > max) {
			nCandidates = 0;
			max = depth;
		}
		if (depth == max && tallest[root] == 0)
			maxCandidates[nCandidates++] = root;
	}
	
	for (i=0 ; i<graph[root].c1 ; i++) {
		if (visited[graph[root].childs[i]] == 0)
			findFurthest(graph[root].childs[i], depth+1);
	}
	
	visited[root] = 0;
}

void solveTallest() {
	
	int root;
	int i;
	
	srand (time(NULL));
	root = rand() % nodes + 1;
	
	findFurthest(root, 0);
	
	for (i=0 ; i<nCandidates ; i++)
		tallest[maxCandidates[i]] = 1;
	
	memset(visited, 0, (1+nodes)*sizeof(int));
	
	findFurthest(maxCandidates[0], 0);
	
	for (i=0 ; i<nCandidates ; i++) {
		tallest[maxCandidates[i]] = 1;
	}
	
	memset(visited, 0, (1+nodes)*sizeof(int));
}

void solveShortest()
{
	int i, j, no, v;
	int newLeafs, remainingNodes;
	
	newLeafs = 0;
	remainingNodes = nodes;
	
	for (i=1 ; i<=nodes ; i++)
		if (graph[i].c1 == 1)
			leafs[nLeafs++] = i;
	
	while (remainingNodes != nLeafs) {
		
		for(i=0 ; i<nLeafs ; i++) {
			
			no = leafs[i];
			remainingNodes--;
			
			for(j=0 ; j<graph[no].c1 ; j++) {
				
				v = graph[no].childs[j];
				
				if(visited[v] == 0) {
					
					graph[v].c2--;
					
					if(graph[v].c2 == 1) {
						
						leafs[newLeafs++] = v;
						visited[v] = 1;
					}
				}
			}
		}
		
		nLeafs = newLeafs;
		newLeafs = 0;
	}
	
	qsort(leafs, nLeafs, sizeof(int), compare);
	printf("Shortest:");
	for (i=0 ; i<nLeafs ; i++)
		printf(" %d", leafs[i]);
	printf("\n");
}

void init() {
	
	int i;
	
	max = 0;
	tallest = (int*) malloc ((1+nodes)*sizeof(int));
	
	nShortest = 0;
	min = nodes*nodes;
	shortest = (int*) malloc ((1+nodes)*sizeof(int));
	
	visited = (int*) calloc ((1+nodes), sizeof(int));
	
	graph = (node*) malloc ((1+nodes)*sizeof(node));
	
	for (i=1 ; i<=nodes ; i++) {
		graph[i].c1 = 0;
		graph[i].c2 = 0;
	}
	
	max = 0;
	maxCandidates = (int*) malloc ((1+nodes)*sizeof(int));
	nCandidates = 0;
	
	leafs = (int*) malloc ((1+nodes)*sizeof(int));
	nLeafs = 0;
}

void show() {
	int i, j;
	printf("Showing Connection Table\n");
	for (i=1 ; i<=nodes ; i++) {
		printf("Node %d:", i);
		for (j=0 ; j<graph[i].c1 ; j++) {
			printf(" %d", graph[i].childs[j]);
		}
		printf("\n");
	}
}

int main(int argc, char** argv)
{
	int i, a, b;
	
	scanf("%d", &nodes);
	connections = nodes-1;
	
	init();
	
	for (i=0 ; i<connections ; i++) {
		scanf("%d %d", &a, &b);
		graph[a].childs[graph[a].c1] = b;
		graph[b].childs[graph[b].c2] = a;
		graph[a].c1++;
		graph[a].c2++;
		graph[b].c1++;
		graph[b].c2++;
	}
	
	/*show();*/
	
	solveTallest();
	solveShortest();
	printSolution();
	
	return 0;
}
