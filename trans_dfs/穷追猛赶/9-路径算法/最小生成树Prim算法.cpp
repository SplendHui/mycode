#defineMAXN 1000
#define INF 1<<30
int closest[MAXN],lowcost[MAXN],m;	//mΪ�ڵ�ĸ���
int G[MAXN][MAXN];					//�ڽӾ���
int prim()
{
	for(int i = 0;i < m; i++)
	{
		lowcost[i] = INF;
	}
	for(int i = 0; i < m; i++)
	{
		closest[i]=0;
	}
	closest[0] = -1;					//�����һ���㣬-1��ʾ�õ��ڼ���U�У������ڼ���V��
	int num = 0,Sum = 0,e = 0;				//eΪ���¼��뼯�ϵĵ�
	while(num < m-1)					//����m-1����
	{
		int micost = INF,miedge = -1;
		for(int i = 0; i < m; i++)
		if(closest[i] != -1)
		{
			int temp = G[e][i];
			if(temp < lowcost[i])
			{
				lowcost[i] = temp;
				closest[i] = e;
			}
			if(lowcost[i] < micost)
			micost = lowcost[miedge=i];
		}
		Sum += micost;
		closest[e=miedge] = -1;
		num++;
	}
	return Sum;
}
#include <stdio.h>
#include <string.h>
#define MaxInt 0x3f3f3f3f
#define N 110
//����map��ά���鴢��ͼ��low�����¼ÿ2�������СȨֵ��visited������ĳ���Ƿ��ѷ���
int map[N][N],low[N],visited[N];
int n;
 
int prim()
{
	int i,j,pos,min,result=0;
	memset(visited,0,sizeof(visited));
	//��ĳ�㿪ʼ���ֱ��Ǻͼ�¼�õ�
	visited[1]=1;pos=1;
	//��һ�θ�low���鸳ֵ
	for(i=1;i<=n;i++)
	if(i != pos)
		low[i]=map[pos][i];
	//������n-1��
	for(i = 1; i < n; i++)
	{
		//�ҳ���СȨֵ����¼λ��
		min=MaxInt;
		for(j=1;j<=n;j++)
		if(visited[j] == 0 && min > low[j])
		{
			min=low[j];
			pos=j;
		}										//��СȨֵ�ۼ�
		result += min;									//��Ǹõ�
		visited[pos] = 1;							//����Ȩֵ
		for(j = 1; j <= n; j++)
		if(visited[j] == 0 && low[j] > map[pos][j] )
		low[j] = map[pos][j];
	}
	return result;
}

int main()
{
	int i,v,j,ans;
	while(scanf("%d",&n)!=EOF)
	{
		//����Ȩֵ��ʼ��Ϊ���
		memset(map,MaxInt,sizeof(map));
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&v);
			map[i][j]=map[i][j]=v;
		}
		ans=prim();
		printf("%d\n",ans);
	}
	return 0;
}
int prim(){
	int i;
	for( i = 0; i < n; i++ )
		lowcost[i]=INF;
	for( i = 0; i < n; i++ )
		closest[i] = 0;
	num = 0, Sum, visited[0] = -1;e = 0; 
	while( num < n-1 )
	{
		int micost = INF;
		for(i = 1; i < n; i++ )
		{
			if( visited[i] != -1 )
			{
				temp = G[e][i];
				if( temp < lowcost[i] )
				{
					lowcost[i] = temp;
					closest[i] = e;
 					
				}
				if( lowcost[i] < micost )
					micost = lowcost[miedge=i];
				
			}			
		}
		Sum += micost;
		closest[e=miedge] = -1;
		num++;
		
		
	}
}