/*
Problem Description
��������ٲ�AC����
���ǵġ���
�������ʲô�أ���
�������籭ѽ����������
��@#$%^&*%...��

ȷʵ��ˣ����籭���ˣ����ԵĽ���Ҳ���ˣ����ƺܶ�ACMerҲ���׿����ԣ���������ˡ�
��Ϊ���ԣ�һ���뿴������������ı�������Ȼ����Ϊ��ʱ���ĺ����꣬��һ�����ῴһЩ�����Ľ�Ŀ������������������Զ��Ҫ���ǹ��Ĺ��Ҵ��£����ǳ�6+7������Ů�����Լ���СѾ�ġ����Ĵǵ䡷�ȵȣ��������Ѿ�֪����������ϲ�����ĵ��ӽ�Ŀ��ת��ʱ������������𣿣�Ŀ�����ܿ��������������Ŀ��
 

Input
�������ݰ����������ʵ����ÿ������ʵ���ĵ�һ��ֻ��һ������n(n<=100)����ʾ��ϲ�����Ľ�Ŀ��������Ȼ����n�����ݣ�ÿ�а�����������Ti_s,Ti_e (1<=i<=n)���ֱ��ʾ��i����Ŀ�Ŀ�ʼ�ͽ���ʱ�䣬Ϊ�˼����⣬ÿ��ʱ�䶼��һ����������ʾ��n=0��ʾ�����������������
 

Output
����ÿ������ʵ������������������ĵ��ӽ�Ŀ�ĸ�����ÿ������ʵ�������ռһ�С�
 

Sample Input
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0
 

Sample Output
5
*/
#include<stdio.h>  
#include<algorithm>  
using namespace std;  
  
struct program{  
    int be,en;  
}programs[100];  
   
int cmp(const program &a, const program &b){  
    if(a.be == b.be)return a.en < b.en;  
    else return a.be < b.be;  
}   // Ϊ���������ƶ��ȽϹ��� ��ʼʱ��һ��ʱ����ʱ��С�ķ�ǰ�棬 ����ʼʱ��С�ķ�ǰ�档  
   
int main()  
{  
    int n;  
    while(scanf("%d", &n), n){  
        int i;  
        for(i = 0; i < n; i++){  
            scanf("%d %d", &programs[i].be, &programs[i].en);  
        }  
        sort(programs, programs + n, cmp);   // �����������cmp����  
        int boundary, sum = 1;  
        boundary = programs[0].en;  
        for(i = 1; i < n; i++){  
            if(boundary <= programs[i].be){  
                boundary = programs[i].en;  
                sum++;  
            }  
            else if(boundary > programs[i].en){  
                boundary = programs[i].en;  
            }  
        }   // ̰�ģ�ÿһ��ѭ�����һ���ֲ����Ž⣬���յ������������Ž⡣  
        printf("%d\n", sum);  
    }  
    return 0;  
}
#include<stdio.h>
#include<algorithm>
using namespace std;

struct program{
	int be,en;
}p[100];

int cmp(const p &a,const p &b){
	
	if( a.be == b.be )
		return a.en < be.en;
	else 
		return a.be < b.be;
}

int main(){
	int n;
	while(scanf("%d", &n), n)
	{
		int i;
		for(i = 0; i < n; i++)
			scanf("%d %d", &p[i].be, &p[i].en);
		sort(p, p+n, cmp);
		int boundary,sum = 1;
		boundary = p[0].en;
			for(i = 1;i < n; i++)
			{
				if( boundary <= p[i].be )
				{
					boundary = p[i].en;
					sum++;
				}
				else if( boundary > p[i].be )
					boundary = p[i].en;
			
			}
	}
		printf("%d\n",sum);

	return 0;
}










































