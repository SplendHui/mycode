#include <iostream>

using namespace std;

class Quote
{
  public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const
    {
        cout << "Quote" << endl;
        return n * price;
    }
    virtual ~Quote() = default;

  private:
    std::string bookNo;

  protected:
    double price = 0.0;
};

class Bulk_quote : public Quote
{
  public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc)
    {

        price = 11;
    }
    double net_price(std::size_t cnt) const
    {
        cout << "Bulk_quote" << endl;
        if (cnt >= min_qty)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }

  private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n); // 常亮引用,必须调用常量的成员函数.
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

class Base
{
  public:
    static void statemem();
};

class Derived : public Base
{
    void f(const Derived &);
};

void Derived::f(const Derived &derived_obj)
{
    Base::statemem();
    Derived::statemem();
    derived_obj.statemem();
    statemem();
}

int main()
{
    // Quote basic;
    // Bulk_quote bulk;

    // print_total(cout, basic, 20);
    // print_total(cout, bulk, 20);

    Quote item("java", 10.5);
    Bulk_quote bulk("C++", 20.5, 10, 0.3);
    Quote *p = &item;
    p = &bulk;
    Quote &r = bulk;
    p->isbn();
    print_total(cout, item, 10);
    print_total(cout, bulk, 10);

    return 0;
}