/*************************************************************************
    > File Name: HDU1052.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 26 Jan 2017 12:40:43 PM
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i, n;
	int Ti[1001], Ki[1001];
	while(cin>>n, n)
	{
		for(i = 0; i < n; i++)
			cin >> Ti[i];
		for(i = 0; i < n; i++)
			cin >> Ki[i];
		sort(Ti, Ti+n);
		sort(Ki, Ki+n);
		int Ki_max, Ti_max, Ki_min, Ti_min, sum = 0;
		Ki_max = Ti_max = n - 1;
		Ki_min = Ti_min = 0;
		while(Ki_min <= Ki_max && Ti_min <= Ti_max)	
		{
			if(Ti[Ti_max] > Ki[Ki_max])
			{
				sum = sum + 200;
				Ki_max--;
				Ti_max--;
			}
			else if(Ti[Ti_max] < Ki[Ki_max])
			{
				sum = sum - 200;
				Ki_max--;
				Ti_min++;
			}
			else
			{
				if(Ti[Ti_min] > Ki[Ki_min])
				{
					sum = sum + 200;
					Ti_min++;
					Ki_min++;
				}
				else if(Ti[Ti_min] < Ki[Ki_min])
				{
					sum = sum - 200;
					Ti_min++;
					Ki_max--;
				}
				else
				{
					if(Ti[Ti_min] < Ki[Ki_max])
						sum = sum - 200;
					Ti_min++;
					Ki_max--;
				}

			}
		}
		cout << sum << endl;
	}
	return 1;
}
