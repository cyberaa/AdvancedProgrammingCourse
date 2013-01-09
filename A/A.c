/*
 *      A.c
 *      Copyright 2012 João Ferreira <joao@void>
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct segment {
	double start;
	double stop;
}segment;

int compare(const void *p1, const void *p2)
{
	const struct segment *elem1 = p1;    
	const struct segment *elem2 = p2;
	
	if ( elem1->start < elem2->start)
		return -1;
	else if (elem1->start > elem2->start)
		return 1;
	else
		return 0;
}

int main(int argc, char** argv)
{
	int posts, i;
	segment *pos;
	double covered=0, last, begin;
	
	scanf("%d", &posts);
	
	pos = (segment*) malloc (posts*sizeof(segment));
	
	for (i=0 ; i<posts; i++)
		scanf("%lf %lf", &pos[i].start, &pos[i].stop);
	
	qsort (pos, posts, sizeof(segment), compare);
	
	begin = pos[0].start;
	last = pos[0].stop;
	
	for (i=1 ; i<posts ; i++)
	{
		/*exists*/
		if (pos[i].start <= last)
		{
			if (pos[i].stop > last)
				last = pos[i].stop;
		}
		/*doesn't*/
		else
		{
			covered += last - begin;
			begin = pos[i].start;
			last = pos[i].stop;
		}
	}
	
	covered += last-begin;
	printf("%.6lf\n", covered);
	
	return 0;
}
