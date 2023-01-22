#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <memory.h>
#include <unordered_map>
#include <cmath>
#include <deque>

using namespace std;

int cache[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a;
    string b;

    cin >> a >> b;

    a = '0' + a;
    b = '0' + b;

    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++)
        {
            if (i == 0 || j == 0)
            {
                cache[i][j] = 0;
                continue;
            }

            if (a[i] == b[j])
            {
                cache[i][j] = cache[i - 1][j - 1] + 1;
            }
            else
            {
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
            }
        }
    }

    cout << cache[a.length() - 1][b.length() - 1] << endl;

    return 0;
}