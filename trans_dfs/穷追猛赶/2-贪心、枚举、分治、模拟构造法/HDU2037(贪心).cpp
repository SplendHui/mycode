/*
Problem Description
“今年暑假不AC？”
“是的。”
“那你干什么呢？”
“看世界杯呀，笨蛋！”
“@#$%^&*%...”

确实如此，世界杯来了，球迷的节日也来了，估计很多ACMer也会抛开电脑，奔向电视了。
作为球迷，一定想看尽量多的完整的比赛，当然，作为新时代的好青年，你一定还会看一些其它的节目，比如新闻联播（永远不要忘记关心国家大事）、非常6+7、超级女生，以及王小丫的《开心辞典》等等，假设你已经知道了所有你喜欢看的电视节目的转播时间表，你会合理安排吗？（目标是能看尽量多的完整节目）
 

Input
输入数据包含多个测试实例，每个测试实例的第一行只有一个整数n(n<=100)，表示你喜欢看的节目的总数，然后是n行数据，每行包括两个数据Ti_s,Ti_e (1<=i<=n)，分别表示第i个节目的开始和结束时间，为了简化问题，每个时间都用一个正整数表示。n=0表示输入结束，不做处理。
 

Output
对于每个测试实例，输出能完整看到的电视节目的个数，每个测试实例的输出占一行。
 

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
}   // 为快速排序制定比较规则， 开始时间一样时结束时间小的放前面， 否则开始时间小的放前面。  
   
int main()  
{  
    int n;  
    while(scanf("%d", &n), n){  
        int i;  
        for(i = 0; i < n; i++){  
            scanf("%d %d", &programs[i].be, &programs[i].en);  
        }  
        sort(programs, programs + n, cmp);   // 对输入对象按照cmp排序。  
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
        }   // 贪心，每一次循环求出一个局部最优解，最终迭代出整体最优解。  
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










































