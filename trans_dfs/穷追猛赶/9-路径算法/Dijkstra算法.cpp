const int  MAXINT = 32767;
const int MAXNUM = 10;
int dist[MAXNUM];
int prev[MAXNUM];
int A[MAXUNM][MAXNUM];

void Dijkstra(int v0)
{
  　　bool S[MAXNUM];                                  // 判断是否已存入该点到S集合中
      int n=MAXNUM;
  　　for(int i=1; i<=n; ++i)
 　　 {
      　　dist[i] = A[v0][i];
      　　S[i] = false;                                // 初始都未用过该点
      　　if(dist[i] == MAXINT)    
            　　prev[i] = -1;
 　　     else 
            　　prev[i] = v0;
   　　}
   　 dist[v0] = 0;
   　 S[v0] = true; 　　
 　　 for(int i=2; i<=n; i++)
 　　 {
       　　int mindist = MAXINT;
       　　int u = v0; 　　                            // 找出当前未使用的点j的dist[j]最小值
      　　 for(int j=1; j<=n; ++j)
      　　    if((!S[j]) && dist[j]<mindist)
      　　    {
         　　       u = j;                             // u保存当前邻接点中距离最小的点的号码 
         　 　      mindist = dist[j];
       　　   }
       　　S[u] = true; 
       　　for(int j=1; j<=n; j++)
       　　    if((!S[j]) && A[u][j]<MAXINT)
       　　    {
           　    　if(dist[u] + A[u][j] < dist[j])     //在通过新加入的u点路径找到离v0点更短的路径  
           　    　{
                   　　dist[j] = dist[u] + A[u][j];    //更新dist 
                   　　prev[j] = u;                    //记录前驱顶点 
            　　    }
        　    　}
   　　}
}
#include<stdio.h>
const int INF=10001;
const int Num=10;
int dist[INF];
int prev[Num];
int graph[Num][Num];
int prim(int v0)
{
	bool S[Num];
	int n = Num;
	for(int i = 1;i <= n; i++)
	{	dist[i] = graph[v0][i];
		S[i] = flase;
		if(dist[i] < INF )
			prev[i] = -1;
		else
			prev[i] = vo;
	}
	S[vo] = true;
	dist[v0] = 0;
		for(int i = 1;i < n; i++)
		{
			int mindist = INF;
			int u = v0;
			for(int j = 1; j <= n; j++)
				if( dist[j] < mindist )
				{
					u = j;
					mindist = dist[j];
				}
			S[u] = true;
			for(int j = 1; j <=n; j++ )
				if( !S[j] && graph[u][j] < INF )
				
				{	
					if(graph[u][j]+dist[u] < dist[j])
					{
						dist[j] = dist[u] + graph[u][j]; 
						prev[j] = u; 
					}
				
				}
		}
}
				
			

			
			
			
			
			
			
			
			
			
			
			
			
			
		}
	
	
	
	
	
	
}
