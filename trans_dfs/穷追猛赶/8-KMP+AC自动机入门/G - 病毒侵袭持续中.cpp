/*
Description
Сt�ǳ���л��Ұ�æ�����������һ�����⡣Ȼ��������Ϯ�����С���Сt�Ĳ�иŬ���£�����������·�еġ����֮Դ��������һ���Ӵ�Ĳ�����վ�������źö�ö�Ĳ��������������վ�����Ĳ�������֣���Щ������������̣ܶ�����ֻ������Ӣ�Ĵ�д�ַ�������ȻСt�������Ϊ�����������Сt��������û��׼����ս����֪��֪�ˣ���ս������Сt����Ҫ������֪�����������վ�������������ٲ�ͬ�Ĳ�����ÿ�ֲ��������˶��ٴΡ�������ٰ������ 
Input
��һ�У�һ������N��1<=N<=1000������ʾ����������ĸ����� 
������N�У�ÿ�б�ʾһ�����������룬�������ַ���������1��50֮�䣬����ֻ������Ӣ�Ĵ�д�ַ����������������������룬������ȫ��ͬ�� 
����֮��һ�У���ʾ�����֮Դ����վԴ�룬Դ���ַ���������2000000֮�ڡ��ַ������ַ�����ASCII��ɼ��ַ����������س����� 
Output
�����¸�ʽÿ��һ�������ÿ���������ִ�����δ���ֵĲ�������Ҫ����� 
����������: ���ִ��� 
ð�ź���һ���ո񣬰����������������˳���������� 
Sample Input
3
AA
BB
CC
ooxxCC%dAAAoen....END
Sample Output
AA: 2
CC: 1

*/
#include<cstdio>
#include<cstring>
using namespace std;

const int kind = 26; //�ж������ַ�
const int N = 1005;
const int M = 2000005;
struct node
{
    node *next[kind];
    node *fail;
    int id;//�������
    node() {
        for(int i = 0; i < kind; i++)
            next[i] = NULL;
        fail = NULL;
        id = 0;
    }
}*q[51*N];
node *root;
int head, tail;
char source[M], s[M];
char vir[N][55];
int cnt[N];

void Insert(char *str, int id)
{
    node *p = root;
    int i = 0, index;
    while(str[i]) {
        index = str[i] - 'A';
        if(p->next[index] == NULL)
            p->next[index] = new node();
        p = p->next[index];
        i++;
    }
    p->id = id;
}
void build_ac_automation(node *root)
{
    root->fail = NULL;
    q[tail++] = root;
    node *p = NULL;
    while(head < tail) {
        node *temp = q[head++];
        for(int i = 0; i < kind; i++) {
            if(temp->next[i] != NULL) {
                if(temp == root) temp->next[i]->fail = root;
                else {
                    p = temp->fail;
                    while(p != NULL) {
                        if(p->next[i] != NULL) {
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p == NULL) temp->next[i]->fail = root;
                }
                q[tail++] = temp->next[i];
            }
        }
    }
}
void Query(char *str)
{
    int i = 0, index;
    node *p = root;
    while(str[i]) {
        index = str[i] - 'A';
        while(p->next[index] == NULL && p != root) p = p->fail;
        p = p->next[index];
        if(p == NULL) p = root;
        node *temp = p;
        while(temp != root && temp->id > 0) {
            cnt[temp->id]++;
            temp = temp->fail;
        }
        i++;
    }
}

int main()
{
    int n;
    while(~scanf("%d",&n)) {
        memset(cnt, 0, sizeof(cnt));
        head = tail = 0;
        root = new node();
      for(int i = 1; i <= n; i++) {
            scanf("%s", vir[i]);
            Insert(vir[i], i);
        }
        build_ac_automation(root);
        scanf("%s",source);
        int len = strlen(source);
        int l = 0;
        for(int i = 0; i <= len; i++) {
            if(source[i] >= 'A' && source[i] <= 'Z') //��Ϊ������ֻ�д�д��ĸ������ֻ���������Ĵ�д��ĸ��ɵ��ַ���
                s[l++] = source[i];
            else {
                s[l] = '\0';
                Query(s);
                l = 0;
            }
        }
        for(int i = 1; i <= n; i++)
            if(cnt[i])
                printf("%s: %d\n",vir[i], cnt[i]);
    }
    return 0;
}