/*
Description
Given two sequences of numbers : a[1], a[2], ...... , a[N], and b[1], b[2], ...... , b[M] (1 <= M <= 10000, 1 <= N <= 1000000). Your task is to find a number K which make a[K] = b[1], a[K + 1] = b[2], ...... , a[K + M - 1] = b[M]. If there are more than one K exist, output the smallest one. 
Input
The first line of input is a number T which indicate the number of cases. Each case contains three lines. The first line is two numbers N and M (1 <= M <= 10000, 1 <= N <= 1000000). The second line contains N integers which indicate a[1], a[2], ...... , a[N]. The third line contains M integers which indicate b[1], b[2], ...... , b[M]. All integers are in the range of [-1000000, 1000000]. 
Output
For each test case, you should output one line which only contain K described above. If no such K exists, output -1 instead. 
Sample Input
2
13 5
1 2 1 2 3 1 2 3 1 3 2 1 2
1 2 3 1 3
13 5
1 2 1 2 3 1 2 3 1 3 2 1 2
1 2 3 2 1
Sample Output
6
-1
*/
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<queue>
#include<math.h>
#include<string.h>
#include <stdlib.h>

//using namespace std;  //影响next名字的使用；
typedef long long ll;

int t,n,m;
int a[1000005],b[10005],next[10005];

void make_next(){
    memset(next,0,sizeof(next));
    next[0]=-1;
    for(int i=1;i<=m;i++){  //对子串求next
        int p=next[i-1];
        while(p>=0&&b[p+1]!=b[i]) p=next[p];
        next[i]=p+1;
    }
}

int kmp(){
    for(int i=1,p=0;i<=n;i++){  //kmp
        while(p>=0&&b[p+1]!=a[i])  p=next[p];
        if(++p==m)
            return i-m+1;
    }
    return -1;
}

int main(){  //hdu1711
  //  freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)//数组下标从1开始；
            scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&b[i]);
        make_next();
        printf("%d\n",kmp());
    }
   return 0;
}