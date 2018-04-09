#include <iostream>
#include <set>
#include <memory>
#include "OOP1.cpp"

class Basket
{
  public:
    void add_item(const std::shared_ptr<Quote> &sale) {}
    double total_receipt(std::ostream &) const;

  private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }
};

int main()
{

    return 0;
}