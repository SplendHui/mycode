/*************************************************************************
    > File Name: HDU1051.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 26 Jan 2017 11:10:04 AM
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int mark[100]={0};
struct stick{
	int l;
	int w;
}S[1001];
bool cmp(stick a, stick b)
{
	if(a.l < b.l) return true;
	else if(a.l > b.l) return false;
	else return a.w < b.w;
}
int main()
{
	int T, i, n;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(i = 0; i < n; i++)
			cin >> S[i].l >> S[i].w;
		sort(S,S+n,cmp);
		int num = 0;
		int count = 0;
		memset(mark, 0, sizeof(mark));
		while(num < n)
		{

			int pos = 0;
			while(mark[pos] != 0) pos++;
			mark[pos] = 1;
			num++;
			for(i = pos + 1; i < n; i++)
			{
				if(!mark[i] && S[pos].l <= S[i].l && S[pos].w <= S[i].w)
				{
					pos = i;
					mark[i] = 1;
					num++;
				}
			}
			count++;
		}
		cout << count << endl;
	}
	return 1;
}
