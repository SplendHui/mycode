/*
小希的迷宫
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 27851    Accepted Submission(s): 8613


Problem Description
上次Gardon的迷宫城堡小希玩了很久（见Problem B），现在她也想设计一个迷宫让Gardon来走。但是她设计迷宫的思路不一样，首先她认为所有的通道都应该是双向连通的，就是说如果有一个通道连通了房间A和B，那么既可以通过它从房间A走到房间B，也可以通过它从房间B走到房间A，为了提高难度，小希希望任意两个房间有且仅有一条路径可以相通（除非走了回头路）。小希现在把她的设计图给你，让你帮忙判断她的设计图是否符合她的设计思路。比如下面的例子，前两个是符合条件的，但是最后一个却有两种方法从5到达8。 

 

Input
输入包含多组数据，每组数据是一个以0 0结尾的整数对列表，表示了一条通道连接的两个房间的编号。房间的编号至少为1，且不超过100000。每两组数据之间有一个空行。 
整个文件以两个-1结尾。
 

Output
对于输入的每一组数据，输出仅包括一行。如果该迷宫符合小希的思路，那么输出"Yes"，否则输出"No"。
 

Sample Input

6 8  5 3  5 2  6 4
5 6  0 0

8 1  7 3  6 2  8 9  7 5
7 4  7 8  7 6  0 0

3 8  6 8  6 4
5 3  5 6  5 2  0 0

-1 -1

 

Sample Output

Yes
Yes
No
*/
    #include<iostream>  
    #include<stdio.h>  
    using namespace std;  
    #define M 100010  
    int pre[M];  
    int cnt[M];  
    int flag=0;  
    int global_edges=0;  
    int _find(int node){  
        if(node==pre[node])return node;  
        else return pre[node]=_find(pre[node]);  
    }  
    int _union(int a,int b)  
    {  
        if(flag)return 1;  
        int p=_find(a);  
        int q=_find(b);  
        if(p==q)return 1;  
        else  
        {  
            pre[a]=b;  
            global_edges++;  
            return 0;  
        }  
    }  
    int main(int argc, char *argv[])  
    {  
        int Yflag=0;  
       // freopen("1272.in","r",stdin);  
        int a,b;  
        for(int i=1;i<M;++i)  
        {    pre[i]=i;  
            cnt[i]=0;  
        }  
        while(scanf("%d %d",&a,&b))  
        {  
            if(a==-1&&b==-1)return 0;  
            else if(a==0&&b==0)  
            {  
                int sum=0;  
                for(int i=1;i<M;++i)  
                {  
                    sum+=cnt[i];  
                }  
                if(Yflag==0)printf("Yes\n");  
                else if(flag)printf("No\n");  
                else if(sum!=global_edges+1)printf("No\n");  
                else  
                    printf("Yes\n");  
                flag=0;  
                global_edges=0;  
                for(int i=1;i<M;++i)  
                {    pre[i]=i;  
                    cnt[i]=0;  
                }  
                Yflag=0;  
            }  
            else  
            {  
                Yflag=1;  
                if(a<b)  
                    flag=_union(a,b);  
                else  
                    flag=_union(b,a);  
                if(cnt[a]==0)cnt[a]++;  
                if(cnt[b]==0)cnt[b]++;  
            }  
        }  
        return 0;  
    }  