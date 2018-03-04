#include "stdio.h"
#include "string.h"
const int N0 = 500;

int longIntegerSum(char a[], char b[], int c[])
{
    char *pa, *pb;
    int *pc, len;
    pa = a + strlen(a) - 1;
    pb = b + strlen(b) - 1;
    //******************************************
    len = 0;
    pc = c;
    while (pa >= a || pb >= b)
    {
        if (pa >= a)
            *pc += *pa - '0';
        if (pb >= b)
            *pc += *pb - '0';
        if (*pc > 9)
        {
            *(pc + 1) += *pc / 10;
            *pc = *pc % 10;
        }
        pa--;
        pb--;
        pc++;
        len++;
    }
    if (*pc > 0)
        len++;
    //==========================================
    return len;
}

int main()
{
    int cas;
    char a[N0 + 1], b[N0 + 1];
    int c[N0 + 5] = {0}, *pc, len;
    scanf("%d", &cas);
    for (int i = 1; i <= cas; i++)
    {
        memset(a, 0, sizeof (a));
        memset(b, 0, sizeof (b));
        memset(c, 0, sizeof (c));
        scanf("%s%s", a, b);
        len = longIntegerSum(a, b, c);
        printf("Case %d:\n", i);
        printf("%s + %s = ", a, b);
        for (pc = c + len - 1; pc >= c; pc--)
            printf("%d", *pc);
        if (i != cas)printf("\n");
    }
    return 0;
}
