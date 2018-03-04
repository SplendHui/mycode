/*  这个会超时。
#include<iostream>
using namespace std;
int n, k;
int map[100][100], dp[100][100];
struct Dir
{
	int row, col;
}dir[4] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
int DFS(int x, int y)
{
	int max, t;
	max = t = 0;
		for (int i = 1; i <= k; i++)
			for (int j = 0; j < 4; j++)
			{
				int xx = x + i * dir[j].row;
				int yy = y + i * dir[j].col;
				if (xx >= 0 && xx < n && yy >= 0 && yy < n && map[xx][yy] > map[x][y])
				{
					t = DFS(xx, yy);
					max = t > max ? t : max;
				}
			}
	return map[x][y] + max;
}
int main() {
	freopen("t.in", "r", stdin); 
	while (cin >> n >> k, (n+1))
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];
		cout << DFS(0, 0) << endl;
	}
	return 1;
}
*/
#include<iostream>
using namespace std;
int n, k;
int map[100][100], dp[100][100];
struct Dir
{
	int row, col;
}dir[4] = { {0,1},{ 0,-1 },{ 1,0 },{ -1,0 } };
int DFS(int x, int y)
{
	int max, t;
	max = t = 0;
	if (!dp[x][y])
	{
		for (int i = 1; i <= k; i++)
			for (int j = 0; j < 4; j++)
			{
				int xx = x + i * dir[j].row;
				int yy = y + i * dir[j].col;
				if (xx >= 0 && xx < n && yy >= 0 && yy < n && map[xx][yy] > map[x][y])
				{
					t = DFS(xx, yy);
					max = t > max ? t : max;
				}
			}
		dp[x][y] = map[x][y] + max;
	}
	return dp[x][y];
}
int main() {
	freopen("t.in", "r", stdin); 
	while (cin >> n >> k, (n + 1))
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];
		cout << DFS(0, 0) << endl;
	}
	return 1;
}
