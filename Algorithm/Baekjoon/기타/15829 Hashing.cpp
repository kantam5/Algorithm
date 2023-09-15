#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;


int main()
{
    int length;
    cin >> length;

    long long result = 0;

    queue<int> q;
    for (int i = 0; i < length; i++)
    {
        long long mul = 1;
        for (int j = 0; j < i; j++)
        {
            mul *= 31;
            mul %= 1234567891;
        }

        char temp;
        cin >> temp;
        q.push((int)temp - 96);

        int int_temp = (int)temp - 96;

        result += int_temp * mul;
        result %= 1234567891;
    }

    cout << result << endl;

    return 0;
}