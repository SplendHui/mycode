/*************************************************************************
    > File Name: POJ3984+典型通过队列回溯.cpp
    > Author: splend
    > Mail: 752406912@qq.com 
    > Created Time: Thu 09 Feb 2017 09:34:03 PM
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
int map[5][5];
int vis[5][5];

struct node {
    int x;
    int y;
    int pre;
} Node[100];
int front = 0, rear = 1;
int dir[4][2] = {
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0}
};

void Print(int i) {
    if (Node[i].pre != -1) {
        Print(Node[i].pre);
        cout << "(" << Node[i].x << ", " << Node[i].y << ")" << endl;
    }
}

void BFS(int x, int y) {
    Node[front].x = x;
    Node[front].y = y;
    Node[front].pre = -1;
    while (front < rear) {
        for (int i = 0; i < 4; i++) {
            int x = Node[front].x + dir[i][0];
            int y = Node[front].y + dir[i][1];
            if (x < 0 || x >= 5 || y < 0 || y >= 5 || vis[x][y] == 1 || map[x][y] == 1)
                continue;
            else {
                vis[x][y] = 1;
                map[x][y] = 1;
                Node[rear].x = x;
                Node[rear].y = y;
                Node[rear].pre = front;
                rear++;
            }
            if (x == 4 && y == 4)
                Print(front);
        }
        front++;
    }
}

int main() {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cin >> map[i][j];
        }
    }
    memset(vis, 0, sizeof (vis));
    cout << "(0, 0)" << endl;
    BFS(0, 0);
    cout << "(4, 4)" << endl;
    return 0;
}
