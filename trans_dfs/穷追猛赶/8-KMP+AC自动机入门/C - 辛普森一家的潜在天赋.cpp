/*
Description
Homer: Marge, I just figured out a way to discover some of the talents we weren¡¯t aware we had. 
Marge: Yeah, what is it? 
Homer: Take me for example. I want to find out if I have a talent in politics, OK? 
Marge: OK. 
Homer: So I take some politician¡¯s name, say Clinton, and try to find the length of the longest prefix 
in Clinton¡¯s name that is a suffix in my name. That¡¯s how close I am to being a politician like Clinton 
Marge: Why on earth choose the longest prefix that is a suffix??? 
Homer: Well, our talents are deeply hidden within ourselves, Marge. 
Marge: So how close are you? 
Homer: 0! 
Marge: I¡¯m not surprised. 
Homer: But you know, you must have some real math talent hidden deep in you. 
Marge: How come? 
Homer: Riemann and Marjorie gives 3!!! 
Marge: Who the heck is Riemann? 
Homer: Never mind. 
Write a program that, when given strings s1 and s2, finds the longest prefix of s1 that is a suffix of s2. 
Input
Input consists of two lines. The first line contains s1 and the second line contains s2. You may assume all letters are in lowercase.
Output
Output consists of a single line that contains the longest string that is a prefix of s1 and a suffix of s2, followed by the length of that prefix. If the longest such string is the empty string, then the output should be 0. 
The lengths of s1 and s2 will be at most 50000.
Sample Input
clinton
homer
riemann
marjorie
Sample Output
0
rie 3
*/
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=50010;

int next[maxn<<1];
char s1[maxn<<1],s2[maxn];

void getnext(char *s){
    int len=strlen(s);
    int i=0,j=-1;
    next[0]=-1;
    while(i<len){
        if(j==-1 || s[i]==s[j]){
            i++;j++;
            next[i]=j;
        }else
            j=next[j];
    }
}

int main(){

    //freopen("input.txt","r",stdin);

    while(~scanf("%s%s",s1,s2)){
        int len1=strlen(s1);
        int len2=strlen(s2);
        strcat(s1,s2);
        getnext(s1);
        int k=len1+len2;
        while(next[k]>len1 || next[k]>len2)
            k=next[k];
        if(next[k]==0)
            printf("0\n");
        else{
            for(int i=0;i<next[k];i++)
                printf("%c",s1[i]);
            printf(" %d\n",next[k]);
        }
    }
    return 0;
}/*
#include<iostream>
#include<cstdiO>
#include<cstring>

using namespace std;

const int maxn=50010;

int next[maxn];
char s1[maxn],s2[maxn];

void getnext(int len2){
    int i=0,j=-1;
    next[0]=-1;
    while(i<len2){
        if(j==-1 || s2[i]==s2[j]){
            i++;j++;
            next[i]=j;
        }else
            j=next[j];
    }
}

void KMP(int len1,int len2){
    int i=0,j=0;
    getnext(len2);
    while(i<len1){  //²»ÄÜÐ´³Éwhile(i<len1 && j<len2)
        if(j==-1 || s1[i]==s2[j]){
            i++;j++;
        }else
            j=next[j];
    }
    if(j!=0){
        for(int k=0;k<j;k++)
            printf("%c",s2[k]);
        printf(" %d\n",j);
    }else
        printf("0\n");
}

int main(){

    //freopen("input.txt","r",stdin);

    while(~scanf("%s%s",s2,s1)){
        int len1=strlen(s1);
        int len2=strlen(s2);
        KMP(len1,len2);
    }
    return 0;
}
*/