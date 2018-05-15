#include <iostream> // C++写的
#include <string>
#include <queue>
#include <stack>
using namespace std;
struct Tree
{
	char val;
	Tree *lchild;
	Tree *rchild;
};

Tree *createTree(string pre, string in) //根据先序中序建树。
{
	Tree *root = NULL;
	if (pre.length() > 0)
	{
		root = new Tree();
		root->val = pre[0];
		int index = in.find(pre[0]);
		root->lchild = createTree(pre.substr(1, index), in.substr(0, index));
		root->rchild = createTree(pre.substr(index + 1), in.substr(index + 1));
	}
	return root;
}

/* 根据中后遍历建树。
Tree *createTree(string in, string po){

	Tree *root = NULL;

	if( in.length() > 0 )
	{
		root = new Tree;
		root->val = *(po.end()-1);
		int index = in.find(root->val);
		int r_len = po.length() - index -1;
		root->left = createTree(in.substr(0,index), po.substr(0,index) );
		root->right = createTree(in.substr(index+1),po.substr(index,r_len) );
	}
	return root;
}
*/
void PreOrder(Tree *root) //先序遍历（递归实现）。
{
	if (root)
	{
		cout << root->val << " ";
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
	else
		return;
}
void TraverseRootFirst(Tree *root) //非递归实现先序遍历
{
	Tree *tp = root;
	Tree *stack[1000];
	int top = -1;
	while (tp || top != -1)
	{
		while (tp)
		{
			cout << tp->val << " ";
			stack[++top] = tp;
			tp = tp->lchild;
		}
		tp = stack[top--];
		tp = tp->rchild;
	}
	cout << endl;
}
void Inorder(Tree *root) //中根序输出（递归）。
{
	if (root)
	{
		Inorder(root->lchild);
		cout << root->val << " ";
		Inorder(root->rchild);
	}
	else
		return;
}
void TraverseRootSecond(Tree *root) // 非递归的中根序遍历
{
	Tree *stack[200]; // 栈
	int top = -1;	 // 栈顶指针及其初始化
	//************************************************
	Tree *tp = root;
	while (tp || top != -1)
	{
		while (tp)
		{
			stack[++top] = tp;
			tp = tp->lchild;
		}
		tp = stack[top--];
		cout << tp->val << " ";
		tp = tp->rchild;
	}
	cout << endl;
	//================================================
}
void postOrder(Tree *root) //后序输出递归。
{
	if (root)
	{
		postOrder(root->lchild);
		postOrder(root->rchild);
		cout << root->val << " ";
	}
	else
		return;
}
void TraverRootThird(Tree *root)
{
	Tree *p = root;
	stack<Tree *> Q;
	Tree *last = root;
	Q.push(p);
	while (!Q.empty())
	{
		p = Q.top();
		if ((p->lchild == NULL && p->rchild == NULL) || (p->rchild == NULL && last == p->lchild) || (last == p->rchild))
		{
			cout << p->val << " ";
			last = p;
			Q.pop();
		}
		else
		{
			if (p->rchild)
				Q.push(p->rchild);
			if (p->lchild)
				Q.push(p->lchild);
		}
	}
} /*
void TraverRootThird(Tree *root)//非递归后序遍历的第二种方法。
{
	Tree *p = root;
	stack<Tree *> Q;
	Q.push(root);
	Q.push(root);
	p = root;
	while( !Q.empty() )
	{
		p = Q.top();
		Q.pop();
		if( !Q.empty() && p == Q.top())
		{
			if( p->rchild )
			Q.push(p->rchild), Q.push(p->rchild);
			if( p->lchild )
			Q.push(p->lchild), Q.push(p->lchild);
		}
		else
			cout << p->val << " ";
	}
}*/
void LevelTraver(Tree *Root)
{
	queue<Tree *> Q;
	Q.push(Root);
	while (!Q.empty())
	{
		Tree *root = Q.front();
		Q.pop();
		cout << root->val << " ";
		if (root->lchild != NULL)
			Q.push(root->lchild);
		if (root->rchild != NULL)
			Q.push(root->rchild);
	}
	cout << endl;
}
void destroyTree(Tree *root)
{
	if (root)
	{
		destroyTree(root->lchild);
		destroyTree(root->rchild);
		delete root;
	}
	else
		return;
}
int CountLeaf(Tree *root)
{
	if (root == NULL)
		return 0;
	else
	{
		if (root->lchild == NULL && root->rchild == NULL)
			return 1;
		else
			return (CountLeaf(root->lchild) + CountLeaf(root->rchild));
	}
}

int bTreeDepth(Tree *root)
{
	if (!root)
		return 0;
	else
	{
		int dep1 = bTreeDepth(root->lchild);
		int dep2 = bTreeDepth(root->rchild);
		if (dep1 >= dep2)
			return dep1 + 1;
		else
			return dep2 + 1;
	}
}
void TraverLeaf(Tree *root)
{

	if (root)
	{
		if (root->lchild == NULL && root->rchild == NULL)
			printf("%c ", root->val);
		TraverLeaf(root->lchild);
		TraverLeaf(root->rchild);
	}
	else
		return;
}
int main()
{
	//	freopen("bTree1.in", "r", stdin);
	//	freopen("bTree1.out", "w", stdout);
	string pre, in;
	cin >> pre >> in;
	Tree *root = createTree(pre, in); //先中序建树。
	int level = bTreeDepth(root);
	int count = CountLeaf(root);
	cout << "二叉树的深度为：" << level << endl;
	cout << "二叉树叶子数目：" << count << endl;
	cout << endl;

	cout << "遍历树叶子节点："; //遍历叶子节点
	TraverLeaf(root);
	cout << endl;

	cout << "递归的先序遍历："; //先序遍历
	PreOrder(root);
	cout << endl;

	cout << "非递归先序遍历："; //中序遍历
	TraverseRootFirst(root);
	cout << endl;

	cout << "递归的中序遍历："; //后序遍历
	Inorder(root);
	cout << endl;

	cout << "非递归中序遍历：";
	TraverseRootSecond(root);
	cout << endl;

	cout << "递归的后序遍历: ";
	postOrder(root);
	cout << endl;

	cout << "非递归后序遍历: ";
	TraverRootThird(root);
	cout << endl;

	cout << endl;
	cout << "二叉树层次遍历: ";
	LevelTraver(root);
	cout << endl;

	destroyTree(root); //delete节点释放空间
	cout << endl;
	return 0;
}
