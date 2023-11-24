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

char ground[1001][1001];

int J_sum[1001][1001];
int O_sum[1001][1001];
int I_sum[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N, K;
    cin >> M >> N >> K;

    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> ground[i][j];
        }
    }

    // 정글, 바다, 얼음 세가지 배열로 나눠서 2차원 누적 합을 구한다.
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            J_sum[i][j] = J_sum[i - 1][j] + J_sum[i][j - 1] - J_sum[i - 1][j - 1];
            O_sum[i][j] = O_sum[i - 1][j] + O_sum[i][j - 1] - O_sum[i - 1][j - 1];
            I_sum[i][j] = I_sum[i - 1][j] + I_sum[i][j - 1] - I_sum[i - 1][j - 1];

            if (ground[i][j] == 'J')
            {
                J_sum[i][j]++;
            }
            else if (ground[i][j] == 'O')
            {
                O_sum[i][j]++;
            }
            else
            {
                I_sum[i][j]++;
            }
        }
    }

    while (K--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << J_sum[c][d] - J_sum[a - 1][d] - J_sum[c][b - 1] + J_sum[a - 1][b - 1] << " ";
        cout << O_sum[c][d] - O_sum[a - 1][d] - O_sum[c][b - 1] + O_sum[a - 1][b - 1] << " ";
        cout << I_sum[c][d] - I_sum[a - 1][d] - I_sum[c][b - 1] + I_sum[a - 1][b - 1] << '\n';
    }

    return 0;
}
