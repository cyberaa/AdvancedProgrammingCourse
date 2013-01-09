/*
 *      D.c
 *      Copyright 2012 JoÃ£o Ferreira <joao@void>
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int m, n, max;
int **matrix, *sums;

void solve()
{
	register int i, j, k, current;
	
	for(i=0 ; i<n ; i++)
	{
		memset(sums, 0, m*sizeof(int));
		
		for(j=i ; j<n ; j++)
		{
			current=0;
			for(k=0 ; k<m ; k++)
			{
				sums[k] += matrix[j][k];
				
				current += sums[k];
				
				if(current < 0)
					current = 0;
				
				if(max < current)
					max = current;
			}
		}
	}
}

int main(int argc, char** argv)
{
	register int i, j;
	
	while ((scanf("%d %d", &n, &m)) != EOF)
	{
		max = 0;
		if (m > n)
		{
			matrix = (int**) malloc (n*sizeof(int*));
			sums = (int*) malloc (m*sizeof(int));
			
			for(i=0 ; i<n ; i++) 
				matrix[i] = (int*) malloc (m*sizeof(int));
			
			for(i=0 ; i<n ; i++)
				for(j=0 ; j<m ; j++)
					scanf("%d", &matrix[i][j]);
			
		} else {
				
			i = m;
			m = n;
			n = i;
				
			matrix = (int**) malloc (n*sizeof(int*));
			sums = (int*) malloc (m*sizeof(int));
			
			for(i=0 ; i<n ; i++) 
				matrix[i] = (int*) malloc (m*sizeof(int));
			
			for(j=0 ; j<m ; j++)
				for(i=0 ; i<n ; i++)
					scanf("%d", &matrix[i][j]);
		}
		
		solve();
		
		printf("%d\n", max);
	}
	
	return 0;
}
