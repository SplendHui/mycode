#include<iostream>
#include<cmath>
using namespace std;
int isPrime(int x)
{
	if (x == 0 || x == 1)
		return 0;
	int i;
	int k = (int)sqrt(x);
	for (i = 2; i <= k; i++)
		if (x % i == 0)
			break;
	if (i > k)
		return 1;
	return 0;
}
int main()
{
	int x;
	int i;
	int cnt = 0;
	while (cin >> x, x)
	{
		cnt = 0;
		for (i = 1; i < x / 2; i++)
			if (isPrime(i) && isPrime(x-i))
				cnt++;
		cout << cnt << endl;
	}
	return 0;
}