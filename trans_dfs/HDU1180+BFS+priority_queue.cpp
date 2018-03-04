#include<iostream>
#include<queue>
using namespace std;
char map[25][25];
int vis[25][25];
int n, m;
int bx, by, ex, ey;
struct node
{
	int x, y;
	int step;
	friend bool operator < (const node &a, const node &b)
	{
		return a.step > b.step;
	}
};
struct Dir
{
	int row, col;
}dir[4] = { {0,-1},{ 0,1 },{ -1,0 },{ 1,0 } };
int Check(int x, int y)
{
	if (x >= 0 && y >= 0 && x < n && y < m && map[x][y] != '*' && !vis[x][y])
		return 1;
	return 0;
}
int BFS()
{
	char stair;
	priority_queue<node> Q;
	node now_p, next_p;
	now_p.x = bx;
	now_p.y = by;
	now_p.step = 0;
	vis[now_p.x][now_p.y] = 1;
	Q.push(now_p);
	while (!Q.empty())
	{
		now_p = Q.top();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			next_p.x = now_p.x + dir[i].row;
			next_p.y = now_p.y + dir[i].col;
			next_p.step = now_p.step + 1;
			if (Check(next_p.x, next_p.y))
			{
				if (map[next_p.x][next_p.y] == '-' || map[next_p.x][next_p.y] == '|')
				{
					if (next_p.step % 2 == 1)
					{
						if (map[next_p.x][next_p.y] == '-')
							stair = '|';
						else
							stair = '-';
					}
					else
						stair = map[next_p.x][next_p.y];
					if (stair == '-' && (i == 2 || i == 3) || stair == '|' && (i == 0 || i == 1))//butongxiang
						next_p.step += 1;
						next_p.x = next_p.x + dir[i].row;
						next_p.y = next_p.y + dir[i].col;
				}
				if (Check(next_p.x, next_p.y))
				{
					if (next_p.x == ex && next_p.y == ey)
						return next_p.step;
					vis[next_p.x][next_p.y] = 1;
					Q.push(next_p);
				}
			}

		}
	}
	return -1;
}
int main()
{

	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'S')
					bx = i, by = j;
				else if (map[i][j] == 'T')
					ex = i, ey = j;
			}
		cout << BFS() << endl;
	}
	return 1;
}