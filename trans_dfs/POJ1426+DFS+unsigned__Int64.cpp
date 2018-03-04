/*************************************************************************
    > File Name: C-FindTheMultiple.cpp
    > Author: splend
    > Mail: 752406912@qq.com 
    > Created Time: Sat 11 Feb 2017 01:52:10 PM
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
bool found;
void DFS(unsigned __int64 t, int n, int k) {
    if (found) return; 
    if (t % n == 0) {
        printf("%I64u\n", t);
        found = true;
        return;
    }
    if (k == 19)
        return;
    DFS(t * 10, n, k + 1); 
    DFS(t * 10 + 1, n, k + 1);
}

int main() {
    int n;
    while (cin >> n, n) {
        found = false; 
        DFS(1, n, 0); 
    }
    return 0;
}
//
/*
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct node {
    string s;
    int mod;
};

void BFS(int n) {
    queue<node> Q;
    node p, q;
    p.s = "1";
    p.mod = 1 % n;
    Q.push(p);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        if (p.mod == 0) {
            cout << p.s << endl;
            return;
        }
        
        q = p;
        q.s += "1";
        q.mod = (q.mod * 10 + 1) % n;
        Q.push(q);

        q = p;
        q.s += "0";
        q.mod = (q.mod * 10) % n;
        Q.push(q);
    }
}

int main() {
    int n;
    while (cin >> n, n)
        BFS(n);
    return 0;
}
 */