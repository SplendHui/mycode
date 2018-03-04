#include <iostream>
#include <cstdio>
#include <cstring>
#include<malloc.h>

using namespace std;

struct node
{
	char *cc;//用来存最后一个单词
	node *next[26];
	int flag;//用来标记
	node()//初始化
	{
		for (int i=0; i<26; i++)
		next[i] = NULL;
		flag=0;
	}
};

node *p,*root=new node();
void insert(char *s,char *t)//对火星文进行建树，在最后一个字符下面存下对应的英文字符串
{
	p=root;
	for (int i=0; s[i]!='\0'; i++)
	{
		int k=s[i]-'a';
		if (p->next[k]==NULL)
		p->next[k]=new node();
		p=p->next[k];
	}
	p->flag = 1;//用来标记当前火星字符串的结尾有对应的英文字符串
	p->cc=(char*)malloc((strlen(t)+1)*sizeof(char));//申请动态空间
	strcpy(p->cc,t);//将对应字符串存下
}

void Search(char *s)
{
	p=root;
	if(strlen(s)==0)
	return ;
	for (int i=0; s[i]!='\0'; i++)
	{
		int k=s[i]-'a';
		if (p->next[k]==NULL)
		{
			printf("%s",s);//把原有字母输出（寻找的字符串不存在的，也就是未全部找完）
			return;
		}
		p=p->next[k];
	}
	if (p->flag)
	printf ("%s",p->cc);//输出找到的对应的单词
	else
	printf ("%s",s);//特殊判断找不到的情况，把原有字母输出（全部找完仍没有对应的）
}

void Translate(char ch1[]){
	int k=0;	
	char ch[3010];
	for(int i=0; ch1[i]!='\0'; i++)
	{
		if(ch1[i]>'z'||ch1[i]<'a')
		{
			ch[k]='\0';
			Search(ch);
			printf("%c",ch1[i]);
			k=0;
		}
		else
		ch[k++]=ch1[i];       
	}
	printf("\n");
}

int main()
{
	char str[15],ch1[3010],ch2[3010];
	scanf("%s",&str);
	while (~scanf("%s",&ch1) && strcmp(ch1,"END")!=0 )
	{
			scanf("%s",&ch2);
			insert(ch2,ch1);
	}
	scanf("%s",&str);
	getchar();
	while (gets(ch1) && strcmp(ch1,"END")!=0)
		Translate(ch1);
	
	return 0;
}