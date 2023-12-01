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

using namespace std;

long long cache[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    // 먼저 약수들의 합을 구해야 한다.
    // 약수들의 합을 O(N * log(N))의 시간복잡도로 구한다.
    for (int i = 1; i <= 1000000; ++i)
    {
        for (int j = 1; i * j <= 1000000; ++j)
        {
            cache[i * j] += i;
        }
    }
    // 구해야 하는 것은 g(x)이므로 g(x) = g(x - 1) + f(x)이다. 
    // 누적 합으로 g(x)를 구한다.
    for (int i = 2; i <= 1000000; ++i)
    {
        cache[i] += cache[i - 1];
    }

    while (T--)
    {
        int N;
        cin >> N;

        // g(N)을 출력한다.
        cout << cache[N] << '\n';
    }

    return 0;
}
