#include <iostream>
#include <cstdio>
#include <cstring>
#include<malloc.h>

using namespace std;

struct node
{
	char *cc;//���������һ������
	node *next[26];
	int flag;//�������
	node()//��ʼ��
	{
		for (int i=0; i<26; i++)
		next[i] = NULL;
		flag=0;
	}
};

node *p,*root=new node();
void insert(char *s,char *t)//�Ի����Ľ��н����������һ���ַ�������¶�Ӧ��Ӣ���ַ���
{
	p=root;
	for (int i=0; s[i]!='\0'; i++)
	{
		int k=s[i]-'a';
		if (p->next[k]==NULL)
		p->next[k]=new node();
		p=p->next[k];
	}
	p->flag = 1;//������ǵ�ǰ�����ַ����Ľ�β�ж�Ӧ��Ӣ���ַ���
	p->cc=(char*)malloc((strlen(t)+1)*sizeof(char));//���붯̬�ռ�
	strcpy(p->cc,t);//����Ӧ�ַ�������
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
			printf("%s",s);//��ԭ����ĸ�����Ѱ�ҵ��ַ��������ڵģ�Ҳ����δȫ�����꣩
			return;
		}
		p=p->next[k];
	}
	if (p->flag)
	printf ("%s",p->cc);//����ҵ��Ķ�Ӧ�ĵ���
	else
	printf ("%s",s);//�����ж��Ҳ������������ԭ����ĸ�����ȫ��������û�ж�Ӧ�ģ�
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