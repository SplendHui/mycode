#include <iostream>
#include <set>
#include <memory>
#include "Quote_Bulk.cpp"
using namespace std;

class Basket
{
  public:
    void add_item(const Quote &sale)
    {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote &&sale)
    {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }

    double total_receipt(std::ostream &) const;

    void print() const
    {
        for (auto i : items)
        {
            cout << "isbn = " << i->isbn() << " price = " << i->net_price(1) << endl;
        }
        // auto be = items.begin();
        // be++;
        // auto up1 = items.upper_bound(*be);
        // cout << "!isbn = " << (*up1)->isbn() << " price = " << (*up1)->net_price(1) << endl;
        // up1 = items.lower_bound(*be);
        // cout << "!isbn = " << (*up1)->isbn() << " price = " << (*up1)->net_price(1) << endl;
    }

  private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() > rhs->isbn();
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
    // bsk.add_item(make_shared<Quote>("123", 45));
    bsk.add_item(Quote("123", 45));
    // bsk.add_item(make_shared<Bulk_quote>("345", 1, 3, .15));
    // bsk.add_item(make_shared<Bulk_quote>("345", 2, 3, .15));
    // bsk.add_item(make_shared<Bulk_quote>("345", 3, 3, .15));
    // bsk.add_item(make_shared<Bulk_quote>("3456", 4, 3, .15));
    // bsk.add_item(make_shared<Bulk_quote>("345", 5, 3, .15));
    bsk.print();

    return 0;
}