#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
int main()
{
    // map
    {
        map<string, size_t> word_count;
        string word;
        while (cin >> word)
            ++word_count[word];
        for (const auto &w : word_count)
            cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times " : " time ") << endl;
    }
    {
        map<string, size_t> word_count;
        set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
        string word;
        while (cin >> word)
            ++word_count[word];
        for (const auto &w : word_count)
            cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times " : " time ") << endl;
    }

    return 0;
}