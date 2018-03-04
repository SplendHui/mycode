/*
Description
In the modern time, Search engine came into the life of everybody like Google, Baidu, etc. 
Wiskey also wants to bring this feature to his image retrieval system. 
Every image have a long description, when users type some keywords to find the image, the system will match the keywords with description of image and show the image which the most keywords be matched. 
To simplify the problem, giving you a description of image, and some keywords, you should tell me how many keywords will be match. 
Input
First line will contain one integer means how many cases will follow by. 
Each case will contain two integers N means the number of keywords and N keywords follow. (N <= 10000) 
Each keyword will only contains characters 'a'-'z', and the length will be not longer than 50. 
The last line is the description, and the length will be not longer than 1000000. 
Output
Print how many keywords are contained in the description.
Sample Input
1
5
she
he
say
shr
her
yasherhs
Sample Output
3
*/
/*
 * acm.hdu.edu.cn
 * Problem#2222
 * Accepted
 * Time:296ms
 * Memory:58152k 
 */
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define SEG_SIZE 26
typedef class TrieNode{
    public:
        TrieNode* next[SEG_SIZE];
        TrieNode* fail;                    //失配指针 
        TrieNode* last;                    //后缀链接 
        int value;
        TrieNode():fail(NULL),last(NULL),value(0){
            memset(next, 0, sizeof(next));
        }
}TrieNode;
typedef class Trie {
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
        static int cti(char ch){        //将字符转换成Trie树中next数组的下标 
            return ch - 'a';
        }
        void insert(string s){
            TrieNode *p = root;
            for(int i = 0;i < s.length();i++){
                int c = cti(s[i]);
                if(p->next[c] == NULL){
                    TrieNode *newNode = new TrieNode();
                    p->next[c] = newNode;     //链接结点 
                }
                p = p->next[c];
            }
            p->value++;                        //用结点的特殊值来存储有多少个单词是在这结尾 
        }
}Trie;
typedef class AhoMachine{
    public:    
        Trie trie;
        int count;
        AhoMachine(){
            trie = Trie();
            count = 0;
        }
        void getFail(){
            queue<TrieNode*> que;                    //以bfs序构造状态转移图 
            trie.root->fail = trie.root;
            for(int i = 0;i < SEG_SIZE;i++){
                TrieNode* pNode = trie.root->next[i];
                if(pNode != NULL){
                    que.push(pNode);
                    pNode->fail = trie.root;        //根节点的直接子节点的失配指针都是指向根节点 
                }
            }
            while(!que.empty()){
                TrieNode* p = que.front();
                que.pop();
                for(int i = 0;i < SEG_SIZE;i++){
                    TrieNode* pNode = p->next[i];
                    if(pNode == NULL)    continue;
                    que.push(pNode);
                    TrieNode* pFail = p->fail;
                    //直到匹配，或者已经指向了根节点 
                    while(pFail != trie.root && pFail->next[i] == NULL)    pFail = pFail->fail;
                    pNode->fail = pFail->next[i];
                    if(pNode->fail == NULL) pNode->fail = trie.root;
                    //后缀链接的链接，指向失配后的结点或失配后的结点的后缀链接 
                    pNode->last = (pNode->fail->value != 0)?(pNode->fail):(pNode->fail->last);
                }
            }
        }
        //当匹配完，或者是在一条链的中途仍然可能存在有匹配的结点 
        void rfind(TrieNode *p){
            if(p != NULL){
                count += p->value;
                rfind(p->last);
                p->value = 0;
            }
        }
        void find(string s){
            TrieNode *pNode = trie.root;
            for(int i = 0;i < s.length();i++){
                int c = Trie::cti(s[i]);
                while(pNode != trie.root && pNode->next[c] == NULL)    pNode = pNode->fail;
                pNode = pNode->next[c];
                if(pNode == NULL) pNode = trie.root;
                if(pNode->value != 0)    rfind(pNode);            //判断有没有可能匹配完其它的模板 
                else if(pNode->last != NULL) rfind(pNode->last);
            }
        }
}AC;
AC *ac;
int cases;
string buf;
int n;
int main(){
    ios::sync_with_stdio(false);            //取消同步，加快cin读取字符串的速度 
    cin>>cases;
    while(cases--){
        ac = new AC();
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>buf;
            ac->trie.insert(buf);
        }
        cin>>buf;
        ac->getFail();
        ac->find(buf);
        cout<<ac->count<<endl;
        delete ac;
    }
    return 0;
}