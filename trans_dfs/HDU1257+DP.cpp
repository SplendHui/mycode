/*************************************************************************
    > File Name: HDU1257tanxin.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 01 Feb 2017 10:04:19 AM
 ************************************************************************/

#include<iostream>
using namespace std;
int n, a[1000], d[1000];
int main()
{
	while(cin >> n)
	{
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			d[i] = 1;
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < i; j++)
				if(a[i] > a[j] && d[i] < d[j] + 1)
					d[i] = d[j] + 1;
		int	max = -1;
		for(int i = 0; i < n; i++)	
			if(max < d[i])
				max = d[i];
		cout << max << endl;
	}
	return 1;
}
