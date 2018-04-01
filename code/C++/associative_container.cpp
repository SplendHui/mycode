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
    }

    return 0;
}