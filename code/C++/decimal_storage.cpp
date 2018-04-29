#include <iostream>
#include <vector>
using namespace std;
struct S
{
    int a, b;
};
void f1(S s)
{
    cout << "OK" << endl;
}
int main()
{
    f1({1, 2});

    float f = 19.2F;
    int *pa = (int *)&f;
    for (int i = 31; i >= 0; i--)
    {
        cout << ((*pa) >> i & 1) << (i == 31 || i == 23 ? "," : "");
    }
    cout << endl;
    f = -19.2F;

    pa = (int *)&f;
    for (int i = 31; i >= 0; i--)
    {
        cout << ((*pa) >> i & 1) << (i == 31 || i == 23 ? "," : "");
    }
    // cout << endl;
    /*
    const char *p1 = "hello";
    const char *p2 = "hello";
    int V = 10;
    int a[V];
    a[9] = 1;
    // cout << a[9] << endl;
    // cout << boolalpha << (p1 == p2) << endl;
    // cout << "p1 = " << p1 << " p2 = " << p2 << endl;

    vector<int> v1(10, 1);
    v1.resize(30, 2);
    v1.assign(10, 3);
    for (auto var : v1)
    {
        cout << var << endl;
    }
    cout << v1.size() << endl;

    */

    cout << endl;
    f = -34.5;
    int *ip = reinterpret_cast<int *>(&f);
    pa = (int *)&f;
    for (int i = 31; i >= 0; i--)
    {
        cout << ((*pa) >> i & 1) << (i == 31 || i == 23 ? "," : "");
    }
    cout << endl;
    cout << "float address :" << &f << "--->" << f << endl;
    cout << "float address :" << ip << "--->" << *ip << endl;

    f = 34.5;
    ip = reinterpret_cast<int *>(&f);
    // double b = static_cast<double>(10);
    pa = (int *)&f;
    for (int i = 31; i >= 0; i--)
    {
        cout << ((*pa) >> i & 1) << (i == 31 || i == 23 ? "," : "");
    }
    cout << endl;
    cout << "float address :" << &f << "--->" << f << endl;
    cout << "float address :" << ip << "--->" << *ip << endl;

    f = 34.5;
    pa = (int *)&f;
    for (int i = 31; i >= 0; i--)
    {
        cout << ((*pa) >> i & 1) << (i == 31 || i == 23 ? "," : "");
    }
    cout << endl;
    cout << "float address :" << &f << "--->" << f << endl;
    cout << "float address :" << ip << "--->" << *ip << endl;
    int a = 1 == 1;
    cout << boolalpha << 1 << endl;

    return 0;
}