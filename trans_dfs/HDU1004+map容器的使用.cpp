#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	
	int n, max;
	string color, maxcolor;
	map<string,int> ballon;
	while( cin >> n, n )
	{
        ballon.clear();
        while( n-- )
		{
			cin >> color;
			ballon[color]++;	
		}
		map<string, int>::iterator it;
		max = 0;
		for(it = ballon.begin(); it != ballon.end(); it++ )
			if( it->second > max )
			{
				max = it->second;
				maxcolor = it->first;
			}
			cout<<maxcolor<<endl;
	}
	
	return 1;
}
