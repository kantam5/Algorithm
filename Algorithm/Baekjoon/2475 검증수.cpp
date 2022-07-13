#include <iostream>

using namespace std;

int main()
{
    int num[5];

    int temp = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> num[i];
    }

    for (int i = 0; i < 5; i++)
    {
        temp += num[i] * num[i];
    }

    cout << temp % 10;

    return 0;
}