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

int main()
{
    int N;
    int A[1001];

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
    }

    if (N == 1)
    {
        cout << "1";
        return 0;
    }

    int cache[1001];
    int cache_reverse[1001];

    // 증가하는 부분 수열
    for (int i = 1; i <= N; ++i)
    {
        cache[i] = 1;
        int maxi = 0;
        for (int j = 1; j <= i; ++j)
        {
            if (A[i] > A[j])
            {
                maxi = max(maxi, cache[j]);
            }
        }

        cache[i] = maxi + 1;
    }

    // 뒤에서 부터 탐색하여 증가하는 부분 수열
    for (int i = N; i >= 1; --i)
    {
        cache_reverse[i] = 1;
        int maxi = 0;
        for (int j = N; j >= i; --j)
        {
            if (A[i] > A[j])
            {
                maxi = max(maxi, cache_reverse[j]);
            }
        }

        cache_reverse[i] = maxi + 1;
    }

    // 가장 긴 바이토닉의 부분 수열의 가운데 값을 찾는 과정
    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        answer = max(answer, cache[i] + cache_reverse[i] - 1);
    }

    cout << answer;

    return 0;
}