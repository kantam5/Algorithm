#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int result = 0;

    int length;
    cin >> length;

    char* numbers = new char[length];
    cin >> numbers;

    for (int i = 0; i < length; i++)
    {
        result += ((int)numbers[i] - 48);
    }

    cout << result;

    return 0;
}