#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <climits>

using namespace std;

typedef struct
{
    int x;
    int y;
}type;
queue<type> bfs;

char ground[601][601];
bool visited[601][601];

int main()
{
    int N;
    int M;
    int result = 0;

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> ground[i][j];

            if (ground[i][j] == 'I')
            {
                // 도연이의 위치를 큐에 저장
                bfs.push({ i, j });
                visited[i][j] = true;
            }
            else if (ground[i][j] == 'X')
            {
                // 벽일 경우
                visited[i][j] = true;
            }
        }
    }

    int move_x[4] = { 0, 0, 1, -1 };
    int move_y[4] = { 1, -1, 0, 0 };

    while (!bfs.empty())
    {
        auto current = bfs.front();
        bfs.pop();

        // 사람을 만나면 result++
        if (ground[current.x][current.y] == 'P')
        {
            result++;
        }

        for (int i = 0; i < 4; ++i)
        {
            int next_x = current.x + move_x[i];
            int next_y = current.y + move_y[i];
            if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && !visited[next_x][next_y])
            {
                bfs.push({ next_x, next_y });
                visited[next_x][next_y] = true;
            }
        }
    }

    if (result == 0)
    {
        cout << "TT";
    }
    else
    {
        cout << result;
    }

    return 0;
}