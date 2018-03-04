#include <iostream>
using namespace std;
#define inf 0x3fffffff
#define M 105
//1、wan用于转弯数剪枝；2、step用于步数剪枝，就不用vis标记访问了
int r, c, ex, ey, k, wan[M][M];
char map[M][M];
int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, 1, 0, -1 };
bool flag;

void dfs(int x, int y, int dir)	//dir为当前方向
{
	if (x == ex && y == ey)
	{
		if (wan[x][y] <= k)
			flag = true;
		return;
	}
	if (wan[x][y] > k)	//转弯数超过k不用往下走了
		return;
	//x !=ex && y != ey 说明必须至少再转一次弯，但是已经不能再转了
	if (wan[x][y] == k && x != ex && y != ey)
		return;
	for (int i = 0; i < 4; i++)
	{
		int tx = x + x_move[i];
		int ty = y + y_move[i];
		if (tx < 0 || tx >= r || ty < 0 || ty >= c)
			continue;
		//转弯数相等不可剪掉，所以是wan[tx][ty] < wan[x][y]而不是wan[tx][ty] <= wan[x][y]
		if (map[tx][ty] == '*' || wan[tx][ty] < wan[x][y])	//转弯数剪枝
			continue;
		if (dir != -1 && i != dir && wan[tx][ty] < wan[x][y] + 1)	//转弯数剪枝
			continue;
		wan[tx][ty] = wan[x][y];
		if (dir != -1 && i != dir)
			wan[tx][ty]++;	//如果方向变了转弯+1
		dfs(tx, ty, i);
		if (flag)
			return;
	}
}

int main()
{
	int t, i, j, sx, sy;	//sx， sy是起点
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &r, &c);
		for (i = 0; i < r; i++)
			scanf("%s", map[i]);
		scanf("%d%d%d%d%d", &k, &sy, &sx, &ey, &ex);
		sx--, sy--, ex--, ey--;	
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				wan[i][j] = inf;	//初始化转弯数和步数为无穷大
		wan[sx][sy] = 0;	//到达起点的转弯数
		flag = false;
		dfs(sx, sy, -1);	//一开始可以走任意方向，所以设方向为-1
		if (flag)
			puts("yes");
		else puts("no");
	}
	return 0;
}
