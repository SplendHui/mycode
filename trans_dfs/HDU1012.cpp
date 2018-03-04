#include<stdio.h>
double run(int n)
{
	int i;
	double sum = n;
	for(i = n - 1; i >= 1; i--)
	sum = sum * i;
	return sum;
}
int main(){
	
	int n, m;
	int i;
	double sum[11];
	printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");
	sum[2] = 2.5;
	for(i = 3; i < 10; i++)
	{
		sum[i] = sum[i-1] + 1.0/run(i);
		printf("%d %.9lf\n",i, sum[i]);
	}
	return 1;
}
