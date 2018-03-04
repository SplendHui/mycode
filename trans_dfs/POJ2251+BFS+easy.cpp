#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct node {
	int x, y, z, step;
};
int bx, by, bz;
int L, R, C;
char map[50][50][50];
int vis[50][50][50];
int dir[6][3] = {
	{0, 0, 1},
	{0, 0, -1},
	{0, -1, 0},
	{0, 1, 0},
	{-1, 0, 0},
	{1, 0, 0}
};

int check(const node &t) {
	if (t.x < 0
		|| t.x >= R
		|| t.y < 0
		|| t.y >= C
		|| t.z < 0
		|| t.z >= L)
		return 1;
	if (vis[t.x][t.y][t.z])
		return 1;
	return 0;
}

void BFS(int x, int y, int z) {
	queue<node> Q;
	node p, q;
	p.x = x, p.y = y, p.z = z, p.step = 0;
	Q.push(p);
	memset(vis, 0, sizeof(vis));
	vis[x][y][z] = 1;
	while (!Q.empty()) {
		p = Q.front();
		Q.pop();
		if (map[p.z][p.x][p.y] == 'E') {
			cout << "Escaped in " << p.step << " minute(s)." << endl;
			return;
		}
		for (int i = 0; i < 6; i++) {
			q.x = p.x + dir[i][0];
			q.y = p.y + dir[i][1];
			q.z = p.z + dir[i][2];
			q.step = p.step + 1;
			if (!check(q) && map[q.z][q.x][q.y] != '#') {
				Q.push(q);
				vis[q.x][q.y][q.z] = 1;
			}
		}

	}
	cout << "Trapped!" << endl;
	return;
}

int main() {
	char s[10];
	int i, j, k;
//	freopen("t.in", "r", stdin);
	while (scanf("%d%d%d", &L, &R, &C) == 3 && (L+R+C)) {
		memset(map, ' ', sizeof(map));
		for (k = 0; k < L; k++) {
			for (i = 0; i < R; i++) {
				for (j = 0; j < C; j++) {
					scanf(" %c", &map[k][i][j]);
					if (map[k][i][j] == 'S')
						bx = i, by = j, bz = k;
				}
			}
		}
		BFS(bx, by, bz);
	}
	return 0;
}
