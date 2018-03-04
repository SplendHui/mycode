#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	char c;
	int count;
}a[5] = { {'A',0},{ 'C',0 },{ 'D',0 },{ 'E',0 },{ 'G',0 } };
int cmp(struct node a, struct node b)
{
	if (a.count != b.count) return a.count > b.count;
	else
		return a.c < b.c;
}
void Insert(char b)
{
	int i;
	for (i = 0; i < 5; i++)
		if (a[i].c == b)
			a[i].count++;
}
int main()
{
	int n, m;
	int i, j;
	char cc;
//	freopen("t.in", "r", stdin);
	while (scanf("%d%d", &n, &m) == 2 )
	{
		if (m == 0 && n == 0)
			break;
		for (i = 0; i < 5; i++)
			a[i].count = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				scanf(" %c", &cc);
				Insert(cc);
			}
		sort(a, a + 5, cmp);
		for (i = 0; i < 5; i++)
			if (a[i].count != 0)
				printf("%c %d ", a[i].c, a[i].count);
		printf("\n");
	}
	return 0;
}
