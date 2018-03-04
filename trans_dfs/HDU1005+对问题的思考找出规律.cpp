#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int rec[60];

int main()
{
    int a, b, n;
    rec[0] = rec[1] = rec[2] = 1;
    while( scanf( "%d %d %d", &a, &b, &n ), a | b | n )
    {
        int beg, end, flag = 0;
        for( int i = 3; i <= n && !flag; ++i )
        {
            rec[i] = ( a * rec[i-1] + b * rec[i-2] ) % 7;
            for( int j = 2; j <= i - 1; ++j )
            {
                if( rec[i] == rec[j] && rec[i-1] == rec[j-1] )
                {
                    beg = j, end = i;
                    flag = 1;
                    break;
                }
            }
        }
        if( flag )
        {
            printf( "%d\n", rec[beg+(n-end)%(end-beg)] );
        }
        else
            printf( "%d\n", rec[n] );
    }
    return 0;
}