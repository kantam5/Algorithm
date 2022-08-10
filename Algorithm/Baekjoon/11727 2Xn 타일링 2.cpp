#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

int cache[1001];

int main()
{
    int n;
    cin >> n;

    cache[0] = 1;
    cache[1] = 3;

    for (int i = 2; i < n; i++)
    {
        cache[i] = (cache[i - 1] + cache[i - 2] * 2) % 10007;
    }

    cout << cache[n - 1];

    return 0;
}