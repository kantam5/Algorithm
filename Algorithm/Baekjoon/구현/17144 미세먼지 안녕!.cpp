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

int room[51][51];
int room_dif[51][51];
int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };
int airConUp = -1;
int airConDown = -1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int R, C, T;
    int answer = 0;

    cin >> R >> C >> T;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> room[i][j];

            if (room[i][j] == -1 && airConUp == -1)
            {
                airConUp = i;
                airConDown = i + 1;
            }
        }
    }

    while (T--)
    {
        // 미세먼지 확산
        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                if (room[i][j] == -1 || room[i][j] == 0 || room[i][j] / 5 == 0)
                {
                    continue;
                }

                int diffuse_count = 0;
                for (int k = 0; k < 4; ++k)
                {
                    int next_x = i + move_x[k];
                    int next_y = j + move_y[k];
                    if (next_x >= 0 && next_y >= 0 && next_x < R && next_y < C && room[next_x][next_y] != -1)
                    {
                        room_dif[next_x][next_y] += (room[i][j] / 5);
                        diffuse_count++;
                    }
                }

                room_dif[i][j] -= (diffuse_count * (room[i][j] / 5));
            }
        }

        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                room[i][j] += room_dif[i][j];
                room_dif[i][j] = 0;
            }
        }

        // 공기청정기 순환
        for (int i = airConUp - 1; i > 0; --i)
        {
            room[i][0] = room[i - 1][0];
        }
        for (int i = 0; i < C - 1; ++i)
        {
            room[0][i] = room[0][i + 1];
        }
        for (int i = 0; i < airConUp; ++i)
        {
            room[i][C - 1] = room[i + 1][C - 1];
        }
        for (int i = C - 1; i > 0; --i)
        {
            if (i == 1)
            {
                room[airConUp][1] = 0;
                continue;
            }
            room[airConUp][i] = room[airConUp][i - 1];
        }

        for (int i = airConDown + 1; i < R - 1; ++i)
        {
            room[i][0] = room[i + 1][0];
        }
        for (int i = 0; i < C - 1; ++i)
        {
            room[R - 1][i] = room[R - 1][i + 1];
        }
        for (int i = R - 1; i > airConDown; --i)
        {
            room[i][C - 1] = room[i - 1][C - 1];
        }
        for (int i = C - 1; i > 0; --i)
        {
            if (i == 1)
            {
                room[airConDown][1] = 0;
                continue;
            }
            room[airConDown][i] = room[airConDown][i - 1];
        }

    }

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (room[i][j] != -1)
            {
                answer += room[i][j];
            }
        }
    }

    cout << answer;

    return 0;
}