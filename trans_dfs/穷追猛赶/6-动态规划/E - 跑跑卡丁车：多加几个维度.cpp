Description
跑跑卡丁车是时下一款流行的网络休闲游戏，你可以在这虚拟的世界里体验驾驶的乐趣。这款游戏的特别之处是你可以通过漂移来获得一种 
加速卡，用这种加速卡可以在有限的时间里提高你的速度。为了使问题简单化，我们假设一个赛道分为L段，并且给你通过每段赛道的普通耗时Ai和用加速卡的耗时Bi。加速卡的获得机制是：普通行驶的情况下，每通过1段赛道,可以获得20%的能量(N2O).能量集满后获得一个加速卡(同时能量清0).加速卡最多可以储存2个,也就是说当你有2个加速卡而能量再次集满,那么能量清零但得不到加速卡。一个加速卡只能维持一段赛道，游戏开始时没有加速卡。 


 


问题是，跑完n圈最少用时为多少？ 
Input
每组输入数据有3行，第一行有2个整数L(0<L<100),N(0<N<100)分别表示一圈赛道分为L段和有N圈赛道，接下来两行分别有L个整数Ai和Bi 
(Ai > Bi). 
Output
对于每组输入数据，输出一个整数表示最少的用时. 
Sample Input
18 1
9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9
8 8 8 8 8 8 8 8 8 8 8 8 8 8 1 1 8 8
Sample Output
145


        
  
对于sample这组数据，你可以先在普通情况下行驶前14段，这时你有2个加速卡以及80%的能量(N2O).在第15和16段用掉2个加速卡，通过第
17段赛道后又可以得到一个加速卡，在第18段赛道使用.
#include <stdio.h>
#include <string.h>
#define MAX 10010
#define INF 1000000000
#define MIN(a,b) (a)<(b)?(a):(b)


int n,m,tot,dp[MAX][16];
int A[MAX],B[MAX];


int main()
{
    int i,j,k,t,add,next;


    while (scanf("%d%d",&n,&m) != EOF) {

        tot = n * m;
        for (i = 0; i < n; ++i)
            scanf("%d",&A[i]);
        for (j = 0; j < n; ++j)
            scanf("%d",&B[j]);
        for (i = 0; i < tot; ++i)
            A[i] = A[i%n],B[i] = B[i%n];
        
        
        for (i = 0; i <= 15; ++i)
            for (j = 0; j <= tot; ++j)
                dp[j][i] = INF;
        dp[1][1] = A[0];
        
        
        for (i = 1; i < tot; ++i)
            for (j = 0; j < 15; ++j) {

                k = j + 1;
                if (k == 15) k = 10;
                dp[i+1][k] = MIN(dp[i][j]+A[i],dp[i+1][k]);
                if (j >= 5) dp[i+1][j-5] = MIN(dp[i][j]+B[i],dp[i+1][j-5]);
            }


        int ans = INF;
        for (i = 0; i < 15; ++i)
            ans = MIN(ans,dp[tot][i]);
        printf("%d\n",ans);
    }
}