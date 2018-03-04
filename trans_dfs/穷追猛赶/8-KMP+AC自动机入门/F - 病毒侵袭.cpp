/*
Description
当太阳的光辉逐渐被月亮遮蔽，世界失去了光明，大地迎来最黑暗的时刻。。。。在这样的时刻，人们却异常兴奋——我们能在有生之年看到500年一遇的世界奇观，那是多么幸福的事儿啊~~ 
但网路上总有那么些网站，开始借着民众的好奇心，打着介绍日食的旗号，大肆传播病毒。小t不幸成为受害者之一。小t如此生气，他决定要把世界上所有带病毒的网站都找出来。当然，谁都知道这是不可能的。小t却执意要完成这不能的任务，他说：“子子孙孙无穷匮也！”（愚公后继有人了）。 
万事开头难，小t收集了好多病毒的特征码，又收集了一批诡异网站的源码，他想知道这些网站中哪些是有病毒的，又是带了怎样的病毒呢？顺便还想知道他到底收集了多少带病毒的网站。这时候他却不知道何从下手了。所以想请大家帮帮忙。小t又是个急性子哦，所以解决问题越快越好哦~~ 
Input
第一行，一个整数N（1<=N<=500），表示病毒特征码的个数。 
接下来N行，每行表示一个病毒特征码，特征码字符串长度在20—200之间。 
每个病毒都有一个编号，依此为1—N。 
不同编号的病毒特征码不会相同。 
在这之后一行，有一个整数M（1<=M<=1000），表示网站数。 
接下来M行，每行表示一个网站源码，源码字符串长度在7000—10000之间。 
每个网站都有一个编号，依此为1—M。 
以上字符串中字符都是ASCII码可见字符（不包括回车）。 
Output
依次按如下格式输出按网站编号从小到大输出，带病毒的网站编号和包含病毒编号，每行一个含毒网站信息。 
web 网站编号: 病毒编号 病毒编号 … 
冒号后有一个空格，病毒编号按从小到大排列，两个病毒编号之间用一个空格隔开，如果一个网站包含病毒，病毒数不会超过3个。 
最后一行输出统计信息，如下格式 
total: 带病毒网站数 
冒号后有一个空格。 
Sample Input
3
aaa
bbb
ccc
2
aaabbbccc
bbaacc
Sample Output
web 1: 1 2 3
total: 1
*/
/*
反了好几个错误
首先是可能含有空格，要用gets，并且过滤换行
第二是除了根节点其他点都不可以重复访问
第三是是不是最后可能包含超过3个病毒网站，我最后WA了几次后直接用
sort排序算了
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int NODE=210*510;
const int CH=129;
int tree[NODE][CH],cnt;
int word[NODE];
int fail[NODE];
int Que[NODE];
char str[201];//题目要求
char s[10010];
bool vis[NODE];
int cou,cout[NODE];
int cas;
void Ins(char *a,int val)
{
    int p=0;
    for(; *a; a++)
    {
        int c=*a;
        if(!tree[p][c])
        {
            memset(tree[cnt],0,sizeof(tree[cnt]));//初始化新的节点
            word[cnt]=0;
            tree[p][c]=cnt++;
        }
        p=tree[p][c];
    }
    word[p]=val;//保存单词的序号
}
void AC()
{
    int *s=Que,*e=Que;
    for(int i=0; i<CH; ++i)
        if(tree[0][i])
        {
            fail[tree[0][i]]=0;
            *e++=tree[0][i];
        }
    while(s!=e)
    {
        int p=*s++;
        for(int i=0; i<CH; ++i)
        {
            if(tree[p][i])
            {
                int v=tree[p][i];
                *e++=v;
                fail[v]=tree[fail[p]][i];
            }
            else
            {
                tree[p][i]=tree[fail[p]][i];
            }
        }
    }
}
int query(char *a)
{
    int p=0;
    for(int c=*a; *a; a++,c=*a)
    {
        p=tree[p][c];
        int pp=p;
        int tt=word[pp];
        while(pp&&vis[tt]==0)
        {
            if(tt!=0)//除了根节点都不可以重复走
            {
                cout[++cou]=tt;
                vis[tt]=1;
            }
            pp=fail[pp];
            tt=word[pp];
        }
    }
    return cou;
}
void print()
{
    if(cou>=1)
    {
        printf("web %d:",cas);
        if(cou==1)
        {
            printf(" %d/n",cout[1]);
        }
        else if(cou==2)
        {
            if(cout[1]>cout[2])  printf(" %d %d/n",cout[2],cout[1]);
            else printf(" %d %d/n",cout[1],cout[2]);
        }
        else
        {
            sort(cout+1,cout+cou+1);
            for(int i=1; i<=cou; ++i) printf(" %d",cout[i]);
            printf("/n");
        }
    }
}
int main()
{
    int n,m;
    cas=0;
    while(scanf("%d/n",&n)!=EOF)//注意换行
    {
        cas=0;
        fail[0]=0;
        memset(tree[0],0,sizeof(tree[0]));//初始化根节点
        cnt=1;//已经有根节点
        for(int i=1; i<=n; ++i)
        {
            //scanf("%s",str);.//注意可能含有空格
            gets(str);
            Ins(str,i);//不同的单词在tri树中不同的位置
        }
        AC();
        scanf("%d/n",&m);
        int sum=0;
        //printf("m=%d/n",m);
        while(m--)
        {
            cas++;
            cou=0;
            memset(vis,0,sizeof(vis));
            gets(s);
            query(s);
            if(cou!=0)  sum++;
            print();
        }
        printf("total: %d/n",sum);
    }
    return 0;
}
