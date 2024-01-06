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

    // (x, y)ĭ�� �� �� �ִ� ����� ���� (x - 1, y)ĭ�� (x, y - 1)ĭ�� �� �� �ִ� ����� ���� ���̴�.
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
        // �߰� ��� K�� (x, y) ��ǥ�� ������ ���� ��Ÿ�� �� �ִ�.
        int inter_x = (K - 1) / M;
        int inter_y = (K - 1) % M;

        // K���� ������ ĭ������ ���
        int inter_count = cache[inter_x][inter_y];
        int dest_count = cache[N - inter_x - 1][M - inter_y - 1];

        // K������ ��ο� K���� ������ ĭ ������ ����� ���� ���
        cout << inter_count * dest_count;
    }

    return 0;
}
