#include <iostream>
#include <vector>
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
    for (int i = 0; i < 10; i++)
    {
        A a;
        v1.push_back(a);
    }
    cout << "----------------------------" << endl;
    for (auto f : v1)
    {
        cout << " nice " << endl;
    }
    return 0;
}