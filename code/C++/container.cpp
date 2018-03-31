#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
int main()
{

    /*
        vector
    */
    {
        vector<int> v;
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
        // list和forward_list 的迭代器不能与数字进行运算
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

    return 0;
}
