#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(string *&p1, string *&p2);
class HasPtr
{
  public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0)
    {
        cout << "std::string()" << endl;
    }
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i)
    {
        p.ps = 0;
        cout << "HasPtr &&p" << endl;
    }
    HasPtr(HasPtr &p) : ps(p.ps), i(p.i)
    {

        cout << "hasptr &p" << endl;
    }
    HasPtr &operator=(HasPtr rhs) noexcept
    {
        cout << "=" << endl;
        swap(ps, rhs.ps); // 这会造成无限递归
        // 由于swap 里面两次调用=,所以自己重新实现swap就可以解决
        // ps = rhs.ps;
        // i = rhs.i;
        return *this;
    }

    std::string *ps;
    int i;
};

void swap(string *&p1, string *&p2)
{
    string *t = p1;
    p1 = p2;
    p2 = p1;
}
class Cat
{
  private:
    string name;
    int size;

  public:
    Cat(const Cat &rv)
    {
        cout << "copy construct" << endl;
    }
    Cat() : name(""), size(1)
    {
        cout << "construct" << endl;
    }
    ~Cat()
    {
        cout << "~Cat" << endl;
    }
    void print()
    {
        cout << "print" << endl;
    }
};

int main()
{
    Cat c1;
    Cat c2;
    Cat c3;
    vector<Cat> v1;
    cout << v1.capacity() << endl;
    v1.push_back(c1);
    cout << v1.capacity() << endl;
    v1.push_back(c1);
    cout << v1.capacity() << endl;
    v1.push_back(c3);
    cout << v1.capacity() << endl;
    HasPtr hp2("hp2");
    // HasPtr hp = hp2;
    HasPtr hp = std::move(hp2);
    // HasPtr hp;
    // hp = hp2;
    cout << *hp.ps << endl;

    return 0;
}