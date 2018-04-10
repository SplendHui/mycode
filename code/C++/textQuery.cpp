#include <iostream>
#include <memory>

using namespace std;

class Query_base
{
    friend class Query;

  protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

  private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

  public:
    Query(const std::string &);
    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { return q->rep() }

  private:
    Query(std::shared_ptr<Query_base> query) : q(query) {}
    std::shared_ptr<Query_base> q;
};

int main()
{
    return 0;
}