#include <iostream>
#include <set>
#include <memory>
#include "OOP1.cpp"

class Basket
{
  public:
    void add_item(const std::shared_ptr<Quote> &sale)
    {
        items.insert(sale);
    }
    double total_receipt(std::ostream &) const;

  private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;

    for (auto iter = items.cbegin();
         iter != items.cend();
         iter = items.upper_bound(*iter))
    {
        sum += print_total(os, **iter, items.count(*iter));
    }

    os << "Total Sale:" << sum << endl;

    return sum;
}

int main()
{
    Basket bsk;
    bsk.add_item(make_shared<Quote>("123", 45));
    bsk.add_item(make_shared<Bulk_quote>("345", 45, 3, .15));

    return 0;
}