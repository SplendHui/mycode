/*************************************************************************
    > File Name: L.cpp
    > Author: splend
    > Mail: 752406912@qq.com 
    > Created Time: Thu 09 Feb 2017 07:15:35 PM
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

struct node {
    int x, y, step;
};
char map[202][202];
int vis[202][202];
int target[4002][2];
int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};
int n, m;
int Yx, Yy, Mx, My;

int check(node &t) {
    if (t.x < 0 || t.y < 0 || t.x >= n || t.y >= m)
        return 1;
    return 0;
}

int check1(int x, int y) {
    int dx = abs(x - Yx);
    int dy = abs(y - Yy);
    int dx1 = abs(x - Mx);
    int dy1 = abs(y - My);
    int total = dx + dy + dx1 + dy1;
    return total;
}

int BFS(int x, int y, int ex, int ey) {
    memset(vis, 0, sizeof (vis));
    queue<node> Q;
    node p, q;
    p.x = x, p.y = y;
    p.step = 0;
    Q.push(p);
    vis[x][y] = 1;
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        if (p.x == ex && p.y == ey)
            return p.step;
        for (int i = 0; i < 4; i++) {
            q.x = p.x + dir[i][0];
            q.y = p.y + dir[i][1];
            q.step = p.step + 1;
            if (!check(q) && !vis[q.x][q.y] && map[q.x][q.y] != '#') {
                Q.push(q);
                vis[q.x][q.y] = 1;
            }
        }
    }
    return 0;
}

int main() {
    int i, j;
    int t1, t2, ans, total;
    //    freopen("t.in", "r", stdin);
    while (cin >> n >> m) {
        int cnt = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++) {
                cin >> map[i][j];
                if (map[i][j] == 'Y')
                    Yx = i, Yy = j;
                else if (map[i][j] == 'M')
                    Mx = i, My = j;
                else if (map[i][j] == '@') {
                    target[cnt][0] = i;
                    target[cnt][1] = j;
                    cnt++;
                }
            }
        total = 0x3fffffff;
        for (i = 0; i < cnt; i++)
            if (check1(target[i][0], target[i][1]) < total) {
                t1 = BFS(target[i][0], target[i][1], Yx, Yy);
                t2 = BFS(target[i][0], target[i][1], Mx, My);
                ans = t1 + t2;
                if (ans < total)
                    total = ans;
            }
        cout << total * 11 << endl;
    }
    return 0;
}
