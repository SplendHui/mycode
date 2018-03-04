#include<stdio.h>
void main()
{
	int n,i,j,a[20][20];
  scanf("%d",&n);
	//*****************************************
  
  for(i=1;i<=n;i++)
		for(j=0;j<=2*n;j++)
			a[i][j]=0;
		    a[1][n]=1;

	for(i=2;i<=n;i++)
		for(j=1;j<2*n;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j+1];

 
  //*****************************************************
/*	for(i=1;i<=n;i++)
		printf("%d  ",a[n][i]);
		printf("\n");
*/	
		for(i=1;i<=n;i++)//ÐÐ
		{	
			for(j=1;j<2*n;j++)
				{
					if(a[i][j]==0)
						printf("   ");
					else
						printf("%3d",a[i][j]);
				}

			printf("\n");
		}

}
