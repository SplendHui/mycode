#include<stdio.h>
#include<string.h>
int mod1 = 73;
int mod2 = 137;
char s[10000001];
int main()
{
	freopen("t.in", "r", stdin);
	int i, k = 0;
	while (scanf("%s", s) == 1)
	{
		int len = strlen(s);
		int v = 0;
		for (i = 0; i < len; i++)
			v = (v * 10 + s[i] - '0') % (mod1*mod2);
		if (v == 0)
			printf("Case #%d: YES\n", ++k);
		else
			printf("Case #%d: NO\n", ++k);
	}
	return 0;
}