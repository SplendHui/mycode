#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
	int x, y;
	int step;
	friend bool operator<(const node &a,const node &b)
	{
		return a.step > b.step;
	}
};
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
char map[303][303];
int vis[303][303];
int n, m;
int bx, by, ex, ey;
int BFS()
{
	priority_queue<node>Q;
	node p, q;
	p.x = bx, p.y = by;
	p.step = 0;
	Q.push(p);
	while (!Q.empty())
	{
		p = Q.top();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			q.x = p.x + dir[i][0];
			q.y = p.y + dir[i][1];
			q.step = p.step + 1;
			if (map[q.x][q.y] == 'T')
				return q.step;
			else if (map[q.x][q.y] == 'B' && !vis[q.x][q.y])
			{
				q.step += 1;
				Q.push(q);
				vis[q.x][q.y] = 1;
			}
			else if (map[q.x][q.y] == 'E' && !vis[q.x][q.y])
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
	int i, j;
//	freopen("t.in", "r", stdin);
	while (cin >> n >> m && n || m)
	{
		memset(vis, 0, sizeof(vis));
		memset(map, 0, sizeof(map));
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'Y')
					bx = i, by = j;
				else if (map[i][j] == 'T')
					ex = i, ey = j;
			}
		cout << BFS() << endl;
	}
	return 0;
}