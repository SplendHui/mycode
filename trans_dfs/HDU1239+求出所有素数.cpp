/*************************************************************************
    > File Name: HDU1239.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 01 Feb 2017 11:56:51 AM
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int prime[10000], flag[10001];
int k = 0;
void Init()
{
	int i, j;
	flag[0] = flag[1] = 1;
	for(i = 2; i < 10001; i++)
		if(!flag[i])
		{
			for(j = 2 * i; j < 10001; j+=i)
				flag[j] = 1;
			prime[k++] = i;
		}

}
int main()
{
	Init();
	int m;
	int i, j;
	int w, h;
	double a, b, limit;
	while(cin >> m >> a >> b, (m+a+b))
	{
		limit = a / b;
		int max = 0;
		for(i = k - 1; i >= 0; i--)
		{
			for(j = i; j >= 0; j--)
			{
				if(prime[i] > m || prime[j] > m || prime[i] * prime[j] > m)
					continue;
				if((double)prime[j]/prime[i] < limit)
					continue;
				if(prime[i] * prime[j] > max)
				{
					max = prime[i] * prime[j];
					w = prime[i];
					h = prime[j];
				}

			}

		}
		printf("%d %d\n",w > h ? h : w, w > h ? w : h);
	}
	return 1;
}
