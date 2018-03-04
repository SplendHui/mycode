/*
题目描述 Description

Yours和zero在研究A*启发式算法.拿到一道经典的A*问题,但是他们不会做,请你帮他们.
问题描述

在3×3的棋盘上，摆有八个棋子，每个棋子上标有1至8的某一数字。棋盘中留有一个空格，空格用0来表示。空格周围的棋子可以移到空格中。要求解的问题是：给出一种初始布局（初始状态）和目标布局（为了使题目简单,设目标状态为123804765），找到一种最少步骤的移动方法，实现从初始布局到目标布局的转变。
输入描述 Input Description

输入初试状态，一行九个数字，空格用0表示
输出描述 Output Description

只有一行，该行只有一个数字，表示从初始状态到目标状态需要的最少移动次数(测试数据中无特殊无法到达目标状态数据)
样例输入 Sample Input

283104765
样例输出 Sample Output

4
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int finl[3][3] = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
int s;
struct node
{
    int map[3][3], stp;
    node(int stp = 0) :stp(stp) { memset(map, 0, sizeof(map)); }
    node(int stp = 0, int now = 0) :stp(stp)
    {
        for(int i = 2; i >= 0; --i) for(int j = 2; j >= 0; --j)
        {
            map[i][j] = now % 10;
            now /= 10;
        }
    }
    bool operator < (const node& b) const
    {
        int t = 0, tb = 0;
        for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j)
        {
            t += (map[i][j] != finl[i][j]);
            tb += (b.map[i][j] != finl[i][j]);
        }
        return t + stp > tb + b.stp;
    }
};
bool check(node& b)
{
    bool f = true;
    for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j)
    {
        if(b.map[i][j] != finl[i][j])
        {
            f = false;
            break;
        }
    }
    return f;
}
void work()
{
    priority_queue <node> Q;
    Q.push(node(0, s));
    while(!Q.empty())
    {
        node t = Q.top();
        if(check(t))
        {
            printf("%d\n", t.stp);
            return;
        }
        Q.pop();
        int x = 0, y = 0;
        for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j)
        {
            if(t.map[i][j] == 0)
            {
                x = i; y = j;
                break;
            }
        }
        for(int i = 0; i < 4; ++i)
        {
            int u = x + dx[i], v = y + dy[i];
            if(u >= 0 && v >= 0 && u < 3 && v < 3)
            {
                swap(t.map[x][y], t.map[u][v]);
                ++t.stp;
                Q.push(t);
                --t.stp;
                swap(t.map[x][y], t.map[u][v]);
            }
        }
    }
}
int main()
{
    scanf("%d", &s);
    work();
    return 0;
}