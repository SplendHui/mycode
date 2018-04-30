#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SmartPointer
{

  public:
    int *count;
    string *elem;
    SmartPointer(string *p = new string("hello")) : count(new int(1)), elem(p)
    {
        cout << "default" << endl;
    }
    SmartPointer(const SmartPointer &s) : elem(s.elem), count(s.count)
    {
        cout << "++" << endl;
        (*count)++;
    }
    SmartPointer &operator=(const SmartPointer &sp)
    {
        cout << "==" << endl;
        (*this).~SmartPointer();
        (*count)++;
        return *this;
    }

    ~SmartPointer()
    {
        cout << *count << endl;
        if (--(*count) == 0)
        {
            cout << "~SmartPointer()" << endl;
            delete elem;
        }
    }
};

void print(SmartPointer s)
{
    cout << "-----------" << endl;
    cout << *s.elem << endl;
}
template <class T, class t>
class Test
{
  private:
    T n;
    const T i;

  public:
    Test() : i(0) {}
    Test(T k);
    ~Test() {}

    void print();
    T operator+(T x);
};

class A
{
  public:
    void print() const
    {
        cout << "A" << endl;
    }
};
class B : public A
{
  public:
    void print() const
    {
        cout << "B" << endl;
    }
};

template <typename T>
void doPrint1(const T &t)
{
    t.print();
}
template <typename T>
void doPrint2(const T *t)
{
    t->print();
};

void doPrint3(const vector<A *> &bs)
{
    for (int i = 0; i < bs.size(); i++)
    {
        doPrint1(*bs[i]);
    }
}

int main()
{
    //     A a1;
    //     B b1;
    //     // A &a2 = b1;
    //     A *a2 = &b1;
    //     doPrint(a1);
    //     doPrint1(a2);
    vector<A *> v1;
    A a1;
    B b1;
    v1.push_back(&a1);
    v1.push_back(&b1);
    doPrint3(v1);

    // SmartPointer s1;
    // print(s1);
    // Test<int, vector<int>> s1;
    // cout << "----------------" << endl;
    // string s1 = "hello";
    // string s1("hello");
    // const char *s2 = s1.c_str();
    // cout << s1 << endl;
    // s1[1] = 'E';
    // cout << s2 << endl;
    return 0;
}