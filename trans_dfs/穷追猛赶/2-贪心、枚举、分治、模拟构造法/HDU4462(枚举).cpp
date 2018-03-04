/*枚举所有的状态
It’s harvest season now! 
Farmer John plants a lot of corn. There are many birds living around his corn field. These birds keep stealing his corn all the time. John can't stand with that any more. He decides to put some scarecrows in the field to drive the birds away. 
John's field can be considered as an N×N grid which has N×N intersections. John plants his corn on every intersection at first. But as time goes by, some corn were destroyed by rats or birds so some vacant intersections were left. Now John wants to put scarecrows on those vacant intersections and he can put at most one scarecrow on one intersection. Because of the landform and the different height of corn, every vacant intersections has a scaring range R meaning that if John put a scarecrow on it, the scarecrow can only scare the birds inside the range of manhattan distance R from the intersection.
The figure above shows a 7×7 field. Assuming that the scaring range of vacant intersection (4,2) is 2, then the corn on the marked intersections can be protected by a scarecrow put on intersection (4,2). 
Now John wants to figure out at least how many scarecrows he must buy to protect all his corn
Input
There are several test cases. 
For each test case: 
The first line is an integer N ( 2 <= N <= 50 ) meaning that John's field is an N×N grid. 
The second line is an integer K ( 0<= K <= 10) meaning that there are K vacant intersections on which John can put a scarecrow.
The third line describes the position of K vacant intersections, in the format of r1,c1,r2,c2 …. rK,ck . (ri,ci) is the position of the i-th intersection and 1 <= r1,c1,r2,c2…. rK,ck <= N. 
The forth line gives the scaring range of all vacant intersections, in the format of R1,R2…RK and 0 <= R1,R2…RK <= 2 × N. 
The input ends with N = 0.
 

Output
For each test case, print the minimum number of scarecrows farmer John must buy in a line. If John has no way to protect all the corn, print -1 instead.
 

Sample Input
4
2
2 2 3 3
1 3
4
2
2 2 3 3
1 4
0
 

Sample Output
-1
1
*/
#include<iostream>  
#include<cstring>  
#include<string>  
#include<cmath>  
#include<cstdio>  
using namespace std;  
int n,p,res;   //p指的是有多少个空地可以放稻草人  
int visi[55][55];  
int vis[12];  //点访问的情况  
int num;  //记录用了多少点  
struct mq  
{  
    int x;  
    int y;  
    int r;  
};  
mq node[12];  
  
void init()  
{  
    memset(visi,0,sizeof(visi));  
    memset(vis,0,sizeof(vis));  
    for(int i=0;i<p;i++)  
        visi[node[i].x][node[i].y]=1;  
}  
  
void fun()  
{  
    int j,k,ra,rb,ca,cb;  
    num=0;  
    for(int i=0;i<p;i++)  
    {  
        if(vis[i])  
        {  
            num++;  
            ra=node[i].x-node[i].r;  
            rb=node[i].x+node[i].r;  
            ca=node[i].y-node[i].r;  
            cb=node[i].y+node[i].r;  
            if(ra<1) ra=1;  
            if(rb>n) rb=n;  
            if(ca<1) ca=1;  
            if(cb>n) cb=n;  
            for(j=ra;j<=rb;j++)  
                for(k=ca;k<=cb;k++)  
                   if(abs(j-node[i].x)+abs(k-node[i].y)<=node[i].r)  //范围之类  
                        visi[j][k]=1;  
        }  
    }  
}  
  
int over()   //是否全部覆盖  
{  
    int i,j;  
    for(i=1; i<=n; i++)  
    {  
        for(j=1; j<=n; j++)  
            if(!visi[i][j])  
            {  
                return 0;  
            }  
    }  
    return 1;  
}  
  
void solve()  
{  
    int i,j;  
    res=100;  
    for(i=0;i<(1<<p);i++)   //枚举所有的状态  
    {  
        init();  
        int tmp=i;  
        for(j=0;j<p;j++)  
        {  
            vis[j]=tmp&1;  //刚好二进制是这样存储，唯一! 所有枚举子集  
            tmp>>=1;  
            //cout<<vis[j]<<" ";  
        }  
        //cout<<endl;  
        fun();  
        if(over())  //可以覆盖了  
            res=min(res,num);  
    }  
}  
int main()  
{  
    int i;  
    while(scanf("%d",&n)&&n)  
    {  
        scanf("%d",&p);  
        for(i=0; i<p; i++)  
            scanf("%d%d",&node[i].x,&node[i].y);  
        for(i=0; i<p; i++)  
            scanf("%d",&node[i].r);  
        init();  
        if(over())   //说明不需要稻草人。。。  
        {  
            puts("0");  
            continue;  
        }  
        solve();  
        if(res==100) puts("-1");  //说明覆盖不了  
        else printf("%d\n",res);  
    }  
    return 0;  
} 