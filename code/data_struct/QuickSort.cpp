#include <iostream>
#include <ctime>

using namespace std;
typedef int keytype;

void quickSort(keytype k[], int be, int end)
{
    int i, j;
    if (be < end)
    {
        i = be;
        j = end + 1;
        while (1)
        {
            do
                i++;
            while (!(k[be] <= k[i] || i == end));

            do
                j--;
            while (!(k[be] >= k[j] || j == be));

            if (i < j)
                swap(k[i], k[j]);
            else
                break;
        }
        swap(k[be], k[j]);
        quickSort(k, be, j - 1);
        quickSort(k, j + 1, end);
    }
}

int partion(keytype k[], int be, int end)
{
    int i, j = 0;
    if (be < end)
    {
        i = be;
        j = end + 1;
        while (1)
        {
            do
                i++;
            while (!(k[be] <= k[i] || i == end));

            do
                j--;
            while (!(k[be] >= k[j] || j == be));

            if (i < j)
                swap(k[i], k[j]);
            else
                break;
        }
        swap(k[be], k[j]);
    }
    return j;
}

int randomPartion(keytype k[], int be, int end)
{
    int i = rand() % (end - be + 1) + be;
    swap(k[i], k[be]);
    return partion(k, be, end);
}

void quickSortOptimized(keytype k[], int be, int end)
{
    /**
     * 
     * 空间复杂度最多log n
     * 
     * */
    while (be < end)
    {
        int mid = randomPartion(k, be, end);
        if (mid - be < end - mid)
        {
            quickSortOptimized(k, be, mid - 1);
            be = mid + 1;
        }
        else
        {
            quickSortOptimized(k, mid + 1, end);
            end = mid - 1;
        }
    }
}

int main()
{
    srand(time(NULL));
    int array[21];

    for (int i = 0; i < 21; i++)
    {
        array[i] = rand() % 100;
    }

    // quickSort(array, 1, 20);
    quickSortOptimized(array, 1, 20);
    for (int i = 1; i < 21; i++)
        cout << array[i] << " ";
    cout << endl;
    return 0;
}