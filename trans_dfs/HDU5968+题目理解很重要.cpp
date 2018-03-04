#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 105;
int a[maxn];
int sum[maxn];
int res[maxn][maxn];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d", &n);
		for (int i = 1;i <= n;i++)scanf("%d", &a[i]);
		memset(sum, 0, sizeof(sum));
		for (int i = 1;i <= n;i++)sum[i] = sum[i - 1] ^ a[i];
		for (int i = 1;i <= n;i++)
			for (int j = i;j <= n;j++)
				res[i][j] = sum[j] ^ sum[i - 1];

		scanf("%d", &m);
		for (int i = 1;i <= m;i++)
		{
			int x;
			scanf("%d", &x);
			int ans = 1e9;
			int pos = 0;
			for (int i = 1;i <= n;i++)
				for (int j = i;j <= n;j++)
				{
					if (ans > abs(res[i][j] - x))
					{
						ans = abs(res[i][j] - x);
						pos = j - i + 1;
					}
					else if (ans == abs(res[i][j] - x))
					{
						pos = max(pos, j - i + 1);
					}
				}
			printf("%d\n", pos);
		}
		printf("\n");
	}
}
