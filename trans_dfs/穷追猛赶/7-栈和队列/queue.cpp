#include "stdio.h"
int main()
{	
	int a[100]={ 11, 15, 23, 35, 98, 112 }, ra=6, fa=0;
	int b[100]={ 3, 25, 36, 42, 53, 66, 67, 79 },rb=8, fb=0;
	int c[100],rc=0,fc=0 ;
	int i;
	while( ra!=fa && rb!=fb )
		if( a[fa]<=b[fb] )
			c[rc++]=a[fa++];
		else 
			c[rc++]=b[fb++];
	while( ra!=fa )
		c[rc++]=a[fa++];
	while( rb!=fb )
		c[rc++]=b[fb++];
	for( i=fc; i<rc; i++)
		printf("%5d", c[i] );
	printf("\n");

	return 0;
}