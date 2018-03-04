/*
Description
输入一行数字，如果我们把这行数字中的‘5’都看成空格，那么就得到一行用空格分割的若干非负整数（可能有些整数以‘0’开头，这些头部的‘0’应该被忽略掉，除非这个整数就是由若干个‘0’组成的，这时这个整数就是0）。 

你的任务是：对这些分割得到的整数，依从小到大的顺序排序输出。 

Input
输入包含多组测试用例，每组输入数据只有一行数字（数字之间没有空格），这行数字的长度不大于1000。?? 

输入数据保证：分割得到的非负整数不会大于100000000；输入数据不可能全由‘5’组成。 
Output
对于每个测试用例，输出分割得到的整数排序的结果，相邻的两个整数之间用一个空格分开，每组输出占一行。 
Sample Input
0051231232050775
Sample Output
0 77 12312320
*/
//很简单的一道题，周赛的时候wrong了3次。。。。。。。。。。打击打击。。。。纪念下
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    char s[5005];
    int a[5005];
    int i,len,k,n;
    while(scanf("%s",s)!=EOF)
    {
        n=0;
        k=0;
        len=strlen(s);
        s[len]='5';   
        i=0;
        while(s[i++]=='5');  //跳过前缀5,防止多输出0
        for(i--;i<=len;++i)
        {
            if(i>0&&s[i]=='5'&&s[i-1]=='5') //忽略连续的5，防止多输出0
                continue;
            if(s[i]!='5')
                k=k*10+s[i]-'0';
            else            //遇到5就增加一个数
            {
                a[n++]=k;
                k=0;
            }
        }
        sort(a,a+n);
        printf("%d",a[0]);
        for(i=1;i<n;++i)
            printf(" %d",a[i]);
        printf("\n");
    }
    return 0;
}