#include <iostream>
#include <algorithm>

using namespace std;

void quick_sort(int* arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = start;
    int i = pivot + 1;
    int j = end;

    while (i <= j)
    {
        while (i <= end && arr[i] <= arr[pivot])
        {
            i++;
        }
        while (j > start && arr[j] >= arr[pivot])
        {
            j--;
        }

        if (i > j)
        {
            swap(arr[pivot], arr[j]);
        }
        else
        {
            swap(arr[i], arr[j]);
        }
    }
    quick_sort(arr, start, j - 1);
    quick_sort(arr, j + 1, end);
}

int main()
{
    int length;
    cin >> length;

    int* arr = new int[length];

    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    quick_sort(arr, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        cout << arr[i];
    }

    delete[] arr;

    return 0;
}