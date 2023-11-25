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

    // �������� ù ĭ�� �������� �����, �Ͼ���� ���带 ������ �����Ѵ�. 
    // sum_black�� (i, j)ĭ ���� ù ĭ�� �������� ���带 ���� ��, ĥ�ؾ� �ϴ� ĭ�� ���̴�. 
    // sum_white�� (i, j)ĭ ���� ù ĭ�� �Ͼ���� ���带 ���� ��, ĥ�ؾ� �ϴ� ĭ�� ���̴�. 
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            sum_black[i][j] = sum_black[i - 1][j] + sum_black[i][j - 1] - sum_black[i - 1][j - 1];
            sum_white[i][j] = sum_white[i - 1][j] + sum_white[i][j - 1] - sum_white[i - 1][j - 1];

            // ���� ĭ�� ¦�� ĭ�� ���, ù ĭ�� �������� ����� �������̴�.
            // ù ĭ�� �Ͼ���� ����� �Ͼ���̹Ƿ�, �ٸ� ���� ��쿡�� sum_black[i][j]�� 1��������. 
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

    // ������ ù ĭ�� �������� �����, �Ͼ���� ����� ������ K X Kĭ�� ���带 ���� ��, ĥ�ؾ� �ϴ� ĭ�� ����
    // �� ���� ���带 �����, �� ���� �ּڰ��� ���Ѵ�.
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
