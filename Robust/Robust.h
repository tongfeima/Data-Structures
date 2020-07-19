#ifndef Robust_H
#define Robust_H
#define Nopath -1
#define Infinity 999
#define Max 6
#include<stdio.h>
#include<stdlib.h>


typedef struct graphnode
{
	int ceil;
	int floor; 
}GraphNode;
typedef GraphNode* Graph;

typedef struct tablenode
{
	int name;
	int visited;
	int robust;
	int path;
}TableNode;
typedef TableNode* TABLE;

void InitializeTable(TABLE T[]);

typedef struct PriorityQueue 
{
	int size;
	TABLE element[Max];
}Queue;
typedef Queue * QUEUE;
QUEUE InitializeQueue();
void enqueue(QUEUE Q, TABLE K);
int dequeue(QUEUE Q);

void ShowTable(TABLE T[]);
void ShowQueue(QUEUE Q);
void Robust(Graph (*map)[Max],TABLE T[],QUEUE Q);
int RobustCalculate(Graph (*map)[Max],int row,int colum );
#endif
