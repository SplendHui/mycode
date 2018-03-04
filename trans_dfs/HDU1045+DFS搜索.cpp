#include<stdio.h>
int cnt, n;
char map[5][5];
void DFS(int,int);
int Judge(int);
int main(){
	int i;
	freopen("t.in","r",stdin);
	while(scanf("%d", &n), n)
	{
		for(i = 0; i < n; i++)
			scanf("%s",map[i]);
		cnt = 0; 
		DFS(0, 0);
		printf("%d\n", cnt);
	}
	return 1;
}
void DFS(int x,int count)
{
	if(x == n*n) 
	{
		if(count > cnt) 
			cnt = count;
		return ;
	}
	if( map[x/n][x%n] == '.' && Judge(x) )
	{
		map[x/n][x%n] = '@';
		DFS(x+1, count+1);
		map[x/n][x%n] = '.';
	}
	DFS(x+1, count);
}
int Judge(int x)
{
	int i, j;
	for(j = x % n; j >= 0; j--) //左边
	{
		if(map[x/n][j] == 'X') break;
		if(map[x/n][j] == '@') return 0;
	}
	
	for(j = x % n; j < n; j++) //右边；
	{
		if(map[x/n][j] == '@') return 0;
		if(map[x/n][j] == 'X') break;
	}
	
	for(i = x / n; i >= 0; i--) //向上
	{
		if(map[i][x%n] == 'X') break;
		if(map[i][x%n] == '@') return 0;
	}
	
	for(i = x / n; i < n; i++) //向下；
	{
		if(map[i][x%n] == '@') return 0;
		if(map[i][x%n] == 'X') break;
	}
	
	return 1;
}

/*
input; 
4
.X..
....
XX..
....
2
XX
.X
3
.X.
X.X
.X.
3
...
.XX
.XX
4
....
....
....
....
0
output;

5
1
5
2
4
*/
/*
#include <iostream>
using namespace std;
const int MAX = 6;
int point[4][2] = {-1,0,0,-1,1,0,0,1};
int n;
char map[MAX][MAX];
int max1;
int judge(int mid_x,int mid_y)
{
    int i;
    int mark = 1;
    for(i=0;i<4;i++)
    {
        int x,y;
        x = mid_x;
        y = mid_y;
        while(1)
        {
            x = x + point[i][0];
            y = y + point[i][1];
            if( map[x][y] == '@')
            {
                mark = 0;
                break;
            }
            else
            {
                if(map[x][y] == 'X')
                {
                    break;
                }
                else
                {
                    if(x<1 || y<1 || x>n || y>n)
                    {
                        break;
                    }
                }
            }
        }
    }
    return mark;
}

void DFS(int rank)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(map[i][j] == '.' && judge(i,j))
            {
                map[i][j] = '@';
                DFS(rank+1);
                map[i][j] = '.';
            }
        }
    }
    if(max1 < rank)
    {
        max1 = rank;
    }
    return ;
}
int main()
{
    while(cin>>n,n)
    {
        memset(map,0,sizeof(map));
        int i,j;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>map[i][j];
            }
        }
        max1 = 0;
        DFS(0);
        cout<<max1<<endl;
    }
    return 0;
}
*/