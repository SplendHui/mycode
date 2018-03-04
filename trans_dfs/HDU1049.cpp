/*************************************************************************
    > File Name: HDU1049.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Wed 25 Jan 2017 09:29:19 PM
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){

	int n, u, d;
	while( cin >> n >> u >> d)
	{
		if(n == 0 && u == 0 && d == 0)
			break;
		int t = (n-u)/(u-d);
		if(t*(u-d) < n-u) t++;
		t = t * 2;
		t++;
		cout << t << endl;
	}
	return 1;
}
