/*
 *      B.c
 *      Copyright 2012 João Ferreira <joao@void>
 */


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

bool fair(int *persons, int size)
{
	int ratio;
	register int p1, p2, p3;
	
	for (p1=0 ; persons[p1]<0 ; p1++)
	{
		p2 = p1+1;
		
		for (p3=size-1 ; p3>p2 ; )
		{
			ratio = persons[p1]+persons[p2]+persons[p3];
			if (ratio == 0)
			{
				/*printf("%d %d %d\n", persons[p1], persons[p2], persons[p3]);*/
				return true;
			} else if (ratio > 0) {
				p3--;
			} else {
				p2++;
			}
		}
	}
	return false;
}

int main(int argc, char** argv)
{
	int p, i, *persons;
	
	while (scanf("%d", &p) != EOF)
	{
		persons = (int*) malloc (p*sizeof(int));
		
		for (i=0 ; i<p ; i++) 
			scanf("%d", &persons[i]);
		
		/*to eat the 0*/
		scanf("%d", &i); 
		
		qsort (persons, p, sizeof(int), compare);
		
		if (fair(persons, p))
		{
			printf("Fair\n");
		} else {
			printf("Rigged\n");
		}
		
		free(persons);
	}
	return 0;
}
