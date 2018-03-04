/*
描述 Description
Bessie不小心游荡出Farmer John的田地，而走进了相邻的农民的地。她举起一个木瓜，木
瓜对奶牛来说可是不可多得得美味。这个木瓜林像一般的威斯康星州的田地一样被分割成一个
R行C列的网格(1 <= R <= 40, 1 <= C <= 40)。Bessie可以从一个格沿著一条跟X轴或
Y轴平行的直线走到邻接的令一个格。Bessie发现一开始她自己在木瓜林的(1,1)，也就是第
一行第一列慢悠悠地咀嚼著木瓜。

Bessie总是用她最信赖地双筒望远镜去数每一个邻接的格的低掛著的木瓜的数目。然后她就游
荡到那个有最多没有被吃掉的木瓜的邻接的格子（保证这洋的格子只有一个）。

按照这种移动方法，最终Bessie总是会在(R,C)停止然后吃掉那裡的木瓜。

给定这个木瓜林的大小及每个格的木瓜数F_ij(1 <= F_ij <= 100), 要求Bessie一共吃了
多少个木瓜。
 
输入格式 InputFormat
* 第一行: 两个空格隔开的整数R和C.

* 第2到R+1行: 第i+1行有C个空格隔开的整数，表示第i行的每个格的水果数。也就是F_i1, 
F_i2, ..., F_iC.
 
输出格式 OutputFormat
* 第一行: 一个单独的整数，表示到Bessie吃完右下角(R,C)的木瓜回到牛棚的时候為止，
一共在木瓜林吃掉了多少个木瓜。
 
样例输入 SampleInput [复制数据]

3 4
3 3 4 5
4 5 3 2
1 7 4 2

 

样例输出 SampleOutput [复制数据]

39

 
数据范围和注释 Hint
Bessie按照下图数字旁边的字母的顺序吃掉木瓜。

     (1,1) ---> (1,C)
(1,1) 3a  3   4g  5h  (1,C)
  |   4b  5c  3f  2i    |
(R,1) 1   7d  4e  2j  (R,C)
     (R,1) ---> (R,C)

她吃了39个木瓜，剩下4个没有吃（也就是说除了2个格幸免於难，剩下的格子都被Bessie扫
荡过了）。
*/
#include <stdbool.h>
#include <stdio.h>
int main(void)
{
    int i,j,r,c,a[41][41],xi=1,yi=1,maxx=1,maxy=1,max;
    bool b[41][41]={false};
    long sum=0;
    scanf("%d%d\n",&r,&c);
    for (i=1;i<=r;i++)
    { 
        for (j=1;j<=c;j++)
        {
         scanf("%d",&a[i][j]);
         b[i][j]=true;
        }
     }
   
            
   sum=sum+a[1][1];
     b[1][1]=false;
    while (true)
    {
        
        max=-1;
        if ((b[xi][yi+1]==true)&&(a[xi][yi+1]>max))
        {
            maxx=xi;maxy=yi+1;
            max=a[xi][yi+1];
        }
         if ((b[xi][yi-1]==true)&&(a[xi][yi-1]>max))
        {
            maxx=xi;maxy=yi-1;
            max=a[xi][yi-1];
        }
          if ((b[xi+1][yi]==true)&&(a[xi+1][yi]>max))
        {
            maxx=xi+1;maxy=yi;
            max=a[xi+1][yi];
        }
           if ((b[xi-1][yi]==true)&&(a[xi-1][yi]>max))
        {
            maxx=xi-1;maxy=yi;
            max=a[xi-1][yi];
        }
           b[maxx][maxy]=false;
           sum=sum+a[maxx][maxy];
           xi=maxx;yi=maxy;
           if ((maxx==r)&&(maxy==c)) break;
            
    }
    
printf("%d\n",sum);
return 0;
        
        
}