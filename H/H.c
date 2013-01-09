/*
 *      H.c
 *      Copyright 2012 João Ferreira <joao@void>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXC 6001

int main(int argc, char** argv)
{
	int cities, connections, i, source, destiny;
	int known[MAXC];
	int knows[MAXC];
	
	while( scanf("%d %d", &cities, &connections) != EOF)
	{
		memset(known, 0, cities*sizeof(int));
		memset(knows, 0, cities*sizeof(int));
		
		for (i=0 ; i<connections ; i++)
		{ 
			scanf("%d %d", &source, &destiny);
			known[destiny]++;
			knows[source]++;
		}
		
		for (i=0 ; i<cities && knows[i] != 0 ; i++);
		
		if ( i != cities && known[i] == cities-1 )
			printf("%d\n", i);
		else
			printf("nix\n");
	}
	
	return 0;
}
