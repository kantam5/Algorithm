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

int cache[16][16];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < M; ++i)
    {
        cache[0][i] = 1;
    }
    for (int i = 0; i < N; ++i)
    {
        cache[i][0] = 1;
    }

    // (x, y)칸에 올 수 있는 경우의 수는 (x - 1, y)칸과 (x, y - 1)칸에 올 수 있는 경우의 수의 합이다.
    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j < M; ++j)
        {
            cache[i][j] = cache[i - 1][j] + cache[i][j - 1];
        }
    }

    if (K == 0)
    {
        cout << cache[N - 1][M - 1];
    }
    else
    {
        // 중간 경로 K의 (x, y) 좌표는 다음과 같이 나타낼 수 있다.
        int inter_x = (K - 1) / M;
        int inter_y = (K - 1) % M;

        // K에서 마지막 칸까지의 경로
        int inter_count = cache[inter_x][inter_y];
        int dest_count = cache[N - inter_x - 1][M - inter_y - 1];

        // K까지의 경로와 K에서 마지막 칸 까지의 경로의 곱을 출력
        cout << inter_count * dest_count;
    }

    return 0;
}
