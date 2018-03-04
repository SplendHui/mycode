/*
天上掉馅饼本指天空中降落类似馅饼那样的即免费又好吃的食物，泛指在自然生活中会无缘无故的发生一些可以满足人们欲望的物质或财富上面的事情；现在也贬指那些坐享其成，成天不务实际的人在假想一些不可能发生的事情，等待出现奇迹，天上怎么可能会掉馅饼。 
? 
? 
有一天， 小王同学正走在路上，忽然天上掉下大把大把的馅饼（哈哈哈。。。。）。这个只能说小王同学的人品太好，这馅饼就掉落在他身旁的10米范围内。所以小王同学马上去接馅饼，因为掉在地方的馅饼就不能吃了。他只能在这个10米范围内接馅饼。由于小王同学是一个非常优秀的Oier，但他不是一个优秀的运动员，所以他每秒钟只有在移动不超过一米的范围内接住坠落的馅饼。现在给这条小径如图标上坐标： 
 
为了使问题简化，假设在接下来的一段时间里，馅饼都掉落在0-10这11个位置。开始时小王站在5这个位置上，因此在第一秒，他只能接到4,5,6这三个位置中其中一个位置上的馅饼。问小王最多可能接到多少个馅饼？（假设他的背包可以容纳无穷多个馅饼） 
Input
输入数据有多组。每组数据的第一行为以正整数n(0<n<100000)，表示有n个馅饼掉在这条小径上。在结下来的n行中，每行有两个整数x,T(0<T<100000),表示在第T秒有一个馅饼掉在x点上。同一秒钟在同一点上可能掉下多个馅饼。n= 0时输入结束。 
Output
每一组输入数据对应一行输出。输出一个整数m，表示小王最多可能接到m个馅饼。 

? 
Sample Input
6 
5 1 
4 1 
6 1 
7 2 
7 2 
8 3 
0? 
Sample Output
4
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int w,h;
struct pie
{
    int time,pos,speed,value,t;
}s[10001];//用结构体来记录数据 
int f[1001][1001];//记录决策 
int main()
{
    cin>>w>>h;
    int n=1,ss,maxn=-999,ans=0;
    //while (scanf("%d%d%d%d",s[n].time,s[n].pos,s[n].speed,s[n].value)==4) 
    while (cin>>s[n].time>>s[n].pos>>s[n].speed>>s[n].value)//由于不知道数据个数，用while读入 
    {
    s[n].t=ceil(h/s[n].speed)+s[n].time;//t指该馅饼下落下来（到最后一格）的时间
        n++;//这一步核心意思就是将该时间取整，但是是加一位（2.....=3）
    }
    n-=1;//n为馅饼个数 
    for (int i=1;i<=n;i++)
    {
        f[s[i].pos][s[i].t]+=s[i].value;
        maxn=max(s[i].t,maxn);//找到最晚的馅饼的时间
    }
        for (int j=maxn-1;j>=0;j--)
         for (int i=1;i<=w;i++)
         { 
            if (f[i-2][j+1]&&i-2>0)    ans=max(ans,f[i-2][j+1]);
            if (f[i-1][j+1]&&i>1)      ans=max(ans,f[i-1][j+1]);
            if (f[i][j+1])             ans=max(ans,f[i][j+1]);
            if (f[i+2][j+1]&&i+2<=w)   ans=max(ans,f[i+2][j+1]);
            if (f[i+1][j+1]&&i+1<=w)   ans=max(ans,f[i+1][j+1]);
            f[i][j]+=ans;//状态转移方程应用 
         }
    cout<<f[w/2+1][0];//由于人以中间为起点，所以输出（w/2+1,0)
    return 0;
}