#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
int map[51][51][51];
int vis[51][51][51];
int A, B, C, T;
struct Dir
{
	int x, y, z;
}dir[6] = { {0,0,-1}, {0,0,1}, {0,-1,0}, {0,1,0}, {-1,0,0}, {1,0,0} };//上下、左右、前后
struct node
{
	int x, y, z;
	int step;
};
int Check(node &t)
{
	if ((t.x < 0 || t.x >= A || t.y < 0 || t.y >= B || t.z < 0 || t.z >= C) || map[t.x][t.y][t.z])
		return 0;
	return 1;
}
int Time_out(node &t)
{
	int min_T = abs(t.x - (A - 1)) + abs(t.y - (B - 1)) + abs(t.z - (C - 1));
	if (min_T + t.step > T)
		return 1;
	return 0;
}
int BFS(int bx, int by, int bz)
{
	node p, q;
	queue<node> Q;
	p.x = bx, p.y = by, p.z = bz, p.step = 0;
	Q.push(p);
	vis[p.x][p.y][p.z] = 1;
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		if (p.x == A - 1 && p.y == B - 1 && p.z == C - 1)
		{
			if (p.step <= T)
				return p.step;
		}
		for (int i = 0; i < 6; i++)
		{
			q.x = p.x + dir[i].x;
			q.y = p.y + dir[i].y;
			q.z = p.z + dir[i].z;
			q.step = p.step + 1;
			if (Check(q) && !vis[q.x][q.y][q.z])
			{
				vis[q.x][q.y][q.z] = 1;
				if (Time_out(q)) continue;
				Q.push(q);
			}
		}
	}
	return -1;
}
int main() {
	int n;
	freopen("t.in","r",stdin);
	scanf("%d", &n);
	while (n--)
	{
		memset(vis, 0, sizeof(vis));
		memset(map, 0, sizeof(map));
		scanf("%d%d%d%d", &A, &B, &C, &T);
		for (int i = 0; i < A; i++)
			for (int j = 0; j < B; j++)
				for (int k = 0; k < C; k++)
					scanf("%d", &map[i][j][k]);
		cout << BFS(0, 0, 0) << endl;
	}
	return 1;
}
