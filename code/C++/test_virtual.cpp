#include <iostream>
using namespace std;

class Base
{
  public:
    Base()
    {
        cout << "Base()" << endl;
    }

    virtual ~Base()
    {
        cout << "~Base()" << endl;
    }

  private:
    virtual void print()
    {
        cout << "hello" << endl;
    }
};

class Derived : public Base
{

  public:
    Derived()
    {
        cout << "Derived()" << endl;
    }
    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
    void print()
    {
        cout << " " << endl;
    }
    int print(int a)
    {
        cout << "int print" << endl;
    }
};

int main()
{

    // Base *p = new Derived();
    Derived b;
    b.print();
    // p->print();
    // delete p;
    return 0;
}