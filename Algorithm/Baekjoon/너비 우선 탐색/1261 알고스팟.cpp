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

int N, M;
int maze[100][100];
int dist[100][100];

int move_x[4] = { -1, 0, 1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

void bfs(int start_x, int start_y)
{
    dist[start_x][start_y] = 0;

    queue<pair<int, int>> q;
    q.push(make_pair(start_x, start_y));

    while (!q.empty())
    {
        pair<int, int> current_node = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            // ���� ����� �����¿츦 Ž��
            int next_node_x = current_node.first + move_x[i];
            int next_node_y = current_node.second + move_y[i];
            if (next_node_x < 0 || next_node_x >= N || next_node_y < 0 || next_node_y >= M)
            {
                continue;
            }

            // ���� �������� �Ÿ����� ���� �ִٸ� +1 ���ٸ� +0�� ���� �������� �Ÿ��̴�.
            int next_dist = dist[current_node.first][current_node.second] + maze[next_node_x][next_node_y];

            // ������ �� �ִٸ� �Ÿ��� �����ϰ�, ť�� �ִ´�.
            if (dist[next_node_x][next_node_y] > next_dist)
            {
                dist[next_node_x][next_node_y] = next_dist;
                q.push(make_pair(next_node_x, next_node_y));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j)
        {
            // �̷ο� �Ÿ��� �ʱ�ȭ
            maze[i][j] = s[j] - '0';
            dist[i][j] = INT_MAX;
        }
    }

    bfs(0, 0);

    cout << dist[N - 1][M - 1];

    return 0;
}
