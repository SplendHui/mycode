//DFS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
const int maxn = 105;
char mat[maxn][maxn];
int dir[8][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1},
    {1, 1},
    {-1, 1},
    {1, -1},
    {-1, -1}};
int m, n;
int sum;

void Dfs(int x, int y) {
    int tx;
    int ty;
    for (int i = 0; i < 8; i++) {
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        if (1 <= tx && tx <= m && 1 <= ty && ty <= n) {
            if (mat[tx][ty] == '@') {
                mat[tx][ty] = '*';
                Dfs(tx, ty);
            }
        }
    }
}

int main() {
    while (scanf("%d%d", &m, &n)) {
        if (m == 0 && n == 0) {
            break;
        }
       
        sum = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> mat[i][j];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (mat[i][j] == '@') {
                    sum++;
                    mat[i][j] = '*';
                    Dfs(i, j); 
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
/*             //BFS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>


using namespace std;
const int maxn=105;
char mat[maxn][maxn];
int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
int  m,n;
int sum;
struct Node{
    int x;
    int y;
};
void Bfs(int x,int y){
    queue <Node> q;
    Node node;
    node.x=x;
    node.y=y;
    q.push(node);
    while(!q.empty()){
        Node cur=q.front();
        Node next;
        q.pop();
        for(int i=0;i<8;i++){
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            if(mat[next.x][next.y]=='@'){
                mat[next.x][next.y]='*';
                q.push(next);
            }
        }
    }
}
int main()
{
    while(scanf("%d %d",&m,&n)){
        if(m==0&&n==0){
            break;
        }
        memset(mat,0,sizeof(mat));
        sum=0;
        int cur=1;
        for(int i=1;i<=m;i++){
            //for(int j=1;j<=n;j++){
                scanf("%s",mat[i]+1);//因为第二维也都是从1开始到n，所以+1开始
                //cin>>mat[i][j];
                //scanf("%c",&mat[i][j]);
            //}
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(mat[i][j]=='@'){
                    sum++;
                    mat[i][j]='*';
                    Bfs(i,j); //广搜，消除同一连通块的所有油田标记
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}*/

