#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <string>
#include <new>

using namespace std;
vector<int> createVector();
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
    return 0;
}
vector<int> createVector()
{
    return vector<int>(10);
}