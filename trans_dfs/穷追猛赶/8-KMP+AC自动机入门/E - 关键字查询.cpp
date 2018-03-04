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
        TrieNode* fail;                    //ʧ��ָ�� 
        TrieNode* last;                    //��׺���� 
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
        static int cti(char ch){        //���ַ�ת����Trie����next������±� 
            return ch - 'a';
        }
        void insert(string s){
            TrieNode *p = root;
            for(int i = 0;i < s.length();i++){
                int c = cti(s[i]);
                if(p->next[c] == NULL){
                    TrieNode *newNode = new TrieNode();
                    p->next[c] = newNode;     //���ӽ�� 
                }
                p = p->next[c];
            }
            p->value++;                        //�ý�������ֵ���洢�ж��ٸ������������β 
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
            queue<TrieNode*> que;                    //��bfs����״̬ת��ͼ 
            trie.root->fail = trie.root;
            for(int i = 0;i < SEG_SIZE;i++){
                TrieNode* pNode = trie.root->next[i];
                if(pNode != NULL){
                    que.push(pNode);
                    pNode->fail = trie.root;        //���ڵ��ֱ���ӽڵ��ʧ��ָ�붼��ָ����ڵ� 
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
                    //ֱ��ƥ�䣬�����Ѿ�ָ���˸��ڵ� 
                    while(pFail != trie.root && pFail->next[i] == NULL)    pFail = pFail->fail;
                    pNode->fail = pFail->next[i];
                    if(pNode->fail == NULL) pNode->fail = trie.root;
                    //��׺���ӵ����ӣ�ָ��ʧ���Ľ���ʧ���Ľ��ĺ�׺���� 
                    pNode->last = (pNode->fail->value != 0)?(pNode->fail):(pNode->fail->last);
                }
            }
        }
        //��ƥ���꣬��������һ��������;��Ȼ���ܴ�����ƥ��Ľ�� 
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
                if(pNode->value != 0)    rfind(pNode);            //�ж���û�п���ƥ����������ģ�� 
                else if(pNode->last != NULL) rfind(pNode->last);
            }
        }
}AC;
AC *ac;
int cases;
string buf;
int n;
int main(){
    ios::sync_with_stdio(false);            //ȡ��ͬ�����ӿ�cin��ȡ�ַ������ٶ� 
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