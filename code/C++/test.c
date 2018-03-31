#include <stdio.h>
int main()
{
    int i, sum = 0;
    for (int j = 0; j < 1000; j++)
        for (i = 10000; i < 10000000; i++)
        {
            sum += i;
        }
    return 0;
}