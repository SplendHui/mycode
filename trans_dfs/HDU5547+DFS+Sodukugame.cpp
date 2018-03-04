#include<iostream>
#include<cstring>
using namespace std;
int map[4][4];
int flag;
int check(int x, int y, int k)
{
	int i;
	for (i = 0;i < 4;i++)
	{
		if (map[x][i] == k || map[i][y] == k)
			return 1;
	}
	if (x / 2 == 0 && y / 2 == 0)
	{
		if (map[0][0] == k || map[0][1] == k || map[1][0] == k || map[1][1] == k)
			return 1;
	}
	else if (x / 2 == 0 && y / 2)
	{
		if (map[0][2] == k || map[0][3] == k || map[1][2] == k || map[1][3] == k)
			return 1;
	}
	else if (x / 2 && y / 2 == 0)
	{
		if (map[2][0] == k || map[2][1] == k || map[3][0] == k || map[3][1] == k)
			return 1;
	}
	else if (x / 2 && y / 2)
	{
		if (map[2][2] == k || map[2][3] == k || map[3][2] == k || map[3][3] == k)
			return 1;
	}
	return 0;
}
void DFS(int k)
{
	int i, j;
	if (flag) return;
	if (k == 4 * 4)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
				cout << map[i][j];
			cout << endl;
		}
		flag = 1;
		return;
	}
	if (map[k / 4][k % 4] != -1)//²»ÓÃÌî£»
		DFS(k + 1);
	else
	{
		for (i = 1; i <= 4 && !flag; i++)
		{
			if (!check(k / 4, k % 4, i))
			{ 
				map[k / 4][k % 4] = i;
				DFS(k + 1);
				map[k / 4][k % 4] = -1;
			}
		}
	}
}
int main()
{
	char c;
	int T, i, j, cas = 0;
	freopen("t.in", "r", stdin);
	cin >> T;
	while (T--)
	{
		flag = 0;
		cas++;
		memset(map, -1, sizeof(map));
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
			{
				cin >> c;
				if (c == '*')
					map[i][j] = -1;
				else
					map[i][j] = c - '0';
			}
		cout << "Case #" << cas << ":" << endl;
		DFS(0);
	}
	return 0;
}