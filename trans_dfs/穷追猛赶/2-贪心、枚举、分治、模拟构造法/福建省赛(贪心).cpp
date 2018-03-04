Problem Description

While HIT ACM Group finished their contest in Shanghai and is heading back Harbin, their train was delayed due to the heavy snow. Their mobile phones are all running out of battery very quick. Luckily, zb has a super mobile charger that can charge all phones.

There are N people on the train, and the i-th phone has p[i] percentage of power, the super mobile charger can charge at most M percentage of power.

Now zb wants to know, at most how many phones can be charged to full power. (100 percent means full power.)
 Input

The first line contains an integer T, meaning the number of the cases (1 <= T <= 50.).

For each test case, the first line contains two integers N, M(1 <= N <= 100,0 <= M <= 10000) , the second line contains N integers p[i](0 <= p[i] <= 100) meaning the percentage of power of the i-th phone.
 Output

For each test case, output the answer of the question.
 Sample Input
2 3 10 100 99 90 3 1000 0 0 0
 Sample Output
2 3

题解：水题，就是说，火车晚点了，就有一块充电宝，能冲一定电量，问能把多少个人的手机充满电；

代码：

	
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f;
#define mem(x,y) memset(x,y,sizeof(x))
#define SI(x) scanf("%d",&x)
#define PI(x) printf("%d",x)
#define T_T while(T--)
const int MAXN=110;
int a[MAXN];
int main(){
    int T,N,M;
    SI(T);
    T_T{
        SI(N);SI(M);
        for(int i=0;i<N;i++)SI(a[i]),a[i]=100-a[i];
        sort(a,a+N);
        int ans=0;
        for(int i=0;i<N;i++){
            M-=a[i];
            if(M<0)break;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}