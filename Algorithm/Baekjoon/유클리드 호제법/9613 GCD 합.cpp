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
#include <climits>
#include <sstream>
#include <cstdlib>

using namespace std;

int nums[100];

int gcd(int a, int b)
{
    if (a < b)
    {
        swap(a, b);
    }

    int temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }

        long long answer = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                answer += gcd(nums[i], nums[j]);
            }
        }

        cout << answer << '\n';

        memset(nums, 0, sizeof(nums));
    }

    return 0;
}
