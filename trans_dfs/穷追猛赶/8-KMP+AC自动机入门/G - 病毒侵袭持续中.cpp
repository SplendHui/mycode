/*
Description
小t非常感谢大家帮忙解决了他的上一个问题。然而病毒侵袭持续中。在小t的不懈努力下，他发现了网路中的“万恶之源”。这是一个庞大的病毒网站，他有着好多好多的病毒，但是这个网站包含的病毒很奇怪，这些病毒的特征码很短，而且只包含“英文大写字符”。当然小t好想好想为民除害，但是小t从来不打没有准备的战争。知己知彼，百战不殆，小t首先要做的是知道这个病毒网站特征：包含多少不同的病毒，每种病毒出现了多少次。大家能再帮帮他吗？ 
Input
第一行，一个整数N（1<=N<=1000），表示病毒特征码的个数。 
接下来N行，每行表示一个病毒特征码，特征码字符串长度在1—50之间，并且只包含“英文大写字符”。任意两个病毒特征码，不会完全相同。 
在这之后一行，表示“万恶之源”网站源码，源码字符串长度在2000000之内。字符串中字符都是ASCII码可见字符（不包括回车）。 
Output
按以下格式每行一个，输出每个病毒出现次数。未出现的病毒不需要输出。 
病毒特征码: 出现次数 
冒号后有一个空格，按病毒特征码的输入顺序进行输出。 
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

const int kind = 26; //有多少种字符
const int N = 1005;
const int M = 2000005;
struct node
{
    node *next[kind];
    node *fail;
    int id;//病毒编号
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
            if(source[i] >= 'A' && source[i] <= 'Z') //因为病毒中只有大写字母，所以只处理连续的大写字母组成的字符串
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