/*
Description

This problem is a reverse case of the problem 2996. You are given the output of the problem H and your task is to find the corresponding input.
Input

according to output of problem 2996.
Output

according to input of problem 2996.
Sample Input

White: Ke1,Qd1,Ra1,Rh1,Bc1,Bf1,Nb1,a2,c2,d2,f2,g2,h2,a3,e4
Black: Ke8,Qd8,Ra8,Rh8,Bc8,Ng8,Nc6,a7,b7,c7,d7,e7,f7,h7,h6
Sample Output

+---+---+---+---+---+---+---+---+
|.r.|:::|.b.|:q:|.k.|:::|.n.|:r:|
+---+---+---+---+---+---+---+---+
|:p:|.p.|:p:|.p.|:p:|.p.|:::|.p.|
+---+---+---+---+---+---+---+---+
|...|:::|.n.|:::|...|:::|...|:p:|
+---+---+---+---+---+---+---+---+
|:::|...|:::|...|:::|...|:::|...|
+---+---+---+---+---+---+---+---+
|...|:::|...|:::|.P.|:::|...|:::|
+---+---+---+---+---+---+---+---+
|:P:|...|:::|...|:::|...|:::|...|
+---+---+---+---+---+---+---+---+
|.P.|:::|.P.|:P:|...|:P:|.P.|:P:|
+---+---+---+---+---+---+---+---+
|:R:|.N.|:B:|.Q.|:K:|.B.|:::|.R.|
+---+---+---+---+---+---+---+---+

*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
 
char map[9][9];
 
void init()
{
    memset(map, 0, sizeof(map));
    string st;
    cin >> st;
    getline(cin, st);
    int i = 0;
    while (st[i] != '\0')
    {
        i++;
        char ch;
        if (st[i] > 'Z')
            ch = 'P';
        else
        {
            ch = st[i];
            i++;
        }
        int y = st[i++] - 'a' + 1;
        int x = st[i++] - '0';
        x = 9 - x;
        map[x][y] = ch;
    }
    cin >> st;
    getline(cin, st);
    i = 0;
    while (st[i] != '\0')
    {
        i++;
        char ch;
        if (st[i] > 'Z')
            ch = 'p';
        else
        {
            ch = st[i] + 'a' - 'A';
            i++;
        }
        int y = st[i++] - 'a' + 1;
        int x = st[i++] - '0';
        x = 9 - x;
        map[x][y] = ch;
    }
}
 
void output()
{
    string line = "+---+---+---+---+---+---+---+---+";
 
    cout << line << endl;
    for (int i = 1; i < 9; i++)
    {
        for (int j = 1; j < 9; j++)
        {
            char ch1 = map[i][j], ch;
            if ((i + j) % 2 == 1)
                ch = ':';
            else
                ch = '.';
            if (ch1 == 0)
                ch1 = ch;
            printf("|%c%c%c", ch, ch1, ch);
        }
        cout << "|" << endl;
        cout << line << endl;
    }
}
int main()
{
    //freopen("D:\\t.txt", "r", stdin);
    init();
    output();
    return 0;
}