#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
using namespace std;

// Sales_Item add(const Sales_item &, const Sales_Item &);
int add(int i, int j)
{
    return i + j;
}

struct divide
{
    int operator()(int denominator, int divisor)
    {
        return denominator / divisor;
    }
};

int main()
{
    auto mod = [](int i, int j) { return i % j; };

    function<int(int, int)> f1 = add;
    function<int(int, int)> f2 = divide();
    function<int(int, int)> f3 = mod;
    cout << f1(4, 2) << endl;
    cout << f2(4, 2) << endl;
    cout << f3(4, 2) << endl;

    map<string, function<int(int, int)>> binops = {
        {"+", add},
        {"-", std::minus<int>()},
        {"/", divide()},
        {"%", mod},
        {"*", [](int i, int j) { return i * j; }}};

    cout << binops["+"](10, 5) << endl;
    cout << binops["-"](10, 5) << endl;
    cout << binops["*"](10, 5) << endl;
    cout << binops["/"](10, 5) << endl;
    cout << binops["%"](10, 5) << endl;
    // 不知道多个add中的哪一个
    // binops.insert({"+", add});
    int (*fp)(int, int) = add;
    binops.insert({"+", fp});
    // 也可以使用lambda表达式消除二义性
    binops.insert({"+", [](int a, int b) { return add(a, b); }});

    return 0;
}