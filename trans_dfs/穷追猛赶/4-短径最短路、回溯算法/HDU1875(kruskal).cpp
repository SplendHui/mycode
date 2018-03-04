/*

Description
���Ŵ�Ҷ���˵һ�����ٵ������ĵط��ɣ��ٵ����ľ��������ڲ�ͬ��С���У���������ȥ������С��ʱ��Ҫͨ����С����ʵ�֡�������������������չ�ٵ�������չ����Ҫ��������⵱Ȼ�ǽ�ͨ���⣬��������ʵ�ְٵ�����ȫ��ͨ����������С��RPRush�԰ٵ������������˽�󣬾����ڷ���������С���佨���ţ���ν��������������2��С��֮��ľ��벻��С��10�ף�Ҳ���ܴ���1000�ס���Ȼ��Ϊ�˽�ʡ�ʽ�ֻҪ��ʵ������2��С��֮����·ͨ���ɡ������ŵļ۸�Ϊ 100Ԫ/�ס�
 

Input
��������������ݡ��������Ȱ���һ������T(T <= 200)��������T�����ݡ�
ÿ������������һ������C(C <= 100),����С���ĸ�������������C�����꣬����ÿ��С�������꣬��Щ���궼�� 0 <= x, y <= 1000��������
 

Output
ÿ�������������һ�У������ŵ���С���ѣ��������һλС��������޷�ʵ�ֹ����Դﵽȫ����ͨ�������oh!��.
 

Sample Input

2
2
10 10
20 20
3
1 1
2 2
1000 1000 

 

Sample Output

1414.2
oh!
*/
    #include<iostream>  
    #include<cstdio>  
    #include<vector>  
    #include<queue>  
    using namespace std;  
      
    struct node  
    {  
        int u,v,w;  
        node(int x,int y,int z):u(x),v(y),w(z){}  
        bool operator <(const node a)const  
        {  
            return w>a.w;  
        }  
    };  
      
    int rank[105],father[105];  
      
    void set(int x)  
    {  
        rank[x]=0;  
        father[x]=x;  
    }  
      
    int find(int x)  
    {  
        if(x!=father[x])  
            father[x]=find(father[x]);  
        return father[x];  
    }  
      
    bool merge(int u,int v)  
    {  
        int x=find(u);  
        int y=find(v);  
        if(x!=y)  
        {  
            if(rank[x]>rank[y])  
            {  
                father[y]=x;  
            }  
            else  
            {  
                if(rank[x]==rank[y])  
                {  
                    rank[y]++;  
                }  
                father[x]=y;  
            }  
            return true;  
        }  
        return false;  
    }  
      
    int main()  
    {  
        //freopen("in.txt","r",stdin);  
        int n;  
        int u,v,w,ans;  
        while(scanf("%d",&n),n)  
        {     
            ans=0;  
            priority_queue<node>prique;  
            n=n*(n-1)>>1;  
            while(n--)  
            {  
                scanf("%d%d%d",&u,&v,&w);  
                prique.push(node(u,v,w));  
                set(u),set(v);  
            }  
            while(!prique.empty())  
            {  
                if(merge(prique.top().u,prique.top().v))  
                    ans+=prique.top().w;  
                prique.pop();  
            }  
            printf("%d\n",ans);  
        }  
        return 0;  
    }  