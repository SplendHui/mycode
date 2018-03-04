/*
Description
省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。现得到城镇道路统计表，表中列出了任意两城镇间修建道路的费用，以及该道路是否已经修通的状态。现请你编写程序，计算出全省畅通需要的最低成本。
 

Input
测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( 1< N < 100 )；随后的 N(N-1)/2 行对应村庄间道路的成本及修建状态，每行给4个正整数，分别是两个村庄的编号（从1编号到N），此两村庄间道路的成本，以及修建状态：1表示已建，0表示未建。

当N为0时输入结束。
 

Output
每个测试用例的输出占一行，输出全省畅通需要的最低成本。
 

Sample Input

3
1 2 1 0
1 3 2 0
2 3 4 0
3
1 2 1 0
1 3 2 0
2 3 4 1
3
1 2 1 0
1 3 2 1
2 3 4 1
0 

 

Sample Output

3
1
0 
题目的意思就是给出n个点，然后给出各点之间连线的代价，其中一些边已连接，在这些边中挑出最少代价的边连接是整个图连通。

思路：总体思路就是克鲁斯卡尔算法的思路，依次加代价小的边并且避免形成回路，现将已有边的点合并（这里用了并查集），对于没有连接的边按权值递增排序，然后从小到大一次合并点（还是并查集），直至最终整个图连通。
*/
    #include <cstdio>  
    #include <cstdlib>  
    #include <cstring>  
      
    const int maxx = 101;  
      
    typedef struct E{  
        int x,y,cost;  
    }E;  
      
    int pre[maxx];  
    E edg[5200];  
      
    void init(int n){  
        int i;  
        for(i=1;i<=n;++i){  
            pre[i] = i;  
        }  
    }  
      
    int root(int x){  
        if(x!=pre[x]){  
            pre[x] = root(pre[x]);  
        }  
        return pre[x];  
    }  
      
    int merge(int x,int y){  
        int ret = 0;  
        int fa = root(x);  
        int fb = root(y);  
        if(fa!=fb){  
            ret = 1;  
            pre[fa] = fb;  
        }  
        return ret;  
    }  
      
    int cmp(const void *a,const void *b){  
        E *pa = (E *)a;  
        E *pb = (E *)b;  
        return pa->cost-pb->cost;  
    }  
      
    int main(){  
        int n,x,y,cst,stat,i,pos;  
      
        while(scanf("%d",&n) && n){  
            init(n);  
            pos = 0;  
            int limit = n*(n-1)/2;  
            for(i=0;i<limit;++i){  
                scanf("%d %d %d %d",&x,&y,&cst,&stat);  
                if(stat==1){//已建的路直接合并两端点  
                    merge(x,y);  
                }else{//未建的路记录下起始点和代价后面排序并从小到大一次插入图中  
                    edg[pos].x = x;  
                    edg[pos].y = y;  
                    edg[pos].cost = cst;  
                    ++pos;  
                }  
            }  
            //从这里往下完全是克鲁斯卡尔算法的思想了  
            qsort(edg,pos,sizeof(E),cmp);  
            int minx = 0;//用来记录最小代价  
            for(i=0;i<pos;++i){  
                //如果返回1说明这两点之前不连通，需要加上该边使这两个点连通，从而两个点并入同一集合  
                if(merge(edg[i].x,edg[i].y)==1){  
                    minx += edg[i].cost;  
                }  
            }  
      
            printf("%d\n",minx);  
        }  
        return 0;  
    }