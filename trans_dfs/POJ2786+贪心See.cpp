#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
struct node
{
	int a, b;
	friend bool operator < (const node &a, const node &b)
	{
		return a.a < b.a;//�ȳ�����������
	}
}a[900000];//����̫С���У�
int cmp(const node &a, const node &b)
{
	return a.b < b.b;
}
int main()
{
	int n, i;
	priority_queue<node> Q;
	while (scanf("%d",&n) == 1)
	{
		for (i = 0; i < n; i++)
			cin >> a[i].a >> a[i].b;
		sort(a, a + n,cmp);
		while (!Q.empty()) Q.pop();
		int sum = 0;
		for (i = 0; i < n; i++)
		{
			Q.push(a[i]);
			sum += a[i].a;
			if (sum > a[i].b)
			{
				sum -= Q.top().a;
				Q.pop();
			}
		}
		cout << Q.size() << endl;
	}
	return 0;
}