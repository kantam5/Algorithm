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

using namespace std;

typedef struct
{
    int x;
    int y;
} types;

int N;
int M;
int lab[9][9];
int temp_lab[9][9];
bool visited[9][9];
int dx[4] = { 1, -1, 0 ,0 };
int dy[4] = { 0, 0, 1, -1 };
queue<types> bfs;
int result = 0;

void buildWall(int cnt)
{
    if (cnt == 3)
    {
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (temp_lab[i][j] == 2)
                {
                    bfs.push({ i, j });
                    visited[i][j] = true;
                }
                else if (temp_lab[i][j] == 1)
                {
                    visited[i][j] = true;
                }
            }
        }

        while (!bfs.empty())
        {
            auto current = bfs.front();
            bfs.pop();

            for (int i = 0; i < 4; i++)
            {
                int new_x = current.x + dx[i];
                int new_y = current.y + dy[i];

                if (new_x >= 0 && new_y >= 0 && new_x < N && new_y < M && !visited[new_x][new_y])
                {
                    bfs.push({ new_x, new_y });
                    visited[new_x][new_y] = true;
                }
            }
        }

        int zero_count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (visited[i][j] == false)
                {
                    zero_count++;
                }
            }
        }
        result = max(result, zero_count);

        return;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (temp_lab[i][j] == 0)
            {
                temp_lab[i][j] = 1;
                buildWall(cnt + 1);
                temp_lab[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> lab[i][j];

            if (lab[i][j] == 2)
            {
                bfs.push({ i, j });
                visited[i][j] = true;
            }
            else if (lab[i][j] == 1)
            {
                visited[i][j] = true;
            }
        }
    }

    copy(&lab[0][0], &lab[0][0] + 81, &temp_lab[0][0]);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (temp_lab[i][j] == 0)
            {
                temp_lab[i][j] = 1;
                buildWall(1);
                temp_lab[i][j] = 0;
            }
        }
    }

    cout << result << '\n';

    return 0;
}