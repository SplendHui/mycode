#include<iostream>
using namespace std;
int n, m, q;
int map[1001][1001];
int dp[1001][1001];
int Be_x, Be_y, Target_x, Target_y;
int flag;
struct Dir
{
	int row, col;
}dir[4] = { {0,-1}, {0,1}, {1,0}, {-1,0} };
int Check(int x, int y, int step)//能走返回1，不能返回0；
{
	if (x < 1 || x > n || y < 1 || y > m || step > 2)
		return 0;
	return 1;
}
void DFS(int x, int y, int to, int step)
{
	if (flag) return;
	if (!Check(x, y, step))
		return;
	if (x == Target_x && y == Target_y)//找到了。
	{
		flag = 1;
		return;
	}
	if (map[x][y] != 0) return;//既然不是终点，又不是0肯定不能走；
	if (dp[x][y] != -1 && dp[x][y] <= step) return;//既然之前的点走过，而且转折数又比较小，那就不要重复走了。
	dp[x][y] = step;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dir[i].row;
		int yy = y + dir[i].col;
		if (i != to)
			DFS(xx, yy, i, step + 1);
		else
			DFS(xx, yy, i, step);
	}
}
int main()
{
	freopen("t.in", "r", stdin);
	while (cin >> n >> m, (n + m))
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> map[i][j];
		cin >> q;
		while (q--)
		{
			flag = 0;
			memset(dp, -1, sizeof(dp));
			cin >> Be_x >> Be_y >> Target_x >> Target_y;
			if (map[Be_x][Be_y] == 0 || map[Be_x][Be_y] != map[Target_x][Target_y])
			{
				cout << "No" << endl;
				continue;
			}
			dp[Be_x][Be_y] = 0;
			for (int i = 0; i < 4; i++)
			{
				int xx = Be_x + dir[i].row;
				int yy = Be_y + dir[i].col;
				DFS(xx, yy, i, 0);
			}
			if (flag)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 1;
