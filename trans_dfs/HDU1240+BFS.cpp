//深度搜索
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

const int MAX = 11;
const int INF = INT_MAX	-3;
const int dirx[6]={1,-1,0,0,0,0},diry[6]={0,0,1,-1,0,0},dirz[6]={0,0,0,0,1,-1};

char map[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
int sx,sy,sz,dx,dy,dz;
int minx,n;

void dfs(int x,int y,int z,int cnt){
	if(x<0 || y<0 || z<0 || x>=n || y>=n || z>=n)return;
	if(map[z][x][y]=='X')return;
	if(x==dx && y==dy && z==dz){
		if(cnt<minx)minx = cnt;
		return;
	}
	if(dist[z][x][y]<=cnt)return;
	else dist[z][x][y] = cnt;
	int i,tx,ty,tz;
	for(i=0;i<6;++i){
		tx = x+dirx[i];
		ty = y+diry[i];
		tz = z+dirz[i];
		dfs(tx,ty,tz,cnt+1);
	}
}

int main(){
	//freopen("t.in","r",stdin);
	char str[10];
	int i,j,k,cnt;
	while(scanf("%s %d%*c",str,&n)!=EOF){
		for(k=0;k<n;++k){
			for(i=0;i<n;++i){
				for(j=0;j<n;++j){
					map[k][i][j]=getchar();
					dist[k][i][j]=INF;
				}
				getchar();
			}
		}
		scanf("%d %d %d",&sy,&sx,&sz);
		scanf("%d %d %d",&dy,&dx,&dz);
		scanf("%s",str);
		cnt = 0;
		minx = INT_MAX;
		dfs(sx,sy,sz,cnt);
		if(minx==INT_MAX){
			printf("NO ROUTE\n");
		}else{
			printf("%d %d\n",n,minx);
		}
	}
/*      //BFS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 11;
const int INF = INT_MAX	-3;
const int dirx[6]={1,-1,0,0,0,0},diry[6]={0,0,1,-1,0,0},dirz[6]={0,0,0,0,1,-1};

typedef struct Point{
	int x,y,z;
}Point;

char map[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
int sx,sy,sz,dx,dy,dz;
int minx,n;

Point pp;

queue<Point> que;

int bfs(int x,int y,int z){
	pp.x = x;
	pp.y = y;
	pp.z = z;
	que.push(pp);
	int i,tx,ty,tz;
	while(!que.empty()){
		pp = que.front();
		x = pp.x;
		y = pp.y;
		z = pp.z;
		que.pop();
		if(x==dx && y==dy && z==dz)break;
		for(i=0;i<6;++i){  
			tx = x+dirx[i];  
			ty = y+diry[i];  
			tz = z+dirz[i];
			if(tx<0 || ty<0 || tz<0 || tx>=n || ty>=n || tz>=n)continue;
			if(dist[tz][tx][ty]!=-1)continue;
			if(map[tz][tx][ty]=='X')continue;
			dist[tz][tx][ty] = dist[z][x][y]+1;
			pp.x = tx;
			pp.y = ty;
			pp.z = tz;
			que.push(pp);
		}
	}
	return dist[dz][dx][dy];
}

int main(){
	//freopen("in.txt","r",stdin);
	char str[10];
	int i,j,k;
	while(scanf("%s %d%*c",str,&n)!=EOF){
		for(k=0;k<n;++k){
			for(i=0;i<n;++i){
				for(j=0;j<n;++j){
					map[k][i][j]=getchar();
					dist[k][i][j] = -1;
				}
				getchar();
			}
		}
		scanf("%d %d %d",&sy,&sx,&sz);
		scanf("%d %d %d",&dy,&dx,&dz);
		scanf("%s",str);
		dist[sz][sx][sy] = 0;
		minx = bfs(sx,sy,sz);
		if(minx==-1){
			printf("NO ROUTE\n");
		}else{
			printf("%d %d\n",n,minx);
		}
		while(!que.empty()){
			que.pop();
		}
	}

		
    return 0;
}
*/
		
    return 0;
}

