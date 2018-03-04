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
			if (px <= 0 || px > h || py <= 0 || py > w) break;//���Խ�磬ѡ����������  
			if (px == ex && py == ey)
			{
				steps++;
				if (cnt > steps) cnt = steps;
				steps--;
				return;
			}
			else if (map[px][py] == 1)//��������ϰ���  
			{

				if (px - dir[i][0] != bx || py - dir[i][1] != by)//���������� 
				{
					map[px][py] = 0;//�����ϰ���  
					steps++;//ǰ��һ��  
					dfs(px - dir[i][0], py - dir[i][1]);//�ݹ���Ҹõ㵽�յ����С����  
					map[px][py] = 1;//��ԭ�ϰ���  
					steps--;//��ԭ����  
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
		for (i = 1;i <= h; i++)//���벢�ҵ������յ�  
			for (j = 1;j <= w; j++)
			{
				scanf("%d", &map[i][j]);
				if (map[i][j] == 2)
					bx = i, by = j;
				else if (map[i][j] == 3)
					ex = i, ey = j;
			}
		cnt = MAX;//��¼��С����  
		steps = 0;//��ʼ������  
		dfs(bx, by);//����  
		if (cnt == MAX)
			printf("-1\n");
		else
			printf("%d\n", cnt);
	}
	return 0;
}