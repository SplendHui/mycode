//假设有几种硬币，如1、3、5，并且数量无限。请找出能够组成某个数目的找零所使用最少的硬币数。 
/*
解法：

	用待找零的数值k描述子结构/状态，记作sum[k]，其值为所需的最小硬币数。
	对于不同的硬币面值coin[0...n]，有sum[k] = min(sum[k-coin[0]] , sum[k-coin[1]], ...)+1。
	对应于给定数目的找零total，需要求解sum[total]的值。
*/

/*
#include <stdio.h>
#define NMAX 100000
int v[6] = {2,5,10,20,50,100};
int min(int a,int b) { return a<b?a:b; }
int solve(int t,int i=0){
	if(t==0) return 0;
	if(i>=6 || t<v[i]) return NMAX;
	return min(solve(t,i+1),solve(t-v[i],i)+1);
}
int main() {
	int n = solve(15);
	printf("%d\n",n);
	return 0;
}
*/
#include<iostream>
#define INF 10000
typedef struct{
    int coinNum;
    int lastSum;
    int addCoin;
}state;

int main(){
	int i, j;
	int n=0, total;
	int coin[100] = {0};

	scanf("%d ", &total);
	state *sum = new state[total+1]();
	while(scanf("%d",&coin[n]),coin[n])
		n++;
	for(i=0; i <= total; i++)
		sum[i].coinNum = INF;
	sum[0].coinNum = 0;
	sum[0].addCoin = 0;
	for(i=1; i <= total; i++)
		for(j=0; j < n; j++)
		{
			if( i >= coin[j] && (sum[i-coin[j]].coinNum+1 < sum[i].coinNum)  )
			{	
				sum[i].coinNum = sum[i-coin[j]].coinNum + 1;
				sum[i].lastSum = j;
				sum[i].addCoin = coin[j];
			}
			
		}
		
		if( sum[total].coinNum == INF )
			printf( "找不开零钱" );
		else
		{
			
			while( total > 0 )
			{
				printf("%d ",sum[total].addCoin);
				total -=  sum[total].addCoin;
			}
			delete []sum;  
			return 0;
		}
		
		
		return 0;
}











































 

