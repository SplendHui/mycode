/*
Description
��̫���Ĺ���𽥱������ڱΣ�����ʧȥ�˹��������ӭ����ڰ���ʱ�̡���������������ʱ�̣�����ȴ�쳣�˷ܡ���������������֮�꿴��500��һ����������ۣ����Ƕ�ô�Ҹ����¶���~~ 
����·��������ôЩ��վ����ʼ�������ڵĺ����ģ����Ž�����ʳ����ţ���������������Сt���ҳ�Ϊ�ܺ���֮һ��Сt���������������Ҫ�����������д���������վ���ҳ�������Ȼ��˭��֪�����ǲ����ܵġ�Сtȴִ��Ҫ����ⲻ�ܵ�������˵������������������Ҳ�������޹���������ˣ��� 
���¿�ͷ�ѣ�Сt�ռ��˺öಡ���������룬���ռ���һ��������վ��Դ�룬����֪����Щ��վ����Щ���в����ģ����Ǵ��������Ĳ����أ�˳�㻹��֪���������ռ��˶��ٴ���������վ����ʱ����ȴ��֪���δ������ˡ����������Ұ��æ��Сt���Ǹ�������Ŷ�����Խ������Խ��Խ��Ŷ~~ 
Input
��һ�У�һ������N��1<=N<=500������ʾ����������ĸ����� 
������N�У�ÿ�б�ʾһ�����������룬�������ַ���������20��200֮�䡣 
ÿ����������һ����ţ�����Ϊ1��N�� 
��ͬ��ŵĲ��������벻����ͬ�� 
����֮��һ�У���һ������M��1<=M<=1000������ʾ��վ���� 
������M�У�ÿ�б�ʾһ����վԴ�룬Դ���ַ���������7000��10000֮�䡣 
ÿ����վ����һ����ţ�����Ϊ1��M�� 
�����ַ������ַ�����ASCII��ɼ��ַ����������س����� 
Output
���ΰ����¸�ʽ�������վ��Ŵ�С�������������������վ��źͰ���������ţ�ÿ��һ��������վ��Ϣ�� 
web ��վ���: ������� ������� �� 
ð�ź���һ���ո񣬲�����Ű���С�������У������������֮����һ���ո���������һ����վ�������������������ᳬ��3���� 
���һ�����ͳ����Ϣ�����¸�ʽ 
total: ��������վ�� 
ð�ź���һ���ո� 
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
���˺ü�������
�����ǿ��ܺ��пո�Ҫ��gets�����ҹ��˻���
�ڶ��ǳ��˸��ڵ������㶼�������ظ�����
�������ǲ��������ܰ�������3��������վ�������WA�˼��κ�ֱ����
sort��������
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
char str[201];//��ĿҪ��
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
            memset(tree[cnt],0,sizeof(tree[cnt]));//��ʼ���µĽڵ�
            word[cnt]=0;
            tree[p][c]=cnt++;
        }
        p=tree[p][c];
    }
    word[p]=val;//���浥�ʵ����
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
            if(tt!=0)//���˸��ڵ㶼�������ظ���
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
    while(scanf("%d/n",&n)!=EOF)//ע�⻻��
    {
        cas=0;
        fail[0]=0;
        memset(tree[0],0,sizeof(tree[0]));//��ʼ�����ڵ�
        cnt=1;//�Ѿ��и��ڵ�
        for(int i=1; i<=n; ++i)
        {
            //scanf("%s",str);.//ע����ܺ��пո�
            gets(str);
            Ins(str,i);//��ͬ�ĵ�����tri���в�ͬ��λ��
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
