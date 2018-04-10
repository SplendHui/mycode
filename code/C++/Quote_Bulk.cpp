#ifndef QUOTE_BULK_H
#define QUOTE_BULK_H
#include <iostream>
#include <set>

class Quote
{
public:
  Quote() = default;
  Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
  std::string isbn() const
  {
    return bookNo;
  }

  virtual Quote *clone() const & { return new Quote(*this); }
  virtual Quote *clone() && { return new Quote(std::move(*this)); }

  virtual double net_price(std::size_t n) const
  {
    std::cout << "Quote" << std::endl;
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
  Bulk_quote *clone() const & { return new Bulk_quote(*this); }
  Bulk_quote *clone() && { return new Bulk_quote(std::move(*this)); }
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) : Disc_quote(book, p, qty, disc)
  {
  }

  double net_price(std::size_t cnt) const override
  {
    std::cout << "Bulk_quote" << std::endl;

    std::cout << "cnt = " << cnt << " discount = " << discount << " price = " << price << std::endl;
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
print_total(std::ostream &os, const Quote &item, size_t n)
{
  double ret = item.net_price(n); // 常量引用,必须调用常量的成员函数.
  os << "ISBN: " << item.isbn()
     << " # sold: " << n << " total due: "
     << ret << std::endl;
  return ret;
}

#endif // !QUOTE_BULK_H