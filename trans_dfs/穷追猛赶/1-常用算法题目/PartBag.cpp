#include <stdio.h>
struct ObjectType{
	int w;
	int p;
};
void swap(ObjectType &a,ObjectType &b)
{ 
	ObjectType temp;
	temp=a;
	a=b;
	b=temp;
}

void sort(ObjectType *a,int n)
{
  int i,j,k;
  for (i=1;i<=n-1;i++){
    k=i;
    for (j=i+1;j<=n;j++){
      if (a[j].p>a[k].p) k=j; 
    }
    if (k!=i) swap(a[k],a[i]);
  }
}

int main()
{
	freopen("PartBag.in","r",stdin);
	freopen("PartBag.out","w",stdout);
	int m=0,n=0,i,sum=0,c;
  scanf("%d",&m);
  scanf("%d",&n);
  ObjectType *ob=new ObjectType[n+1];
	int *r=new int[n+1];
	for (i=1;i<=n;i++){
		scanf("%d",&ob[i].w);
		r[i]=0;
	}
	for (i=1;i<=n;i++)
		scanf("%d",&ob[i].p);

	//******************************************************





     
  
	//******************************************************
  delete []ob;
	delete []r;
	return 0;
}