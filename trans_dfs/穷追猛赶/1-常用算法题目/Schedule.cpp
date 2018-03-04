#include <stdio.h>
struct ScType{
	int b;
	int e;
};
void swap(ScType &a,ScType &b)
{ 
	ScType temp;
	temp=a;
	a=b;
	b=temp;
}
void heapadjust(ScType *a,int s,int m)
{
	ScType temp=a[s];
	for(int j=2*s;j<=m;j*=2){
		if(j<m && (a[j].e<a[j+1].e)) ++j;
		if(!(temp.e<a[j].e)) break;  
		a[s]=a[j];
		s=j;
	}
	a[s]=temp;
}

void heapsort(ScType *a,int m)
{
	int i; 
	for(i=m/2;i>0;--i) heapadjust(a,i,m);
	for(i=m;i>1;--i){
		swap(a[1],a[i]);
		heapadjust(a,1,i-1);
	}
}

int main()
{
	freopen("Schedule.in","r",stdin);
	freopen("Schedule.out","w",stdout);
	int n=0,i,k,sum=0;
  scanf("%d",&n);
  ScType *s=new ScType[n+1];
	int *r=new int[n+1];
	for (i=1;i<=n;i++){
		scanf("%d",&s[i].b);
		scanf("%d",&s[i].e);
		r[i]=0;
	}
	//******************************************************





	//******************************************************
  delete []s;
	delete []r;
	return 0;
}