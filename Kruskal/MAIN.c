#include "kruskal.h" 

	const int map[6][6]={
//		 A B C D E F	
/*A*/	{0,5,1,X,X,X},
/*B*/	{5,0,2,1,X,X},
/*C*/	{1,2,0,4,8,X},
/*D*/	{X,1,4,0,3,6},
/*E*/	{X,X,8,3,0,X},
/*F*/	{X,X,X,6,X,0},
		};
	

int main(void)
{
	QUEUE Q;
	VER V[Max];
	Q=InitializeQueue();
	Initialize(map,Q,V);

	Kruskal(Q,V);
/*	for(int i=0;i<Max;i++)
	{
		printf("%c	%d\n",V[i]->name,V[i]->IfInSet);
	 } */
	
	return 0;
}
