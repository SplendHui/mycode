#include<iostream>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;
char s[30], t[6];
int a[30];
int n, target;
int num = 0;
int flag;
struct node {
	char c;
	int dir[100];
};
int Judge(int n, int k)
{
	int i;
	for (i = 0; i < n; i++)
		if (s[k] == t[i])
			return 0;
	return 1;
}

int DFS()
{
	stack<node> S;
	node p;
	int i, k, temp;
	node ttt;
	node tttt;
	tttt.c = 'A';
	for (i = 0; i < n; i++)
		tttt.dir[i] = 0; 
	num = 0;
	for (k = 0; k < n; k++)
	{
		t[num++] = s[k];
		ttt = tttt;
		ttt.c = s[k];
		S.push(ttt);
		while (!S.empty())
		{
			p = S.top();
			for (i = 0; i < n; i++)
				if (p.dir[i] == 0)
				{
					if (!Judge(num, i))
					{
						p.dir[i] = 1;
						S.pop(), S.push(p);
						continue;
					}
					p.dir[i] = 1;
					break;
				}
			S.pop(), S.push(p);
			if (i < n)
			{
				node tt;
				t[num++] = s[i];
				tt =  tttt;
				tt.c = s[i];
				S.push(tt);
			}
			else
			{
				S.pop();
				num--;
			}
			if (S.size() == 5)
			{
				temp = a[t[0] - 'A'] - pow(a[t[1] - 'A'], 2) + pow(a[t[2] - 'A'], 3) - pow(a[t[3] - 'A'], 4) + pow(a[t[4] - 'A'], 5);
				if (temp == target)
				{
					cout << t << endl;
					return 1;
				}
				S.pop();
				num--;
			}
		}
	}
	return 0;
}
int main()
{
	int i, j;
	for (i = 0; i < 26; i++)
		a[i] = i + 1;
	freopen("t.in", "r", stdin);
	while (cin >> target >> s && (target || strcmp(s, "END")))
	{
		flag = 0;
		n = strlen(s);
		flag = DFS();
		if (!flag)
			cout << "no solution" << endl;
	}
	return 1;
}
