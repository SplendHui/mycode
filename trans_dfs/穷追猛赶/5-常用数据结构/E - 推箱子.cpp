/*
Description
推箱子是一个很经典的游戏.今天我们来玩一个简单版本.在一个M*N的房间里有一个箱子和一个搬运工,搬运工的工作就是把箱子推到指定的位置,注意,搬运工只能推箱子而不能拉箱子,因此如果箱子被推到一个角上(如图2)那么箱子就不能再被移动了,如果箱子被推到一面墙上,那么箱子只能沿着墙移动. 

现在给定房间的结构,箱子的位置,搬运工的位置和箱子要被推去的位置,请你计算出搬运工至少要推动箱子多少格. 

 

Input
输入数据的第一行是一个整数T(1<=T<=20),代表测试数据的数量.然后是T组测试数据,每组测试数据的第一行是两个正整数M,N(2<=M,N<=7),代表房间的大小,然后是一个M行N列的矩阵,代表房间的布局,其中0代表空的地板,1代表墙,2代表箱子的起始位置,3代表箱子要被推去的位置,4代表搬运工的起始位置. 
Output
对于每组测试数据,输出搬运工最少需要推动箱子多少格才能帮箱子推到指定位置,如果不能推到指定位置则输出-1. 
Sample Input
1
5 5
0 3 0 0 0
1 0 1 4 0
0 0 1 0 0
1 0 2 0 0
0 0 0 0 0
Sample Output
4
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include <fstream>
#include <limits>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cassert>

#define maxn 10

using namespace std;
bool vis[maxn][maxn][4];
bool v[maxn][maxn];
int flag;
int m,n;
int t[maxn][maxn];

struct node
{
    int x,y;
    bool operator ==(node a)const
    {
        if(x==a.x&&y==a.y)
            return 1;
        return 0;
    }
    node operator + (node a)const
    {
        a.x=x+a.x;
        a.y=y+a.y;
        return a;
    }
    node operator - (node a)const
    {
        a.x=x-a.x;
        a.y=y-a.y;
        return a;
    }
} bourn,box,people,dir[4]= {0,1,1,0,0,-1,-1,0};

struct qu_node
{
    node box,people;
    int step;
};

void initial();
void putin();
void solve();
void putout();
bool iudje(node);
int people_find_box(node ,node);

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        initial();
        putin();
        solve();
         putout();
    }
    return 0;
}

void putout()
{
    printf("%d\n",flag);
}
void putin()
{
    scanf("%d %d",&m,&n);
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            scanf("%d",&t[i][j]);
            if(t[i][j]==2)//box
            {
                box.x=i;
                box.y=j;
            }
            else if(t[i][j]==3)//bourn
            {
                bourn.x=i;
                bourn.y=j;
            }
            else if(t[i][j]==4)//people
            {
                people.x=i;
                people.y=j;
            }
        }
}
void solve()
{
    queue<qu_node>qu;
    qu_node a;
    while(!qu.empty())
        qu.pop();
    a.box=box;
    a.people=people;
    a.step=0;
    qu.push(a);
    while(!qu.empty())
    {
        a=qu.front();//cout<<a.box.x<<a.box.y<<endl;
        qu.pop();
        box=a.box;
        people=a.people;
        int step=a.step;
        if(box==bourn)
        {
            flag=step;
            return ;
        }
        for(int i=0; i<4; i++)
        {
            memset(v,0,sizeof(v));
            v[box.x][box.y]=1;//箱子不可以越过
            a.box=box+dir[i];
            if(iudje(a.box)&&!vis[a.box.x][a.box.y][i])//是否有墙
                if(iudje(box-dir[i])&&people_find_box(people,box-dir[i]))//人是否能到达
                {
                    a.people=box;
                    a.step=step+1;
                    qu.push(a);
                    vis[a.box.x][a.box.y][i]=1;
                }
        }
    }
}

int people_find_box(node people,node box)//人找推箱子的位置
{//cout<<'\t'<<people.x<<people.y<<'\t'<<box.x<<box.y<<endl;
    //cout<<'!';
    node a=people;
    if(people==box)return 1;
    for(int i=0; i<4; i++)
    {
        people=a+dir[i];
        if(!iudje(people)||v[people.x][people.y])continue;
        //if(people.x==3&&people.y==1)printf("!\n");
        if(box==people)
            return 1;
        else
        {
            v[people.x][people.y]=1;
            if(people_find_box(people,box))
            return 1;
        }
    }
    return 0;
}

bool iudje(node a)//判断边界
{
    int x=a.x,y=a.y;
    if(x>=0&&x<m&&y>=0&&y<n)
        if(t[x][y]!=1)
            return 1;
    return 0;
}

void initial()
{
    memset(vis,0,sizeof(vis));
    memset(v,0,sizeof(v));
    flag=-1;
}

