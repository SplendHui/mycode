#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
char map[1005][1005];
int times[1005][1005];
int dir[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
int n, r, c;
const int INF = 0x3f3f3f3f;
struct node {
	int x, y;
	int times;
};
queue<node> Q_fire;
bool check(const node &q)
{
	if (q.x >= 0
		&& q.x < r
		&& q.y >= 0
		&& q.y < c
		&& (map[q.x][q.y] == 'J' || map[q.x][q.y] == '.')
		&& times[q.x][q.y] == INF)
		return true;
	return  false;
}
void BFS_fire() {
	node p, q;
	while (!Q_fire.empty()) {
		p = Q_fire.front();
		Q_fire.pop();
		for (int i = 0; i < 4; i++) {
			q.x = p.x + dir[i][0];
			q.y = p.y + dir[i][1];
			q.times = p.times + 1;
			if (check(q))
			{
				times[q.x][q.y] = q.times;
				Q_fire.push(q);
			}
		}
	}
}

void BFS_J(int ex, int ey) {
	queue<node> Q;
	node p, q;
	p.x = ex, p.y = ey;
	p.times = 0;
	Q.push(p);
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) 
		{
			q.x = p.x + dir[i][0];
			q.y = p.y + dir[i][1];
			q.times = p.times + 1;
			if (q.x < 0 || q.x >= r || q.y < 0 || q.y >= c) 
			{
				cout << q.times << endl;
				return;
			}
			if (q.x < 0 || q.y < 0 || q.x >= r || q.y >= c)
				continue;
			if (map[q.x][q.y] == '.' && q.times < times[q.x][q.y])
			{
				times[q.x][q.y] = q.times;
				Q.push(q);
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}

int main() {
	int i, j;
	int jx, jy;
	freopen("t.in", "r", stdin);
	cin >> n;
	while (n--) {
		cin >> r >> c;
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				times[i][j] = INF;
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'J') 
				{
					jx = i;
					jy = j;
				}
				else if (map[i][j] == 'F')
				{
					node t;
					t.x = i, t.y = j;
					times[i][j] = t.times = 0;
					Q_fire.push(t);
				}
			}
		BFS_fire();
		BFS_J(jx, jy);
	}
	return 0;
}
