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

char board[2001][2001];
int sum_black[2001][2001];
int sum_white[2001][2001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> board[i][j];
        }
    }

    // 보드판의 첫 칸이 검정색인 보드와, 하얀색인 보드를 나눠서 생각한다. 
    // sum_black은 (i, j)칸 까지 첫 칸이 검정색인 보드를 만들 때, 칠해야 하는 칸의 수이다. 
    // sum_white는 (i, j)칸 까지 첫 칸이 하얀색인 보드를 만들 때, 칠해야 하는 칸의 수이다. 
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            sum_black[i][j] = sum_black[i - 1][j] + sum_black[i][j - 1] - sum_black[i - 1][j - 1];
            sum_white[i][j] = sum_white[i - 1][j] + sum_white[i][j - 1] - sum_white[i - 1][j - 1];

            // 현재 칸이 짝수 칸인 경우, 첫 칸이 검정색인 보드는 검정색이다.
            // 첫 칸이 하얀색인 보드는 하얀색이므로, 다른 색인 경우에는 sum_black[i][j]가 1더해진다. 
            if ((i + j) % 2 == 0)
            {
                if (board[i][j] == 'B')
                {
                    sum_white[i][j]++;
                }
                else
                {
                    sum_black[i][j]++;
                }
            }
            else
            {
                if (board[i][j] == 'B')
                {
                    sum_black[i][j]++;
                }
                else
                {
                    sum_white[i][j]++;
                }
            }
        }
    }

    // 보드의 첫 칸이 검정색인 보드와, 하얀색인 보드로 나눠서 K X K칸의 보드를 만들 때, 칠해야 하는 칸의 수가
    // 더 작은 보드를 만들며, 그 때의 최솟값을 구한다.
    int answer = INT_MAX;
    for (int i = 1; i <= N - K + 1; ++i)
    {
        for (int j = 1; j <= M - K + 1; ++j)
        {
            int current_black = sum_black[i + K - 1][j + K - 1]
                - sum_black[i - 1][j + K - 1] - sum_black[i + K - 1][j - 1] + sum_black[i - 1][j - 1];

            int current_white = sum_white[i + K - 1][j + K - 1]
                - sum_white[i - 1][j + K - 1] - sum_white[i + K - 1][j - 1] + sum_white[i - 1][j - 1];

            answer = min(answer, min(current_black, current_white));
        }
    }

    cout << answer;

    return 0;
}
