/*
Description
������������������Խ��Խ��������Խ��Խ��������һ��ֵ��ȫ�����ѧ��˼��������,ͬ��������EddyҲһֱ��˼������Ϊ���ں�С��ʱ���֪���׺ʹ�����ж��ˣ����Ƿ��֣����ڳ�����ȴ��֪����ôȥ�ж��׺ʹ��ˣ�������ֻ������һ������̴������������˵��������������⡣ 
�׺ʹ��Ķ����������ģ����������ַ���s1��s2,�����ͨ��s1ѭ����λ��ʹs2������s1�У���ô���Ǿ�˵s2 ��s1���׺ʹ��� 
Input
�����ж���������ݣ�ÿ�����ݵĵ�һ�а��������ַ���s1,�ڶ��а��������ַ���s2��s1��s2�ĳ��Ⱦ�С��100000�� 
Output
���s2��s1���׺ʹ��������"yes"����֮�����"no"��ÿ����Ե����ռһ�С� 
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
