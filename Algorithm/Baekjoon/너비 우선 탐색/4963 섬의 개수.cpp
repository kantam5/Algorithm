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

int w, h;
int m[50][50];
bool visited[50][50];
int move_x[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int move_y[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };

int numIslands()
{
    memset(visited, false, sizeof(visited));
    int result = 0;

    // w, h 주의
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (m[i][j] == 1 && visited[i][j] == false)
            {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                visited[i][j] = true;

                while (!q.empty())
                {
                    int current_x = q.front().first;
                    int current_y = q.front().second;
                    q.pop();

                    // 상하좌우, 대각 8방향, 너비 우선 탐색
                    for (int k = 0; k < 8; ++k)
                    {
                        int next_x = current_x + move_x[k];
                        int next_y = current_y + move_y[k];

                        if (next_x < 0 || next_x >= h || next_y < 0 || next_y >= w
                            || visited[next_x][next_y] == true || m[next_x][next_y] == 0)
                        {
                            continue;
                        }

                        q.push(make_pair(next_x, next_y));
                        visited[next_x][next_y] = true;
                    }
                }

                result++;
            }
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // w, h 주의
    while (cin >> w >> h)
    {
        if (w == 0 && h == 0)
        {
            break;
        }

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin >> m[i][j];
            }
        }

        cout << numIslands() << '\n';
    }

    return 0;
}
