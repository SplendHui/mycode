#include<stdio.h>
int main(){
	int n, m, count = 1;
	int num;
	while(scanf("%d%d",&n,&m) == 2)
	{
		count = 1;
		num = n;
		while(num % m != 0 && count <= m )
		{
			count++;
			num = (num % m) * 10 + n;
		}
		if(count == m+1)
		printf("%d\n",0);
		else
		printf("%d\n",count);
	} 
	return 0;
}
