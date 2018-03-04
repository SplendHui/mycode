#include<iostream>
using namespace std;
int flag;
typedef struct treeNode
{
	int isPhone;
	treeNode *next[10];
	treeNode()
	{
		for (int i = 0; i < 10; i++)
			next[i] = NULL;
		isPhone = 0;
	}
}Tnode;
Tnode * root;
void Insert(char *s)
{
	Tnode *p = root;
	char *p1 = s;
	int i;
	while ((*p1) != '\0')
	{
		if (p->next[*p1 - 48] == NULL)
		{
			Tnode *t = new treeNode();
			p->next[*p1 - 48] = t;
		}
		if (p->isPhone)
			flag = 1;
		p = p->next[*p1 - 48];
		p1++;
	}
	p->isPhone = 1;
	for (i = 0; i < 10; i++)
		if (p->next[i] != NULL)
		{
			flag = 1;
			break;
		}
}
void Delete(Tnode *p)
{
	int i;
	for (i = 0; i < 10; i++)
		if (p->next[i] != NULL)
			Delete(p->next[i]);
	delete p;
}
int main()
{
	int T;
	int i, j, n;
	char s[100];
	cin >> T;
	while (T--)
	{
		cin >> n;
		flag = 0;
		root = new treeNode();
		root->isPhone = 0;
		for (i = 0; i < n; i++)
		{
			cin >> s;
			if (!flag)
				Insert(s);
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "NO" << endl;
		Delete(root);
	}
	return 0;
}