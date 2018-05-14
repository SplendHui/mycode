#include <iostream>
#include <ctime>
using namespace std;

typedef int keytype;

void adjust(keytype k[], int i, int n)
{
    int j;
    keytype tmp;
    tmp = k[i];
    j = i * 2;

    while (j <= n)
    {
        if (j < n && k[j] < k[j + 1]) // 改为 k[j] < k[j+1]
        {
            j++;
        }
        if (tmp >= k[j]) // 改为 tmp <= k[j]
        {
            break;
        }
        k[j / 2] = k[j];
        j = j * 2;
    }
    k[j / 2] = tmp;
}

void HeapSort(keytype k[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        adjust(k, i, n);
    }
    keytype tmp;
    for (int i = n - 1; i >= 1; i--)
    {
        tmp = k[i + 1];
        k[i + 1] = k[1];
        k[1] = tmp;
        adjust(k, 1, i);
    }
}

int main()
{
    srand(time(NULL));
    int array[21];
    for (int i = 0; i < 21; i++)
    {
        array[i] = rand() % 1000;
    }

    HeapSort(array, 20);

    for (int i = 1; i < 21; i++)
        cout << array[i] << " ";
    cout << endl;
}
