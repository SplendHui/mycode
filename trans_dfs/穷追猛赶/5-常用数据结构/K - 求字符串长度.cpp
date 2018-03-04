/*
Description
求一个长度不大于100的字符串的长度，要求不使用strlen方法，并且使用到字符指针。 
Output
字符串的长度。 
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