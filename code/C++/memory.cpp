#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <new>
#include <set>

using namespace std;
vector<int> createVector();
void runQueries(ifstream &infile);
class QueryResult;
class TextQuery;
ostream &print(ostream &os, const QueryResult &qr);
class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

  public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(p), file(f) {}

  private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};
class TextQuery
{
  public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

  private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
    string text;
    while (getline(is, text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word)
        {
            auto &lines = wm[word];
            if (!lines)
            {
                lines.reset(new set<line_no>);
            }
            lines->insert(n);
        }
    }
}
ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << ((qr.lines->size() > 1)
               ? "times"
               : "time")
       << endl;
    for (auto num : *qr.lines)
    {
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    }
    return os;
}
QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}
int main()
{

    { // 智能指针
        shared_ptr<vector<int>> p;
        shared_ptr<string> p1;
        shared_ptr<list<int>> p2;
        if (p1 && p1->empty())
            *p1 = "hi";
        shared_ptr<int> p3 = make_shared<int>(42);
        shared_ptr<string> p4 = make_shared<string>(10, '9');
        shared_ptr<int> p5 = make_shared<int>();
        auto p6 = make_shared<vector<string>>();
        for (int i = 0; i < 10; i++)
            p6->push_back(to_string(i));
        for (const auto t : *p6)
            cout << stoi(t) << endl;
        /* *p = createVector();
        cout << (*p).size() << endl;
        内存访问出错，因为局部的vector已经释放
        */
    }

    {
        // new
        int *pi = new int(1024);
        string *ps = new string(10, '9');

        vector<int> *pv = new vector<int>{0, 1, 2, 3, 4};
        vector<int> *pz = new vector<int>(10, 10);
        cout << *(pz->begin()) << endl;
        int i(1024);

        auto p1 = new auto(10);
        // auto p2 = new auto(1, 2, 3); 只能有单个
    }

    {
        int i;
        int *p1 = new int;           // 内存消耗完后抛出 std::bad_alloc
        int *p2 = new (nothrow) int; // 内存消耗完不抛出异常，而是返回一个空指针
        delete p1;
        // delete p1; // repeat free is not defined
        delete p2; //
        const int *pci = new const int(1024);
        delete pci;
        pci = nullptr;
    }

    // new combine share_ptr
    {
        shared_ptr<double> p1;
        shared_ptr<int> p2(new int(42));
        // shared_ptr<int> p3 = new int(1024); // 这样是错的，不能隐式转换
        /* 这样也是不行的
        shared_ptr<int> clone(int p){
            return new int(p);
        }*/

        /* 这样就可以
        shared_ptr<int> clone(int p){
            return shared_ptr<int>(new int(p));
        }
        */

        /*
        int *x(new int(1024)); // 不是智能指针
        process(x);
        process(shared_ptr<int>(x)); //在调用完后引用变0
        int j = *x;                  // 访问悬空指针
        */
        shared_ptr<string> p(new string("shared_ptr"));
        shared_ptr<string> px(p);

        if (!p.unique())
        {
            cout << "many " << endl;
            p.reset(new string(*p));
        }
        *p += " 11";
        cout << "*p = " << *p << endl;
    }
    // weak_prt
    {

        auto p = make_shared<int>(42);
        weak_ptr<int> wp(p);
        if (shared_ptr<int> np = wp.lock())
        {
            // through lock function determine whether references exists or not
        }
    }

    {
        int *pia = new int[10];          // non initialize
        int *pia2 = new int[10]();       //already initialize 0
        string *psa = new string[10];    // ten empty string
        string *psa2 = new string[10](); // ten empty string

        // char arr[0]; // error
        char *cp = new char[0]; // correct , but cp can't *cp
        unique_ptr<int[]> up(new int[10]);
        // shared_ptr don't directly support dynamic array
        for (int i = 0; i != 10; i++)
            up[i] = i;
        up.release(); // auto call delete[] to destroy pointer

        shared_ptr<int> sp(new int[10], [](int *p) { delete[] p; });
        for (size_t i = 0; i != 10; ++i)
            *(sp.get() + i) = i;
        sp.reset();
    }
    // allocator
    {
        int n = 10;
        allocator<string> alloc;
        auto const p = alloc.allocate(n); // allocate n non-initialize string

        auto q = p;
        alloc.construct(q++, 10, 'c');
        cout << "after alloc.construct " << *p << endl;
        alloc.construct(q++, "hi");
        // if p is not initialize , it is a disaster
        while (q != p)
            alloc.destroy(--q);
        // we just only call destroy for constructed object;

        alloc.deallocate(p, n); // n must be equal to initial distribution

        allocator<int> alloc1;
        vector<int> vi = {1, 2, 3, 4, 5};
        auto p1 = alloc1.allocate(vi.size() * 2);
        auto q1 = uninitialized_copy(vi.begin(), vi.end(), p1);
        uninitialized_fill_n(q1, vi.size(), 42);
        cout << "*p1 = " << (*p1) << " q1 = " << *q1 << endl;
    }

    {
        vector<string> vs = {"one", "two", "three", "four"};
        cout << vs[0] << endl;
    }
    // ifstream mfile("/home/splend/github/code/C++/infile");
    ifstream mfile("infile");
    runQueries(mfile);
    return 0;
}
vector<int> createVector()
{
    return vector<int>(10);
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter a word to look for, or q to quit :";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}