#include <iostream>
#include <stdio.h>
using namespace std;
struct t
{
    int a;
    int b;
} T[100];
int main()
{

    // int array[][10] = {1, 2};
    // printf("%d", array[1][0]);
    // char a = '0', b = '9';
    // cout << (int)((b - a) / 7) << endl;
    // cout << 1.0 << endl;
    // cout << (double)((b - a) / 7) << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << T[i].a << endl;
    }

    return 0;
}