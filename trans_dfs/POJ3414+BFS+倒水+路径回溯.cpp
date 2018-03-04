/*************************************************************************
    > File Name: F-pot.cpp
    > Author: splend
    > Mail: 752406912@qq.com 
    > Created Time: Sun 12 Feb 2017 09:57:38 AM
 ************************************************************************/

#include<iostream>
using namespace std;

struct node {
    int a, b;
    int step;
    int pre;
    int op;
} Q[1000];
int front = 0, rear = 1;
int vis[105][105];

void print(int p) {

    if (Q[p].pre == -1)
        return;
    print(Q[p].pre);
        switch (Q[p].op) {
            case 0:
                cout << "FILL(1)" << endl;
                break;
            case 1:
                cout << "FILL(2)" << endl;
                break;
            case 2:
                cout << "DROP(1)" << endl;
                break;
            case 3:
                cout << "DROP(2)" << endl;
                break;
            case 4:
                cout << "POUR(1,2)" << endl;
                break;
            case 5:
                cout << "POUR(2,1)" << endl;
                break;
        }
    }

void BFS(int a, int b, int c) {
    node p, q;
    p.a = p.b = p.step = 0;
    p.pre = p.op = -1;
    vis[0][0] = 1;
    Q[front] = p;
    while (front != rear) {
        p = Q[front];
        if (p.a == c || p.b == c) {
            cout << p.step << endl;
            print(front);
            return;
        }
        for (int i = 0; i < 6; i++) {
            switch (i) {
                case 0:
                {
                    q = p;
                    q.step++;
                    q.a = a; //fill(1);
                    q.op = 0;
                    q.pre = front;
                    if (!vis[q.a][q.b]) {
                        Q[rear++] = q;
                        vis[q.a][q.b] = 1;
                    }
                }
                    break;
                case 1:
                {
                    q = p;
                    q.step++;
                    q.b = b; //fill(2);
                    q.op = 1;
                    q.pre = front;
                    if (!vis[q.a][q.b]) {
                        Q[rear++] = q;
                        vis[q.a][q.b] = 1;
                    }
                }
                    break;
                case 2:
                {//drop(1);
                    q = p;
                    q.step++;
                    q.a = 0;
                    q.op = 2;
                    q.pre = front;
                    if (!vis[q.a][q.b]) {
                        Q[rear++] = q;
                        vis[q.a][q.b] = 1;
                    }
                }
                    break;
                case 3:
                {//drop(2);
                    q = p;
                    q.step++;
                    q.b = 0;
                    q.op = 3;
                    q.pre = front;
                    if (!vis[q.a][q.b]) {
                        Q[rear++] = q;
                        vis[q.a][q.b] = 1;
                    }
                }
                    break;
                case 4:
                {//pour(1,2)
                    q = p;
                    q.step++;
                    int temp = q.b;
                    q.b = ((q.a + q.b) > b) ? b : (q.a + q.b);
                    q.a = (q.a - (b - temp)) >= 0 ? (q.a - (b - temp)) : 0;
                    q.op = 4;
                    q.pre = front;
                    if (!vis[q.a][q.b]) {
                        Q[rear++] = q;
                        vis[q.a][q.b] = 1;
                    }
                }
                    break;
                case 5:
                {//pour(2,1);
                    q = p;
                    q.step++;
                    int temp = q.a;
                    q.a = ((q.a + q.b) > a) ? a : (q.a + q.b);
                    q.b = (q.b - (a - temp)) >= 0 ? (q.b - (a - temp)) : 0;
                    q.op = 5;
                    q.pre = front;
                    if (!vis[q.a][q.b]) {
                        Q[rear++] = q;
                        vis[q.a][q.b] = 1;
                    }
                }
                    break;
            }
        }
        front++;
    }
    cout << "impossible" << endl;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    BFS(a, b, c);
    return 0;
}
