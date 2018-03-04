/*
Description
��������һ���ܾ������Ϸ.������������һ���򵥰汾.��һ��M*N�ķ�������һ�����Ӻ�һ�����˹�,���˹��Ĺ������ǰ������Ƶ�ָ����λ��,ע��,���˹�ֻ�������Ӷ�����������,���������ӱ��Ƶ�һ������(��ͼ2)��ô���ӾͲ����ٱ��ƶ���,������ӱ��Ƶ�һ��ǽ��,��ô����ֻ������ǽ�ƶ�. 

���ڸ�������Ľṹ,���ӵ�λ��,���˹���λ�ú�����Ҫ����ȥ��λ��,�����������˹�����Ҫ�ƶ����Ӷ��ٸ�. 

 

Input
�������ݵĵ�һ����һ������T(1<=T<=20),����������ݵ�����.Ȼ����T���������,ÿ��������ݵĵ�һ��������������M,N(2<=M,N<=7),������Ĵ�С,Ȼ����һ��M��N�еľ���,������Ĳ���,����0����յĵذ�,1����ǽ,2�������ӵ���ʼλ��,3��������Ҫ����ȥ��λ��,4������˹�����ʼλ��. 
Output
����ÿ���������,������˹�������Ҫ�ƶ����Ӷ��ٸ���ܰ������Ƶ�ָ��λ��,��������Ƶ�ָ��λ�������-1. 
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
            v[box.x][box.y]=1;//���Ӳ�����Խ��
            a.box=box+dir[i];
            if(iudje(a.box)&&!vis[a.box.x][a.box.y][i])//�Ƿ���ǽ
                if(iudje(box-dir[i])&&people_find_box(people,box-dir[i]))//���Ƿ��ܵ���
                {
                    a.people=box;
                    a.step=step+1;
                    qu.push(a);
                    vis[a.box.x][a.box.y][i]=1;
                }
        }
    }
}

int people_find_box(node people,node box)//���������ӵ�λ��
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

bool iudje(node a)//�жϱ߽�
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

