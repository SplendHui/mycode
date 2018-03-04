/*
Michaelϲ����ѩ���Ⲣ����֣� ��Ϊ��ѩ��ȷ�ܴ̼�������Ϊ�˻���ٶȣ������������������б�����ҵ��㻬���µף��㲻�ò��ٴ������»��ߵȴ������������㡣Michael��֪����һ����������׻��¡�������һ����ά��������������ÿ�����ִ����ĸ߶ȡ�������һ������ 
 1  2  3  4 5

16 17 18 19 6

15 24 25 20 7

14 23 22 21 8

13 12 11 10 9

һ���˿��Դ�ĳ���㻬���������������ĸ���֮һ�����ҽ����߶ȼ�С��������������У�һ���ɻ��еĻ���Ϊ24-17-16-1����Ȼ25-24-23-...-3-2-1��������ʵ�ϣ��������һ���� 
Input
����ĵ�һ�б�ʾ���������R������C(1 <= R,C <= 100)��������R�У�ÿ����C������������߶�h��0<=h<=10000�� 
Output
��������ĳ��ȡ� 
Sample Input
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
Sample Output
25
*/
/* 
*JackyZheng 
*2010/12/12 
*C 
*/  
#include<stdio.h>  
  
int dp[100][100];  
int arr[100][100];  
int R,C;  
  
int getHigh(int i,int j)  
{  
    if(dp[i][j]>1)  
    {  
        return dp[i][j];  
    }  
    int max=1;  
    if(arr[i][j]>arr[i][j-1]&&j-1>=0)  
    {  
        int h=getHigh(i,j-1)+1;  
        if(h>max)  
        {  
            max=h;  
        }  
    }  
    if(arr[i][j]>arr[i][j+1]&&j+1<C)  
    {  
        int h=getHigh(i,j+1)+1;  
        if(h>max)  
        {  
            max=h;  
        }  
    }  
    if(arr[i][j]>arr[i-1][j]&&i-1>=0)  
    {  
        int h=getHigh(i-1,j)+1;  
        if(h>max)  
        {  
            max=h;  
        }  
    }  
    if(arr[i][j]>arr[i+1][j]&&i+1<R)  
    {  
        int h=getHigh(i+1,j)+1;  
        if(h>max)  
        {  
            max=h;  
        }  
    }  
    return max;  
}  
  
int main()  
{  
        scanf("%d%d",&R,&C);  
        int i,j;  
        for(i=0;i<R;i++)  
        {  
            for(j=0;j<C;j++)  
            {  
                scanf("%d",&arr[i][j]);  
                dp[i][j]=1;  
            }  
        }  
        int res=0;  
        for(i=0;i<R;i++)  
        {  
            for(j=0;j<C;j++)  
            {  
                dp[i][j]=getHigh(i,j);  
                if(dp[i][j]>res)  
                {  
                    res=dp[i][j];  
                }  
            }  
        }  
        printf("%d/n",res);  
} 