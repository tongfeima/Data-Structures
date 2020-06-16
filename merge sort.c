#include<stdio.h>
#define N 10
void merge(int arr[],int L,int M ,int R);
void mergesort(int arr[],int L,int R);

int main(void)
{
	int good[N]={9,8,2,4,6,1,0,3,5,7};

	mergesort(good,0,9);


	for(int i=0;i<N;i++)
	printf("%d ",good[i]);
	

	return 0;	
}

void mergesort(int arr[],int L,int R)
{
	
	if(L<R)
	{
		int M;
		M=(L+R)/2;
		mergesort(arr,L,M);
		mergesort(arr,M+1,R);
		merge(arr,L,M,R);	
	}
	else
		return;	
 } 


void merge(int arr[],int L,int M ,int R)
{
	
	int LEFT_SIZE=(M-L)+1;
	int RIGHT_SIZE=R-M;
	int left[LEFT_SIZE];
	int right[RIGHT_SIZE];
	
	for(int i=L;i<=R;i++)
	{
		if(i<=M)
		left[i-L]=arr[i];
		else if (i>M)
		right[i-M-1]=arr[i];
	}
	printf("left=");
	for(int i=0;i<LEFT_SIZE;i++)
	{
		printf("%d ",left[i]);
	}
	printf("  right=");
	for(int i=0;i<RIGHT_SIZE;i++)
	{
		printf("%d ",right[i]);
	}	
	int a=0,b=0,c=L;
	
	while(a<LEFT_SIZE&&b<RIGHT_SIZE)
	{
		if(left[a]<=right[b])
		{
			arr[c]=left[a];
			c++;a++;
		}
		else
		{
			arr[c]=right[b];
			c++;b++;
		}
	}
	while(a<LEFT_SIZE)
	{
		arr[c]=left[a];
		c++;a++;

	}
	while(b<RIGHT_SIZE)
	{
		arr[c]=right[b];
		c++;b++;
	} 
	/*printf("\n arr=");
	for(int i=0;i<N;i++)
	printf("%d ",arr[i]);*/
	puts("");
	puts("");
}
