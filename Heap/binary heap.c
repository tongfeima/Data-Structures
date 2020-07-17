#include<stdio.h>
#include<stdlib.h>
typedef struct Heap
{
	int size;
	int capacity;
	int *element;
}heap;

typedef heap *HEAP;
void insert(HEAP H,int X);
HEAP Initialize(int capacity);
int Delete(HEAP H);
int main(void)
{
	HEAP good;
	good=Initialize(10);
	insert(good,99);
	insert(good,23);
	insert(good,44);
	insert(good,92);
	insert(good,45);
	insert(good,34);
	insert(good,05);
	insert(good,78);
	insert(good,56);
	Delete(good);
	Delete(good);
	Delete(good);
	Delete(good);
	Delete(good);
	Delete(good);
	Delete(good);
	for(int i=1;i<=good->size;i++)
	printf("%d\n",good->element[i]);
	return 0;
}

HEAP Initialize(int capacity)
{
	
	HEAP H;
	H=malloc(sizeof(heap));
	H->element=malloc(sizeof(int)*capacity);
	H->capacity=capacity;
	H->size=0;
	
	H->element[0]=0;
	return H;
}

void insert(HEAP H,int X)
{
	int i;
	int hole;
	H->size++;
	hole=H->size;
	i=hole/2;
	while(X<H->element[i])
	{
		H->element[hole]=H->element[i];
		hole=i;
		i=i/2;
	}
	H->element[hole]=X;
	
}

int Delete(HEAP H)
{
	int r,hole,child,last;
	r=H->element[1];
	last=H->size;
	H->size--;
	hole=1;
	child=2;
	
	while(H->element[child]<H->element[last]&&child<=H->size)
	{
	if(H->element[child]>H->element[child+1])
		child++;
	H->element[hole]=H->element[child];
	hole=child;
	child=hole*2;
	}
	H->element[hole]=H->element[last];
	H->element[last]=0;
	
	return r;	
}



