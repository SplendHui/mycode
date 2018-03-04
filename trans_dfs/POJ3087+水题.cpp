#include<iostream>  
#include<string>  
using namespace std;
int cas, c, ans;
string s, bs, s12, s1, s2;

void shuf(string s1, string s2)
{
	if (bs == s) return;
	++ans;
	int i = -1, j = -1, k;
	string ss1, ss2;
	for (k = 0; k < c; ++k)
		ss1 += (i == j ? s2[++i] : s1[++j]);
	for (k = 0; k < c; ++k)
		ss2 += (i == j ? s2[++i] : s1[++j]);
	s12 = ss1 + ss2;
	if (s12 == s || s12 == bs) return;
	else shuf(ss1, ss2);
}

int main()
{
	cin >> cas;
	for (int ca = 1; ca <= cas; ++ca)
	{
		ans = 0;
		cin >> c >> s1 >> s2 >> s;
		bs = s1 + s2;
		shuf(s1, s2);
		if (s12 != s) ans = -1;
		cout << ca << " " << ans << endl;
	}
	return 0;
}