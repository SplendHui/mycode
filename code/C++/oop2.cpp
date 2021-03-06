#include <iostream>
#include <set>
using namespace std;

class Quote
{
public:
  Quote() = default;
  Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
  std::string isbn() const
  {
    return bookNo;
  }

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

class Disc_quote : public Quote
{

public:
  Disc_quote() = default;
  Disc_quote(const std::string &book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) {}
  double net_price(std::size_t) const = 0;

protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) : Disc_quote(book, p, qty, disc)
  {
  }

  double net_price(std::size_t cnt) const override
  {
    cout << "Bulk_quote" << endl;

    cout << "cnt = " << cnt << " discount = " << discount << " price = " << price << endl;
    if (cnt >= quantity)
      return cnt * (1 - discount) * price;
    else
      return cnt * price;
  }

private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};

double
print_total(ostream &os, const Quote &item, size_t n)
{
  double ret = item.net_price(n); // 常亮引用,必须调用常量的成员函数.
  os << "ISBN: " << item.isbn()
     << " # sold: " << n << " total due: "
     << ret << endl;
  return ret;
}
/*
int main()
{
  // Quote basic;
  // Bulk_quote bulk;

  // print_total(cout, basic, 20);
  // print_total(cout, bulk, 20);

  Quote item("java", 10.5);
  Bulk_quote bulk("C++", 20.5, 20, 0.3);
  // 如果Quote类型的变量就永远是一个Quote对象,
  // 只有当表达式是引用,或者指针的时候,才进行动态绑定.
  Quote *p = &item;
  p = &bulk;
  cout << bulk.net_price(10);
  print_total(cout, item, 10);
  print_total(cout, bulk, 10);

  return 0;
}
*/