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

// 캐시를 두어 시간초과 방지
int cache[30][30];

int Combination(int n, int r)
{
    if (n == r || r == 0)
    {
        cache[n][r] = 1;
        return 1;
    }
    else if (cache[n][r] != -1)
    {
        return cache[n][r];
    }
    else
    {
        cache[n][r] = Combination(n - 1, r - 1) + Combination(n - 1, r);
        return cache[n][r];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    memset(cache, -1, sizeof(cache));

    while (T--)
    {
        // 동쪽의 사이트 중에서 N개를 고르는 경우의 수
        int N, M;
        cin >> N >> M;

        cout << Combination(M, N) << '\n';
    }

    return 0;
}
