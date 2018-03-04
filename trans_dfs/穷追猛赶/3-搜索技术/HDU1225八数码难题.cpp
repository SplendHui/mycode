/*
��Ŀ���� Description

Yours��zero���о�A*����ʽ�㷨.�õ�һ�������A*����,�������ǲ�����,���������.
��������

��3��3�������ϣ����а˸����ӣ�ÿ�������ϱ���1��8��ĳһ���֡�����������һ���ո񣬿ո���0����ʾ���ո���Χ�����ӿ����Ƶ��ո��С�Ҫ���������ǣ�����һ�ֳ�ʼ���֣���ʼ״̬����Ŀ�겼�֣�Ϊ��ʹ��Ŀ��,��Ŀ��״̬Ϊ123804765�����ҵ�һ�����ٲ�����ƶ�������ʵ�ִӳ�ʼ���ֵ�Ŀ�겼�ֵ�ת�䡣
�������� Input Description

�������״̬��һ�оŸ����֣��ո���0��ʾ
������� Output Description

ֻ��һ�У�����ֻ��һ�����֣���ʾ�ӳ�ʼ״̬��Ŀ��״̬��Ҫ�������ƶ�����(�����������������޷�����Ŀ��״̬����)
�������� Sample Input

283104765
������� Sample Output

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