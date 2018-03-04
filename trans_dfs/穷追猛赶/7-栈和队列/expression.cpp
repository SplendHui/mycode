#include "stdio.h"
#include "string.h"
#include "math.h"
char a[8][8]={
	{ '>','>','<','<','<','>','>','<' },
	{ '>','>','<','<','<','>','>','<' },
	{ '>','>','>','>','<','>','>','<' },
	{ '>','>','>','>','<','>','>','<' },
	{ '<','<','<','<','<','=','E','<' },
	{ '>','>','>','>','E','>','>','>' },
	{ '<','<','<','<','<','E','=','<'},
	{ '>','>','>','>','<','>','>','<' },
};
char b[8]={'+','-','*','/','(',')','#','^'};
int c[255];
void ini( )
{	int i;
	for( i=0; i<8; i++)
		c[b[i]]=i; //c['+']=0,c['^']=7
}    
// a[0][7]  a[c['+']][c['^']]

int compare( char ch1, char ch2 )
{
	return a[c[ch1]][c[ch2]];
}
double cal( double a, char ch, double b )
{	double r;
	switch( ch )
	{	case '+' : r=a+b;break;
		case '-' : r=a-b;break;
		case '*' : r=a*b; break;
		case '^' : r=pow( a, b );break;
		case '/' : if( b==0 ) r=0;
				   else r=a/b;break;
	}
	return r;
}

double expression( char *str )
{	char op[1000],s[1000], ch;
	double da[1000], r, aa, bb;
	int topOp=0, topDa=0;
	strcat( str, "#" );
	op[++topOp]='#';
	int i=0,j;
	while( str[i]!='#' || op[topOp]!='#' )
	{	if( i==0 && str[i]=='-' || str[i]=='(' && str[i+1]=='-' )
			da[++topDa]=0;
		if( str[i]>='0' && str[i]<='9' || str[i]=='.' )
		{	j=0;
			while( str[i]>='0' && str[i]<='9' || str[i]=='.' )
		 		s[j++]=str[i++];
			s[j]='\0';
			sscanf(s, "%lf", &r );
			da[++topDa]=r;
		}
		else switch( compare( op[topOp], str[i] ) )
		{	
			case '<' : op[++topOp]=str[i]; i++; break;
			case '=' : i++; topOp--; break;
			case '>' : 
				bb=da[topDa--];
				aa=da[topDa--];
				ch=op[topOp--];
				r=cal( aa, ch, bb );
				da[++topDa]=r;
		}

	
	}
	
	
	return da[topDa];
}
int main()
{
	char str[1000];
	gets( str );
	ini();
	printf("%.3f\n", expression( str ));
	return 0;
}