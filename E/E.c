/*
 *      E.c
 *      Copyright 2012 João Ferreira <joao@void>
 */

#include <stdio.h>
#include <stdlib.h>

int **matrix;
int w1size, w2size;
char *w1, *w2;

void printMatrix()
{
	int i, j;
	printf("\n");
	for (i=0 ; i<w1size+1 ; i++)
	{
		for (j=0 ; j<w2size+1 ; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

int max(int a, int b, int c)
{
	if (a > b && a > c)
		return a;
	if (b > c)
		return b;
	return c;
}

void fillMatrix()
{
	int i, j;
	
	for (i=1 ; i<w1size+1 ; i++)
	{
		for (j=1 ; j<w2size+1 ; j++)
		{
			if (w1[i-1] == w2[j-1])
				matrix[i][j] = matrix[i-1][j-1] + 1;
			else
				matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) -1 ;
		}
	}
}


int main(int argc, char** argv)
{
	int i n;
	scanf("%d", &n);

	while (n--)
	{
		scanf("%s", w1);
		scanf("%s", w2);
		
		w1size = strlen(w1);
		w2size = strlen(w2);

		matrix = (int**) malloc ((w1size+1)*sizeof(int*));
		for (i=0 ; i<w1size+1 ; i++)
		{
			matrix[i] = (int*) malloc ((w2size+1)*sizeof(int));
			matrix[i][0] = i*-1;
		}
		
		for (i=0 ; i<w2size+1 ; i++)
			matrix[0][i] = i*-1;
		
		fillMatrix();
		
		printMatrix();
		
		printf("%d\n", matrix[w1size][w2size]);	

	}
	return 0;
}
