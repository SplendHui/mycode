//�����м���Ӳ�ң���1��3��5�������������ޡ����ҳ��ܹ����ĳ����Ŀ��������ʹ�����ٵ�Ӳ������ 
/*
�ⷨ��

	�ô��������ֵk�����ӽṹ/״̬������sum[k]����ֵΪ�������СӲ������
	���ڲ�ͬ��Ӳ����ֵcoin[0...n]����sum[k] = min(sum[k-coin[0]] , sum[k-coin[1]], ...)+1��
	��Ӧ�ڸ�����Ŀ������total����Ҫ���sum[total]��ֵ��
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
			printf( "�Ҳ�����Ǯ" );
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











































 

