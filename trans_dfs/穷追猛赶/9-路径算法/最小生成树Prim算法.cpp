#defineMAXN 1000
#define INF 1<<30
int closest[MAXN],lowcost[MAXN],m;	//m为节点的个数
int G[MAXN][MAXN];					//邻接矩阵
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
	closest[0] = -1;					//加入第一个点，-1表示该点在集合U中，否则在集合V中
	int num = 0,Sum = 0,e = 0;				//e为最新加入集合的点
	while(num < m-1)					//加入m-1条边
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
//创建map二维数组储存图表，low数组记录每2个点间最小权值，visited数组标记某点是否已访问
int map[N][N],low[N],visited[N];
int n;
 
int prim()
{
	int i,j,pos,min,result=0;
	memset(visited,0,sizeof(visited));
	//从某点开始，分别标记和记录该点
	visited[1]=1;pos=1;
	//第一次给low数组赋值
	for(i=1;i<=n;i++)
	if(i != pos)
		low[i]=map[pos][i];
	//再运行n-1次
	for(i = 1; i < n; i++)
	{
		//找出最小权值并记录位置
		min=MaxInt;
		for(j=1;j<=n;j++)
		if(visited[j] == 0 && min > low[j])
		{
			min=low[j];
			pos=j;
		}										//最小权值累加
		result += min;									//标记该点
		visited[pos] = 1;							//更新权值
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
		//所有权值初始化为最大
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