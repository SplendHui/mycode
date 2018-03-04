#include <stdio.h>
void main()
{ 
	int i,n,max,a[10000];  
  scanf("%d",&n);
	//****************************************
	max=1;
	a[0]=0;
	for(i=1;i<=n/2;i++)
	{
		a[1]=1;
		a[2*i]=a[i]+1;
		a[2*i+1]=a[i]+a[i+1];
	
	}
	for(i=1;i<n;i++)
		if(a[i]>=max)
			max=a[i];

  //***************************************
	printf("%d\n",a[n]);
  printf("%d\n",max);
}
