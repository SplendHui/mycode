/*
I have made a huge ice-sugar gourd by two kinds of fruit, hawthorn and tangerine, in no particular order. Since I want to share it with two of my friends, Felicia and his girl friend, I need to get an equal cut of the hawthorns and tangerines. How many times will I have to cut the stick so that each of my friends gets half the hawthorns and half the tangerines? Please notice that you can only cut the stick between two adjacent fruits, that you cannot cut a fruit in half as this fruit would be no good to eat. 
����:


The input consists of multiply test cases. The first line of each test case contains an integer, n(1 <= n <= 100000), indicating the number of the fruits on the stick. The next line consists of a string with length n, which contains only ��H�� (means hawthorn) and ��T�� (means tangerine).
The last test case is followed by a single line containing one zero. 
���:


The input consists of multiply test cases. The first line of each test case contains an integer, n(1 <= n <= 100000), indicating the number of the fruits on the stick. The next line consists of a string with length n, which contains only ��H�� (means hawthorn) and ��T�� (means tangerine).
The last test case is followed by a single line containing one zero.
��������:


4
HHTT
4
HTHT
4
HHHT
0
�������:

2
1 3
1
2
-1
*/
/*
#include<stdio.h>
#define N 100001
int n;
char ice[N];
void solve()
{
    int i,t_tol=0,h_tol=0,h=0,t=0,m=n>>1;
    for(i=0;i<n;++i)
        if(ice[i]=='H')
            h_tol++;
        else
            t_tol++;
    if((h_tol%2)||(t_tol%2))
    {
        printf("-1\n");
        return ;
    }
    for(i=0;i<m;++i)
        if(ice[i]=='H')
            ++h;
        else
            ++t;
    if( h*2 == h_tol && t*2 == t_tol )
    {
        printf("1\n%d\n",m);
        return ;
    }
    for(;i<n;++i)
    {
        if(ice[i]=='H')
            h++;
        else
            t++;
        if(ice[i-m]=='H')
            --h;
        else
            --t;
        if(h*2==h_tol && t*2==t_tol)
        {
            printf("2\n%d %d\n",i-m+1,i+1);
            return ;
        }
    }
    printf("-1\n");
}
int main()
{
    while(scanf("%d",&n) ==1 && n)
    {
        scanf("%s",ice);
        solve();
    }
    return 0;
}


������⣺
����һ������������H��T�����ַ���Ȼ�������⵶��ʹ���ܰ�H��T���Է�Ϊԭ����һ�롣
����˼·��
�Ѵ������һ������ֻҪ����H��T��Ϊż��������ô�Ϳ�����һ����Բ�ĵ�ֱ�߰�H��Tƽ�ֵ���
��ֱ�ߣ�ֻҪ����ƽ��H����T�е�һ���Ϳ����ˣ���Ϊֱ�߱����Ͱѻ�ƽ�֣�����ʱƽ����H����T��
��ôʣ�µ��Ǹ�Ҳ��ƽ�ֵ��ġ�
���룺ö��ÿ��λ��
��һ���ַ���ֻ�ɡ�H���͡�T����ɣ��������ַ�֮�����и���Ƿ�������и�֮��T��H�ֱ�ƽ�ֳ����ݡ����ܣ������Ҫ�и�ĵ����Լ��ֱ��ڵڼ����ַ������и�����ܣ����-1. 
*/


#include<stdio.h>
#define N 100001
char ice[N];
int n;
void cut(){
	int i,j;
	int h=0,t=0,h_total=0,t_total=0;
	for(i = 0; i < n; i++)
		if( ice[i] == 'H' )
			h_total++;
		else
			t_total++;
		if( h_total%2 || t_total%2 )
			{	
				printf("-1\n");
				return ;
		
			}
	for(i = 0; i < n/2; i++ )
		if( ice[i] == 'H' )
			h++;
		else 
			t++;
		if( h == h_total/2 && t == t_total/2 )
			{
				printf("1\n%d\n",n/2);
				return ;
			}
	for( i = 0,j = n/2;j < n; i++,j++ )
	{
		if( ice[j] == 'H' )
			h++;
		else
			t++;
		if( ice[i] == 'H')
			h--;
		else
			t--;
		if( h == h_total/2 && t == t_total/2 )
		{
			printf("2\n%d %d\n",i+1,j+1);
			return ;
		}

	}
			    printf("-1\n");
}
int main()
{
	while( scanf("%d",&n)==1 && n )
	{
		scanf("%s",ice);
		cut();
	}
		return 0;
}
