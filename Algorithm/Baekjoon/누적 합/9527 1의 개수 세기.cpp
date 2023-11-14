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

using namespace std;

long long sum[55];

long long solution(long long x, long long i = 54)
{
    long long out = x & 1;
    for (; i > 0; i--)
    {
        if (x & ((long long)1 << i))
        {
            out += sum[i - 1] + (x - ((long long)1 << i) + 1);
            x -= (long long)1 << i;
        }
    }

    return out;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B;
    cin >> A >> B;

    sum[0] = 1;
    for (int i = 1; i < 55; ++i)
    {
        sum[i] = (2 * sum[i - 1]) + ((long long)1 << (i));
    }

    cout << solution(B) - solution(A - 1);

    return 0;
}