#include<iostream>
#include<string>
#include<algorithm>//STL reverse函数的头文件，reverse反转函数，
using namespace std;
int main()
{
	int cas, len, sub, maxn;
	int n, k, i, j;
	string s[102];
	cin >> cas;
	while (cas--)
	{
		cin >> n;
		len = 1000;
		sub = 0;
		for (i = 0; i < n; i++)
		{
			cin >> s[i];
			if (len > s[i].size())//找最小 的母串
			{
				len = s[i].size();
				sub = i;
			}
		}
		maxn = 0;
		for (i = s[sub].size(); i > 0; i--) //从最小的母串开始从长到短找子串，
		{
			for (j = 0; j < s[sub].size() - i + 1; j++) //长度为i的子串在母串中找
			{
				string s1, s2;//s1为子串正 ，s2为子串反
				s1 = s[sub].substr(j, i);//去j开始i长度是字符
				s2 = s1;
				reverse(s2.begin(), s2.end());//反串
				for (k = 0; k < n; k++)
				{
					if (s[k].find(s1, 0) == -1 && s[k].find(s2, 0) == -1) //当正反子串在母串中都未发现时即跳出
						break;

				}
				if (k == n && maxn < s1.size())
					maxn = s1.size();

			}

		}
		cout << maxn << endl;
	}
	return 0;
}