#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int length;
    std::cin >> length;

    int* array = new int[length];

    for (int i = 0; i < length; i++)
    {
        scanf_s("%d", &array[i]);
    }

    int min = array[0];
    int max = array[0];

    for (int i = 1; i < length; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }
        if (max < array[i])
        {
            max = array[i];
        }
    }

    cout << min << " " << max;

    delete[] array;

    return 0;
}