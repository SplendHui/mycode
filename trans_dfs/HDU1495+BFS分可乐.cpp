#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define MAXN 101
int s, m, n;
int vis[101][101];
struct node
{
	int all, x, y, step;// x < y < s
};						// m < n < s
void BFS()
{
	memset(vis, 0, sizeof(vis));
	queue<node> Q;
	node p, q;
	p.all = s;
	p.x = p.y = p.step = 0;
	Q.push(p);
	vis[p.x][p.y] = 1;
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		if (p.all == p.y && p.all == s / 2)
		{
			cout << p.step << endl;
			return;
		}
		if (p.all + p.x > m)//s->m
		{
			q.x = m;
			q.y = p.y;
			q.all = p.all - (m - p.x);
			q.step = p.step + 1;
			if (!vis[q.x][q.y])
			{
				Q.push(q);
				vis[q.x][q.y] = 1;
			}
		}
		else
		{
			q.x = p.all + p.x;
			q.y = p.y;
			q.all = 0;
			q.step = p.step + 1;
			if (!vis[q.x][q.y])
			{
				Q.push(q);
				vis[q.x][q.y] = 1;
			}
		}
		if (p.all + p.y > n)                                //s돌n
		{
			q.x = p.x;
			q.y = n;
			q.all = p.all + p.y - n;
			q.step = p.step + 1;
			if (!vis[q.x][q.y])
			{
				Q.push(q);
				vis[q.x][q.y] = 1;
			}
		}
		else
		{
			q.x = p.x;
			q.y = p.all + p.y;
			q.all = 0;
			q.step = p.step + 1;
			if (!vis[q.x][q.y])
			{
				Q.push(q);
				vis[q.x][q.y] = 1;
			}
		}
		if (p.x + p.y > n)                                //m돌n
		{
			q.x = p.x + p.y - n;
			q.y = n;
			q.all = p.all;
			q.step = p.step + 1;
			if (!vis[q.x][q.y])
			{
				Q.push(q);
				vis[q.x][q.y] = 1;
			}
		}
		else
		{
			q.x = 0;
			q.y = p.x + p.y;
			q.all = p.all;
			q.step = p.step + 1;
			if (!vis[q.x][q.y])
			{
				Q.push(q);
				vis[q.x][q.y] = 1;
			}
		}
		q.all = p.all + p.x;
		q.x = 0;
		q.y = p.y;
		q.step = p.step + 1; //m돌s
		if (!vis[q.x][q.y])
		{
			Q.push(q);
			vis[q.x][q.y] = 1;
		}
		if (p.x + p.y > m)
		{
			q.y = p.y + p.x - m; q.x = m;
			q.all = p.all;
			q.step = p.step + 1;//n돌m
			if (!vis[q.x][q.y])
			{
				Q.push(q);
				vis[q.x][q.y] = 1;
			}
		}
		else
		{
			q.x = p.x + p.y;
			q.y = 0;
			q.all = p.all;
			q.step = p.step + 1;
			if (!vis[q.x][q.y])
			{
				Q.push(q);
				vis[q.x][q.y] = 1;
			}
		}
		q.all = p.all + p.y;
		q.x = p.x;
		q.y = 0;
		q.step = p.step + 1; //n돌s
		if (!vis[q.x][q.y])
		{
			Q.push(q);
			vis[q.x][q.y] = 1;
		}
	}
	cout << "NO" << endl;
}
int main()
{
	while (cin >> s >> m >> n &&  (s + m + n))
	{
		if (s % 2)
		{
			cout << "NO" << endl;
			continue;
		}
		if (m > n) swap(m, n);
		BFS();
	}
	return 1;
}