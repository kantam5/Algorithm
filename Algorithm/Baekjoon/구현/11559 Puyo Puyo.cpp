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
}tile;

char field[12][6];

queue<vector<tile>> explode;        // 폭발할 뿌요들을 넣어놓은 queue

// bfs를 위한 준비
int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };
bool visited[12][6];

void search_explode()
{
    // 필드의 타일들을 탐사한다. 
    for (int x = 0; x < 12; ++x)
    {
        for (int y = 0; y < 6; ++y)
        {
            // 빈공간이 아닐 경우 bfs로 서로 연결된 뿌요들을 vector에 넣는다. 
            if (field[x][y] == '.')
            {
                continue;
            }

            queue<tile> bfs;
            if (visited[x][y] == false)
            {
                bfs.push({ x, y });
                visited[x][y] = true;
            }

            vector<tile> puyos;
            while (!bfs.empty())
            {
                tile current_tile = bfs.front();
                bfs.pop();
                puyos.push_back(current_tile);

                for (int i = 0; i < 4; ++i)
                {
                    int next_x = current_tile.x + move_x[i];
                    int next_y = current_tile.y + move_y[i];
                    if (next_x < 12 && next_x >= 0 && next_y < 6 && next_y >= 0
                        && field[next_x][next_y] == field[x][y] && visited[next_x][next_y] == false)
                    {
                        bfs.push({ next_x, next_y });
                        visited[next_x][next_y] = true;
                    }
                }
            }

            // vector가 4이상일 경우 explode에 넣는다.
            if (puyos.size() >= 4)
            {
                explode.push(puyos);
            }
        }
    }

    memset(visited, false, sizeof(visited));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);

    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            cin >> field[i][j];
        }
    }

    // 처음 터질 뿌요들을 탐사한다.
    search_explode();

    int answer = 0;
    while (!explode.empty())
    {
        answer++;

        // explode내의 모든 뿌요들을 터트린다.
        while (!explode.empty())
        {
            auto current = explode.front();
            explode.pop();

            for (tile t : current)
            {
                field[t.x][t.y] = '.';
            }
        }

        // 터트린 후에 아랫줄 부터 검사하면서 위에 있는 뿌요들을 떨어뜨린다.
        // 현재 타일이 '.'일 경우 해당 타일 바로 위에 있는 뿌요로 값을 바꾼다.
        // 떨어진 뿌요는 '.'로 값을 설정한다.
        for (int x = 11; x >= 0; --x)
        {
            for (int y = 5; y >= 0; --y)
            {
                if (field[x][y] == '.')
                {
                    for (int i = x - 1; i >= 0; --i)
                    {
                        if (field[i][y] != '.')
                        {
                            swap(field[x][y], field[i][y]);
                            break;
                        }
                    }
                }
            }
        }

        // 다시 explode를 탐사한다.
        search_explode();
    }

    cout << answer;

    return 0;
}