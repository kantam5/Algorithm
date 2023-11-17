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

typedef struct
{
    int x;
    int y;
}block;

queue<block> bfs;
int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };

int road[1001][1001];
bool water[1001][1001];
int water_sum[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int h, w;
    cin >> N >> M;
    cin >> h >> w;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> road[i][j];
        }
    }
    memset(water, true, sizeof(water));

    int K;
    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        int x, y;
        cin >> x >> y;

        // �ϼ����������� BFS ����
        water[x][y] = false;
        bfs.push({ x, y });
    }

    // BFS�� ��� ĭ�� ���� �������� Ž���Ѵ�.
    while (!bfs.empty())
    {
        block current = bfs.front();
        bfs.pop();

        for (int i = 0; i < 4; ++i)
        {
            int next_x = current.x + move_x[i];
            int next_y = current.y + move_y[i];

            if (next_x < 1 || next_x > N || next_y < 1 || next_y > M || !water[next_x][next_y])
            {
                continue;
            }

            // ���� ĭ���� ���� ���� �̻��� ĭ�� ���� ������.
            if (road[current.x][current.y] <= road[next_x][next_y])
            {
                water[next_x][next_y] = false;
                bfs.push({ next_x, next_y });
            }
        }
    }

    // (1, 1)���� (i, j)ĭ ���� ���� �ִ� ĭ�� ��
    // ������
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            water_sum[i][j] = water_sum[i - 1][j] + water_sum[i][j - 1] - water_sum[i - 1][j - 1] + water[i][j];
        }
    }

    int answer = 0;
    // (i, j)ĭ���� (i - h + 1, j + w - 1)ĭ���� ���� ���ٸ� answer++
    for (int i = 1; i <= N - h + 1; ++i)
    {
        for (int j = 1; j <= M - w + 1; ++j)
        {
            int section = water_sum[i + h - 1][j + w - 1] - water_sum[i + h - 1][j - 1] - water_sum[i - 1][j + w - 1]
                + water_sum[i - 1][j - 1];

            if (section == 0)
            {
                answer++;
            }
        }
    }

    cout << answer;

    return 0;
}