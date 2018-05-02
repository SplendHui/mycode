#include <iostream>
#include <string>
using namespace std;
void print(int);

void print(int v)
{
    cout << "value = " << ++v << endl;
}

int main(int argc, char **argv)
{

    cout << argc << endl;
    for (int i = 0; i < argc; i++)
    {

        cout << *((argv + i)) << endl;
        // cout << argv[10];
    }
    // cout << *(argv + 30) << endl;
    const int value = 10;
    print(value);
    string s1;
    cin >> s1;
    cout << s1 << endl;
    return 0;
}