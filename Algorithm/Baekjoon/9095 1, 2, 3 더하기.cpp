#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int cache[11];

int make_number(int n)
{
    int result = 0;
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
    else if (n == 3)
    {
        return 4;
    }

    if (cache[n] != 0)
    {
        return cache[n];
    }

    cache[n] = make_number(n - 1) + make_number(n - 2) + make_number(n - 3);
    return cache[n];
}

int main()
{
    int repeat;
    cin >> repeat;

    for (int i = 0; i < repeat; i++)
    {
        int n;
        cin >> n;
        cout << make_number(n) << endl;
    }

    return 0;
}