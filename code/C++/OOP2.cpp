#include <iostream>
using namespace std;

void acc();
class Base
{
  public:
    void pub_mem() { cout << "pub_mem()" << endl; }
    friend void acc();
    virtual ~Base() { cout << "Base destroy" }

  protected:
    int prot_mem = 10;

  private:
    char priv_mem = 'A';
};

class Pub_Derv : public Base
{

    int f() { return prot_mem; }
    // 没有访问权限
    // char g() { return priv_mem; }
    virtual ~Pub_Derv() { cout << "Pub_Derv destroy" << endl; }
};

class Priv_Derv : private Base
{
  public:
    int f1() const { return prot_mem; }
    virtual ~Priv_Derv() { cout << "Priv_Derv destroy" << endl; }
    friend void acc();
};

class Prot_Derv : protected Base
{
  public:
    friend void acc(Prot_Derv &p);
    int use_base()
    {
        cout << prot_mem << endl;
        pub_mem();
        return 1;
    }
};

class Derived_from_Public : public Pub_Derv
{
    int use_base()
    {
        return prot_mem;
    }
};

class Derived_from_Private : public Priv_Derv
{
    // int use_base() { return prot_mem; }
};

void acc(Prot_Derv &p)
{
    //    p.priv_mem;
}
int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    d1.pub_mem();
    int a = d2.f1();
    cout << "a = " << a << endl;
    // d2.pub_mem(); // 访问错误

    return 0;
}