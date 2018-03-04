/*
 Farmer John一直努力让他的草地充满鲜美多汁的而又健康的牧草。可惜天不从人愿，他在植物大战人类中败下阵来。邪恶的乳草已经在他的农场的西北部份佔领了一片立足之地。

草地像往常一样，被分割成一个高度為Y(1 <= y <= 100), 宽度為X(1 <= x <= 100)的直角网格。(1,1)是左下角的格（也就是说坐标排布跟一般的X,Y坐标相同）。乳草一开始佔领了格(Mx,My)。每个星期，乳草传播到已被乳草佔领的格子四面八方的每一个没有很多石头的格（包括垂直与水平相邻的和对角线上相邻的格）。1周之后，这些新佔领的格又可以把乳草传播到更多的格裡面了。

Bessie想要在草地被乳草完全佔领之前尽可能的享用所有的牧草。她很好奇到底乳草要多久才能佔领整个草地。如果乳草在0时刻处於格(Mx,My)，那麼还在那个时刻它们可以完全佔领入侵整片草地呢（对给定的数据总是会发生）？

草地由一个图片表示。"."表示草，而"*"表示大石。比如这个X=4, Y=3的例子。

     ....
     ..*.
     .**.

如果乳草一开始在左下角（第1排，第1列），那麼草地的地图将会以如下态势发展：

      ....  ....  MMM.  MMMM  MMMM  
      ..*.  MM*.  MM*.  MM*M  MM*M  
      M**.  M**.  M**.  M**.  M**M  
星期数  0     1     2     3     4

乳草会在4星期后佔领整片土地。
输入格式
* 第一行: 四个由空格隔开的整数: X, Y, Mx, My

* 第2到第Y+1行: 数据的第y+1行由X个字符（"."表示草地，"*"表示大石），描述草地的
第(Y+2-y)行。
输出格式
* 第一行: 一个单独的整数表示最后一个不是大石块的格子被乳草佔领的星期数。
测试样例1
输入

    4 3 1 1
    ....
    ..*.
    .**. 

输出

    4 
*/
    #include<cstdio>  
    #include<cstring>  
    #include<string>  
    #include<cmath>  
    #include<iostream>  
    #define LL long long  
    #define db double  
    #define maxn 10000000  
    #define max(a,b) ((a>b)?(a):(b))  
    #define min(a,b) ((a<b)?(a):(b))  
    using namespace std;  
    int n,m,bx,by;  
    bool mp[101][101];  
    int xx[8]={1,-1,1,-1,0,0,1,-1},yy[8]={1,-1,-1,1,1,-1,0,0};  
    struct data{  
        int x,y,step;  
    }q[10001];  
      
    bool judge(int x,int y){  
        if (mp[x][y]||x<1||y<1||x>m||y>n) return 0;  
        mp[x][y]=1;  
        return 1;  
    }  
    int bfs(int bx,int by){  
        int t=0,w=1;  
        int nowx,nowy;  
        q[0].x=bx; q[0].y=by;  
        mp[bx][by]=1;  
        while (t<w){  
            for (int i=0;i<8;i++){  
                nowx=q[t].x+xx[i];  
                nowy=q[t].y+yy[i];  
                if (judge(nowx,nowy)){  
                    q[w].x=nowx;  
                    q[w].y=nowy;  
                    q[w].step=q[t].step+1;  
                    w++;  
                }  
            }  
            t++;  
        }  
        printf("%d",q[w-1].step);  
    }  
    int main(){  
        scanf("%d%d%d%d",&n,&m,&bx,&by);  
        char ch[101];  
        for (int i=m;i>0;i--){  
            scanf("%s",ch);  
            for (int j=0;j<n;j++)  
                if (ch[j]=='*') mp[i][j+1]=1;  
            }  
        bfs(bx,by);  
        return 0;  
    }   
