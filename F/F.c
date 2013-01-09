/*
 *      F.c
 *      Copyright 2012 João Ferreira <joao@void>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 30001

typedef struct event{
	int id;
	int start;
	int end;
}event;

event events[MAX_EVENTS];
event rooms[MAX_EVENTS];

int compare(const void *p1, const void *p2)
{
	const struct event *elem1 = p1;
	const struct event *elem2 = p2;
	
	if ( elem1->start < elem2->start)
		return -1;
	else if (elem1->start > elem2->start)
		return 1;
	else
		return 0;
}

void printEvents(int size)
{
	int i;
	for (i=0 ; i<size ; i++)
		printf("Event %d from %d to %d\n", events[i].id, events[i].start, events[i].end);
}

int main(int argc, char** argv)
{
	int i, size, occupied, j;
	
	while ( scanf("%d", &size) != EOF )
	{
		occupied = 0;
		
		memset(rooms, 0, size*sizeof(event));
		
		for (i=0 ; i<size ; i++)
		{
			scanf("%d %d", &events[i].start, &events[i].end);
			events[i].id = i+1;
		}
		
		qsort(events, size, sizeof(event), compare);
		
		/*printEvents(size);*/
		
		for (i=0 ; i<size ; i++)
		{
			for (j=0 ; events[i].start < rooms[j].end ; j++);
			
			rooms[j] = events[i];
			
			/*por causa de os índices começarem em 1*/
			j++;
			
			if (occupied < j)
				occupied = j;
			
			printf("%d %d\n", events[i].id, j);
		}
		
		printf("%d\n", occupied);
	}
	
	return 0;
}
