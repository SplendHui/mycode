/*************************************************************************
    > File Name: HDU1015.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 26 Jan 2017 07:49:17 PM
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char s[30], t[6],Ti[6];
int vis[30], a[30];
int n, target;
void DFS(int num)
{
	int temp, i;
	if(num == 5)
	{
		temp = a[t[0]-'A'] - pow(a[t[1]-'A'], 2) + pow(a[t[2]-'A'],3) - pow(a[t[3]-'A'],4) + pow(a[t[4]-'A'],5);
		if(temp == target && strcmp(t,Ti) > 0)
			strcpy(Ti, t);
		return ;
	}
	for(i = 0; i < n; i++)
	{
		if(!vis[s[i]-'A'])
		{
			t[num] = s[i];
			vis[s[i]-'A'] = 1;
			DFS(num+1);
			vis[s[i]-'A'] = 0;
		}
	}
}
int main()
{
	int i;
	for(i = 0; i < 26; i++)
		a[i] = i + 1;
	freopen("t.in", "r", stdin);
	while(cin >> target >> s && (target || strcmp(s,"END")))
	{
		memset(t, '\0', sizeof(t));
		memset(vis, 0, sizeof(vis));
		memset(Ti, '\0', sizeof(Ti));
		n = strlen(s);
		DFS(0);
		if(strlen(Ti) == 0)
			cout << "no solution" << endl;
		else
			cout << Ti << endl;
	}
	return 1;
}
