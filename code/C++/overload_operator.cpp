#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include "Sales_item.hpp"

using namespace std;
struct asbInt
{
    int operator()(int val)
    {
        return val < 0 ? -val : val;
    }
};

class PrintString
{
  public:
    PrintString(ostream &o = cout, char c = ' ') : os(o), sep(c) {}
    void operator()(const string &s) const
    {
        os << s << sep;
    }

  private:
    ostream &os;
    char sep;
};

class ShorterString
{
  public:
    bool operator()(const string &s1, const string &s2) const
    {
        return s1.size() > s2.size();
    }
};

class SizeComp
{
  public:
    SizeComp(size_t n) : sz(n) {}
    bool operator()(const string &s) const
    {
        return s.size() >= sz;
    }

  private:
    size_t sz;
};

class A
{
  public:
    A()
    {
        cout << "A construct" << endl;
    }
    A(const A &a)
    {
        this->a = a.a;
        cout << "copy construct" << endl;
    }
    A(A &&a)
    {
        cout << "&&a" << endl;
    }
    A &operator=(A &&a)
    {
        cout << "= &&a" << endl;
    }
    int operator+(int b)
    {
        cout << "add" << endl;
        return a + b;
    }

  private:
    int a;
};

int main()
{
    int i = -42;
    asbInt absObj;
    int ui = absObj(i);
    cout << "i = " << i << " ui = " << ui << endl;

    PrintString printer;
    string s = "nice to meet you";
    printer(s);
    PrintString errors(cerr, '\n');
    //errors(s);
    cout << endl
         << "---------------------" << endl;
    vector<string> vs = {"a", "aa", "aaa", "aaaa"};
    // for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));
    // for_each(vs.begin(), vs.end(), printer);
    // 很奇怪, errors的输出根在了两个for_each中间.
    // for_each(vs.begin(), vs.end(), [](const string &s) { cout << s << endl; });

    // stable_sort(vs.begin(), vs.end(),
    //             [](const string &a, const string &b) { return a.size() < b.size(); });

    // for_each(vs.begin(), vs.end(), [](const string &s) { cout << s << endl; });

    // stable_sort(vs.begin(), vs.end(),
    //             ShorterString());
    // for_each(vs.begin(), vs.end(), [](const string &s) { cout << s << endl; });
    int sz = 3;

    auto wc = find_if(vs.begin(), vs.end(), [sz](const string &a) { return a.size() >= sz; });

    for_each(wc, vs.end(), PrintString());

    cout << endl
         << "----------------------" << endl;
    wc = find_if(vs.begin(), vs.end(), SizeComp(sz));

    // SizeComp(sz) 和 [sz](const string &a){ return a.size() > sz; } 是等价的

    for_each(wc, vs.end(), printer);

    cout << endl
         << "----------------------" << endl;

    plus<int> intAdd;

    int sum = intAdd(10, 20);
    cout << "sum = " << sum << endl;

    plus<string> stringAdd;
    minus<string> stringSub;
    multiplies<string> stringMul;
    divides<string> stringDiv;
    // plus minus mutiplies ... 无非就是调用对象的 + - * / 等运算符,如果对象没有定义相应的运算符就会出错
    string result = stringAdd("111111", "111111");

    cout << "result = " << result << endl;

    //  result = stringDiv("1111", "1111");
    //  string 没有定义 / 运算符, 所以不能进行 / 操作

    cout << "result = " << result << endl;

    plus<Sales_item> SaleAdd;
    // 因为 Sales_item 类定义了 + 运算符,可以进行运算
    Sales_item s1("1");
    s1.units_sold = 1;
    Sales_item s2("2");
    s2.units_sold = 2;
    Sales_item si = SaleAdd(s1, s2);
    // 运算结果是两个sold 相加, 也就是 3
    cout << "si.units_sold = " << si.units_sold << endl;

    sort(vs.begin(), vs.end(), greater<string>());
    // less<string *> 对指针也是支持的

    return 0;
}