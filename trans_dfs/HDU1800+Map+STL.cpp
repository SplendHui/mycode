/*************************************************************************
    > File Name: HDU1800map.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 01 Feb 2017 10:55:07 AM
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
using namespace std;
string Dele_0(string t)
{
	int i;
	for(i = 0; i < t.length() - 1; i++)
		if(t[i] == '0')
			continue;
		else break;
	return t.substr(i);
}
int main()
{
	int n;
	string a, b;
	map<string, int> mymap;
	while(cin >> n)
	{
		for(int i = 0; i < n; i++)
		{
			cin >> a;
			b = Dele_0(a);
			mymap[b]++;		
		}
		int max = 0;
		map<string, int>::iterator it;
		for(it = mymap.begin(); it != mymap.end(); it++)
		{
			if(it->second > max)
				max = it->second;
		}
		cout << max << endl;
	}
	return 1;
}
