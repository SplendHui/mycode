#include<iostream>
#include<cstring>
int dp[105][105];
int score[105][105];
int num[100];
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int m, n;
	int T;
	int i, j, k;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		for(i = 1; i <= m; i++)
			for(j = 1; j <= m; j++)
				cin >> score[i][j];
		for(i = 1; i <= n; i++)
			cin >> num[i];
		memset(dp, 0, sizeof(dp));
		for(i = 2; i <= n; i++){
			if(num[i] != -1 && num[i-1] != -1)
				dp[i][num[i]] = dp[i-1][num[i-1]] + score[num[i-1]][num[i]];
			else if(num[i] != -1 && num[i-1] == -1)
			{
				for(k = 1; k <= m; k++)
					dp[i][num[i]] = max(dp[i][num[i]], dp[i-1][k] + score[k][num[i]]);
			}
			else if(num[i] == -1 && num[i-1] != -1)
			{
				for(k = 1; k <= m; k++)
					dp[i][k] = max(dp[i][k], dp[i-1][num[i-1]] + score[num[i-1]][k]);
			}
			else if(num[i] == -1 && num[i-1] == -1)
			{
				for(j = 1; j <= m; j++)
					for(k = 1; k <= m; k++)
						dp[i][j] = max(dp[i][j], dp[i-1][k]+score[k][j]);
			}
		}
		int ans = 0;
		for(i = 1; i <= m; i++)
			ans = max(ans, dp[n][i]);
		cout << ans << endl;
	}
	return 0;
}
