#include "DIJKSTRA.h" 

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
	TABLE T[Max];
	Dijkstra(map,0,T);
	ShowTable(T);
	
	return 0;
}
