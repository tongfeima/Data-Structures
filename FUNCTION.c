#include "DIJKSTRA.h"

void InitializeTable(int start,TABLE T[])	
{
	int i;
	for(i=0;i<Max;i++)
	{
		T[i]=malloc(sizeof(Node));
		T[i]->visited=0;
		T[i]->path=Nopath;
		T[i]->distance=X;
		T[i]->name=65+i;//ASCII A B C  D E F 
	}
	T[start]->distance=0;
	
}

QUEUE InitializeQueue(int capacity)
{
	QUEUE Q;
	Q=malloc(sizeof(Queue));
	Q->capacity=capacity;
	Q->size=0;
	
	for(int i=1;i<Max;i++)
	{
		Q->element[i]=NULL;
	}
	Q->element[0]=malloc(sizeof(Node));
	Q->element[0]->distance=0;
	
	return Q;
	
}

void enqueue(QUEUE Q, TABLE K)
{
	int i,hole;
	
	if(K->path==Nopath)
	{
		Q->size++;
		hole=Q->size;
	}
	else
	{
		i=1;
		while(K->name!=Q->element[i]->name&&Q->element[i]!=NULL)
		{
			i++;
		} 
		hole=i;	
	}
	i=hole/2;
	
	while(K->distance < Q->element[i]->distance)
	{
		Q->element[hole]=Q->element[i];
		hole=i;
		i=i/2;
	}
	Q->element[hole]=K;
}

int dequeue(QUEUE Q)
{	TABLE OUT;
	int hole=1,child=2,last=Q->size;
	OUT=Q->element[1];
	Q->size--;
	while(child <= Q->size && Q->element[child]->distance < Q->element[last]->distance  )
	{	
		
		if(Q->element[child]->distance > Q->element[child+1]->distance )	
			child++;			
		Q->element[hole]=Q->element[child];
		hole=child;
		child=hole*2;	
	}
	
	Q->element[hole]=Q->element[last];
	Q->element[last]=NULL;
	
	return OUT->name-65;
	
}

void Dijkstra(int const(*map)[Max],int start,TABLE T[])
{
	 
	int current;
	InitializeTable(start,T);
	QUEUE Q;
	Q=InitializeQueue(Max);
	enqueue(Q,T[start]);
	while(Q->size!=0)
	{
		current=dequeue(Q);
	
		for(int i=0;i<Max;i++)
		{
			int EdgeLength = map[current][i];
			
			if(EdgeLength!=0 && EdgeLength!=X && T[i]->visited==0)
			{
				if(T[i]->distance > EdgeLength + T[current]->distance);
				{
					T[i]->distance = EdgeLength + T[current]->distance;
					enqueue(Q,T[i]);
					T[i]->path=current;
				}	
			}
		}
		T[current]->visited=1;
	}
}


void ShowTable(TABLE T[])
{
	int i;
	printf("name	dis	path\n");
	for(i=0;i<Max;i++)
	{
		printf("%c:	%d	%c\n",T[i]->name,T[i]->distance,T[i]->path+65);
	}
}
