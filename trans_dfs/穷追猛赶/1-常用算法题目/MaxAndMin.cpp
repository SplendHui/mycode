#include <stdio.h>
#define N 1000
int x[N];
void pd(int r1,int r2, int &maxx,int &minn)
{
	int max1,min1,max2,min2,d;
	//************************************************
	max1=x[1];
	min1=x[1];
	for(d=2;d<r2;d++)
	{
		if(x[d]>max1)
			max1=x[d];
		if(x[d]<min1)
			min1=x[d];

	}
		maxx=max1;
		minn=min1;

	//*******************************************
}
int main()
{ 
	int max=0,min=0,n,i;
//	freopen("MaxAndMin.in","r",stdin);
//	freopen("MaxAndMin.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]);
  pd(1,n,max,min);
	printf("%d\n",max);
	printf("%d",min);
	return 0;
}