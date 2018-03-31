#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <functional>
using namespace std;
using namespace std::placeholders;
bool isShorter(const string &s1, const string &s2);
string make_plural(size_t ctr, const string &word, const string &ending);
void fcn1();
bool check_size(const string &s, string::size_type sz);
int main()
{

    /*
        vector
    */
    {
        vector<int> v;
        for (int i = 0; i < 5; i++)
        {
        }

        for (int i = 0; i < 5; i++)
            v.push_back(i);
        vector<int>::iterator begin = v.begin();
        auto end = v.end();
        while (begin < end)
        {
            cout << *begin << endl;
            begin++;
        }
    }
    /*
        list
    */
    {
        list<string> ls = {"01", "02"};
        list<int> l1{1, 2, 3, 4};
        list<int> l2 = {1, 2, 3, 4};
        list<int> l3(10);
        list<int> l4(10, 1);

        cout << "size of l1 : " << l1.size() << endl;
        cout << "size of l2 : " << l2.size() << endl;
        cout << "size of l3 : " << l3.size() << endl;
        ls.push_back("03");
        ls.push_front("00");
        ls.push_back("04");
        list<string>::iterator lbegin = ls.begin();
        list<string>::iterator lend = ls.end();
        while (lbegin != lend)
        {
            cout << *lbegin << endl;
            lbegin++;
        }
    }
    /*
        vector
    */
    {
        vector<int> ivec(10, -1);
        list<string> svec(10, "hi!");
        forward_list<int> flvec(10);
        deque<string> dsevc(10);
        list<string> autohors = {"Milton", "Shakespeare", "Austen"};
        vector<const char *> articles = {"a", "an", "the"};
    }
    /*
        array
    */

    {
        array<int, 10>::size_type i;
        array<int, 5> a1 = {1, 2, 3, 4, 5};
        array<int, 5> a2 = {1, 2, 3}; //剩余的是0
        a2.swap(a1);
        array<int, 5>::iterator begin = a1.begin();
        array<int, 5>::iterator end = a1.end();
        while (begin != end)
        {
            cout << "array" << *begin << endl;
            begin++;
        }

        array<int, 5>
            copy = a1; //array<int, 10> copy = a1 error size must be same
        int digs[10] = {1, 2, 3, 4, 5, 6};
        //int cpy[10] = digs;// error
        // array<int>::size_type

        list<string> names = {"1", "2"};
        vector<const char *> oldstyle = {"3", "4"};
        // names = oldstyle; error
        // assign 方法会替换原来的。
        names.assign(oldstyle.cbegin(), oldstyle.cend());
        cout << "names end = " << *--names.end() << endl;
        // result : 3
        vector<string> svec1(10, "1"); // 10 个元素的vector
        vector<string> svec2(24);
        list<int> c1 = {1, 2};
        if (!c1.empty())
        {
            c1.front() = 42;
            int &v = c1.back();
            auto &v1 = c1.back();
            v = 1024;
            cout << "v = " << v << endl;
            auto v2 = c1.back();
            v2 = 0;
            cout << "v = " << c1.back() << endl;
        }

        svec1.insert(svec1.end(), {"1", "2"});

        swap(svec1, svec2);
        (*svec1.begin()) += 1;
        cout << " vector string " << (*svec1.begin()) << endl;
        cout << " vector string " << *svec2.begin() << endl;
        svec1.push_back("1"); //因为string是字符容器
        string s1;
        s1.push_back('a');
        cout << "s1 = " << s1 << endl; // 容器元素只是拷贝，和原始对象没有关系
    }
    {
        //cout << "v[0] = " << v[0] << endl;
        //cout << "v.at(0) = " << v.at(0) << endl;
        /*terminate called after throwing an instance of 'std::out_of_range'
        what() : vector::_M_range_check : __n(which is 0) >= this->size()(which is 0)
        Aborted(core dumped) */
        // list和forward_list 的迭代器不能与数字进行运
        vector<string> v;
        v.begin() + 2;
    }

    // delete operation
    {
        list<int> lst = {0, 1, 2, 3, 4, 5};
        auto it = lst.begin();
        auto begin = lst.begin();
        it++;
        it++;
        lst.erase(lst.begin(), it);
        cout << "begin = " << *begin << endl;
        cout << "lst begin = " << *lst.begin() << endl;
        it = lst.begin();
        while (it != lst.end())
        {
            if (*it % 2)
            {
                it = lst.erase(it);
            }
            else
            {
                ++it;
            }
        }
        lst.clear();
    }

    /*
        forward_lsit
    */
    {
        forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        auto it = flst.begin();
        flst.before_begin();
        it++;
        it++;
        it++;
        cout << "flst.erase " << *flst.erase_after(flst.begin(), it) << endl;
        cout << *flst.begin() << endl;
        // out : 3
        auto begin = flst.begin();
        auto end = flst.end();
        while (begin != end)
        {
            cout << "flst = " << *begin << endl;
            begin++;
        }
        cout << "flst.erase " << *flst.erase_after(flst.begin()) << endl;
        // out : 4
        cout << *++flst.begin() << endl;
    }

    {
        vector<int> v1;
        fill(v1.begin(), v1.begin() + v1.size() / 2, 0);
        v1.begin() + 1;
    }

    {
        stack<int> s1;
        for (int i = 0; i < 10; i++)
        {
            s1.push(i);
            // 不能调用 s1.push_back(i + 1);
        }
        priority_queue<int> pq;
        pq.push(1);
        pq.pop();
        cout << "pq size = " << pq.size() << endl;
        ;
    }

    cout << "---------------algorithm-----------------------------" << endl;

    {

        vector<int> v1 = {1, 2, 3, 4};
        int sum = accumulate(v1.begin(), v1.end(), 0);
        vector<string> v2 = {"1", "2", "3"};
        string s = accumulate(v2.begin(), v2.end(), string(""));
        cout << "s = " << s << endl;
        // 不能把整数加到字符串上.

        vector<int> v3 = v1;
        v3 = v1;
        // 报错 equal(v1.begin(), v1.end(), v2.begin());
        cout << equal(v1.begin(), v1.end(), v3.begin()) << endl;

        // fill
        fill(v1.begin(), v1.end(), 0);
        fill_n(v1.begin(), v1.size(), 0);
        // fill_n 如果v1 是空那就会出错。
        vector<int> t1;
        // fill_n(t1.begin(), 10, 0);
        // 导致非法访问
        auto it = back_inserter(t1);
        fill_n(back_inserter(t1), 10, 0);
        cout << "t1 size = " << t1.size() << endl;

        int a1[] = {0, 1, 2, 3, 4, 5, 6};
        int a2[sizeof(a1) / sizeof(*a1)];
        auto ret = copy(begin(a1), end(a1), a2);

        list<int> ilst = {1, 2, 3, 4, 5};

        replace(ilst.begin(), ilst.end(), 1, 11);
        vector<int> ivec;
        replace_copy(ilst.cbegin(), ilst.cend(), back_inserter(ivec), 0, 42);
        // ivec包含了ilst的拷贝
        cout << "size = " << ivec.size() << " first value = " << *ivec.begin() << endl;
        // size = 5 first value = 11

        // sort
        vector<string> words = {"fox", "jumps", "the", "red", "over", "quick", "red", "slow", "the", "no", "the1"};
        sort(words.begin(), words.end());
        auto end_unique = unique(words.begin(), words.end());
        words.erase(end_unique, words.end());
        for (auto w : words)
            cout << w << endl;
        sort(words.begin(), words.end(), isShorter);
        stable_sort(words.begin(), words.end(), isShorter);
        // lambda
        stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) {
            cout << "hello lambda" << endl;
            return s1.size() < s2.size();
        });
        // find_if()
        int sz = 5;
        auto wc = find_if(words.begin(), words.end(), [sz](const string &s1) { return s1.size() >= sz; });
        auto count = words.end() - wc;
        cout << count << " " << make_plural(count, "word", "s") << " of length = " << sz << " or longer " << endl;

        for_each(wc, words.end(), [](const string &s) { cout << s << " "; });
        cout << endl;
        for (auto w : words)
            cout << w << endl;
        cout << endl;
        fcn1();
    }

    cout << "---------------algorithm-----------------------------" << endl;
    /*
        bind library
     */

    {
        auto check6 = bind(check_size, _1, 6);
        string s = "hello";
        bool b1 = check6(s);
        // auto wc = find_if(words.begin(), words.end(),bind(check_size, _1, sz));
    }

    return 0;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() > s2.size();
}
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
void fcn1()
{
    size_t v1 = 42;
    auto f = [v1] { return v1; };
    v1 = 0;
    auto j = f();
    cout << "fcn1' s = " << j << endl;
    // j = 42 也就是说lambda在创建的时候就保存了v1的拷贝，不管后面怎么变，还是原来的值
}
void biggies(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char c = ' ')
{
    // io对象是不能拷贝的，因为也不能当参数也函数进行调用,引用却可以 。
    //lambda表达式可以获取在当前作用域中可见的名字，比如全局变量，std里面的等等。
    for_each(words.begin(), words.end(), [&os, c](const string &s) { os << s << c; });
    // = 为默认值捕获, &则是引用
    for_each(words.begin(), words.end(), [=, &os](const string &s) { os << s << c; });
}
void fcn3()
{
    // 可以修改局部变量
    size_t v1 = 42;
    auto f = [v1]() mutable { return ++v1; };
    v1 = 0;
    auto j = f(); // j = 43;
}
void fcn4()
{
    // 可以修改局部变量
    size_t v1 = 42;
    auto f = [&v1]() mutable { return ++v1; };
    v1 = 0;
    auto j = f(); // j = 1;
    const size_t v2 = 42;
    // auto f1 = [&v2]() mutable { return ++v2; };
    // 如果是const 则不能进行修改
    j = f();
}
bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}