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

using namespace std;

typedef struct
{
    int x;
    int y;
    int distance;
}types;

int N;
queue<types> bfs;
int ground[101][101];
int water_ground[101][101];
int visited[101][101];

int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; ++i)
    {
        // 상하좌우 잠기지 않은 지역으로 dfs
        int next_x = x + move_x[i];
        int next_y = y + move_y[i];
        if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N && !visited[next_x][next_y] && water_ground[next_x][next_y] == 1)
        {
            dfs(next_x, next_y);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result = 0;

    int max_ground = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> ground[i][j];
            max_ground = max(max_ground, ground[i][j]);
        }
    }

    for (int i = 0; i <= max_ground; ++i)
    {
        int safe_area_count = 0;

        for (int x = 0; x < N; ++x)
        {
            for (int y = 0; y < N; ++y)
            {
                // 잠긴 지역 표시
                if (ground[x][y] < i)
                {
                    water_ground[x][y] = 0;
                }
                else
                {
                    water_ground[x][y] = 1;
                }
            }
        }

        // 잠긴 ground로 dfs실행
        for (int x = 0; x < N; ++x)
        {
            for (int y = 0; y < N; ++y)
            {
                if (water_ground[x][y] == 1 && !visited[x][y])
                {
                    safe_area_count++;
                    dfs(x, y);
                }
            }
        }

        memset(visited, false, sizeof(visited));

        result = max(result, safe_area_count);
    }

    cout << result;

    return 0;
}