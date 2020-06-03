#include<stdio.h>
#include<stdlib.h>
#define Max 10
#define HeapMax 65535
#define Mask 1
#include<math.h>

struct node{
	struct node* sibling;
	struct node* firstchild;
	int data;
};
typedef struct node * BinNode;
struct heap{
	BinNode list[Max];
	int size;
};

typedef struct heap * BinHeap;
typedef struct node * BinTree;

BinNode combine(BinNode tree1, BinNode tree2);
void insert(BinHeap H,int C);
BinHeap Initialize();
void show(BinHeap H);
void traverse(BinTree L);
void merge(BinHeap H1,BinHeap H2);
int PopMin(BinHeap H);

int main(void)
{
	BinHeap nice;
	nice=Initialize();
	insert(nice,1);
	insert(nice,2);
	insert(nice,3);
	insert(nice,4);
	insert(nice,5);
	insert(nice,6);

					
	//show(nice);
//	puts("");
	BinHeap good;
	good=Initialize();
	insert(good,61);
	insert(good,91);
	insert(good,81);	
	insert(good,71);
	insert(good,72);
	show(good);
	puts("");
	
	merge(good,nice);
	
	show(good);
//	printf("nice size =%d\n",nice->size);
	
//	puts("");
	//printf("pop=%d \n",PopMin(nice));
	//show(nice);
	return 0;
}
int PopMin(BinHeap H)
{
	BinHeap New;
	BinTree DeleteTree;
	int MIN=99999;
	int n;
	n=log2(H->size);
	int MinTree;
	for(int i=0;i<=n;i++)
	{
		if(!!H->list[i]&&H->list[i]->data<MIN) 
		{
			MIN=H->list[i]->data;
			MinTree=i;
		}
	} 
	
	New=Initialize();
	New->size=1<<MinTree-1;
	DeleteTree=H->list[MinTree]->firstchild;
	free(H->list[MinTree]);
	H->list[MinTree]=NULL;
	H->size=H->size-(1<<MinTree);
	
	for(int i=MinTree-1;i>=0;i--)
	{
		New->list[i]=DeleteTree;
		DeleteTree=DeleteTree->sibling;
		New->list[i]->sibling=NULL;
	}
	
	printf("New size =%d\n",New->size);
	merge(New,H);
	
	
	return MIN;
}

BinNode combine(BinNode tree1, BinNode tree2)
{
	if(tree1->data>tree2->data)
	return combine(tree2,tree1);
	tree2->sibling=tree1->firstchild;
	tree1->firstchild=tree2;
	
	return tree1;
}

BinHeap Initialize()
{	
	BinHeap H;
	H=malloc(sizeof(struct heap));
	H->size=0;
	for(int i=0;i<Max;i++)
	{
	H->list[i]=NULL;
	}
	return H;
}

void insert(BinHeap H,int C)
{
	BinHeap TempHeap;
	BinTree TempTree;
	BinNode X;
	int i,tempsize,position;
	X=malloc(sizeof(struct node));
	X->data=C;
	X->firstchild=NULL;
	X->sibling=NULL; 
	TempTree=X;
	position=0;
	tempsize=H->size;
	while(tempsize&Mask)
	{
		tempsize=tempsize>>1;
		position++;
	}
	for(i=0;i<position;i++)
	{
		
		TempTree=combine(TempTree,H->list[i]);	
		H->list[i]=NULL;
	}
	H->list[position]=TempTree;
	H->size++;
}
void show(BinHeap H)
{
	int TreesNum;
	TreesNum=log2(H->size);
	for(int i=0;i<=TreesNum;i++)
	{
		if(!!H->list[i])
		printf("%d, ",H->list[i]->data);
	}	
	puts("");

	for(int i=0;i<=TreesNum;i++)
	{
		if(!!H->list[i])
		traverse(H->list[i]);
	}
}
void traverse(BinTree L)
{
	if(L==NULL)
		return;
	printf("%d  ",L->data);
	traverse(L->firstchild);
	traverse(L->sibling);
}

void merge(BinHeap H1,BinHeap H2)
{
	BinTree carry;
	carry=NULL;
	H1->size=H1->size+H2->size;
	int i,j;
	j=log2(H1->size);

	for(i=0;i<=j;i++)
	{	
		

		switch(!!H1->list[i]+!!H2->list[i]*2+4*!!carry)
		{
			case 0:
				break;
			case 1:	
				break;
			case 2: 
				H1->list[i]=H2->list[i];
				H2->list[i]=NULL;	
				break;
			case 3:
				carry=combine(H1->list[i],H2->list[i]);
				H1->list[i]=NULL;
				H2->list[i]=NULL;
				break;
			case 4:
				H1->list[i]=carry;
				carry=NULL;
				break;
			case 5:
				carry=combine(carry,H1->list[i]);
				H1->list[i]=NULL;
				break;
			case 6:
				H1->list[i]=combine(carry,H2->list[i]);
				H2->list[i]=NULL;
				carry=NULL;
				break;
			case 7:
				carry=combine(carry,H2->list[i]);
				H2->list[i]=NULL;
				break;	
		}		
	}
	
	H2->size=0;	
}
	
