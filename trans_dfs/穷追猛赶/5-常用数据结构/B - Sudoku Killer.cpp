/*
Description
数独（すうどく，Sūdoku）是一种运用纸、笔进行演算的逻辑游戏。玩家需要根据9×9盘面上的已知数字，推理出所有剩余空格的数字，并满足每一行、每一列、每一个粗线宫内的数字均含1-9，不重复。 
数独盘面是个九宫，每一宫又分为九个小格。在这八十一格中给出一定的已知数字和解题条件，利用逻辑和推理，在其他的空格上填入1-9的数字。使1-9每个数字在每一行、每一列和每一宫中都只出现一次，所以又称“九宫格”。 
? 
杭州学军中学金策同学是NOI2014年全国第一，NOI2015年全国第二，同时也是数独世界锦标赛个人组冠军，在这里膜拜一下大神。 

数独游戏的规则是这样的：在一个9x9的方格中，你需要把数字1-9填写到空格当中，并且使方格的每一行和每一列中都包含1-9这九个数字。同时还要保证，空格中用粗线划分成9个3x3的方格也同时包含1-9这九个数字。比如有这样一个题，大家可以仔细观察一下，在这里面每行、每列，以及每个3x3的方格都包含1-9这九个数字。 

例题： 
 

答案： 
 
Input
本题包含多组测试，每组之间由一个空行隔开。每组测试会给你一个 9*9 的矩阵，同一行相邻的两个元素用一个空格分开。其中1-9代表该位置的已经填好的数，问号（? ）表示需要你填的数。 
Output
对于每组测试，请输出它的解，同一行相邻的两个数用一个空格分开。两组解之间要一个空行。 
对于每组测试数据保证它有且只有一个解。 
Sample Input
7 1 2 ? 6 ? 3 5 8 
? 6 5 2 ? 7 1 ? 4 
? ? 8 5 1 3 6 7 2 
9 2 4 ? 5 6 ? 3 7 
5 ? 6 ? ? ? 2 4 1 
1 ? 3 7 2 ? 9 ? 5 
? ? 1 9 7 5 4 8 6 
6 ? 7 8 3 ? 5 1 9 
8 5 9 ? 4 ? ? 2 3? 
Sample Output
7 1 2 4 6 9 3 5 8 
3 6 5 2 8 7 1 9 4 
4 9 8 5 1 3 6 7 2 
9 2 4 1 5 6 8 3 7 
5 7 6 3 9 8 2 4 1 
1 8 3 7 2 4 9 6 5 
2 3 1 9 7 5 4 8 6 
6 4 7 8 3 2 5 1 9 
8 5 9 6 4 1 7 2 3? 
郁闷呐，为啥我一用搜索，那毛病就一个接一个的出来，还一直找不到原因，唉！
此题比较简单，就是记下没有被赋值的位置，然后依次深搜，每次赋值都要看看他与原有数据是否冲突，不冲突的话，进行下一个深搜，最后得到结果，强烈建议大家以后不要用scanf("%c",&s);这个很容易读错，我就是在这上面错了不知道多少次，可是就是找不到原因，唉，泪奔啊！
*/
#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
struct point{
    int x,y;
}pur[100];
int map[10][10],flag,num;
int check(int k,int cur)
{
    int i,j,x,y;
    for(i=0;i<9;i++)
        if(map[pur[cur].x][i]==k||map[i][pur[cur].y]==k)return 0;
    x=(pur[cur].x/3)*3;
    y=(pur[cur].y/3)*3;
    for(i=x;i<x+3;i++)
        for(j=y;j<y+3;j++)
            if(map[i][j]==k)return 0;
    return 1;
}
void DFS(int step)
{
    int i,j;
    if(step==num){
        for(i=0;i<9;i++)
        {   
            for(j=0;j<8;j++)
                printf("%d ",map[i][j]);
                printf("%d\n",map[i][8]);
            }
            flag=1;
            return;
    }
    else{
        for(i=1;i<=9;i++)
        {
            if(check(i,step)&&!flag)
            {
                map[pur[step].x][pur[step].y]=i;
                DFS(step+1);
                map[pur[step].x][pur[step].y]=0;
            }
        }
    }
    return;
}
int main()
{
    int i,j,cas=0;
    char s[3];
    while(scanf("%s",s)!=EOF)
    {
        num=0;
        if(s[0]=='?'){pur[num].x=0;pur[num].y=0;num++;map[0][0]=0;}
        else map[0][0]=s[0]-'0';
        for(i=0;i<9;i++)
            for(j=0;j<9;j++)
            {
                if(i==0&&j==0)continue;
                scanf("%s",s);
                if(s[0]=='?'){pur[num].x=i;pur[num].y=j;num++;map[i][j]=0;}
                else map[i][j]=s[0]-'0';
            }
        flag=0;
        if(cas++)printf("\n");
        DFS(0);
    }
    return 0;
}