#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
#define maxn 10
#define INF 0xfffffff
#define min(a,b) (a<b?a:b)
struct Point
{
	int x, y;//人的坐标
	int nx, ny;//箱子的坐标
	int step;
} Ps;
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int maps[maxn][maxn];
int vis[maxn][maxn][maxn][maxn];//人的坐标，，，箱子的坐标
int m, n;

bool OK(Point P)
{
	return P.x >= 0 && P.x < m && P.y >= 0 && P.y < n  && maps[P.x][P.y] != 1 && P.step < vis[P.x][P.y][P.nx][P.ny];
}

bool OK2(Point P)
{
	return P.nx >= 0 && P.nx < m && P.ny >= 0 && P.ny < n && maps[P.nx][P.ny] != 1 && P.step < vis[P.x][P.y][P.nx][P.ny];
}
void init()
{
	for(int i=0; i<maxn; i++)
		for(int j=0; j<maxn; j++)
			for(int k=0; k<maxn; k++)
				for(int p=0; p<maxn; p++)
					vis[i][j][k][p] = INF;
}
int BFS()
{
	Point P, Pn;
	queue<Point> Q;
	Q.push(Ps);
	int ans = INF;

	vis[Ps.x][Ps.y][Ps.nx][Ps.ny] = true;

	while( !Q.empty() )
	{
		P = Q.front();
		Q.pop();

		if(maps[P.nx][P.ny] == 3)
		{
			ans = min(ans,P.step);
		}

		for(int i=0; i<4; i++)
		{
			Pn = P;//人向前走一步
			Pn.x +=  dir[i][0];
			Pn.y +=  dir[i][1];
			if( OK(Pn) )//判断人走一步是否合法
			{
				if( Pn.x == Pn.nx && Pn.y == Pn.ny)//如果人和箱子重合则箱子向前进一步
				{
					Pn.nx += dir[i][0];
					Pn.ny += dir[i][1];
					Pn.step ++;
					if( OK2(Pn))//判断箱子前进是否合法
					{
						vis[Pn.x][Pn.y][Pn.nx][Pn.ny] = Pn.step;
						Q.push(Pn);
					}
				}
				else
				{
					vis[Pn.x][Pn.y][Pn.nx][Pn.ny] = Pn.step;
					Q.push(Pn);
				}
			}
		}
	}
	return ans;
}

int main()
{
	int T, k;
	scanf("%d",&T);

	while(T--)
	{
		init();//对VIS进行初始化

		scanf("%d%d",&m,&n);

		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				scanf("%d",&maps[i][j]);
				if(maps[i][j] == 4)
					Ps.x = i, Ps.y = j, Ps.step = 0;
				else if(maps[i][j] == 2)
					Ps.nx = i, Ps.ny = j;
			}
		}
		k = BFS();
		if(k == INF)
			k = -1;
		printf("%d\n", k);
	}
	return 0;
}
