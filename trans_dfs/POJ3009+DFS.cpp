#include<stdio.h>  
int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
int ex, ey;
int map[25][25];
int w, h, steps, cnt;
#define MAX 11 
void dfs(int bx, int by)
{
	int i, px, py;
	if (steps >= 10) return;

	for (i = 0;i < 4;i++)
	{
		px = bx, py = by;
		while (1)
		{
			px += dir[i][0];
			py += dir[i][1];
			if (px <= 0 || px > h || py <= 0 || py > w) break;//如果越界，选择其他方向  
			if (px == ex && py == ey)
			{
				steps++;
				if (cnt > steps) cnt = steps;
				steps--;
				return;
			}
			else if (map[px][py] == 1)//如果遇到障碍物  
			{

				if (px - dir[i][0] != bx || py - dir[i][1] != by)//如果不是起点 
				{
					map[px][py] = 0;//消除障碍物  
					steps++;//前进一步  
					dfs(px - dir[i][0], py - dir[i][1]);//递归查找该点到终点的最小步数  
					map[px][py] = 1;//还原障碍物  
					steps--;//还原步数  
				}
				break;
			}
		}
	}
}
int main()
{
	int bx, by, i, j;
	freopen("t.in", "r", stdin);
	while (scanf("%d%d", &w, &h) == 2 && (w || h))
	{
		for (i = 1;i <= h; i++)//输入并找到起点和终点  
			for (j = 1;j <= w; j++)
			{
				scanf("%d", &map[i][j]);
				if (map[i][j] == 2)
					bx = i, by = j;
				else if (map[i][j] == 3)
					ex = i, ey = j;
			}
		cnt = MAX;//记录最小步数  
		steps = 0;//初始化步数  
		dfs(bx, by);//深搜  
		if (cnt == MAX)
			printf("-1\n");
		else
			printf("%d\n", cnt);
	}
	return 0;
}