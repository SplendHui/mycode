#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j,k,mi,mj,mk,m;
    while(scanf("%d",&n)!=EOF)
    {
        m=10000000;
        for(i=1;i<=sqrt(n)+1;i++)
        {
            if(n%i==0)
            {
                for(j=1;j<=n/i;j++)
                {                   
                    k=i*j;
                    if(n%k==0)
                    {
                        k=n/k;
                        if(i*j+i*k+j*k<m)
                        {
                            mi=i;
                            mj=j;
                            mk=k;
                            m=i*j+i*k+j*k;
                        }
                    }
                }
            }
        }       
        printf("%d %d %d\n",mi,mj,mk);
    }
}