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
    Bulk_quote(const std::string &, double, std::size_t, double);
    double net_price(std::size_t) const override
    {
        return discount * price;
    }

  private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

int main()
{
    // Quote basic;
    // Bulk_quote bulk;

    // print_total(cout, basic, 20);
    // print_total(cout, bulk, 20);

    Quote item;
    Bulk_quote bulk;
    Quote *p = &item;
    p = &bulk;
    Quote &r = bulk;
    p->isbn();

    return 0;
}