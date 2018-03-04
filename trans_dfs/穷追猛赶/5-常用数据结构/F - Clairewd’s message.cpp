/*
Description
Clairewd is a member of FBI. After several years concealing in BUPT, she intercepted some important messages and she was preparing for sending it to ykwd. They had agreed that each letter of these messages would be transfered to another one according to a conversion table. 
Unfortunately, GFW(someone's name, not what you just think about) has detected their action. He also got their conversion table by some unknown methods before. Clairewd was so clever and vigilant that when she realized that somebody was monitoring their action, she just stopped transmitting messages. 
But GFW knows that Clairewd would always firstly send the ciphertext and then plaintext(Note that they won't overlap each other). But he doesn't know how to separate the text because he has no idea about the whole message. However, he thinks that recovering the shortest possible text is not a hard task for you. 
Now GFW will give you the intercepted text and the conversion table. You should help him work out this problem. 
Input
The first line contains only one integer T, which is the number of test cases. 
Each test case contains two lines. The first line of each test case is the conversion table S. S[i] is the ith latin letter's cryptographic letter. The second line is the intercepted text which has n letters that you should recover. It is possible that the text is complete. 
Hint 
Range of test data: 
T<= 100 ; 
n<= 100000; 
Output
For each test case, output one line contains the shorest possible complete text.
Sample Input
2
abcdefghijklmnopqrstuvwxyz
abcdab
qwertyuiopasdfghjklzxcvbnm
qwertabcde
Sample Output
abcdabcd
qwertabcde
*/
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;
const int N = 100010;
char T[N];
char S[N];
int next[N];
int extend[N];
char table[30];
char rtable[30];

void EXTEND_KMP ()
{
	int lens = strlen (S);
	int lent = strlen (T);
	next[0] = lent;
	int i, j, p, L;
	j = 0;
	while (j + 1 < lent && T[j] == T[j + 1])
	{
		++j;
	}
	next[1] = j;
	int a = 1;
	for (i = 2; i < lent; ++i)
	{
		p = next[a] + a - 1;
		L = next[i - a];
		if (i + L < p + 1)
		{
			next[i] = L;
		}
		else
		{
			j = max(0, p - i + 1);
			while (i + j < lent && T[i + j] == T[j])
			{
				++j;
			}
			next[i] = j;
			a = i;
		}
	}
	j = 0;
	while (j < lens && S[j] == T[j])
	{
		++j;
	}
	extend[0] = j;
	a = 0;
	for (i = 1; i < lens; ++i)
	{
		p = extend[a] + a - 1;
		L = next[i - a];
		if (L + i < p + 1)
		{
			extend[i] = L;
		}
		else
		{
			j = max(0, p - i + 1);
			while (i + j < lens && j < lent && S[i + j] == T[j])
			{
				++j;
			}
			extend[i] = j;
			a = i;
		}
	}
}

int main ()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", table);
		scanf("%s", S);
		int len = strlen (S);
		for (int i = 0; i < 26; ++i)
		{
			rtable[table[i] - 'a'] = 'a' + i;
		}
		for (int i = 0; i < len; ++i)
		{
			T[i] = rtable[S[i] - 'a'];
		}
		T[len] = '\0';
		EXTEND_KMP ();
		bool flag = false;
		int e;
		int mid = len / 2 + (len % 2 ? 1 : 0);
		for (int i = 0; i < len; ++i)
		{
			if (extend[i] + i >= len && i >= mid)
			{
				e = i;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			printf("%s%s\n", S, T);
			continue;
		}
		for (int i = 0; i < e; ++i)
		{
			printf("%c", S[i]);
		}
		for (int i = 0; i < e; ++i)
		{
			printf("%c", T[i]);
		}
		printf("\n");
	}
	return 0;
}