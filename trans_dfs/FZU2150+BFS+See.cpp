#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
int n, m, ans;
bool vis[15][15];
char grid[15][15];
int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

struct node {
    int x, y, times;
};
vector <node>grass;

bool check(int x, int y) {
    if (!vis[x][y] && grid[x][y] == '#' && x >= 0 && x < n && y >= 0 && y < m)
        return true;
    else
        return false;
}

bool judge() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#' && !vis[i][j])
                return false;
        }
    }
    return true;
}

void init() {
    grass.clear();
    memset(vis, false, sizeof (vis));
    ans = inf;
}

void readData() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                node t;
                t.x = i, t.y = j;
                t.times = 0;
                grass.push_back(t);
            }
        }
}

int BFS(node n1, node n2) {
    memset(vis, 0, sizeof (vis));
    queue<node> Q;
    node p, q;
    Q.push(n1);
    Q.push(n2);
    int tt;
    vis[n1.x][n1.y] = 1;
    vis[n2.x][n2.y] = 1;
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        tt = p.times;
        for (int i = 0; i < 4; i++) {
            q.x = p.x + dir[i][0];
            q.y = p.y + dir[i][1];
            q.times = p.times + 1;
            if (check(q.x, q.y)) {
                Q.push(q);
                vis[q.x][q.y] = 1;
            }
        }
    }
    return tt;
}

void solve() {
    for (int i = 0; i < grass.size(); ++i) {
        for (int j = i; j < grass.size(); ++j) {
            grass[i].times = 0;
            grass[j].times = 0;
            int temp = min(BFS(grass[i], grass[j]), ans);
            if (judge())
                ans = min(ans, temp);
        }
    }
}

int main() {
    //freopen("t.in","r",stdin);
    int t, cas = 0;
    scanf("%d", &t);
    while (t--) {
        init();
        readData();
        solve();
        printf("Case %d: ", ++cas);
        if (ans == inf)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
