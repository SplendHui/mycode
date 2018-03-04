#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
char map[102][102];
int visted[102][102];
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
int r, c;
struct node
{
	int x, y;
	int time;
	friend bool operator<(node n1, node n2)
	{
		return n2.time < n1.time;
	}
};
struct Pre
{
	int x, y;
}pre[102][102];
void BFS(int ex, int ey)
{
	int i;
	priority_queue<node> Q;
	node now_p, next_p;
	now_p.x = ex, now_p.y = ey;
	now_p.time = 0;
	visted[ex][ey] = 1;
	pre[ex][ey].x = -1;//÷’µ„±Íº«
	if (map[ex][ey] != '.')
		now_p.time = map[ex][ey] - '0';
	Q.push(now_p);
	while (!Q.empty())
	{
		now_p = Q.top();
		Q.pop();
		if (now_p.x == 0 && now_p.y == 0)
		{
			cout << "It takes " << now_p.time << " seconds to reach the target position, let me show you the way." << endl;
			int xx = 0, yy = 0;
			int time = 1;
			while (pre[xx][yy].x != -1)
			{
				int tx = pre[xx][yy].x;
				int ty = pre[xx][yy].y;
				cout << time << "s" << "(" << xx << "," << yy << ")" << "->" << "(" << tx << "," << ty << ")" << endl;
				time++;
				if (map[tx][ty] != '.')
					for (i = 0; i < map[tx][ty] - '0'; i++)
					{
						cout << time << "s:FIGHT AT " << "(" << tx << "," << ty << ")" << endl;
						time++;
					}
				xx = tx, yy = ty;
			}
			return ;
		}
		for (i = 0; i < 4; i++)
		{
			next_p.x = now_p.x + dir[i][0];
			next_p.y = now_p.y + dir[i][1];
			if (   next_p.x < 0
				|| next_p.x >= r
				|| next_p.y < 0
				|| next_p.y >= c
				|| map[next_p.x][next_p.y] == 'X'
				|| visted[next_p.x][next_p.y] == 1
				)
				continue;
			if (map[next_p.x][next_p.y] == '.')
				next_p.time = now_p.time + 1;
			else
				next_p.time = now_p.time + map[next_p.x][next_p.y] - '0' + 1 ;
			pre[next_p.x][next_p.y].x = now_p.x;
			pre[next_p.x][next_p.y].y = now_p.y;
			visted[next_p.x][next_p.y] = 1;
			Q.push(next_p);
		}
	}
	cout << "God please help our poor hero." << endl;
}
int main() {
	int i, j;
	freopen("t.in","r",stdin);
	while (cin >> r >> c)
	{
		memset(visted, 0, sizeof(visted));
		int flag = 0;
		for(i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				cin >> map[i][j];
		BFS(r-1, c-1);

		cout << "FINISH" << endl;
	}
	return 1;
}
