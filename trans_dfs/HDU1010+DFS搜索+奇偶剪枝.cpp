/*************************************************************************
    > File Name: HDU1010DFS+奇偶剪枝.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 26 Jan 2017 04:54:06 PM
 ************************************************************************/

#include<iostream>
using namespace std;
int ex, ey, flag;
int N, M, T; 
char map[10][10];
struct Dir{ 
    int row, col; 
}dir[4] = {{0,1},{0,-1},{-1,0},{1,0}};
int abs(int p)
{
	return p >= 0 ? p : -p;
}
int Judge(int bx, int by) 
{ if(bx < 0 || bx >= N || by < 0 || by >= M) 
        return 0; 
    return 1; 
} 
void DFS(int bx, int by, int k) 
{   if(bx == ex && by == ey) 
    {   if(k == T) 
            flag = 1; 
        return ; 
    }    
    int mindist = abs(ex-bx) + abs(ey-by); 
    if( (T-k+mindist) % 2 != 0 || (T-k) < mindist ) 
        return ;
    int i;
    for(i = 0; i < 4; i++)
    {   
        int x = bx + dir[i].row;// notice  x should be declared;
		int y = by + dir[i].col;
		if(map[x][y] != 'X' && Judge(x,y))
		{
            map[x][y] = 'X';
            DFS(x, y, k+1);
            map[x][y] = '.';
		}
    }
}
int main()
{
	int X = 0;
	int bx, by;
	int i, j;
	while(cin >> N >> M >> T, (N+M+T))
	{
		X = flag = 0;
		for(i = 0; i < N; i++)
			for(j = 0; j < M; j++)
			{
				cin >> map[i][j];
				if(map[i][j] == 'S')
				{
					bx = i;
					by = j;
				}
				else if(map[i][j] == 'D')
				{
					ex = i;
					ey = j;
				}
				else if(map[i][j] == 'X')
					X++;
			}
		if(N*M - X <= T || (abs(ex-bx)+abs(ey-by)+T)%2 != 0)
		{
			cout << "NO" << endl;
			continue;
		}
		map[bx][by] = 'X';
		DFS(bx, by, 0);
		if(flag)
			cout << "Yes" << endl;
		else
			cout << "NO" << endl;
	}
	return 1;
}
