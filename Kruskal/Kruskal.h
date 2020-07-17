#ifndef Kruskal_H
#define Kruskal_H
#define X 999
#define Max 6
#define Nopath -1
#include <stdio.h>
#include "Kruskal.h" 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct vertex 
{
	char name;
	int parent;
}Vertex;

typedef Vertex* VER;

typedef struct edge 
{
	VER A;
	VER B;
	int length; 
}Edge;

typedef Edge* EDGE;


typedef struct PriorityQueue 
{
	int size;
	EDGE element[Max*Max];
}Queue;
typedef Queue * QUEUE;
QUEUE InitializeQueue();
void Initialize(int const(*map)[Max],QUEUE Q,VER V[]);
void enqueue(QUEUE Q, EDGE K);
EDGE dequeue(QUEUE Q);
void Kruskal(QUEUE Q,VER V[]);
void output(EDGE E);
int IfAdopted(EDGE E,VER V[]);
#endif
