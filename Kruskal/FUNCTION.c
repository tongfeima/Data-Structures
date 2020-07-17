#include "Kruskal.h"

void Initialize(int const(*map)[Max],QUEUE Q,VER V[])
{
	for(int i=0;i<Max;i++)
	{
		V[i]=malloc(sizeof(Vertex));
		V[i]->name=i+65;
		V[i]->parent=Nopath;
	}
	int TempMap[Max][Max];
	for(int j=0;j<Max;j++)
		for(int k=0;k<Max;k++)
			TempMap[j][k]=map[j][k];
			

	for(int i=0;i<Max;i++)
	{
		for(int k=0;k<Max;k++)
			if(TempMap[i][k]!=0 && TempMap[i][k]!=X)
			{
				if(TempMap[i][k]==TempMap[k][i])
				{
					EDGE temp;
					temp=malloc(sizeof(Edge));		
					temp->length=TempMap[i][k];
					temp->A=V[i];
					temp->B=V[k];
					enqueue(Q,temp);
					TempMap[i][k]=0;
					TempMap[k][i]=0;
				}
			}
	}
	
}

QUEUE InitializeQueue()
{
	QUEUE Q;
	Q=malloc(sizeof(Queue));
	Q->size=0;
	
	for(int i=1;i<(Max*Max);i++)
	{
		Q->element[i]=malloc(sizeof(EDGE));
		Q->element[i]=NULL;
	}
	Q->element[0]=malloc(sizeof(Edge));
	Q->element[0]->length=0;

	return Q;
	
}

void enqueue(QUEUE Q, EDGE E)
{
	int i,hole;
	Q->size++;
	hole=Q->size;
	i=hole/2;
	while(E->length < Q->element[i]->length)
	{
		Q->element[hole]=Q->element[i];
		hole=i;
		i=i/2;
	}
	Q->element[hole]=E;
}

EDGE dequeue(QUEUE Q)
{	EDGE Min,Last;
	int i,child;
	Min=Q->element[1];
	Last=Q->element[Q->size--];

	for(i=1;i*2<=Q->size;i=child)
	{
		child=i*2;
		if(child!=Q->size && Q->element[child]->length> Q->element[child+1]->length)
			{
			child++;
			}
			if(Last->length>Q->element[child]->length)
				Q->element[i]=Q->element[child];
			else
				break;			
	}
	Q->element[i]=Last;	
	Last=NULL;
	return Min;
	
}

void Kruskal(QUEUE Q,VER V[])
{
	EDGE current;
	int edgenumber=0;
	
	while(edgenumber<Max-1)
	{	
		current=dequeue(Q);
		if(IfAdopted(current,V))
		{
			output(current);
			edgenumber++;
		}

	}
}
int IfAdopted(EDGE E,VER V[])
{
	int A,B,a,b;
	A=E->A->name-65;
	B=E->B->name-65;
	a=A,b=B;
	
	while(V[a]->parent!=Nopath)
		a=V[a]->parent;

	while(V[b]->parent!=Nopath)
		b=V[b]->parent;

	if(a==b)
		return 0;
	else
		V[b]->parent=a;
		return 1;
}

void output(EDGE E)
{
		printf("%c 	%c	%d\n",E->A->name,E->B->name,E->length);
}
