#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int ans[22], vis[22], n;
int isPrime(int n)
{
	int i;
	for(i = 2; i < n; i++)
		if(n % i == 0)
			break;
	if(i < n)
		return 0;
	return 1;
}
void DFS(int cnt)
{
	int i; 
	if(cnt == n )
	{
		if(isPrime(ans[0]+ans[cnt-1]))
		{
			for(i = 0; i < n; i++)
				printf("%d ",ans[i]);
			printf("\n");
		}
		return ;
	}
	for(i = 2; i <= n; i++)
		if( !vis[i] && isPrime(ans[cnt-1]+i) )
		{
			ans[cnt] = i;
			vis[i] = 1;
			DFS(cnt+1);
			vis[i] = 0;
		}
}
int main(){
	int cas = 0;
	ans[0] = 1;
	while(scanf("%d", &n) == 1)
	{
		memset(vis, 0, sizeof(vis));
		printf("Case %d:\n",cas++);
		DFS(1);
	}
	return 1;
}
