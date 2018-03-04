#include <iostream>
#include <cstring>
using namespace std;
char str[100][100];
int vis[100], n, k, count;

void DFS(int r, int num) {
    if (num == k) {
        count++;
        return;
    }
    if (r > n)
        return;
    for (int i = 0; i < n; i++) {
        if (!vis[i] && str[r][i] == '#') {
            vis[i] = 1;
            DFS(r + 1, num + 1);
            vis[i] = 0;
        }
    }
    DFS(r + 1, num);
}

int main() {
    while (cin >> n >> k) {
        count = 0;
        if (n == -1 && k == -1)
            break;
        for (int i = 0; i < n; i++) {
            cin >> str[i];
        }
        DFS(0, 0);
        cout << count << endl;
    }
    return 0;
}
