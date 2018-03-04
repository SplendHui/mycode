#include<stdio.h>
#include<algorithm>
using namespace std; 
struct C_{
	double get, pay, ave;
}M[10001];
int cmp(C_ a, C_ b)
{
	if(a.ave > b.ave) return 1;
	return 0;
}
int main(){
	int m, n;
	int i;
	double sum;
	while(scanf("%d%d",&m, &n) == 2 && (m != -1 && n != -1))
	{
		for(i = 0; i < n; i++)
		{
			scanf("%lf %lf",&M[i].get, &M[i].pay);
			M[i].ave = M[i].get/M[i].pay;
		}
		sort(M, M+n, cmp);
		sum = 0;
		for(i = 0; i < n; i++)
		{
			if(m >= M[i].pay)
			{
				sum = sum + M[i].get;
				m = m - M[i].pay;	
			}
			else
			{
				sum = sum + M[i].ave * m;
				break;
			}
		}
		printf("%.3lf\n", sum);
	}
	return 0;
}
