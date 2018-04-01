#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>
using namespace std;
void func();
int main()
{
    // map
    {
        map<string, size_t> word_count;
        map<string, string> authors = {{"Joyce", "James"}, {"Austen", "Jane"}, {"Dickens", "Charles"}};
        string word;
        //while (cin >> word)
        //    ++word_count[word];
        for (const auto &w : word_count)
            cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times " : " time ") << endl;
    }

    {
        map<string, size_t> word_count;
        set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
        string word;
        /*
        while (cin >> word)
            if (exclude.find(word) == exclude.end())
                ++word_count[word];
        for (const auto &w : word_count)
            cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times " : " time ") << endl;
        */
    }

    {
        vector<int> ivec;
        for (vector<int>::size_type i = 0; i != 10; ++i)
        {
            ivec.push_back(i);
            ivec.push_back(i);
        }
        set<int> iset(ivec.cbegin(), ivec.cend());
        multiset<int> miset(ivec.cbegin(), ivec.cend());
        cout << ivec.size() << endl;
        cout << iset.size() << endl;
        cout << miset.size() << endl;
    }
    decltype(func) *p;
    p = &func;
    p();

    {
        map<string, size_t> word_count;
        string word;
        while (cin >> word)
            ++word_count[word];
        auto map_it = word_count.begin();
        cout << map_it->first;
        cout << " " << map_it->second;
        // map_it->first = "new key"; // error
        ++map_it->second;
    }

    // set iterator 不能修改
    {
        set<int> iset = {0, 1, 2, 3, 4, 5};
        set<int>::iterator set_it = iset.begin();
        if (set_it != iset.end())
        {
            // *set_it = 42; // error
        }
        cout << *set_it << endl;
    }

    {
        map<string, size_t> word_count;
        string word;
        while (cin >> word)
        {
            auto ret = word_count.insert({word, 1});
            if (!ret.second)
                ++ret.first->second;
        }
    }

    {
        multimap<string, string> authors;
        authors.insert({"Barth, John", "Sot-Weed Factor"});
        authors.insert({"Barth, John", "Lost in the Funhouse"});
        authors.insert({"Barth, 1", "1 in the Funhouse"});
        authors.insert({"Barth, 2", "2 in the Funhouse"});
        for (auto t : authors)
            cout << t.first << " " << t.second << endl;
        // auto cnt = authors.erase("Barth, John");
        // cout << "cnt = " << cnt << endl;
        string search_item = "Barth, John";
        auto entries = authors.count(search_item);
        auto iter = authors.find(search_item);
        while (entries)
        {
            cout << iter->second << endl;
            ++iter;
            --entries;
        }
        for (auto beg = authors.lower_bound(search_item),
                  end = authors.upper_bound(search_item);
             beg != end; ++beg)
            cout << beg->second << endl;
        for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
            cout << pos.first->second << endl;

        authors.erase(++authors.begin(), --authors.end());
        // 删除的不包括 end，
        cout << authors.size() << endl;
    }
    return 0;
}
void func()
{
    cout << "func()" << endl;
}
pair<string, int> process(vector<string> &v)
{
    // process v
    if (!v.empty())
    {
        return {v.back(), v.back().size()};
        // return pair<string, int>(v.back(), v.back().size());
        // return make_pair(v.back(), v.back().size());
    }
    else
        return pair<string, int>();
}