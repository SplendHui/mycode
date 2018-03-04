Description
��һ¥�ݹ�M�����տ�ʼʱ���ڵ�һ������ÿ��ֻ�ܿ���һ���������Ҫ���ϵ�M�������ж������߷��� 
Input
�����������Ȱ���һ������N����ʾ����ʵ���ĸ�����Ȼ����N�����ݣ�ÿ�а���һ������M��1<=M<=40��,��ʾ¥�ݵļ�����
Output
����ÿ������ʵ�����������ͬ�߷�������
Sample Input
2
2
3
Sample Output
1
2
#include <stdio.h>  
#include <string.h>  
int count[40];  
  
int fibonacci(int m)  
{  
    if(m == 1 || m == 2)  
    {  
        return m;  
    }  
    if(count[m] != 0)  
    {  
        return count[m];  
    }  
    count[m] = fibonacci(m-1) + fibonacci(m-2);  
    return count[m];  
}  
  
int main()  
{  
    int n,m;  
    while(scanf("%d",&n)!=EOF)  
    {  
        while(n--)  
        {  
            scanf("%d",&m);  
            (int *)memset(count,0,40);  
            printf("%d\n",fibonacci(m-1));  
        }  
    }  
} 