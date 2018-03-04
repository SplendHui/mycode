/*************************************************************************
    > File Name: POJ3126+BFS+PrimePath.cpp
    > Author: splend
    > Mail: 752406912@qq.com 
    > Created Time: Sat 11 Feb 2017 11:14:11 AM
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int prime[10005];
int visted[10005];
int a, b;

struct node {
    int s[4];
    int step;
};

void init() {
    int i, j;
    memset(prime, 1, sizeof (prime));
    for (i = 2; i < 10002; i++)
        for (j = 2 * i; j < 10002; j += i)
            prime[j] = 0;
}

int charToNumber(node &t) {
    int sum = 0;
    for (int i = 0; i < 4; i++)
        sum = sum * 10 + t.s[i];
    return sum;
}

void BFS(int x, int y) {
    queue<node> Q;
    memset(visted, 0, sizeof (visted));
    visted[x] = 1;
    int i;
    node p, q;
    for (i = 3; i >= 0; i--) {
        p.s[i] = x % 10;
        x = x / 10;
    }
    p.step = 0;
    Q.push(p);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        if (charToNumber(p) == y) {

            cout << p.step << endl;
            return;
        }
        for (i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 0 && j == 0)
                    continue;
                if (i == 3 && j % 2 == 0)
                    continue;
                q = p;
                q.s[i] = j;
                q.step++;
                int t = charToNumber(q);
                if (prime[t] && !visted[t]) {
                    Q.push(q);
                    visted[t] = 1;
                }
            }
        }
    }
    cout << "Impossible" << endl;
}

int main() {
    int cas;
    init();
    cin >> cas;
    while (cas--) {
        cin >> a >> b;
        BFS(a, b);
    }
    return 0;
}
