#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

    return 0;
}