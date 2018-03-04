/*************************************************************************
    > File Name: HDU1548+Dijkstra+BFS.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Mon 06 Feb 2017 03:33:24 PM
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF = 0x7ffffff;
int map[100][100];
int dist[100];
int vis[100];
int a[100];
int n;

void Dijkstra(int x, int y) {
    int min, i, j, pos;
    memset(vis, 0, sizeof (vis));
    for (i = 0; i < n; i++)
        dist[i] = map[x][i];
    dist[x] = 0;
    vis[x] = 1;
    for (i = 1; i < n; i++) {
        min = INF;
        for (j = 0; j < n; j++)
            if (!vis[j] && dist[j] < min) {
                min = dist[j];
                pos = j;
            }
        vis[pos] = 1;
        if (min == INF)
            break;
        for (j = 0; j < n; j++)
            if (!vis[j] && dist[pos] + map[pos][j] < dist[j])
                dist[j] = dist[pos] + map[pos][j];
    }
}

int main() {
    int i, j, s, e;
    while (cin >> n, n) {
        scanf("%d%d", &s, &e);
        s--, e--;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                map[i][j] = INF;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            if (i + a[i] < n)
                map[i][i + a[i]] = 1;
            if (i - a[i] >= 0)
                map[i][i - a[i]] = 1;

        }
        Dijkstra(s, e);
        printf("%d\n", dist[e] == INF ? -1 : dist[e]);
    }
    return 0;
}
/*
 #include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

int n,s,e;
int ss[205],vis[205];

struct node
{
    int x,step;
};

int check(int x)
{
    if(x<=0 || x>n)
    return 1;
    return 0;
}

int BFS()
{
    queue<node> Q;
    node a,next;
    int i;
    a.x = s;
    a.step = 0;
    vis[s] = 1;
    Q.push(a);
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        if(a.x == e)
        return a.step;
        for(i = -1;i<=1;i+=2)
        {
            next = a;
            next.x +=i*ss[next.x];
            if(check(next.x) || vis[next.x])
            continue;
            vis[next.x] = 1;
            next.step++;
            Q.push(next);
        }
    }
    return -1;
}

int main()
{
    int i,j;
    while(~scanf("%d",&n),n)
    {
        scanf("%d%d",&s,&e);
        for(i = 1;i<=n;i++)
        scanf("%d",&ss[i]);
        memset(vis,0,sizeof(vis));
        printf("%d\n",BFS());
    }

    return 0;
}

 
 */

