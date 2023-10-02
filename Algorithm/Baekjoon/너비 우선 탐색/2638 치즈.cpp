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
}type;
queue<type> q;
int ground[101][101];
int visited[101][101];
int cheese_ground[101][101];
int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int cheese = 0;
    int answer = 0;

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> ground[i][j];
            // 처음 치즈의 수
            if (ground[i][j] == 1)
            {
                cheese++;
            }
        }
    }

    // 치즈가 모두 없어질 때까지 진행
    while (cheese > 0)
    {
        // 가장자리는 모두 비어있으므로 (0, 0)에서 bfs 시작
        q.push({ 0, 0 });
        visited[0][0] = true;

        while (!q.empty())
        {
            int current_x = q.front().x;
            int current_y = q.front().y;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int next_x = current_x + move_x[i];
                int next_y = current_y + move_y[i];
                if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M
                    && !visited[next_x][next_y] && ground[next_x][next_y] == 0)
                {
                    q.push({ next_x, next_y });
                    visited[next_x][next_y] = true;
                }

                // bfs와 동시에 치즈마다 몇 번 공기와 접촉하는지 체크
                if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M
                    && ground[next_x][next_y] == 1)
                {
                    cheese_ground[next_x][next_y]++;
                }
            }
        }

        // 치즈가 공기와 2번 이상 접촉했다면 삭제
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (cheese_ground[i][j] >= 2)
                {
                    ground[i][j] = 0;
                    cheese--;
                }
            }
        }

        answer++;
        memset(cheese_ground, 0, sizeof(cheese_ground));
        memset(visited, false, sizeof(visited));
    }

    cout << answer;

    return 0;
}