/*************************************************************************
    > File Name: HDU1050.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 26 Jan 2017 09:08:01 AM
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int i, j, t, n;
	int a, b;
	int temp;
	int room[202];
	cin >> t;
	while(t--)
	{
		cin >> n;
		memset(room, 0, sizeof(room));
		for(i = 0; i < n; i++)
		{
			cin >> a >> b;
			if(a>b)
			{
				temp = a;
				a = b;
				b = temp;
			}
			for(j = (a+1)/2; j < (b+1)/2; j++)
				room[j]++;
		}
		temp = 0;
		for(i = 1; i < 202; i++)
			if(temp < room[i])
				temp = room[i];
		cout << temp*10 << endl;
	}
	return 1;
}
