/*
Description
���ڸ�����һ���ַ�����ͳ�����������ַ����ֵĴ����� 
Input
���������ж��У���һ����һ������n����ʾ����ʵ���ĸ������������n�У�ÿ�а���һ������ĸ��������ɵ��ַ����� 
Output
����ÿ������ʵ��������ô�����ֵ�ĸ�����ÿ�����ռһ�С� 
Sample Input
2 
asdfasdf123123asdfasdf 
asdf111111111asdfasdfasdf 
Sample Output
6 
9 
*/
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        string s1;
        cin>>s1;
        int num=0;
        for(string::size_type i=0; i<s1.size(); i++)
            if(isdigit(s1[i]))
                num++;
        cout<<num<<endl;
    }
    return 0;
}
1