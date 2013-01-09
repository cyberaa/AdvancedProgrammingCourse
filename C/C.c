/*
 *      C.c
 *      Copyright 2012 João Ferreira <joao@void>
 */

#include <stdio.h>
#include <string.h>

#define MAX_MEMBERS 100

int matrix[MAX_MEMBERS][MAX_MEMBERS];
int friendships[MAX_MEMBERS];
int members, best = 0, subset=0;

void add(int *a, int initial)
{
	register int i;
	for (i=initial ; i<members ; i++)
		friendships[i]+=a[i];
}

void subtract(int *a, int initial)
{
	register int i;
	for (i=initial ; i<members ; i++)
		friendships[i]-=a[i];
}

int countZeros(int initial)
{
	register int i, counter=0;
	for (i=initial ; i<members ; i++)
		if (friendships[i] == 0)
			counter++;
	return counter;
}

void solve(int pos)
{
	add(matrix[pos], pos+1);
	subset++;
	
	register int i;
	for (i=pos+1 ; subset+countZeros(i) > best && i<members; i++) {
		if (friendships[i] == 0) {
			solve(i);
		}
	}
	
	if (best < subset)
		best = subset;
	
	subset--;
	subtract(matrix[pos], pos+1);
}

int main(int argc, char** argv)
{
	int connections, i, x, y;
	
	scanf("%d %d", &members, &connections);
	
	memset(matrix, 0, MAX_MEMBERS*MAX_MEMBERS*sizeof(char));
	memset(friendships, 0, MAX_MEMBERS*sizeof(int));
	
	for (i=0 ; i<connections ; i++)
	{
		scanf("%d %d", &x, &y);
		matrix[x][y] = matrix[y][x] = 1;
	}
	
	for (i=0 ; i<members-1 ; i++)
		solve(i);
	
	printf("%d\n", best);
	
	return 0;
}
