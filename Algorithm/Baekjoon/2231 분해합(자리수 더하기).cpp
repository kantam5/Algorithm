#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int part(int number)
{
    int sum = number;

    while (number)
    {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

int main()
{
    int number;
    cin >> number;

    for (int i = 1; i < number; i++)
    {
        if (part(i) == number)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << "0" << endl;

    return 0;
}