#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
int map[100005];
int vis[100005][3][3];
#define INF 0x3f3f3f3f
struct Node {
	int s[5];
	int op2, op3;
	int step;
} init = { {1, 2, 3, 4, 5}, 3, 2, 0 };

int arrayTonumber(Node a) {
	int sum = 0;
	for (int i = 0; i < 5; i++) 
		sum = sum * 10 + a.s[i];
	return sum;
}

void Init() {
	int i, t;
	memset(vis, INF, sizeof(vis));
	t = arrayTonumber(init);
	memset(map, -1, sizeof(map));
	queue<Node>Q;
	Q.push(init);
	map[t] = 0;
	while (!Q.empty())
	{
		Node p = Q.front();
		Q.pop();
		for (i = 1; i <= 4; i++) {
			Node q = p;
			swap(q.s[i], q.s[i - 1]);
			t = arrayTonumber(q);
			q.step++;
			if (map[t] == -1 || q.step < vis[t][q.op2][q.op3])
			{
				if (q.step < map[t] || map[t] == -1)
					map[t] = q.step;
				vis[t][q.op2][q.op3] = q.step;
				Q.push(q);
			}
		}
		if (p.op2 > 0)
		{
			for (i = 0; i < 5; i++)
			{
				Node q = p;
				q.op2--;
				q.s[i] = (q.s[i] + 1) % 10;
				t = arrayTonumber(q);
				q.step++;
				if (map[t] == -1 || q.step < vis[t][q.op2][q.op3])
				{
					if (q.step < map[t] || map[t] == -1)
						map[t] = q.step;
					vis[t][q.op2][q.op3] = q.step;
					Q.push(q);
				}
			}
		}
		if (p.op3 > 0)
		{
			for (i = 0; i < 5; i++)
			{
				Node q = p;
				q.op3--;
				q.step++;
				q.s[i] = (q.s[i] * 2) % 10;
				t = arrayTonumber(q);
				if (map[t] == -1 || q.step < vis[t][q.op2][q.op3])
				{
					if(q.step < map[t] || map[t] == -1)
						map[t] = q.step;
					vis[t][q.op2][q.op3] = q.step;
					Q.push(q);
				}
			}
		}
	}
}

int main()
{
	int n;
	Init();
	while (scanf("%d", &n) != EOF)
		printf("%d\n", map[n]);
	return 0;
}

