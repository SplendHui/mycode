#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int map[26][26];
int vis[26];
void DFS(int k)
{
	vis[k] = 1;
	for (int i = 0; i < 26; i++)
		if (map[k][i] && !vis[i])
			DFS(i);
}
int main()
{
	string s;
	int i = 0; 
	freopen("t.in", "r", stdin);
	while (cin >> s)
	{
		memset(vis, 0, sizeof(vis));
		memset(map, 0, sizeof(map));
		map[s[0] - 'a'][s[s.length() - 1]-'a'] = 1;
		while(cin >> s, s != "0") 
			map[s[0] - 'a'][s[s.length() - 1] - 'a'] = 1;
		DFS('b'-'a');
		if (vis['m' - 'a'])
			cout << "Yes." << endl;
		else
			cout << "No." << endl;
	}
	return 1;
}