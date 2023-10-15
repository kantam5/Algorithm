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

int house[1001][3];
int cache[1001][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> house[i][j];
        }
    }

    // ù��° ������ R�� �������� ��, G�� �������� ��, B�� �������� ��
    // 3���� ��츦 ���Ѵ�.
    int color = 0;
    int answer = INT_MAX;
    while (color < 3)
    {
        // ������ �� �ܿ��� ����� ū ������ ����
        cache[0][color] = house[0][color];
        cache[0][(color + 1) % 3] = 10000;
        cache[0][(color + 2) % 3] = 10000;

        // ���� ���� �� �ڽ��� ���� �ٸ� ���� ��츸 ���Ѵ�.
        for (int i = 1; i < N; ++i)
        {
            cache[i][0] = min(house[i][0] + cache[i - 1][1], house[i][0] + cache[i - 1][2]);
            cache[i][1] = min(house[i][1] + cache[i - 1][0], house[i][1] + cache[i - 1][2]);
            cache[i][2] = min(house[i][2] + cache[i - 1][0], house[i][2] + cache[i - 1][1]);
        }

        for (int i = 0; i < 3; ++i)
        {
            // ������ ���� ù��° ���� ������ ���� ���� �����Ѵ�.
            if (i == color)
            {
                continue;
            }

            answer = min(answer, cache[N - 1][i]);
        }

        // ���� ������ �Ѿ��.
        color++;
    }

    cout << answer;

    return 0;
}