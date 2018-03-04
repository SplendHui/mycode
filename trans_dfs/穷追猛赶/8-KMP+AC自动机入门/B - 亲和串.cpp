/*
Description
人随着岁数的增长是越大越聪明还是越大越笨，这是一个值得全世界科学家思考的问题,同样的问题Eddy也一直在思考，因为他在很小的时候就知道亲和串如何判断了，但是发现，现在长大了却不知道怎么去判断亲和串了，于是他只好又再一次来请教聪明且乐于助人的你来解决这个问题。 
亲和串的定义是这样的：给定两个字符串s1和s2,如果能通过s1循环移位，使s2包含在s1中，那么我们就说s2 是s1的亲和串。 
Input
本题有多组测试数据，每组数据的第一行包含输入字符串s1,第二行包含输入字符串s2，s1与s2的长度均小于100000。 
Output
如果s2是s1的亲和串，则输出"yes"，反之，输出"no"。每组测试的输出占一行。 
Sample Input
AABCD
CDAA
ASD
ASDF
Sample Output
yes
no
*/
#include <cstdio>
#include <cstring>
#define MAX 100010
void getnext(char s[],int next[]){
    int i,j,length;
    next[0]=-1;
    i=0;
    j=-1;
    length=strlen(s);
    while(i<length){
        if(j==-1||s[i]==s[j]){
            i++;j++;next[i]=j;
        }
        else j=next[j];
    }
}
int kmp(char t[],char p[],int next[]){
    int i=0,j=0;
    int len1=strlen(t),len2=strlen(p);
    while(i<len1&&j<len2){
        if(j==-1||t[i]==p[j])
            i++,j++;
        else j=next[j];
    }
    if(j==len2) return i-len2;
    else return -1;
}
int main(){
    char s1[MAX*2],s2[MAX];
    int l1,l2,next[MAX];
    while(~scanf("%s",s1)){
        scanf("%s",s2);
        l1=strlen(s1);
        for(int i=0;i<l1;i++)
            s1[i+l1]=s1[i];
        s1[l1*2]=0;
        getnext(s2,next);
        printf("%s\n",kmp(s1,s2,next)==-1?"no":"yes");
    }
}
