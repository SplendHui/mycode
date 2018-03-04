#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define ll __int64
char a[200];
int main()
{
	int t;
	int kase = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", a);
		int n = strlen(a);
		ll output = -1000000000000000000;
		for (int i = 2;i < n - 2;i++)
		{
			ll aa = 0;
			for (int j = 0;j < i - 1;j++)
			{
				aa = aa * 10 + a[j] - '0';
			}
			ll b = a[i - 1] - '0';
			ll tmp = aa + b;
			aa = 0;b = 0;
			for (int j = 1;j < i;j++)
			{
				aa = aa * 10 + a[j] - '0';
			}
			b = a[0] - '0';
			ll tmp2 = aa + b;
			ll c = a[i] - '0';
			ll d = a[i + 1] - '0';
			ll e = 0;
			for (int j = i + 2;j < n;j++)
			{
				e = e * 10 + a[j] - '0';
			}
			output = max(output, max(tmp, tmp2) - c*d / e);
		}
		printf("Case #%d: ", ++kase);
		printf("%I64d\n", output);
	}
}