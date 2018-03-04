/*
Problem Description
Today is Ignatius' birthday. He invites a lot of friends. Now it's dinner time. Ignatius wants to know how many tables he needs at least. You have to notice that not all the friends know each other, and all the friends do not want to stay with strangers.

One important rule for this problem is that if I tell you A knows B, and B knows C, that means A, B, C know each other, so they can stay in one table.

For example: If I tell you A knows B, B knows C, and D knows E, so A, B, C can stay in one table, and D, E have to stay in the other one. So Ignatius needs 2 tables at least.
 

Input
The input starts with an integer T(1<=T<=25) which indicate the number of test cases. Then T test cases follow. Each test case starts with two integers N and M(1<=N,M<=1000). N indicates the number of friends, the friends are marked from 1 to N. Then M lines follow. Each line consists of two integers A and B(A!=B), that means friend A and friend B know each other. There will be a blank line between two cases.
 
Output
For each test case, just output how many tables Ignatius needs at least. Do NOT print any blanks.
 

Sample Input

2
5 3
1 2
2 3
4 5

5 1
2 5

 

Sample Output

2
4
*/
#include <iostream>  
#include <stdio.h>  
using namespace std;  
  
int sum, n, m;  
int father[1000];  
  
void makeset(int x)  
{  
    for(int i=1; i<=x; i++)  
        father[i]=i;  
}  
  
int findset(int x)//查找  
{  
    if(x!=father[x])  
        father[x]=findset(father[x]);//回溯，路径压缩  
    return father[x];  
}  
  
void Union(int a, int b)//合并  
{  
    int x=findset(a);  
    int y=findset(b);  
    if(x==y)  
        return;  
    sum=sum-1;  
    father[y]=x;  
}  
  
int main()  
{  
    int t;  
    scanf("%d", &t);  
    for(int j=1; j<=t; j++)  
    {  
        scanf("%d%d", &n, &m);  
        sum=n;  
        makeset(n);  
        int first, second;  
        for(int i=1; i<=m; i++)  
        {  
            scanf("%d%d", &first, &second);  
            Union(first, second);  
        }  
        printf("%d\n", sum);  
        getchar();  
    }  
    return 0;  
  
} 