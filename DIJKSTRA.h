#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#define X 999
#define Max 6
#define Nopath -1
#include <stdio.h>
#include "DIJKSTRA.h" 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node 
{
	int path;
	int visited;
	int distance; 
	char name;
}Node;
typedef Node* TABLE;

void InitializeTable(int start,TABLE T[]);


typedef struct PriorityQueue 
{
	int size;
	int capacity; 
	TABLE element[Max];
}Queue;
typedef Queue * QUEUE;

QUEUE InitializeQueue(int capacity);
void enqueue(QUEUE Q, TABLE K);
int dequeue(QUEUE Q);
void Dijkstra(int const(*map)[Max],int start,TABLE T[]);
void ShowTable(TABLE T[]);


#endif
