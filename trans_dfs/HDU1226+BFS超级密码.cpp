#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node
{
	int pre;
	int mod;
	int digit;
	int step;
}Q[5005], init = { -1,0,0,0 };
int N, C, M, flag;
int num[17];
int used[5005];
void Print(int rear)
{
	if (Q[rear].pre == -1)
		return;
	Print(Q[rear].pre);
	if (Q[rear].digit > 10)
		printf("%c", Q[rear].digit + 'A' - 10);
	else
		printf("%c", Q[rear].digit + '0');
}
void BFS()
{
	memset(used, 0, sizeof(used));
	int front = 0, rear = 1;
	Q[0] = init;
	flag = 0;
	while (front != rear && !flag)
	{
		node p = Q[front];
		for (int i = 0; i < M; i++)
		{
			int ans = (p.mod * C + num[i]) % N;
			if (used[ans] || p.pre == -1 && num[i] == 0 || p.step >= 500)//num[i] 第一个0没有意义；
				continue;
			Q[rear].digit = num[i];
			Q[rear].mod = ans;
			Q[rear].pre = front;
			Q[rear].step = p.step + 1;
			if (ans == 0)
			{
				Print(rear);
				printf("\n");
				flag = 1;
				break;
			}
			rear++;
		}
		front++;
	}
	if (!flag)
		printf("give me the bomb please\n");
}
int main()
{
	int T;
	freopen("t.in", "r", stdin);
	cin >> T;
	char str[2];
	while (T--)
	{
		cin >> N >> C;
		cin >> M;
		for (int i = 0; i < M; i++)
		{
			scanf("%s", str);
			if (str[0] >= '0' && str[0] <= '9')
				num[i] = str[0] - '0';
			else
				num[i] = str[0] - 'A' + 10;
		}
		sort(num, num + M);
		BFS();
	}
	return 1;
}