#include <iostream>
#include "Sales_item.hpp"

using namespace std;

template <typename T>
int compare(const T &lhs, const T &rhs)
{
    // 如果只使用 < 来判断，那就不必要求T类型实现>了，
    // 比如multiset为什么只使用 < 的compare就解决了。
    if (lhs < rhs)
        return -1;
    if (lhs > rhs)
        return 1;
    return 0;
}
//上面的如果传入的是指针的话，并且指向相同的数组，则代码行为是未定义的
template <typename T>
int compare1(const T &lhs, const T &rhs)
{
    if (less<T>(v1, v2))
        return -1;
    if (less<T>(v2, v1))
        return 1;
    return 0;
}

int main()
{

    /*
    int a = 10, b = 10;
    int result = compare(a, b);
    cout << "result = " << result << endl;
    */
    Sales_item s1, s2;
    compare(s1, s2);

    return 0;
}