
/*
			F - 还是畅通工程
Description
某省调查乡村交通状况，得到的统计表中列出了任意两村庄间的距离。省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可），并要求铺设的公路总长度为最小。请计算最小的公路总长度。 
 

Input
测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( < 100 )；随后的N(N-1)/2行对应村庄间的距离，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间的距离。为简单起见，村庄从1到N编号。 
当N为0时，输入结束，该用例不被处理。 
 

Output
对每个测试用例，在1行里输出最小的公路总长度。 
 

Sample Input

 3
1 2 1
1 3 2
2 3 4
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
0 

 

Sample Output

 3
5 

Hint

Hint  Huge input, scanf is recommended.
*/
    #include <iostream>  
    #include <algorithm>  
    #include <cstdio>  
    #define N 101  
    using namespace std;  
    struct road  
    {  
        int x,y;  
        int v;  
    }V[6000];  
    bool cmp(const struct road &a,const struct road &b)  
    {  
        return a.v<b.v;  
    }  
    int par[N];  
    void Init(int n)  
    {  
        for(int i=0;i<=n;i++)  
            par[i]=i;  
    }  
    int findroot(int x)  
    {  
        if(par[x]!=x)  
            return par[x]=findroot(par[x]);  
        return par[x];  
    }  
    int unite(int x,int y)  
    {  
        x=findroot(x);  
        y=findroot(y);  
        if(x==y)  
            return 0;  
        par[y]=x;  
        return 1;  
    }  
    int main()  
    {  
        int n,m;  
        int cnt;  
        int ans;  
        while(~scanf("%d",&n)&&n!=0)  
        {  
            for(int i=0;i<n*(n-1)/2;i++)  
                scanf("%d%d%d",&V[i].x,&V[i].y,&V[i].v);  
            sort(V,V+n*(n-1)/2,cmp);  
            Init(n);  
            ans=0;  
            cnt=0;  
            for (int i=0; i<n*(n-1)/2; ++i)  
            {  
                if (cnt == n - 1)  
                    break;  
                if (unite(V[i].x, V[i].y))  
                {  
                    ++cnt;  
                    ans += V[i].v;  
                }  
            }  
            cout<<ans<<endl;  
        }  
        return 0;  
    }  