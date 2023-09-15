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

using namespace std;

typedef struct
{
    int x;
    int y;
    int distance;
}types;

queue<types> bfs;
int board[1001][1001];
bool visited[1001][1001];
int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };
int result[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
            {
                bfs.push(types{ i, j, 0 });
                visited[i][j] = true;
            }
            else if (board[i][j] == 0)
            {
                visited[i][j] = true;
            }
        }
    }

    while (!bfs.empty())
    {
        auto current = bfs.front();
        bfs.pop();

        result[current.x][current.y] = current.distance;

        for (int i = 0; i < 4; ++i)
        {
            int next_x = current.x + move_x[i];
            int next_y = current.y + move_y[i];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && !visited[next_x][next_y])
            {
                bfs.push(types{ next_x, next_y, current.distance + 1 });
                visited[next_x][next_y] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == 1 && !visited[i][j])
            {
                result[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}