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

int N;
int room[125][125];
int dist[125][125];

int move_x[4] = { -1, 0, 1, 0 };
int move_y[4] = { 0, 1, 0, -1 };

void solution(int start_x, int start_y)
{
    // 시작 위치의 거리는 0이 아니라 시작 위치의 도둑 루피의 크기이다.
    dist[start_x][start_y] = room[start_x][start_y];

    queue<pair<int, int>> q;
    q.push(make_pair(start_x, start_y));

    while (!q.empty())
    {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            // 현재 칸의 상하좌우를 탐색
            int next_x = current_x + move_x[i];
            int next_y = current_y + move_y[i];
            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
            {
                continue;
            }

            // 다음 칸의 거리를 갱신할 수 있다면 갱신하고, 큐에 넣는다.
            int next_dist = dist[current_x][current_y] + room[next_x][next_y];
            if (next_dist < dist[next_x][next_y])
            {
                dist[next_x][next_y] = next_dist;
                q.push(make_pair(next_x, next_y));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int count = 0;
    while (cin >> N)
    {
        if (N == 0)
        {
            break;
        }

        count++;

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cin >> room[i][j];
                dist[i][j] = INT_MAX;
            }
        }

        solution(0, 0);

        cout << "Problem " << count << ": " << dist[N - 1][N - 1] << '\n';
    }

    return 0;
}
