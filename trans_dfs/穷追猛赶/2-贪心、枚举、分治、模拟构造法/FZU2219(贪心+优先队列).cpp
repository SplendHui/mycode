/*
ZB loves playing StarCraft and he likes Zerg most!

One day, when ZB was playing SC2, he came up with an idea:

He wants to change the queen's ability, the queen's new ability is to choose a worker at any time, and turn it into an egg, after K units of time, two workers will born from that egg. The ability is not consumed, which means you can use it any time without cooling down.

Now ZB wants to build N buildings, he has M workers initially, the i-th building costs t[i] units of time, and a worker will die after he builds a building. Now ZB wants to know the minimum time to build all N buildings.

Input

The first line contains an integer T, meaning the number of the cases. 1 <= T <= 50.

For each test case, the first line consists of three integers N, M and K. (1 <= N, M <= 100000, 1 <= K <= 100000).

The second line contains N integers t[1] ... t[N](1 <= t[i] <= 100000).

Output

For each test case, output the answer of the question.

Sample Input
2
3 1 1
1 3 5
5 2 2
1 1 1 1 10

Sample Output
6
10
*/
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <climits>
# include <iostream>
# include <iomanip>
# include <set>
# include <map>
# include <vector>
# include <stack>
# include <queue>
# include <algorithm>
using namespace std;


const int debug = 1;
const int size  = 5000 + 10; 
const int INF = INT_MAX>>1;
typedef long long ll;

int main()
{
	std::ios::sync_with_stdio(false);cin.tie(0);
	int i,j;
	int T;
	cin >> T;
	priority_queue<int,vector<int>,greater<int> > pri_que;
	while (T--){
		while (!pri_que.empty()) pri_que.pop();
		int n,m,k,tmp;
		cin >> n >> m >> k;
		for (i=0;i<n;i++){
			cin >> tmp;
			pri_que.push(tmp);
		}
		while (pri_que.size()>m){
			pri_que.pop();
			tmp = pri_que.top();
			pri_que.pop();
			pri_que.push(tmp+k);
		}
		while (pri_que.size()>1)
			pri_que.pop();
		cout << pri_que.top() << '\n';
	}
	return 0;
}
