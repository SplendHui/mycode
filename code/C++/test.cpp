#include <iostream>
#include <vector>
#include <set>
#include <new>
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

  private:
    int a;
};
int main()
{

    vector<A> v1;
    set<A *> v2;
    for (int i = 0; i < 10; i++)
    {
        A *a = new A();
        v2.insert(v2.begin(), a);
    }
    cout << "----------------------------" << endl;
    cout << v2.size() << endl;
    for (auto f : v2)
    {
        cout << " nice " << endl;
    }
    return 0;
}