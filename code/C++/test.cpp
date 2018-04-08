#include <iostream>
#include <vector>
#include <set>
#include <new>
#include "Sales_item.hpp"
using namespace std;
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

  private:
    ~A()
    {
        cout << "destroy A" << endl;
    }
    int a;
};

class B : public A
{
};

int main()
{
    B b;
    vector<A> v1;
    set<A *> v2;
    for (int i = 0; i < 10000; i++)
    {
        A *a = new A();
        v2.insert(v2.begin(), a);
    }
    // cout << "----------------------------" << endl;
    // cout << v2.size() << endl;
    //auto v2c = std::move(v2);
    // for (auto f : v2)
    // {
    //     cout << " nice " << endl;
    // }

    return 0;
}