#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
using namespace std;
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
        while (cin >> word)
            if (exclude.find(word) == exclude.end())
                ++word_count[word];
        for (const auto &w : word_count)
            cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times " : " time ") << endl;
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

    return 0;
}