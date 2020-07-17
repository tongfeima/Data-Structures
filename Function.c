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

void RobustCalculate(Graph (*map)[Max],int row,TABLE T[],QUEUE Q)
{	

	Graph self,others;
	enqueue(Q,T[row]);
	while(Q->size!=0)
	{
		row=dequeue(Q);
		
		for(int i=1;i<Max;i++)
		{	
			int MaxRob=0,Result;
			if(map[row][i]==NULL) 
				i++;
			self=map[row][i];
			
			for(int o=1;o<Max;o++)
			{	
				if(o==i||map[row][o]==NULL) 
					o++;
				else
				{
				
				others=map[row][o];			
				if(self->ceil >= others->floor)
					Result=self->ceil-others->floor;
				else
					Result=others->floor-self->ceil;
					
				if(Result>MaxRob)
					MaxRob=Result;
				o++;
				}
			}
			
			if(T[row]->robust+MaxRob<T[i]->robust)
			{	
				T[i]->robust=T[row]->robust+MaxRob;
				enqueue(Q,T[i]);
				T[i]->path=row;
			}
			ShowTable(T);
		}

		T[row]->visited=1;
	}
	
	
}

void ShowTable(TABLE T[])
{
	int i;
	printf("name	rob	path\n");
	for(i=0;i<Max;i++)
	{
		printf("%d:	%d	%d\n",T[i]->name,T[i]->robust,T[i]->path);
	}
}
void ShowQueue(QUEUE Q)
{
	
	printf("%d",Q->size);
}
