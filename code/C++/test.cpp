#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
    HasPtr &operator=(HasPtr rhs)
    {
        cout << "=" << endl;
        std::swap(*this, rhs); // 这会造成无限递归
        // ps = rhs.ps;
        // i = rhs.i;
        return *this;
    }

  private:
    std::string *ps;
    int i;
};

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
    //     Cat c1;
    //     Cat c2;
    //     Cat c3;
    //     vector<Cat> v1;
    //     cout << v1.capacity() << endl;
    //     v1.push_back(c1);
    //     cout << v1.capacity() << endl;
    //     v1.push_back(c1);
    //     cout << v1.capacity() << endl;
    //     v1.push_back(c3);
    //     cout << v1.capacity() << endl;
    HasPtr hp2;
    //HasPtr hp = hp2;
    HasPtr hp = std::move(hp2);
    hp = hp2;

    return 0;
}