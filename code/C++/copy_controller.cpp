#include <iostream>
#include <string>
using namespace std;
class Sale_Item;
class HasPtr;
inline void swap(HasPtr &lhs, HasPtr &rhs);
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
    friend void swap(HasPtr &, HasPtr &);
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i)
    {
        cout << "construct" << endl;
    }
    HasPtr &operator=(const HasPtr &);
    ~HasPtr() { delete ps; }
    void print()
    {
        cout << *ps << endl;
        HasPtr h1;
        h1 = h1;
    }

  private:
    std::string *ps;
    int i;
};
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    cout << "swap" << endl;
    using std::swap;
    // 用了using 后,其他类型swap优于std::swap,如果没有就用std::swap
    // 这个例子中没有特别，所以还是调用std::swap的;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}
HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    return *this;
    /* 这种是错误的，如果rhs和本对象是同一对象，那就空指针了,我测试还没出现错误
    delete ps;
    cout << "=" << endl;
    ps = new string(*(rhs.ps));
    i = rhs.i;
    return *this;
    // 好的习惯，先赋值右边对象，然后再释放，再赋值。
    */
}
class HasPtr1
{
  public:
    HasPtr1(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    HasPtr1(const HasPtr1 &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr1 &operator=(const HasPtr1 &);
    ~HasPtr1();

  private:
    std::string *ps;
    int i;
    std::size_t *use;
};
HasPtr1::~HasPtr1()
{
    if (*--use == 0)
    {
        delete ps;
        delete use;
    }
}
HasPtr1 &HasPtr1::operator=(const HasPtr1 &rhs)
{
    ++*rhs.use;
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
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
    HasPtr h1("1");
    HasPtr h2(h1);
    swap(h1, h2);
    h2 = h1;
    h1.print();
    h1 = h1;
    h2.print();

    return 0;
}
