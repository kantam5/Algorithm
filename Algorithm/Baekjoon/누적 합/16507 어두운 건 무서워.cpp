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

int nums[1001][1001];
int sum[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C, Q;
    cin >> R >> C >> Q;

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            cin >> nums[i][j];
        }
    }

    // (0, 0)에서 (i, j)까지의 누적합
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            sum[i][j] = nums[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    while (Q--)
    {
        // (r1, c1)에서 (r2, c2)까지의 합을 구하고, 해당 구간의 원소의 수로 나눈다.
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int answer = sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];
        int pixel_num = (r2 - r1 + 1) * (c2 - c1 + 1);

        cout << answer / pixel_num << '\n';
    }

    return 0;
}