#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 정진교
int part(int number)
{
    int sum = number;

    // 자릿수에 해당하는 값을 더하는 부분
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