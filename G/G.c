/*
 *      G.c
 *      Copyright 2012 João Ferreira <joao@void>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 161

typedef struct item {
	int bonus;
	int weight;
	int price;
	double profitWeight;
	double profitValue;
} item;

item items[MAX_ITEMS];
int ordW[MAX_ITEMS], ordV[MAX_ITEMS]; 
int upperBound, lowerBound;

void bounds()
{
	
}

int compareWeight(const void *p1, const void *p2)
{
	int i = *(int *)p1;
	int j = *(int *)p2;
	
	if (items[i].profitWeight > items[j].profitWeight)
		return -1;
	
	else if (items[i].profitWeight < items[j].profitWeight)
		return 1;
	
	return 0;
}

int compareValue(const void *p1, const void *p2)
{
	int i = *(int *)p1;
	int j = *(int *)p2;
	
	if (items[i].profitValue > items[j].profitValue)
		return -1;
	
	else if (items[i].profitValue < items[j].profitValue)
		return 1;
	
	return 0;
}

int main(int argc, char** argv)
{
	int i, testCases, nItems, maxWeight, maxMoney, j, bonus;
	scanf("%d", &testCases);
	
	for (i=0 ; i<testCases ; i++)
	{
		bonus = 0;
		
		scanf("%d %d %d", &nItems, &maxWeight, &maxMoney);
		
		for (j=0 ; j<nItems ; j++)
		{
			scanf("%d %d %d", &items[j].bonus, &items[j].weight, &items[j].price);
			items[j].profitValue = ((double) items[j].bonus) / items[j].price;
			items[j].profitWeight = ((double) items[j].bonus) / items[j].weight;
			ordW[j] = ordV[j] = j;
		}
		
		qsort(ordW, nItems, sizeof(int), compareWeight);
		qsort(ordV, nItems, sizeof(int), compareValue);
		
		int k;
		printf("Input\n");
		printf("Bonus\tWeight\tPrice\n");
		for (k=0 ; k<nItems ; k++)
			printf("%d\t%d\t%d\t\n", items[k].bonus, items[k].weight, items[k].price);
		
		printf("\nBy Weight\n");
		printf("Bonus\tWeight\tPrice\tRatio\n");
		for (k=0 ; k<nItems ; k++)
			printf("%d\t%d\t%d\t%lf\n", items[ordW[k]].bonus, items[ordW[k]].weight, items[ordW[k]].price, items[ordW[k]].profitWeight);
		
		printf("\nBy Price\n");
		printf("Bonus\tWeight\tPrice\tRatio\n");
		for (k=0 ; k<nItems ; k++)
			printf("%d\t%d\t%d\t%lf\n", items[ordV[k]].bonus, items[ordV[k]].weight, items[ordV[k]].price, items[ordV[k]].profitValue);
		
		printf("\nMax Bonus => %d\n", bonus);
	}
	
	return 0;
}
