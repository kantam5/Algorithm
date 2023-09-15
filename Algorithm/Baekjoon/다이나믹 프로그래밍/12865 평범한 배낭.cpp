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

int cache[101][100001];
int W[101];
int V[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int K;

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> W[i] >> V[i];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (i == 0 || j == 0)
                cache[i][j] = 0;
            else
            {
                // 현재 체크하는 보석이 들어갈 수 있는 무게라면
                if (j - W[i] >= 0)
                    // 이전에 체크한 보석의 캐시와 현재 체크하는 보석이 들어갈 수 있도록 무게를 확보하고 보석을 추가했을 때의 가치와 비교
                    cache[i][j] = max(cache[i - 1][j], V[i] + cache[i - 1][j - W[i]]);
                // 현재 들어갈 수 없는 무게라면 이전의 캐시를 넣는다.
                else
                    cache[i][j] = cache[i - 1][j];
            }
        }
    }

    cout << cache[N][K];

    return 0;
}