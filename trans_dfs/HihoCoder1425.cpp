#include<iostream>
using namespace std;
int main()
{
	int n;
	int i;
	int a[102];
//	freopen("t.in", "r", stdin);
	while (cin >> n, n)
	{
		int cnt, k;
		cnt = k = 0;
		for (i = 0; i < n; i++)
			cin >> a[i];
		int j;
		if (n == 1)
		{
			cout << 0 << endl;
			continue;
		}
		for (i = 0; i < n; i++)
		{
			j = i;
			if (a[(j + 1) % n] > a[j])
				while (a[(j + 1) % n] > a[j])
				{
					j = (j + 1) % n;
					k++;
				}
			else if (a[(j + 1) % n] < a[j])
				while (a[(j + 1) % n] < a[j])
				{
					j = (j + 1) % n;
					k++;
				}
			if (k > cnt)
				cnt = k;
			k = 0;
		}
		cout << cnt << endl;
	}
	return 0;
}
/*4
1 1 1 1
8
5 1 2 3 4 5 6 2
6
5 4 3 2 1 2
10
1 0 2 3 2 2 3 4 3 2
0
*/