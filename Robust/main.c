#include "Robust.h" 


int main(void)
{
	Graph map[Max][Max];
	for(int i=0;i<Max;i++)
		for(int j=0;j<Max;j++)
			map[i][j]=NULL;
		map[0][1]=malloc(sizeof(GraphNode)); map[0][1]->ceil=3;map[0][1]->floor=1;
		map[0][2]=malloc(sizeof(GraphNode)); map[0][2]->ceil=4;map[0][2]->floor=2;
		map[1][2]=malloc(sizeof(GraphNode)); map[1][2]->ceil=3;map[1][2]->floor=1;
		map[1][3]=malloc(sizeof(GraphNode)); map[1][3]->ceil=7;map[1][3]->floor=3;
		map[1][4]=malloc(sizeof(GraphNode)); map[1][4]->ceil=5;map[1][4]->floor=2;
		map[2][3]=malloc(sizeof(GraphNode)); map[2][3]->ceil=7;map[2][3]->floor=3;
		map[2][4]=malloc(sizeof(GraphNode)); map[0][2]->ceil=6;map[0][2]->floor=2;
		map[3][4]=malloc(sizeof(GraphNode)); map[3][4]->ceil=4;map[3][4]->floor=2;
		map[3][5]=malloc(sizeof(GraphNode)); map[3][5]->ceil=6;map[3][5]->floor=4;
		map[4][5]=malloc(sizeof(GraphNode)); map[4][5]->ceil=7;map[4][5]->floor=3;

	TABLE T[Max];
	QUEUE Q;
	InitializeTable(T);
	Q=InitializeQueue();
	RobustCalculate(map,0,T,Q);
	//ShowTable(T);
	return 0;	
}	

