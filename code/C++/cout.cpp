#include <iostream>
#include <iomanip>

using namespace std;
enum Color
{
    Red = 5,
    Green = 10,
    Yellow = 15
};
int main()
{

    // cout << showpoint << 3.14 << endl;
    // cout << noshowpoint << 3.14 << endl;
    // cout << setw(50) << left << setfill('$') << hex << 10 << endl;
    // cout << 10 << endl;
    // cout << "nice to meet you" << endl;

    Color red = Red;
    Color green = Color(5);
    if (5 == red)
        cout << red << endl;
    {

        bool a = true;
        int b = 10 + a;
        cout << "b = " << b << endl;
    }

    cout << boolalpha << 1 << endl;

    return 0;
}