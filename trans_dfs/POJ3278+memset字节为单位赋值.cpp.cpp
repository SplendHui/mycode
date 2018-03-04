/*************************************************************************
    > File Name: A-CatchThatCow.cpp
    > Author: splend
    > Mail: 752406912@qq.com 
    > Created Time: Sat 11 Feb 2017 10:24:51 AM
 ************************************************************************/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n, m;
int times[100005];

struct node {
    int x, step;
};

bool check(node &t)
{
    if(t.x < 0 || t.x > 100000 || t.step > times[t.x])
        return true;
    return false;
}
int BFS(int x, int y) {
    memset(times,0x3f, sizeof(times));
    node p, q;
    queue<node> Q;
    p.x = x, p.step = 0;
    Q.push(p);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        if(p.x == y)
            return p.step;
        for(int i = 0; i < 3; i++)
        {
            if(i == 0)
            {
                q = p;
                q.x--;
                q.step++;
            }
            else if (i == 1)
            {
                q = p;
                q.x++;
                q.step++;
            }
            else if (i == 2)
            {
                q = p;
                q.x = q.x * 2;
                q.step++;
            }
            if(q.x == y)
                return q.step;
             if(!check(q))
             {
                 Q.push(q);
                 times[q.x] = q.step;
             }
        }
    }
}

int main() {
    cin >> n >> m;
        cout << BFS(n, m) << endl;
    return 0;
}
