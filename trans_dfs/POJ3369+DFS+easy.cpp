/*************************************************************************
    > File Name: E.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 09 Feb 2017 10:17:41 AM
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int map[400][400];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int vis[400][400];
const int INF = 0x3fffff;
struct node
{
	int x, y, step;
};
void dealData(int x, int y, int t)
{
	int i;
	if(t < map[x][y])
		map[x][y] = t;
	for(i = 0; i < 4; i++)
	{
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if(xx >= 0 && yy >= 0)
		{
			if(map[xx][yy] > t)
				map[xx][yy] = t;
		}
	}
}
int BFS()
{
	queue<node> Q;
	node p, q;
	int i, j;
	p.x = p.y = 0;
	p.step = 0;
	memset(vis,0,sizeof(vis)); 
	vis[0][0] = 1;
	Q.push(p);
	while(!Q.empty())
	{
		p = Q.front();
		Q.pop();
		if(map[p.x][p.y] == INF)
			return p.step;
		for(i = 0; i < 4; i++)
		{
			q.x = p.x + dir[i][0];
			q.y = p.y + dir[i][1];
			q.step = p.step + 1;
			if(q.x >= 0 && q.y >= 0 && !vis[q.x][q.y] && map[q.x][q.y] > q.step )
			{
				Q.push(q);
				vis[q.x][q.y] = 1;
			}
		}
		
	}
	return -1;
}
int main()
{
	int i, j, t;
	int n, k;
	for(i = 0; i < 310; i++)
		for(j = 0; j < 310; j++)
			map[i][j] = INF;
	while(scanf("%d",&n) == 1)
	{
		for(k = 0; k < n; k++)
		{
			scanf("%d%d%d",&i, &j, &t);
			dealData(i, j, t);
		}
		printf("%d\n",BFS());
	}
	return 0;
}
