/*
Сϣ���Թ�
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 65536/32768 K (Java/Others)
Total Submission(s): 27851    Accepted Submission(s): 8613


Problem Description
�ϴ�Gardon���Թ��Ǳ�Сϣ���˺ܾã���Problem B����������Ҳ�����һ���Թ���Gardon���ߡ�����������Թ���˼·��һ������������Ϊ���е�ͨ����Ӧ����˫����ͨ�ģ�����˵�����һ��ͨ����ͨ�˷���A��B����ô�ȿ���ͨ�����ӷ���A�ߵ�����B��Ҳ����ͨ�����ӷ���B�ߵ�����A��Ϊ������Ѷȣ�Сϣϣ�����������������ҽ���һ��·��������ͨ���������˻�ͷ·����Сϣ���ڰ��������ͼ���㣬�����æ�ж��������ͼ�Ƿ�����������˼·��������������ӣ�ǰ�����Ƿ��������ģ��������һ��ȴ�����ַ�����5����8�� 

 

Input
��������������ݣ�ÿ��������һ����0 0��β���������б���ʾ��һ��ͨ�����ӵ���������ı�š�����ı������Ϊ1���Ҳ�����100000��ÿ��������֮����һ�����С� 
�����ļ�������-1��β��
 

Output
���������ÿһ�����ݣ����������һ�С�������Թ�����Сϣ��˼·����ô���"Yes"���������"No"��
 

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