#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 40321;
const int fac[8] = { 1, 1, 2, 6, 24, 120, 720, 5040 };
string ans[MAXN];
struct node
{
	int a[8];
	int n;
}t, p;
void A(node &t) //A²Ù×÷
{
	swap(t.a[0], t.a[7]);
	swap(t.a[1], t.a[6]);
	swap(t.a[2], t.a[5]);
	swap(t.a[3], t.a[4]);
}
void B(node &t) //B²Ù×÷
{
	swap(t.a[3], t.a[2]);
	swap(t.a[2], t.a[1]);
	swap(t.a[1], t.a[0]);
	swap(t.a[4], t.a[5]);
	swap(t.a[5], t.a[6]);
	swap(t.a[6], t.a[7]);
}
void C(node &t) //C²Ù×÷
{
	swap(t.a[1], t.a[6]);
	swap(t.a[6], t.a[5]);
	swap(t.a[5], t.a[2]);
}
int cantor(node &t)
{
	int tmp, num = 0;
	for (int i = 0; i < 8; i++)
	{
		tmp = 0;
		for (int j = i + 1; j < 8; j++)
			if (t.a[j] < t.a[i])
				tmp++;
		num += tmp * fac[7 - i];
	}
	return num;
}
void Init()
{
	void(*ptr[3])(node&);
	ptr[0] = A;
	ptr[1] = B,
	ptr[2] = C;
	int mark[MAXN] = { 1 };
	for (int i = 0; i < 8; i++)
		p.a[i] = i + 1;
	p.n = cantor(p);
	queue<node> Q;
	Q.push(p);
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		for (int i = 0; i < 3; i++)
		{
			t = p;
			ptr[i](t);
			t.n = cantor(t);
			if (mark[t.n] == 0)
			{
				char ch = 'A' + i;
				ans[t.n] = ans[p.n] + ch;
				mark[t.n] = 1;
				Q.push(t);
			}
		}
	}
}
int main() {
	string a, b;
	Init();
	while (cin >> a >> b)
	{
		int n[10];
		for (int i = 0; i < 8; i++)
			n[a[i] - '0'] = i + 1;
		for (int i = 0; i < 8; i++)
			p.a[i] = n[b[i] - '0'];
		cout << ans[cantor(p)] << endl;
	}
	return 1;
}