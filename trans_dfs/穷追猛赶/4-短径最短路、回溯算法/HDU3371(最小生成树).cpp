/*
In 2100, since the sea level rise, most of the cities disappear. Though some survived cities are still connected with others, but most of them become disconnected. The government wants to build some roads to connect all of these cities again, but they don’t want to take too much money.  
 

Input
The first line contains the number of test cases.
Each test case starts with three integers: n, m and k. n (3 <= n <=500) stands for the number of survived cities, m (0 <= m <= 25000) stands for the number of roads you can choose to connect the cities and k (0 <= k <= 100) stands for the number of still connected cities.
To make it easy, the cities are signed from 1 to n.
Then follow m lines, each contains three integers p, q and c (0 <= c <= 1000), means it takes c to connect p and q.
Then follow k lines, each line starts with an integer t (2 <= t <= n) stands for the number of this connected cities. Then t integers follow stands for the id of these cities.
 

Output
For each case, output the least money you need to take, if it’s impossible, just output -1.
 

Sample Input

1
6 4 3
1 4 2
2 6 1
2 3 5
3 4 33
2 1 2
2 1 3
3 4 5 6 

 

Sample Output

1

题意：某地发洪水，导致某些城市被淹而消失，现在想把剩下的零散的城市通过修路连接起来，已知现在有部分城市是连通的。可选择修的路有m条，城市总共有n个，给出了m条路的起点终点和修路花费，问最少可花多少钱能保证所有的城市连通。明显的克鲁斯卡尔。把边权排序然后并查集添加边即可。
*/
    #include <cstdio>  
    #include <cstring>  
    #include <cstdlib>  
    #include <cmath>  
    #include <queue>  
    #include <climits>  
      
    using namespace std;  
      
    const int MAX = 25003;  
      
    typedef struct Road{  
        int x;  
        int y;  
        int c;  
    }Road;  
      
    Road road[MAX];  
    int cr;  
      
    int pre[501];  
      
    void init(int n){  
        int i;  
        for(i=1;i<=n;++i){  
            pre[i] = i;  
        }  
        cr = n-1;  
    }  
      
    int root(int x){  
        if(x!=pre[x]){  
            pre[x] = root(pre[x]);  
        }  
        return pre[x];  
    }  
      
    int merge(int x,int y){  
        if(x==-1)return 0;  
        int ret = 0;  
        int fx = root(x);  
        int fy = root(y);  
        if(fx!=fy){  
            --cr;  
            pre[fx] = fy;  
            ret = 1;  
        }  
        return ret;  
    }  
      
    int cmp(const void *a,const void *b){  
        return ((Road *)a)->c - ((Road *)b)->c;  
    }  
      
    int main(){  
        //freopen("in.txt","r",stdin);  
        //freopen("out.txt","w",stdout);  
        int t,n,m,k,cid,tc,pre;  
        int sum,i,j;  
        scanf("%d",&t);  
        while(t--){  
            scanf("%d %d %d",&n,&m,&k);  
            init(n);  
            for(i=0;i<m;++i){  
                scanf("%d %d %d",&road[i].x,&road[i].y,&road[i].c);  
            }  
            sum = 0;  
            for(i=0;i<k;++i){  
                scanf("%d",&tc);  
                pre = -1;  
                for(j=0;j<tc;++j){  
                    scanf("%d",&cid);  
                    merge(pre,cid);  
                    pre = cid;  
                }  
            }  
            qsort(road,m,sizeof(Road),cmp);  
            for(i=0;i<m;++i){  
                if(merge(road[i].x,road[i].y)==1){  
                    sum += road[i].c;  
                }  
            }  
            if(cr!=0){  
                printf("-1\n");  
            }else{  
                printf("%d\n",sum);  
            }  
        }  
        return 0;  
    }  