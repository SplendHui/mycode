#include <iostream>
#include <set>

using namespace std;

class A
{

  public:
    A() = default;

    A(int a, string name)
    {
        this->a = a;
        this->name = name;
    }

    static bool compare(const A &lhs, const A &rhs)
    {
        return lhs.name > rhs.name;
    }

    int a;
    string name;
};
bool compare(const A &lhs, const A &rhs)
{
    return lhs.name < rhs.name;
}

int main()
{

    set<A, decltype(compare) *> s{compare};
    s.insert({1, "10"});
    s.insert({2, "10"});
    s.insert({3, "30"});
    s.insert({4, "20"});

    for (auto i : s)
        cout << "a = " << i.a << " name = " << i.name << endl;
    return 0;
}