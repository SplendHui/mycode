#include <iostream>
#include <string>
using namespace std;
class Sale_Item;
class Sale_Item
{
  public:
    Sale_Item(string bn, string bname, double pce);
    Sale_Item(const Sale_Item &it);
    void printBook() const;

  private:
    double price;
    string bookname;
    string bookno;
};
void Sale_Item::printBook() const
{
    cout << bookname << endl;
}
Sale_Item::Sale_Item(string bno, string bname, double pce)
    : bookno(bno),
      bookname(bname),
      price(pce)
{
}
Sale_Item::Sale_Item(const Sale_Item &it)
{
}
struct NoCopy
{
    NoCopy() = default;
    NoCopy(const NoCopy &);
    NoCopy &operator=(const NoCopy &) = delete;
    ~NoCopy() = delete;
};
struct NoDtor
{
    NoDtor() = default;
    ~NoDtor() = delete;
};
class HasPtr
{
  public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) {}
    HasPtr &operator=(const HasPtr &);
    ~HasPtr() { delete ps; }

  private:
    std::string *ps;
    int i;
};
HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    return *this;
}
int main()
{
    /*
    {
        NoDtor nd; // error 
        NoDtor *p = new NoDtor(); it can do, but can't free memory;
        delete p; //error
    }
    */
    Sale_Item sale_Item("1", "C++ primer", 5.5);
    Sale_Item s1(sale_Item);
    sale_Item.printBook();
    return 0;
}