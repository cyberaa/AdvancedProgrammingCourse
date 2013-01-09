/*
 *      I.c
 *      Copyright 2012 João Ferreira <joao@void>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LETTERS 26

char **table;
int dictionary[LETTERS], zeros[LETTERS], chosen[10], **solutions;
int m, n, nSolutions;

void printSolutions()
{
	int i, j, prev;
	if (nSolutions == 0)
		printf("No solution!\n");
	
	for (i=0 ; i<nSolutions ; i++)
	{
		for (j=0, prev=0 ; j<26 ; j++)
		{
			if (solutions[i][j] >= 0)
			{
				if (prev)
					printf(" ");
				prev = 1;
				printf("%c=%d", j + 'A', solutions[i][j]);
			}
		}
		printf("\n");
	}
}

void zeroalbe()
{
	int i, j;
	for (i=0 ; i<m ; i++)
	{
		for (j=0 ; j<n && table[i][j] == ' ' ; j++);
		zeros[table[i][j]-'A'] = 1;
	}
}

int sum(int column, int carryBit, int *carryout)
{
	int line;
	
	for (line=0 ; line<m-1 ; line++)
		if (table[line][column] != ' ')
			carryBit += dictionary[table[line][column]-'A'];
	
	*carryout = carryBit / 10;
	if (carryBit % 10 == dictionary[table[m-1][column]-'A'])
		return 1;
	
	return 0;
}

void addSolution()
{
	solutions = realloc(solutions, sizeof(int *) * ++nSolutions);
	solutions[nSolutions-1] = malloc(sizeof(int) * 26);
	memcpy(solutions[nSolutions-1], dictionary, sizeof(int) * 26);
}

void solve(int column, int line, int carryBit)
{
	int i;
	int carryout, validSolution;
	
	 if (line == m)
	 {
		validSolution = sum(column, carryBit, &carryout);
		
		if (validSolution && column == 0 && carryout == 0)
			addSolution();
		
		else if (validSolution)
			solve(column-1, 0, carryout);
		
		return;
	}
	
	if (table[line][column] == ' ' || dictionary[table[line][column] - 'A'] >= 0)
	{
		solve(column, line+1, carryBit);
		return;
	} 
	
	for (i=0 ; i<10 ; i++)
	{
		if (i == 0 && zeros[table[line][column] - 'A'])
			continue;
		
		if (chosen[i] == 0)
		{
			chosen[i] = 1;
			dictionary[table[line][column] - 'A'] = i;
			solve(column, line+1, carryBit);
			chosen[i] = 0;
			dictionary[table[line][column] - 'A'] = -1;
		}
	}
}

int compare(int **a, int **b)
{
	int i;
	for (i=0 ; i <LETTERS ; i++)
	{
		if ((*a)[i] > (*b)[i])
			return 1;
		else if ((*a)[i] < (*b)[i])
			return -1;
	}
	return 0;
}

int main(int argc, char** argv)
{
	int i, j, testCases;
	
	for(testCases=0 ; scanf("%d %d", &m, &n) != EOF ; testCases++)
	{
		nSolutions = 0;
		memset(chosen, 0, 10*sizeof(int));
		memset(zeros, 0, 26*sizeof(int));
		memset(dictionary, -1, 26*sizeof(int));
		
		table = (char**) malloc (m*sizeof(char*));
		
		for (i=0 ; i<m ; i++)
		{
			table[i] = (char*) malloc (n*sizeof(char));
			for (j=0 ; j<n ; j++)
			{
				table[i][j] = getchar();
				if (table[i][j] == '\n')
					j--;
			}
		}
		
		zeroalbe();
		
		solve(n-1, 0, 0);
		
		qsort(solutions, nSolutions, sizeof(int*), (int(*)(const void *, const void *)) compare);
		
		if (testCases > 0)
			printf("\n");
		
		printSolutions();
	}
	
	return 0;
}
