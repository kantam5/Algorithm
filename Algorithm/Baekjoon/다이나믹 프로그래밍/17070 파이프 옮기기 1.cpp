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

#define VER 0
#define HOR 1
#define DIA 2

using namespace std;

int cache[16][16][3];
bool ground[16][16];

int main()
{
    int N;
    int answer = 0;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> ground[i][j];
        }
    }

    // 첫 시작 위치
    cache[0][1][0] = 1;

    for (int i = 2; i < N; ++i)
    {
        if (!ground[0][i])
        {
            cache[0][i][VER] = cache[0][i - 1][VER];
        }
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = 2; j < N; ++j)
        {
            if (!ground[i][j])
            {
                cache[i][j][VER] = cache[i][j - 1][VER] + cache[i][j - 1][DIA];
                cache[i][j][HOR] = cache[i - 1][j][HOR] + cache[i - 1][j][DIA];
                if (!ground[i - 1][j] && !ground[i][j - 1])
                {
                    cache[i][j][DIA] = cache[i - 1][j - 1][VER] + cache[i - 1][j - 1][HOR] + cache[i - 1][j - 1][DIA];
                }
            }
        }
    }

    answer = cache[N - 1][N - 1][VER] + cache[N - 1][N - 1][HOR] + cache[N - 1][N - 1][DIA];

    cout << answer;

    return 0;
}