/*

Description
相信大家都听说一个“百岛湖”的地方吧，百岛湖的居民生活在不同的小岛中，当他们想去其他的小岛时都要通过划小船来实现。现在政府决定大力发展百岛湖，发展首先要解决的问题当然是交通问题，政府决定实现百岛湖的全畅通！经过考察小组RPRush对百岛湖的情况充分了解后，决定在符合条件的小岛间建上桥，所谓符合条件，就是2个小岛之间的距离不能小于10米，也不能大于1000米。当然，为了节省资金，只要求实现任意2个小岛之间有路通即可。其中桥的价格为 100元/米。
 

Input
输入包括多组数据。输入首先包括一个整数T(T <= 200)，代表有T组数据。
每组数据首先是一个整数C(C <= 100),代表小岛的个数，接下来是C组坐标，代表每个小岛的坐标，这些坐标都是 0 <= x, y <= 1000的整数。
 

Output
每组输入数据输出一行，代表建桥的最小花费，结果保留一位小数。如果无法实现工程以达到全部畅通，输出”oh!”.
 

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