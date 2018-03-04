#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 0x3fffffff
using namespace std;

int a[15];
int n;

void solve()
{
    while(a[0]==0)
        next_permutation(a,a+n);

    int ans=INF;
    int mid=(n+1)/2;
    do
    {
        if(a[mid])
        {
            int x=a[0],y=a[mid];
            for(int i=1;i<mid;i++)
                x=x*10+a[i];
            for(int i=mid+1;i<n;i++)
                y=y*10+a[i];
            if(ans>abs(x-y))
                ans=abs(x-y);
        }

    }while(next_permutation(a,a+n));
    cout<<ans<<endl;
}

int main()
{
    int T;
    char c;

    scanf("%d",&T);
    getchar();
    while(T--)
    {
        n=0;
        memset(a,0,sizeof(a));

        while((c=getchar())!='\n')
        {
            if(c!=' ')
                a[n++]=c-'0';
        }

        if(n==1)
            printf("%d\n",a[0]);
        else if(n==2)
            printf("%d\n",abs(a[1]-a[0]));
        else
            solve();
    }
    return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int a[12],b[12],n,ans;
bool vis[12];

void solve(int aa)
{
    int len=0;
    int bb=0;
    for(int i=0;i<n;i++)
        if(!vis[i])//如果被分割的这个点没有访问过
            b[len++]=a[i],bb=bb*10+a[i];//就存入b数组里
    if(b[0]!=0||len==1)
        ans=min(ans,abs(aa-bb));
    while(next_permutation(b,b+len))//这里是从开妹那里学来的，这个stl的含义是才生成从b到b+len的序列的全排列
    {
        bb=0;
        for(int i=0;i<len;i++)//针对每一种排列进行运算，然后比较求出，最小
            bb=bb*10+b[i];
        if(b[0]!=0||len==1)
            ans=min(ans,abs(aa-bb));
    }
}
void dfs(int k,int r)
{
    if(k==n/2)//想要差距最小，位数看就要最接近，所以要对半分
    {
        solve(r);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(a[i]==0&&k==0&&n>3)//多位的时候，不允许有前导0
               continue;
            vis[i]=true;
            dfs(k+1,r*10+a[i]);
            vis[i]=false;
        }
    }
}
int main()
{
    int T;
    for(scanf("%d ",&T);T;T--)
    {
        n=0;
        char ch;
        while((ch=getchar())!='\n')
        {
            if(ch==' ')
                continue;
            a[n++]=ch-'0';
        }
        ans=inf;
        memset(vis,false,sizeof(vis));
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
