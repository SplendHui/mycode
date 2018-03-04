
/*
			F - ���ǳ�ͨ����
Description
ĳʡ������彻ͨ״�����õ���ͳ�Ʊ����г�����������ׯ��ľ��롣ʡ��������ͨ���̡���Ŀ����ʹȫʡ�κ�������ׯ�䶼����ʵ�ֹ�·��ͨ������һ����ֱ�ӵĹ�·������ֻҪ�ܼ��ͨ����·�ɴＴ�ɣ�����Ҫ������Ĺ�·�ܳ���Ϊ��С���������С�Ĺ�·�ܳ��ȡ� 
 

Input
��������������ɲ���������ÿ�����������ĵ�1�и�����ׯ��ĿN ( < 100 )������N(N-1)/2�ж�Ӧ��ׯ��ľ��룬ÿ�и���һ�����������ֱ���������ׯ�ı�ţ��Լ�������ׯ��ľ��롣Ϊ���������ׯ��1��N��š� 
��NΪ0ʱ������������������������� 
 

Output
��ÿ��������������1���������С�Ĺ�·�ܳ��ȡ� 
 

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