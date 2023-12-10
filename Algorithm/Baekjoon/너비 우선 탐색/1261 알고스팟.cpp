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
            // 현재 노드의 상하좌우를 탐색
            int next_node_x = current_node.first + move_x[i];
            int next_node_y = current_node.second + move_y[i];
            if (next_node_x < 0 || next_node_x >= N || next_node_y < 0 || next_node_y >= M)
            {
                continue;
            }

            // 현재 노드까지의 거리에서 벽이 있다면 +1 없다면 +0이 다음 노드까지의 거리이다.
            int next_dist = dist[current_node.first][current_node.second] + maze[next_node_x][next_node_y];

            // 갱신할 수 있다면 거리를 갱신하고, 큐에 넣는다.
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
            // 미로와 거리를 초기화
            maze[i][j] = s[j] - '0';
            dist[i][j] = INT_MAX;
        }
    }

    bfs(0, 0);

    cout << dist[N - 1][M - 1];

    return 0;
}
