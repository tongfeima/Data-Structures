#include "Robust.h" 

void InitializeTable(TABLE T[])	
{
	int i;
	for(i=0;i<Max;i++)
	{
		T[i]=malloc(sizeof(TableNode));
		T[i]->visited=0;
		T[i]->path=Nopath;
		T[i]->robust=Infinity;
		T[i]->name=i;
	}
		T[0]->robust=0;
}

QUEUE InitializeQueue()
{
	
	QUEUE Q;
	Q=malloc(sizeof(Queue));
	Q->size= 0;
	for(int i=1;i<Max;i++)
	{
		Q->element[i]=NULL;
	}
	Q->element[0]=malloc(sizeof(TableNode));
	Q->element[0]->robust = -1;
	return Q;
}

void enqueue(QUEUE Q, TABLE K)
{
	int i=1,hole;
	
	if(K->path==Nopath)
	{
		Q->size++;
		hole=Q->size;
	}
	else
	{
		while(K->name!=Q->element[i]->name&&Q->element[i]!=NULL)
			i++;
		hole=i;	
	}
	
	i=hole/2;
	
	while(K->robust < Q->element[i]->robust)
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
	while(child <= Q->size && Q->element[child]->robust < Q->element[last]->robust  )
	{	
		
		if(Q->element[child]->robust > Q->element[child+1]->robust )	
			child++;			
		Q->element[hole]=Q->element[child];
		hole=child;
		child=hole*2;	
	}
	
	Q->element[hole]=Q->element[last];
	Q->element[last]=NULL;
	
	return OUT->name;
	
}

void Robust(Graph (*map)[Max],TABLE T[],QUEUE Q)
{		
	int row=0,i,iRob;
	enqueue(Q,T[row]);
	while(Q->size!=0)
	{
		row=dequeue(Q);
		for(i=0;i<Max;i++)
		{	
			if(i==row||map[row][i]==NULL) 
				continue;	
			iRob=RobustCalculate(map,row,i);		
			if(T[i]->robust> T[row]->robust+iRob)
			{	
				T[i]->robust=T[row]->robust+iRob;
				enqueue(Q,T[i]);
				T[i]->path=row;
			}
		}
		T[row]->visited=1;
	}
	ShowTable(T);	
}

int RobustCalculate(Graph (*map)[Max],int row,int colum )
{
	Graph self,others;
	int MaxRob=0,Result,i;

	self=map[row][colum];			
	for(i=0;i<Max;i++)
	{	
		if(i==colum||map[row][i]==NULL) 
			continue;	
		others=map[row][i];			
		
		if(self->ceil > others->floor)
			Result=self->ceil-others->floor;
		else
			Result=others->floor-self->ceil;
		
		if(Result>MaxRob)
			MaxRob=Result;		
	}	
	return MaxRob;
}

void ShowTable(TABLE T[])
{
	int i;
	printf("name	path	robust\n");
	for(i=0;i<Max;i++)
	{
		printf("%c	%c	%d\n",T[i]->name+65,T[i]->path+65,T[i]->robust);
	}
}
void ShowQueue(QUEUE Q)
{
	printf("table size=%d	",Q->size);
	for(int i=1;Q->element[i]!=NULL;i++)
	 printf("name:%d	path:%d	robust:%d\n",Q->element[i]->name,Q->element[i]->path,Q->element[i]->robust);
}
