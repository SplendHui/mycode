/*
Description
��һ�����Ȳ�����100���ַ����ĳ��ȣ�Ҫ��ʹ��strlen����������ʹ�õ��ַ�ָ�롣 
Output
�ַ����ĳ��ȡ� 
Sample Input
I love Beijing.
Sample Output
15
*/
#include<stdio.h>

int strlen(char *p)
{
	int len=0;
	while(*p!='\0')
	{
		p++;
		len++;
	}
	return len;
}

void?main()
{
	char str[20];
	scanf("%s",str);
	int len=0;
	len=strlen(str);
	printf("the?length?of?string is %d\n",len);
}