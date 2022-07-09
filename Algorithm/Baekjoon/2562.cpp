#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int array[9];

    for (int i = 0; i < 9; i++)
    {
        std::cin >> array[i];
    }

    int max = array[0];
    int max_index = 0;

    for (int i = 1; i < 9; i++)
    {
        if (max < array[i])
        {
            max = array[i];
            max_index = i;
        }
    }

    std::cout << max << endl << max_index + 1;

    return 0;
}